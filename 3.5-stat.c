#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void printFileProps(struct stat stats);

int main(){
    struct stat buf;

    if((stat("5.2-sjf.exe",&buf)) == -1){
        perror("Error : ");
    } else {
        printFileProps(buf);
    }
}

void printFileProps(struct stat stats){
    struct tm dt;

    printf("File access : ");
    if(stats.st_mode & R_OK){
        printf("read ");
    }
    if(stats.st_mode & W_OK){
        printf("write ");
    }
    if(stats.st_mode & X_OK){
        printf("execute ");
    }

    printf("\nSize : %ld",stats.st_size);

    dt = *(gmtime(&stats.st_ctime));
    printf("\nChanged On : %d:%d:%d %d:%d:%d",dt.tm_mday,dt.tm_mon,dt.tm_year+1900,dt.tm_hour,dt.tm_min,dt.tm_sec);

    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified On : %d:%d:%d %d:%d:%d",dt.tm_mday,dt.tm_mon,dt.tm_year+1900,dt.tm_hour,dt.tm_min,dt.tm_sec);
}