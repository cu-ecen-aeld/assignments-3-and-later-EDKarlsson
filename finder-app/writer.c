#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * Instructions
 * -----------------------------------------------------------------
 * Write the specified string to a specified file given by the user.
 * 1. Does not have to create directories if it does not exist.
 * 2. Setup syslog logging for your utility using the LOG_USER facility.
 * 3. Use syslog to write "Writing <string> to <file>" where 
 *      - <string> is the 2nd argument provided.
 *      - <file> is the 1st argument provided.
 *      - Should be written with LOG_DEBUG level
 * 4. Use syslog to log any unexpected errors with LOG_ERR level
 */

// int open(const char *name, int flags);
// int open(const char *name, int flags);
// syslog(LOG_INFO, "Just logging some info");
// syslog(LOG_DEBUG, "Just logging some debug stuff");

int main(int argc, char *argv[]) {
    int fd;
    ssize_t nr;

    openlog("Writer App", LOG_PERROR, LOG_USER);

    if(argc < 3) {
        syslog(LOG_ERR, "Not enough arguments provided"); 
        syslog(LOG_ERR, "\tusage: ./writer file string");
        return 1;
    }

    fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
    if(fd == -1){
        syslog(LOG_ERR, "Unable to open file.");
        return 1;
    }

    nr = write(fd, argv[2], strlen(argv[2]));
    if (nr == 1) {
        syslog(LOG_ERR, "Failed to write to file.");
        return 1;
    }

    return 0;
}
