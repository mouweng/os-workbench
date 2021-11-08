#include <stdio.h>
#include <assert.h>
#include <string.h>

char default_path[1024] = "/proc/";

int main(int argc, char *argv[]) {
    char dir[1024];
    struct dirent **namelist;
    strcpy(dir, default_path);
    int total = scandir(dir, &namelist, 0, alphasort);
    printf("path=%s, total = %d\n", dir, total);
}
