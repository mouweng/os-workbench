#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>

char default_path[1024] = "/proc/";

int main(int argc, char *argv[]) {
    char dir[1024];
    struct dirent **namelist;
    strcpy(dir, default_path);
    int total = scandir(dir, &namelist, 0, alphasort);
    printf("%d", namelist);
    printf("path=%s, total = %d\n", dir, total);
}
