#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
int pid, j, status;

for (j=0; j<2; j++) {

    /*** error handling ***/
    if ((pid = fork()) < 0 ) {
        printf ("fork failed with error code= %d\n", pid);
        //exit(0);
    }

    /*** this is the child of the fork ***/
    else if (pid ==0) {
        //do_nothing();
        printf("--(%d->%d:%d)\n",getpid(),pid,j);
        //exit(0);
    }

    /*** this is the parent of the fork ***/
    else {
        printf("--(%d->%d:%d)\n",getpid(),pid,j);
        waitpid(pid, &status, 0);
        printf("\t\tchild %d of %d end\n",pid,getpid());
    }
  }
  exit(0);
} 