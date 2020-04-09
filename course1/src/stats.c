/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Final_Assignment_stats.C
 * @brief A simple application That Perform statistical analytics on data set
 *
 * Analyzing an array of unsigned char data items and report analytics on the 
 * Maximum, Minimum, Mean, and median of the data set Rounded down to the 
 * nearest interger.
 *
 * After analysis and sorting is doen, data will be printed on the screen in 
 * nicely formatted presentation.
 *
 * We modified print_array() function so that we can enable/disable debug 
 * printing with a compile time switch by using -Dverbose flag.
 *
 * @author Mohab Gouda
 * @date   7-4-2020
 *
 */


#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

int states() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  
#ifdef VERBOSE
  //Print the Original array
  printf("The original array :\n");
  print_array(test,SIZE);
#endif

  //Functions implementation

  //Sort Process Descendingly
  sort_array(test, SIZE);
#ifdef VERBOSE
  printf("The array after sorting process descendingly is : \n");
  print_array(test, SIZE);
#endif

  // Printing Statistics  Functions
  print_statistics(test,SIZE);
  return 0;
}


//Function Definition

/**
 * @brief Print unsigned Char
 *
 * Function to print Median, Mean, Max, Mini
 *
 * @param unsigned char Value  
 *  
 * @return None
 */
void print_statistics(unsigned char* array, unsigned char length){

	printf("and it is statistics :\n");
	printf("the median: %d\n", find_median(array,length));
	printf("the mean: %d\n", find_mean(array,length));
	printf("the MAX: %d\n", find_maximum(array,length));
	printf("the MIN: %d\n", find_minimum(array,length));
}

/**
 * @brief Print array of char
 *
 * Function to print an array of char
 *
 * @param Pointer to an array 
 * @param unsigned char length of array 
 *  
 * @return None
 */
#ifdef VERBOSE
void print_array(unsigned char* array, unsigned char length){
	unsigned char i;
	for(i =0;i < length; i++){
		printf("%d ", array[i]);
	}
	printf("\n\n");
}
#endif

/**
 * @brief Find the Median 
 *
 * Function to find the Median 
 *
 * @param Pointer to an array 
 * @param unsigned char length of array 
 *  
 * @return Median value
 */
unsigned char find_median(unsigned char* array, unsigned char length){
  unsigned char median;
	if((length % 2) == 0){
		median = (array[((length - 1)/2)] + array[(length/2)])/2;
	}
	else{
		median = array[((length/2) + 1)];
	}
	return median;
}

/**
 * @brief Find the Mean
 *
 * Function to find the Mean 
 *
 * @param Pointer to an array 
 * @param unsigned char length of array 
 *  
 * @return Mean value
 */
unsigned char find_mean(unsigned char* array, unsigned char length){
  unsigned char i;
  unsigned char mean = 0;
  for(i =0;i < length;i++){
    mean += array[i];
  }
  mean = mean /length;
  return mean;
}

/**
 * @brief Find the Maximum
 *
 * Function to find the Maximum 
 *
 * @param Pointer to an array 
 * @param unsigned char length of array 
 *  
 * @return Maximum value
 */
unsigned char find_maximum(unsigned char* array, unsigned char length){
  unsigned char max = array[0];
  unsigned char i;
  for(i = 0; i < length; i++){
    if(array[i] > max){
      max = array[i];
    }
  }
  return max;
}

/**
 * @brief Find the minimum
 *
 * Function to find the minimum 
 *
 * @param Pointer to an array 
 * @param unsigned char length of array 
 *  
 * @return minimum value
 */
unsigned char find_minimum(unsigned char* array, unsigned char length){
  unsigned char mini;
  unsigned char i;
	for (i=1;i < length;i++){
		if(array[i] < mini)
		{
			mini = array[i];
		}
	}

	return mini;
}

/**
 * @brief Sort an array descendingly
 *
 * Given an array of data and length, Sort the array from largest to smalles
 *
 * @param Pionter to an array 
 * @param unsigned char length of array 
 *  
 * @return None
 */
void sort_array(unsigned char* array, unsigned char length){
  unsigned char i,j;
  unsigned char temp;
  for(i = 0; i < (length - 1); i++){
    for(j = i+1 ; j < (length - i - 1); j++){
      if(array[j] < array[j + 1]){
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

