#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, highest;
    int at[20], bt[20], rt[20], pr[20];
    int ct[20], wt[20], tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d AT BT Priority: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(completed < n) {
        highest = -1;

        
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(highest == -1 || pr[i] < pr[highest]) {
                    highest = i;
                }
            }
        }

        if(highest == -1) {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0) {
            completed++;
            ct[highest] = time;
        }
    }

    
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}