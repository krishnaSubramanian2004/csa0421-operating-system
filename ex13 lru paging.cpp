#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int main() {
    int pageFaults = 0;
    int frames[MAX_FRAMES];
    int pages[MAX_PAGES];
    int page, i, j;
    int frameFound;
    int leastRecentIndex;

    printf("Enter the page reference string (separated by spaces): ");
    for (i = 0; i < MAX_PAGES; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("\nPage Reference String\t\tPage Frames\tPage Faults\n");
    printf("----------------------------------------------------------------\n");

    for (i = 0; i < MAX_PAGES; i++) {
        page = pages[i];

        frameFound = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                frameFound = 1;
                break;
            }
        }

        if (frameFound == 0) {
            leastRecentIndex = 0;
            for (j = 1; j < MAX_FRAMES; j++) {
                if (frames[j] < frames[leastRecentIndex]) {
                    leastRecentIndex = j;
                }
            }

            frames[leastRecentIndex] = page;
            pageFaults++;
        }

        printf("%d\t\t\t", page);
        for (j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", frames[j]);
        }

        if (frameFound == 0) {
            printf("\tPage Fault");
        }

        printf("\n");
    }

    printf("----------------------------------------------------------------\n");
    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
