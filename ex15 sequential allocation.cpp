#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_SIZE 100
typedef struct {
    int startBlock;
    int blockSize;
} FileAllocation;

void allocateFile(FileAllocation *fileTable, int numFiles) {
    int i, j, startBlock, blockSize;
    
    for (i = 0; i < numFiles; i++) {
        scanf("%d %d", &startBlock, &blockSize);
        
        for (j = startBlock; j < startBlock + blockSize; j++) {
            if (fileTable[j].blockSize != 0) {
                printf("Blocks are not available for file %d\n", i+1);
                return;
            }
        }
        
        for (j = startBlock; j < startBlock + blockSize; j++) {
            fileTable[j].blockSize = blockSize;
            fileTable[j].startBlock = startBlock;
        }
    }
    
    printf("File allocation successful!\n");
}

void displayFileAllocation(FileAllocation *fileTable, int numBlocks) {
    int i;
    
    printf("\nBlock\tStart\tSize\n");
    for (i = 0; i < numBlocks; i++) {
        printf("%d\t%d\t%d\n", i, fileTable[i].startBlock, fileTable[i].blockSize);
    }
}

int main() {
    int numBlocks, numFiles, i;
    FileAllocation *fileTable;
    
    scanf("%d", &numBlocks);
    
    fileTable = (FileAllocation*)malloc(numBlocks * sizeof(FileAllocation));
    
    for (i = 0; i < numBlocks; i++) {
        fileTable[i].startBlock = -1;
        fileTable[i].blockSize = 0;
    }
    
    scanf("%d", &numFiles);
    
    allocateFile(fileTable, numFiles);
    displayFileAllocation(fileTable, numBlocks);
    
    free(fileTable);
    
    return 0;
}
