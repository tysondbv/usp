#include <stdio.h>
#include <sys/stat.h>
#include <utime.h>

int main() {
    const char *orif = "p51.txt";
    const char *destf = "p52.txt";

    struct stat ft;
    struct utimbuf tb;

    // Get the access and modification times of the original file
    if (stat(orif, &ft) == -1) {
        printf("Error getting file status for the original file.\n");
        return -1;
    }

    // Copy the access and modification times to the destination file
    tb.actime = ft.st_atime;
    tb.modtime = ft.st_mtime;
    if (utime(destf, &tb) == -1) {
        printf("Error setting file times for the destination file.\n");
        return -1;
    }

    // Verify if the times are copied correctly by re-reading the destination file's times
    struct stat destStat;
    if (stat(destf, &destStat) == -1) {
        printf("Error getting file status for the destination file.\n");
        return -1;
    }

    // Compare the access times (atime) of the original file and the destination file
    if (ft.st_atime == destStat.st_atime) {
        printf("Access time is the same for the original and destination files.\n");
    } else {
        printf("Access time is different for the original and destination files.\n");
    }

    // Compare the modification times (mtime) of the original file and the destination file
    if (ft.st_mtime == destStat.st_mtime) {
        printf("Modification time is the same for the original and destination files.\n");
    } else {
        printf("Modification time is different for the original and destination files.\n");
    }

    printf("Copied access and modification times successfully.\n");

    return 0;
}
