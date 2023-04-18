#include <stdio.h>
#include <stdlib.h>

int main()
{
    int queue[100], n, head, i, j, k, seek_time = 0, diff;
    float avg_seek_time;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("Enter the queue: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    queue[0] = head;
    n++;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (queue[i] > queue[j])
            {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    k = 0;
    while (queue[k] < head)
        k++;
    for (i = k - 1, j = k; i >= 0; i--, j++)
    {
        diff = abs(queue[i] - head);
        seek_time += diff;
        head = queue[i];
    }
    seek_time += abs(head - queue[j - 1]);
    head = queue[j - 1];
    for (i = j; i < n; i++, j++)
    {
        diff = abs(queue[i] - head);
        seek_time += diff;
        head = queue[i];
    }

    avg_seek_time = (float)seek_time / n;
    printf("Total seek time: %d\n", seek_time);
    printf("Average seek time: %f\n", avg_seek_time);

    return 0;
}
