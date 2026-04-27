#include<stdio.h>

void solve(){
    int n,time  = 0, min, shortest;
    printf("Enter Number of process : ");
    scanf("%d",&n);

    int at[n],bt[n],rt[n],ct[n],tat[n],wt[n];
    int completed = 0;

    for(int i = 0; i < n ; i++){
        printf("P%d AT BT : ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }

    while(completed < n){
        min = 9999;
        shortest = -1;

        for(int i = 0; i < n; i++){
            if(at[i] <= time && rt[i] > 0 && rt[i] < min){
                min = rt[i];
                shortest = i;
               // printf("Min = %d, Shortest= %d\n",min,shortest);
            }
        }

        if(shortest == -1){
            time++;
            continue;
        }
        rt[shortest]--;
        time++;

        if(rt[shortest] == 0){
            completed++;
            ct[shortest] = time;
        }
    }
    for(int i = 0 ; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n ",
            i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}
int main(){
    solve();
    return 0;
}