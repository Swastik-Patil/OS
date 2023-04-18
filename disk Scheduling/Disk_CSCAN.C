#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b)
{
    return abs(a - b);
}

int main()
{
    int queue[100], n, head, i, j, temp, seek_time = 0, diff[100];
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
        for (j = i + 1; j < n; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    int start = 0;
    for (i = 0; i < n; i++)
    {
        if (queue[i] == head)
        {
            start = i;
            break;
        }
    }

    printf("Sequence of movement: ");
    for (i = start; i < n; i++)
    {
        printf("%d ", queue[i]);
    }
    if (start == 0)
        printf("%d ", queue[0]);
    for (i = 0; i < start - 1; i++)
    {
        printf("%d ", queue[i]);
    }

    for (i = start; i < n - 1; i++)
    {
        seek_time += abs_diff(queue[i], queue[i + 1]);
    }
    seek_time += abs_diff(queue[n - 1], queue[start - 1]);

    avg_seek_time = (float)seek_time / n;
    printf("\nTotal seek time: %d\n", seek_time);
    printf("Average seek time: %f\n", avg_seek_time);

    return 0;
}