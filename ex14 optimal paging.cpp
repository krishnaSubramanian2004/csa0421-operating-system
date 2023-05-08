#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int main() {
    int pageFaults = 0;
    int frames[MAX_FRAMES];
    int pages[MAX_PAGES];
    int page, i, j;
    int frameFound;
    int maxDistance;
    int replaceIndex;

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
            replaceIndex = -1;
            for (j = 0; j < MAX_FRAMES; j++) {
                int k;
                for (k = i + 1; k < MAX_PAGES; k++) {
                    if (pages[k] == frames[j]) {
                        if (k > replaceIndex) {
                            replaceIndex = k;
                            maxDistance = k - i;
                        }
                        break;
                    }
                }
                if (k == MAX_PAGES) {
                    replaceIndex = k;
                    maxDistance = MAX_PAGES - i;
                }
            }

            if (replaceIndex == MAX_FRAMES) {
                replaceIndex = 0;
            }

            frames[replaceIndex] = page;
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
