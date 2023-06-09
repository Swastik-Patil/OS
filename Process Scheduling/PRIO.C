#include <stdio.h>

struct process
{
    int pid, burst_time, wating_time, turnaround_time, prio;
} p[15], temp;

int main()
{
    int total_time;
    float avg_turnaround_time, avg_wating_time, tt_time, tw_time;

    int n, i, j;
    printf("Enter the numbers of processes : ");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        p[i].pid = i;

        printf("Enter the burst Time for process %d : \t", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter the priority for process %d : \t", i + 1);
        scanf("%d", &p[i].prio);
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].prio < p[j].prio)
            {
                temp.pid = p[i].pid;
                temp.burst_time = p[i].burst_time;

                p[i].pid = p[j].pid;
                p[j].pid = temp.pid;

                p[i].burst_time = p[j].burst_time;
                p[j].burst_time = temp.burst_time;
            }
        }
    }

    total_time = 0;
    tt_time = tw_time = 0;

    // setting waiting time and turnaround time
    p[0].wating_time = 0;
    p[0].turnaround_time = p[0].burst_time + p[0].wating_time;
    total_time = p[0].burst_time;
    for (j = 1; j < n; j++)
    {
        total_time = total_time + p[j].burst_time;

        p[j].turnaround_time = total_time;
        p[j].wating_time = p[j - 1].turnaround_time;

        tt_time += p[j].turnaround_time;
        tw_time += p[j].wating_time;
    }

    // display
    printf("\nprocess\t\tburst_time\twating_time\tturnaround_time");
    for (j = 0; j < n; j++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d", (p[j].pid + 1), p[j].burst_time, p[j].wating_time, p[j].turnaround_time);
    }

    printf("\nAverage Turn around time = %f", tt_time / (float)n);
    printf("\nAverage waiting time = %f", tw_time / (float)n);
    return 0;
}