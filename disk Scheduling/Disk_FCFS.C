
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int queue[100], n, head, i, seek_time = 0, diff;
    float avg_seek_time;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("Enter the queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    queue[n] = head;
    n++;
    for (i = 0; i < n - 1; i++)
    {
        diff = abs(queue[i] - queue[i + 1]);
        seek_time += diff;
    }

    avg_seek_time = (float)seek_time / (n - 1);
    printf("Total seek time: %d\n", seek_time);
    printf("Average seek time: %f\n", avg_seek_time);

    return 0;
}
