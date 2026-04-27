#include<stdio.h>
#include<unistd.h>

void solve(){

    pid_t pid1, pid2;
    pid1 = fork();

    if(pid1 == 0){
        printf("\nFirst Child Process\n");
        printf("PID : %d, PPID : %d",getpid(),getppid());
    }else{
        pid2 = fork();

        if(pid2 == 0){
            printf("\nSecond Child Process\n");
            printf("PID : %d, PPID : %d",getpid(),getppid());
        }else{
            printf("\nParent Process :");
            printf("PID : %d\n",getpid());

            printf("\nChild1 PID : %d\n",pid1);
            printf("Child2 PID : %d\n",pid2);
        }
    }
}

int main(){
    solve();
    return 0;
}