// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// char default_path[1024] = "/proc/";

// int main(int argc, char *argv[]) {
//   assert(!argv[argc]);
//   if (argc != 2) {
//     printf("argc = %d, Argument Number Error!\n", argc);
//     return 0;
//   }
//   assert(argv[1]);
//   // printf("argv = %s\n", argv[1]);
//   if (strcmp(argv[1], "-V") == 0 || strcmp(argv[1], "--version") == 0) {
//     printf("version\n");
//   } else if (strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--numeric-sort") == 0) {
//     printf("numeric-sort\n");
//   } else if (strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "--show-pids") == 0) {
//     printf("show-pids\n");
//   } else {
//     printf("There Is No Such Argument Named \"%s\"\n", argv[1]);
//   }
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>
char default_path[1024]="/proc/";
int s=0;
typedef struct file_info
{
    int pid;
    int ppid;
    char name[1024];
    int flag;
    int rec;
}info;

int my_getpid(char *str){
    int len=strlen(str);
    char num[10];
    int i,j,ret;
    if(strncmp(str,"Pid",3)==0){
        for(i=0;i<len;i++){
            if(str[i]>='0'&&str[i]<='9')
                break;
        }
        for(j=0;j<len-i;j++){
            num[j]=str[i+j];
        }
        ret=atoi(num);
    }else
        ret=0;
    return ret;
}
int my_getppid(char *str){
    int len=strlen(str);
    char num[10];
    int i,j,ret;
    if(strncmp(str,"PPid",4)==0){
        for(i=0;i<len;i++){
            if(str[i]>='0'&&str[i]<='9')
                break;
        }
        for(j=0;j<len-i;j++){
            num[j]=str[i+j];
        }
        ret=atoi(num);
        }
    else
        ret=0;
    return ret;
}
int child_exist(info *file,int count,int ppid){
    int i;
    for(i=0;i<count;i++){
        if(file[i].flag==0&&file[i].ppid==ppid)
            return 1;
        }
    return 0;
}
void print_pstree(info *file,int count,int ppid,int rec){
    int i,j,k;
    for(i=0;i<count;i++){
        if(file[i].flag==0&&file[i].ppid==ppid)
        {
            file[i].rec=rec+1;
            file[i].flag=1;
            for(k=0;k<rec;k++)
                printf("      ");
            printf("[%d]%s\n",file[i].pid,file[i].name);
            print_pstree(file,count,file[i].pid,file[i].rec);
        }
    }
}
int main(){
    int i,j,k,total,s1,s2,count,t;
    char str[1024],dir[1024];
    struct dirent **namelist;
    strcpy(dir,default_path);
    total = scandir(dir, &namelist, 0, alphasort);
    printf("path=%s,total=%d\n",dir,total);
    for(i=0;i<total;i++){
        strcpy(str,namelist[i]->d_name);
        if(str[0]>='0'&&str[0]<='9')
            count++;
    }
    printf("进程数:%d\n",1);
    // info file[1024];
    // i=0;t=0;
    // while(i<total)
    // {
    // FILE *fp;
    // char path[1024],name[1024];
    // int pid,ppid;
    // strcpy(str,namelist[i]->d_name);
    // strcpy(path,default_path);
    // if(str[0]>='0'&&str[0]<='9'){
    //     strcat(path,str);
    //     strcat(path,"/status");
    //     fp=fopen(path,"r");
    //     while(!feof(fp)){
    //         fgets(str,1024,fp);
    //             if((s1=my_getpid(str))!=0)
    //                 pid=s1;
    //             if((s2=my_getppid(str))!=0)
    //                 ppid=s2;
    //             if(strncmp(str,"Name",4)==0){
    //                 for(j=4;j<strlen(str);j++){
    //                     if(str[j]>='a'&&str[j]<='z')
    //                         break;
    //                 }
    //                 for(k=j;k<strlen(str);k++){
    //                     name[k-j]=str[k];
    //                 }
    //                 name[k-j-1]='\0';
    //             }
    //             file[t].pid=pid;
    //             file[t].ppid=ppid;
    //             strcpy(file[t].name,name);
    //         }
    //         fclose(fp);
    //         t++;
    //     }
    //     i++;
    // }
    // memset(&file->flag,0,count);
    // memset(&file->rec,0,count);
    // print_pstree(file,count,0,0);
}