#include<stdio.h>
#include<unistd.h>

void solve(){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        printf("Fork Failed \n");
    }else if(pid == 0){

        printf("\n Child Process:\n");
        for(int i = 6 ; i <= 10; i++){
            printf("%d ",i);
        }
        printf("\n");
    }else{
        printf("\n Parent Process :\n");
        for(int i = 1; i <= 5; i++){
            printf("%d ",i);
        }
        printf("\n");
    }
}

int main(){

    solve();
    return 0;
}