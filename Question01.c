#include<stdio.h>
#include<unistd.h>

void solve(){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        printf("Fork Failed \n");
    }else if(pid == 0){
        printf("Child Process :");
        printf("Child PID : %d\n",getpid());
        printf("Parent PID (PPID of Child): %d\n",getppid());
    }else{
        printf("\nParent Process : ");
        printf("Parent PID : %d\n",getpid());
        printf("Child PID : %d\n",pid);
    }
}
int main(){
    solve();
    return 0;
}