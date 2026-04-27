#include<stdio.h>

void solve(){
int n, i;

printf("Enter number of process: ");
scanf("%d",&n);

int bt[n],wt[n],tat[n];



for(i = 0 ; i < n; i++){
    printf("Enter Burst time for P%d :", i+1);
    scanf("%d",&bt[i]);
}

wt[0] = 0;

for(i = 1; i < n; i++){
    wt[i] = wt[i - 1] + bt[i - 1];
}

for(i = 0; i < n ; i++){
    tat[i] = wt[i] + bt[i];
}

printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
for(i = 0; i < n; i++){
    printf("P%d\t%d\t%d\t\t%d\n", i + 1,bt[i],wt[i],tat[i]);
}

float avg_wt = 0, avg_tat = 0;

for(i = 0; i < n; i++){
    avg_wt += wt[i];
    avg_tat += tat[i];
}

printf("Average waiting time : %.2f", avg_wt/n);
printf("\nAverage Turnaround time : %0.2f",avg_tat/n);

}

int main(){    
    solve();
    return 0;
}