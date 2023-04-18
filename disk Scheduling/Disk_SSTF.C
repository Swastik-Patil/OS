#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b)
{
    return abs(a - b);
}

int main()
{
    int queue[100], n, head, i, j, min, seek_time = 0, diff[100];
    float avg_seek_time;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("Enter the queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++)
        diff[i] = abs_diff(queue[i], head);

    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (diff[j] < diff[min])
                min = j;
        }
        int temp = queue[i];
        queue[i] = queue[min];
        queue[min] = temp;
        temp = diff[i];
        diff[i] = diff[min];
        diff[min] = temp;
    }

    for (i = 0; i < n - 1; i++)
    {
        seek_time += abs_diff(queue[i], queue[i + 1]);
    }

    avg_seek_time = (float)seek_time / (n - 1);
    printf("Total seek time: %d\n", seek_time);
    printf("Average seek time: %f\n", avg_seek_time);

    return 0;
}
