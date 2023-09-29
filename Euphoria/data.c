#include <stdio.h>
#include <stdbool.h>
#include <io.h> // Include the necessary header for _access()

/**
 * Checks if a file exists.
 *
 * @param filename The file name.
 *
 */
bool doesFileExist(const char* filename) {
    return _access(filename, 0) != -1;
}
