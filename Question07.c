#include<stdio.h>

void solve(){
    int n, tq, time = 0, remain ;

    printf("Enter Number of Process : ");
    scanf("%d",&n);
    scanf("Enter Time Quantum : %d",&tq);
    remain = n;

    int at[n],bt[n],ct[n],rt[n],tat[n],wt[n];

    for(int i = 0 ; i < n; i++){
        printf("Process AT BT :");
        scanf("%d %d", &at[i],&bt[i]);
        rt[i] = bt[i];
    }
    printf("\n Gantt chat : \n|");

    while(remain != 0){
        int executed = 0;

        for(int i = 0; i < n ; i++){
            if(at[i] <= time && rt[i] > 0){
                executed = 1;
                printf("p%d |",i+1);
                printf("%d ",rt[i]);
            
            if(rt[i] > tq){
                time += tq;
                rt[i] -= tq;
            }else{
                time += rt[i];
                ct[i] = time;
                wt[i] = ct[i]- at[i] - bt[i];
                rt[i] = 0;
                remain--;
            }
        }
    }
        if(executed == 0){
            time++;
        }
    }
    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
    }
    printf("\n\n Process \tAT\tBT\tCT\tWT\tTAT\n");
    for(int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    
}

int main(){
    solve();
    return 0;
}