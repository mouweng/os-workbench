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
    int count = 0;
    char dir[1024], str[1024];
    struct dirent **namelist;
    strcpy(dir, default_path);
    int total = scandir(dir, &namelist, 0, alphasort); //查看所有文件的个数
    printf("path=%s, total = %d\n", dir, total);
    for (int i = 0; i < total; i ++) {
        strcpy(str, namelist[i]->d_name);
        if (str[0] >= '0' && str[0] <= '9') count ++;
    }
    printf("进程数：%d\n", count);
}
