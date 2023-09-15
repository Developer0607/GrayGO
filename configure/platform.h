#define PLT_CONSOLE 1000
#define PLT_WIN     1001 //This is unavailable
#define PLT_LINUX   1002 //This is unavailable
#define PLT_MACOS   1003 //This is unavailable


//TODO: Change this for current system
#define PLATFORM    PLT_CONSOLE

#if PLATFORM == PLT_CONSOLE

    #include "platform-console.h"

#endif
