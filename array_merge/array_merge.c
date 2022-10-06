#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdio>
#include <cstdlib>

// This assumes that the array of values is already sorted
int count_unique(int* values, int size){
// uniq is the counter for unique numbers and curruniq is the current uniq value
// we start uniq at one since the base case is that the first one always is unique
// curruniq follows the same idea
int uniq = 1, curruniq = values[0];


  for(int i = 0; i < size; i++){
	  if(curruniq != values[i]){
	    curruniq = values[i];
	    uniq++;  
	  }


}
 return uniq;
}



int* array_merge(int num_arrays, int* sizes, int** values) {
  int total_size = 0;
  int *endgoal;
  // If there are no arrays then we don't run the function
  if(num_arrays == 0){
  	endgoal = (int*)calloc(1,sizeof(int));
	endgoal[0]=0;  
	return endgoal;//values[0];
  }
	
  // Find the total size to initiate the final array
  for(int i = 0; i < num_arrays; i++){
  	total_size = total_size + sizes[i];
  }
  // The actual allocation line for the final result
  int *destination =(int*)calloc(total_size, sizeof(int));

// This iterates through all of the elements of the multi-array and puts it all into
// the destination array
  int destIndex = 0;
  for(int j = 0; j < num_arrays; j++){
  	for(int i = 0; i < sizes[j]; i++){
		destination[destIndex] = values[j][i];
		destIndex++;
	}	
  }
  // Sort the destination array, since our counter only works when it is already sorted
  mergesort(total_size , destination);
  // Number of unique numbers
  int count = count_unique(destination, total_size);
  // The final goal
  endgoal = (int*)calloc(count+1,sizeof(int));
  // First element in the array is the total unique characters
  endgoal[0] = count;
  // This assumes the first element in destination is already unique
  endgoal[1] = destination[0];
  int curruniq = destination[0];
  int index = 2;


  // Here we iterate through and only add unique characters
  // This only works when the destination array is already sorted
  for(int i = 0; i < total_size; i++){
          if(curruniq != destination[i]){
            curruniq = destination[i];
	    endgoal[index] = destination[i];
            index++;
          } 
  }
  free(destination);
  return endgoal;
}
