#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

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

int main() {
    openlog("EDK Writer", LOG_PERROR, LOG_USER);
    syslog(LOG_INFO, "Just logging some info");
    syslog(LOG_DEBUG, "Just logging some debug stuff");
    return 0;
}
