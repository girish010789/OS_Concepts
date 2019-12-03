//FCFS Scheduling algorithm

#include <stdio.h>

int main () {
        int bt[10], tat[10], at[10], wt[10], ct[10];
        int n, sum = 0;
        int totalTAT=0, totalWT=0;
        float AverageTAT, AverageWT;
        printf("Enter the number of process");
        scanf("%d", &n);

        for (int i=1;i<=n;i++) {
                printf("Enter the arrival time for process [%d]",i);
                scanf("%d", &at[i]);
                printf("Enter the burst time for process [%d]",i);
                scanf("%d", &bt[i]);
        }

        //completion time calculation
        for (int j=1; j<=n;j++) {
                sum = sum + bt[j];
                ct[j] = sum - at[j];
        }

        //turn-around time calculation
        for (int k=1;k<=n;k++) {
                tat[k] = ct[k] - at[k];
                totalTAT += tat[k];
        }

        //wait time calculation
        for (int w=1;w<=n;w++) {
                wt[w] = tat[w] - bt[w];
                totalWT += wt[w];
        }

        AverageWT = totalWT/n;
        AverageTAT = totalTAT/n;

        for (int p=1;p<=n;p++) {
                printf("P%d \t %d \t %d \t %d\t %d\t %d\n", p, at[p], bt[p], ct[p], tat[p], wt[p]);
        }

        printf("Average Turnaround time is %f\n", AverageTAT);
        printf("Average Weight time is %f\n", AverageWT);
}
~
