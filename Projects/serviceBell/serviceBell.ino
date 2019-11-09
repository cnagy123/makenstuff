///////////////
// Includes
///////////////
#include "config.h"
#include "Adafruit_NeoPixel.h"

///////////////
// Prototypes
//////////////
void addBlocks(void);
void handleCall(void);
void handleReply(void);

///////////////
// Defines
///////////////
#define SWITCH_PIN    4
#define PIXEL_PIN     5
#define PIXEL_COUNT   12
#define PIXEL_TYPE    NEO_GRB + NEO_KHZ800

///////////////
// Globals
///////////////
// Feeds
AdafruitIO_Feed *call_feed = io.feed("call");
AdafruitIO_Feed *reply_feed = io.feed("reply");

// Dashboard
AdafruitIO_Dashboard *service_dashboard = io.dashboard("service");

// Lever Switch
bool current = false;
bool last = false;

// NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Strings
String service_string = "SERVICE CALL";
String idle_string = "IDLE";

///////////////
// Main Setup
///////////////
void setup(){

  // set lever-switch pin to input
  pinMode(SWITCH_PIN, INPUT);

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  // create the feeds if they don't exist
  if(call_feed->exists()) {
    Serial.println("Call feed exists.");
  } else {
    if(call_feed->create()) {
      Serial.println("Call feed created.");
    } else {
      Serial.println("Call feed creation failed.");
    }
  }
  
  if(reply_feed->exists()) {
    Serial.println("Reply feed exists.");
  } else {
    if(reply_feed->create()) {
      Serial.println("Reply feed created.");
    } else {
      Serial.println("Reply feed creation failed.");
    }
  }
  
  // create the dashboard if it doesn't exist
  if(service_dashboard->exists()) {
    Serial.println("Service dashboard exists.");
  } else {
    if(service_dashboard->create()) {
      Serial.println("Service dashboard created.");
      // add blocks to the dashboard using the function below
      addBlocks();
    } else {
      Serial.println("Service dashboard creation failed.");
    }
  }
  
  // attach handler to reply feed
  reply_feed->onMessage(handleReply);

  // neopixel init
  pixels.begin();
  pixels.show();
}

///////////////
// Main Loop
///////////////
void loop(){

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  // check for user input
  pollSwitch();
  
  // handle call if needed
  handleCall();
}

///////////////
// Functions
////////////////

/*** addBlocks ***/
void addBlocks(void){

  bool added = false;

  Serial.print("Adding Reply Button momentary block... ");
  MomentaryBlock *button = dashboard->addMomentaryBlock(reply_feed);
  button->text = "Button";
  button->value = "1";
  button->release = "0";
  added = button->save();
  Serial.println(added ? "added" : "failed");

  Serial.print("Adding Call Status text block... ");
  TextBlock *text = dashboard->addTextBlock(call_feed);
  text->fontSize = "large"; // small, medium, or large
  added = text->save();
  Serial.println(added ? "added" : "failed");
}

/*** pollSwitch ***/
void pollSwitch(void){
 
	if(digitalRead(SWITCH_PIN) == LOW){
		current = false;
	}else{
		current = true;
	}
}

/*** handleCall ***/
void handleCall(void){

  // detect low to high condition
  if((current == true)&&(last == false)){
	
	// change the neopixels to the call request color (red)
	for(int i=0; i<PIXEL_COUNT; ++i) {
		pixels.setPixelColor(i, 150,0,0);
	}
	pixels.show();
  
	// send the service call
	Serial.print("sending call -> ");
	Serial.println(service_string);
    call_feed->save(service_string);
  }
  
  // update the last state with the current state
  last = current;
}

/*** handleCall ***/
void handleReply(void){

	// change the neopixels to the idle color (green)
	for(int i=0; i<PIXEL_COUNT; ++i) {
		pixels.setPixelColor(i, 0,150,0);
	}
	pixels.show();
	
	// send the idle call
	Serial.print("sending call -> ");
	Serial.println(idle_string);
    call_feed->save(idle_string);
}