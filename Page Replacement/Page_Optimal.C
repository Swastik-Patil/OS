#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int main()
{
    int num_frames, num_pages, page_faults = 0;
    int pages[MAX_PAGES], frames[MAX_FRAMES], next_use[MAX_FRAMES];
    int i, j, k, max, replace_index;

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the reference string: ");
    for (i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i]);
    }

    // Initialize frames with -1 to indicate empty frames
    for (i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
    }

    // Loop through each page in the reference string
    for (i = 0; i < num_pages; i++)
    {
        int page = pages[i];
        int page_found = 0;

        // Check if the page is already in one of the frames
        for (j = 0; j < num_frames; j++)
        {
            if (frames[j] == page)
            {
                page_found = 1;
                break;
            }
        }

        // If the page is not in any frame, we need to find a frame to replace
        if (!page_found)
        {
            // Initialize next_use with -1 to indicate pages that are not used again
            for (j = 0; j < num_frames; j++)
            {
                next_use[j] = -1;
            }

            // Loop through each frame to find the page that is used furthest in the future
            for (j = 0; j < num_frames; j++)
            {
                int frame = frames[j];
                for (k = i + 1; k < num_pages; k++)
                {
                    if (pages[k] == frame)
                    {
                        next_use[j] = k;
                        break;
                    }
                }
            }

            // Find the frame with the largest next use time
            max = next_use[0];
            replace_index = 0;
            for (j = 1; j < num_frames; j++)
            {
                if (next_use[j] == -1)
                {
                    replace_index = j;
                    break;
                }
                else if (next_use[j] > max)
                {
                    max = next_use[j];
                    replace_index = j;
                }
            }

            // Replace the page in the frame with the largest next use time
            frames[replace_index] = page;
            page_faults++;
        }
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
}
