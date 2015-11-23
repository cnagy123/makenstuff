
// Buffer for Full Path of Current Working Directory
static uint8_t CWD_Buffer[SD_PATH_BUFFER_SIZE] = "/"; // Set to root

// Buffer for Temporary Storage
static uint8_t TMP_Buffer[SD_PATH_BUFFER_SIZE];

// Buffer for Command Line
static uint8_t CMD_Buffer[CMD_BUFFER_SIZE];


// FatFs Data Structures
static FATFS FatFs;
static DIR DirObject;
static FILINFO FileInfo;
static FIL FileObject;