#include<stdio.h>

void solve(){
    int n,m;
    printf("Enter number of process :");
    scanf("%d",&n);
    printf("Enter number of resources :");
    scanf("%d",&m);

    int alloc[n][m],req[n][m],need[n][m];

    int avail[m],finish[n];

    printf("Enter Allocation matrix :");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0;  j < m ; j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter Request matrix :");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0;  j < m ; j++){
            scanf("%d",&req[i][j]);
        }
    }

    printf("Enter available resources :");
    for(int i = 0 ; i < m; i++){
        scanf("%d",&avail[i]);
    }

    for(int i = 0 ; i < n; i++){
        finish[i] = 0;
    }

    int found;

    do{
        found  = 0;

        for(int i = 0 ; i < n; i++){
            if(finish[i] == 0){
                int flag = 1;


                for(int j = 0; j < m; j++){
                    if(req[i][j] > avail[j]){
                        flag = 0 ;
                        break;
                    }
                }
                if(flag == 1){
                    for(int k = 0; k < m; k++){
                        avail[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    }while(found);

    int deadlock = 0;

    printf("\n Deadlocked Processes :");
    for(int i = 0 ; i < n ; i++){
        if(finish[i] == 0){
            printf("P%d",i);
            deadlock = 1;
        }
    }

    if(deadlock == 0){
        printf("\n No deadlock \n");
    }else{
        printf("\n System is in Deadlock \n");
    }

}
int main(){
    solve();
    return 0;
}