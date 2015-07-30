#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* creatBinaryArr(int);
void displayBinaryArr(int*);

int main(void)
{

    int i=32, n=-34; // Some variables for binary display
    int *bitArrPtr;  // Array pointer

    displayBinaryArr(bitArrPtr = creatBinaryArr(i));
    free(bitArrPtr);
    printf("\n");
    displayBinaryArr(bitArrPtr = creatBinaryArr(n));
    free(bitArrPtr);
    printf("\n");

    return 0;
}

int* creatBinaryArr(int numForDisplay)
{
        if(numForDisplay<=INT_MAX && numForDisplay>=INT_MIN) {
           int *bitArr = (int*)malloc(32 * sizeof(int));
           int *pArrRev = bitArr, *pArr = bitArr, num;
           pArrRev += 31;
           if(numForDisplay>=0) { num = numForDisplay; }
           else { num = -numForDisplay; }
           for(int i=0; i<32; i++) {
             *(pArr+i) = 0;
           }
           for(int i=0; num>0; i++) {
               *(pArrRev-i) = num % 2;
               num /= 2;
           }
           if(numForDisplay<0) { *pArr = 1; }
           else { *pArr = 0; }

           return bitArr;
        } else {
            printf("The number must be in range between %d and %d\n", INT_MIN, INT_MAX);
            return (int*)0;
        }

}

void displayBinaryArr(int *pArr)
{
    for(int i=0, oct=1; i<32; i++, oct++) {
        printf("%d", *(pArr+i));
        if(!(oct%8)) { printf(" "); }
    }
}

