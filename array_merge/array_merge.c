#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdio>
#include <cstdlib>

// This assumes that the array of values is already sorted
int count_unique(int* values, int size){

int uniq = 1, tempIndex = values[0];
 //Hopefully this for loop counts the unique values


  for(int i = 0; i < size; i++){
	  if(tempIndex != values[i]){
	    tempIndex = values[i];
	    uniq++;  
	  }


}
 return uniq;
}



int* array_merge(int num_arrays, int* sizes, int** values) {
  int total_size = 0;
if(num_arrays == 0) return values[0] ;
	
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





  mergesort(total_size , destination);

  int count = count_unique(destination, total_size);
  printf("\nNumber of uniq: %d", count);



// This is the print statement to see what the values of destination are
  printf("-------------------List of values in destination------------------------ \n");
      // Navigate through the destination array and print:
      for(int i = 0; i < total_size; i++) { 
	      printf("Position %d in destination: %d\n", i, destination[i]);
      }


int *endgoal = (int*)calloc(count+1,sizeof(int));
endgoal[0] = count;

endgoal[1] = destination[0];

int curruniq = destination[0];
int index = 2;

 //Hopefully this for loop counts the unique values


  for(int i = 0; i < total_size; i++){
          if(curruniq != destination[i]){
            curruniq = destination[i];
	    endgoal[index] = destination[i];
            index++;
          } 
  }

// This is the print statement to see what the values of destination are
  printf("-------------------List of values in endgoal------------------------ \n");
      // Navigate through the destination array and print:
      for(int i = 0; i < count; i++) {
              printf("Position %d in end goal: %d\n", i, endgoal[i]);
      }



  return endgoal;
}
