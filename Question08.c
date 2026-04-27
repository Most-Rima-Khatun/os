#include<stdio.h>

void solve(){
    int n, i, j;

    int bt[20], wt[20], tat[20], pr[20], p[20]; // burst time, wait time, turnaround time,priority, process number

    printf("Enter number of process :");
    scanf("%d", &n);

    for(i = 0; i < n ; i++){
        printf("\nProcess %d\n", i + 1);
        printf("Enter Burst Time :");
        scanf("%d", &bt[i]);
        printf("Enter Priority :");
        scanf("%d", &pr[i]);
        p[i] = i + 1; 
    }
    int temp = 0;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n ; j++){
            if(pr[i] > pr[j]){
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    //wating time

    wt[0] = 0;
    for(i = 1; i < n ; i++){
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    //turnaround time
   // tat[0] = 0;
    for(i = 0; i < n ; i++){
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBurst time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",
            p[i],bt[i],pr[i],wt[i],tat[i]);
    }

    float avg_wt = 0, avg_tat = 0;

    for(i = 0; i < n; i++){
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("Average waiting time : %.2f\n", avg_wt/n);
    printf("Average turnaround time : %.2f\n", avg_tat/n);
}

int main(){

    solve();
    return 0;
}