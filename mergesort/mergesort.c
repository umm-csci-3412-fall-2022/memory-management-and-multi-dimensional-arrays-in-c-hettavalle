#include "mergesort.h"
#include <cstdlib>
#include <cstdio>

void mergeRanges(int values[], int startIndex, int midPoint,
  int endIndex) {
    // Initialize values
    int rangeSize = endIndex - startIndex + 1;
    int *destination =(int*)calloc(rangeSize, sizeof(int));
    int firstIndex = startIndex;
    int secondIndex = midPoint+1;
    int copyIndex = 0;

    // Iterate through the two given sections and sort them into the destination array
    // This assumes both sections are sorted already
    while (firstIndex <= midPoint && secondIndex <= endIndex) {
      if (values[firstIndex] < values[secondIndex]) {
        destination[copyIndex] = values[firstIndex];
        ++firstIndex;
      } else {
        destination[copyIndex] = values[secondIndex];
        ++secondIndex;
      }
      ++copyIndex;
    }

    // This only happens if the second section runs out of numbers
    // Because we then know that the rest of the first section is sorted and goes at the end
    while (firstIndex <= midPoint) {
      destination[copyIndex] = values[firstIndex];
      ++copyIndex;
      ++firstIndex;
    }

    // Same as the while loop above, but if the first section finished before the second
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
    // This is so we know the size of the section we are working on 
    int rangeSize = (endIndex - startIndex)+1;

    // This is to stop the recursion when the size of the section becomes one or less (base case) 
    if (rangeSize >= 2) {
      // Calculate the midpoint (to separate the section into two halves)
      int midPoint = (startIndex + endIndex) / 2;
      // Sort the first half (assuming everything works)
      mergesortRange(values, startIndex, midPoint);
      // Sort the second half (assuming everything works)
      mergesortRange(values, midPoint+1, endIndex); 
      // Combine the two sorted ranges
      mergeRanges(values, startIndex, midPoint, endIndex);
    }
}

void mergesort(int size, int values[]){

// This is where it starts, setting up our startIndex and endIndex
// which turns out to be the first value and last value to start
mergesortRange(values, 0, size-1);
}



