#include<stdio.h>

void solve(){

    int n;
    printf("Enter number of process : ");
    scanf("%d",&n);
    int bt[n], wt[n], tat[n], p[n];

    for(int i = 0 ; i < n; i++){
        printf("Enter Burst Time for P%d : ",i + 1);
        scanf("%d",&bt[i]);
        p[i] = i + 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(bt[i] > bt[j]){
                int temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(int i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i - 1];
    }
    for(int i = 0; i < n; i++){
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Gantt Chart:\n|");
    for(int i = 0; i < n; i++){
        printf("P%d\t |",p[i]);
    }

    printf("\n0");
    int time = 0;

    for(int i = 0; i < n; i++){
        time += bt[i];
        printf(" \t%d ", time);
    }
}

int main(){
    solve();
    return 0;
}