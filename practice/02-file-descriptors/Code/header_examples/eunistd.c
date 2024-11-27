#include <unistd.h>
#include <stdio.h> 
int main() { 
    printf("Current process ID: %d\n", getpid());
    return 0; 
}
