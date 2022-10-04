#include "mergesort.h"
#include <cstdlib>
#include <cstdio>

void mergeRanges(int values[], int startIndex, int midPoint,
  int endIndex) {
    int rangeSize = endIndex - startIndex + 1;
    int *destination =(int*)calloc(rangeSize, sizeof(int));
    int firstIndex = startIndex;
    int secondIndex = midPoint;
    int copyIndex = 0;
    while (firstIndex < midPoint && secondIndex <= endIndex) {
      if (values[firstIndex] < values[secondIndex]) {
        destination[copyIndex] = values[firstIndex];
        ++firstIndex;
      } else {
        destination[copyIndex] = values[secondIndex];
        ++secondIndex;
      }
      ++copyIndex;
    }
    while (firstIndex < midPoint) {
      destination[copyIndex] = values[firstIndex];
      ++copyIndex;
      ++firstIndex;
    }
    while (secondIndex <= endIndex) {
      destination[copyIndex] = values[secondIndex];
      ++copyIndex;
      ++secondIndex;
    }
    for (int i = 0; i < rangeSize; ++i) {
      values[i + startIndex] = destination[i];
    }
    free (destination);
}

void mergesortRange(int values[], int startIndex, int endIndex) {
    int rangeSize = (endIndex - startIndex)+1;
    printf("Size : %d \n", rangeSize); //Print size to check accuracy

    if (rangeSize >= 2) {
      int midPoint = (startIndex + endIndex) / 2;
      mergesortRange(values, startIndex, midPoint); // < --- Actual code

// Start of debug print
          
    printf("Elements of given array(First Half): \n");    
    //Loop through the array by incrementing value of i     
    for (int i = startIndex; i <= midPoint; i++) {     
        printf("%d ", values[i]);	
    }
    printf("\n");
// End of Print debug
//
      mergesortRange(values, midPoint+1, endIndex); // <-- Actual Code
// Start of debug print

    printf("Elements of given array(Second Half): \n");
    //Loop through the array by incrementing value of i
    for (int i = startIndex; i <= midPoint; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
// End of Print debug

      mergeRanges(values, startIndex, midPoint, endIndex); //<--- Actual code

// Start of debug print
    printf("Elements of given array(End Result): \n");
    //Loop through the array by incrementing value of i
    for (int i = startIndex; i <= midPoint; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
// End of Print debug

    }
}

void mergesort(int size, int values[]){


mergesortRange(values, 0, size-1);
}



