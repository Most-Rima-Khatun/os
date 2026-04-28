#include<stdio.h>

void solve(){
    FILE *fp;
    int n,m; //n = process, m = resources
    fp = fopen("input.txt","r");
    //printf("Enter number of process \t resoureces:");
     fscanf(fp,"%d %d",&n, &m);

    int alloc[n][m],max[n][m],avail[m],need[n][m];
    int finish[n],safeseq[n];

    //printf("Enter allocation matrix :");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(fp,"%d",&alloc[i][j]);
        }
    }

    //printf("Enter Max matrix :");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(fp,"%d",&max[i][j]);
        }
    }

    //printf("Enter available Resources :");
    for(int j = 0; j < m; j++){
        fscanf(fp,"%d",&avail[j]);
    }
   // printf("Enter Need matrix :");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    //initial process finish = 0;

    for(int i = 0; i < n; i++){
        finish[i] = 0;
    }

    int pcount = 0;

    while(pcount < n){
        int found = 0;

        for(int i = 0; i < n ; i++){
            if(finish[i] == 0){
                int flag = 1;

                for(int j = 0 ; j < m ;j++){
                    if(need[i][j] > avail[j]){
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1){

                    for(int k= 0; k < m ; k++){
                        avail[k] +=alloc[i][k];
                    }
                    safeseq[pcount++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0){
            printf("\n System is not safe state(deadlock possible)");
            return ;
        }
    }
    printf("\n System is safe state \n safe sequences : ");
    for(int i = 0 ; i < n; i++){
        printf("P%d ",safeseq[i]);
    }

}

int main(){

    solve();
    return 0;
}