#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Hi from parent");
    char* args[] = {"./3.2-child.exe",NULL};
    fflush(stdout);
    execv(args[0],args);
    printf("End");
}