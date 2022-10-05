#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdio>
#include <cstdlib>

int* array_merge(int num_arrays, int* sizes, int** values) {
  int total_size = 0;
	
  // Find the total size to initiate the final array
  for(int i = 0; i < num_arrays; i++){
  	total_size = total_size + sizes[i];
  }
  // The actual allocation line for the final result
  int *destination =(int*)calloc(total_size, sizeof(int));


// Print statement to see all of the elements of the input values
  printf("---------------------Elements of the multi-dim array----------------- \n");    
      //Loop through the array by incrementing value of i
      for(int j = 0; j < num_arrays; j++){     
          for (int i = 0; i < sizes[j]; i++) {     
                  printf("This is row %d column %d, value : %d\n", j, i, values[j][i]);	
                      }
      }

// Print statement to see all of the values of the input sizes
  printf("-------------------List of Sizes for each array------------------------ \n"); 
      // Navigate through the sizes array:
      for(int i = 0; i < num_arrays; i++) {
      printf("Position %d in sizes: %d\n", i, sizes[i]);
      }

// This iterates through all of the elements of the multi-array and puts it all into
// the destination array
  int destIndex = 0;
  for(int j = 0; j < num_arrays; j++){
  	for(int i = 0; i < sizes[j]; i++){
		destination[destIndex] = values[j][i];
		destIndex++;
	}
  }

// This is the print statement to see what the values of destination are
  printf("-------------------List of values in destination------------------------ \n");
      // Navigate through the destination array and print:
      for(int i = 0; i < total_size; i++) { 
	      printf("Position %d in destination: %d\n", i, destination[i]);
      }




  return sizes;
}
