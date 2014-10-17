#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
  int i;
  for(i = 0;i < 2;i++){
    int pid = fork();
    if(pid == 0){
      fflush(stdout);
      printf("|--(%d,%d,%d:%d)",getppid(),getpid(),pid,i);
    } else{
      printf("--(%d,%d,%d:%d)",getppid(),getpid(),pid,i);
    }
  }
} 