#include <stdio.h>

struct process
{
    int pid, burst_time, waiting_time, turnaround_time;
} p[15];

int main()
{
    int total_time;
    float avg_turnaround_time, avg_waiting_time, tt_time, tw_time;

    int n, i, j;
    printf("Enter the numbers of processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter the burst Time for process %d : ", i + 1);
        scanf("%d", &p[i].burst_time);
    }

    total_time = 0;
    tt_time = tw_time = 0;
    // setting waiting time and turnaround time
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time + p[0].waiting_time;
    total_time = p[0].burst_time;
    for (j = 1; j < n; j++)
    {
        total_time = total_time + p[j].burst_time;

        p[j].turnaround_time = total_time;
        p[j].waiting_time = p[j - 1].turnaround_time;

        tt_time += p[j].turnaround_time;
        tw_time += p[j].waiting_time;
    }

    // display
    printf("\nprocess\tburst_time\twaiting_time\tturnaround_time");
    for (j = 0; j < n; j++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d", p[j].pid, p[j].burst_time, p[j].waiting_time, p[j].turnaround_time);
    }

    printf("\nAverage Turn around time = %f", tt_time / (float)n);
    printf("\nAverage waiting time = %f", tw_time / (float)n);
    return 0;
}