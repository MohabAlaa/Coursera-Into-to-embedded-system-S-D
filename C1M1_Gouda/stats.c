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
 * @file Week1_Programming_Assignment_stats.C
 * @brief A simple application That Perform statistical analytics on data set
 *
 * Analyzing an array of unsigned char data items and report analytics on the 
 * Maximum, Minimum, Mean, and median of the data set Rounded down to the 
 * nearest interger.
 * After analysis and sorting is doen, data will be printed on the screen in 
 * nicely formatted presentation.
 *
 * @author Mohab Gouda
 * @date   17-2-2020
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  //Round the unsigned array to int array 
  int test_int[SIZE],i;
  for(i =0;i < SIZE;i++){
    test_int[i] = (int)test[i];
  }
  
  //Print the Original array
  printf("The original array :\n");
  print_array(test_int,SIZE);

  //Functions implementation

  //Sort Process Descendingly
  sort_array(test_int, SIZE);
  printf("The array after sorting process descendingly is : \n");
  print_array(test_int, SIZE);

  //Maximum Value
  int T = find_maximum(test_int, SIZE);
  printf("The Maximum Value in the array is : ");
  print_statistics(T);

  //The minimum Value
  T = find_minimum(test_int, SIZE);
  printf("The Minimum Value in the array is : ");
  print_statistics(T);

  //THe Median Value if the array
  T = find_median(test_int, SIZE);
  printf("The Median Value of the array is : ");
  print_statistics(T);

  //The Mean Value of the array
  T = find_mean(test_int, SIZE);
  printf("The Mean Value of the array is : ");
  print_statistics(T);

}


//Function Definition

/**
 * @brief Print unsigned Char
 *
 * Function to print Median, Mean, Max, Mini
 *
 * @param int Value  
 *  
 * @return None
 */
void print_statistics(int stats){
  printf("%d\n",stats);
  for(int i = 1; i <= 60; i++){
    printf("*");
    if(i == 60 ){
      printf("\n");
    }
  }
}

/**
 * @brief Print array of char
 *
 * Function to print an array of char
 *
 * @param Pointer to an array 
 * @param int size of array 
 *  
 * @return None
 */
void print_array(int* array, int size){
  int i;
  for(i =0;i < size;i++){
    if(i == 0){
      printf("%d\t", *(array + i));
      continue;
    }
    else if((i+1)%5 == 0){
      printf("%d\n", *(array + i));
      continue;
    }
    else{
      printf("%d\t", *(array + i));
    }
  }
  for(i = 1; i <= 60; i++){
    printf("*");
    if(i == 60 ){
      printf("\n");
    }
  }
}

/**
 * @brief Find the Median 
 *
 * Function to find the Median 
 *
 * @param Pointer to an array 
 * @param int size of array 
 *  
 * @return Median value
 */
int find_median(int* array, int size){
  int median;

  /*Because of the size of the array is even 
   *The median = (array[size/2]+array[(size/2)+1])/2
   *Note: The median calculation take a place after sorting processe
   */
  median = (*(array+ ((size - 1)/2)) + *(array + (size/2)))/2;
  return median;
}

/**
 * @brief Find the Mean
 *
 * Function to find the Mean 
 *
 * @param Pointer to an array 
 * @param int size of array 
 *  
 * @return Mean value
 */
int find_mean(int* array, int size){
  int i;
  int mean = 0;
  for(i =0;i < size;i++){
    mean += *(array + i);
  }
  mean = mean /size;
  return mean;
}

/**
 * @brief Find the Maximum
 *
 * Function to find the Maximum 
 *
 * @param Pointer to an array 
 * @param int size of array 
 *  
 * @return Maximum value
 */
int find_maximum(int* array, int size){
  int max;
  int i;
  for(i =0;i < size;i++){
    if(i == 0){
      max = *(array + i);
    }
    if(*(array + i) > max){
      max = *(array + i);
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
 * @param int size of array 
 *  
 * @return minimum value
 */
int find_minimum(int* array, int size){
  int mini;
  int i;
  for(i = 0;i < size;i++){
    if(i == 0){
      mini = *(array + i);
    }
    if(*(array + i) < mini){
      mini = *(array + i);
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
 * @param int size of array 
 *  
 * @return None
 */
void sort_array(int* array, int size){
  int i,j;
  for(i = 0; i < size; i++){
    int temp;
    for(j = i+1 ; j < size; j++){
      if(*(array + i) < *(array + j)){
        temp = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = temp;
      }
    }
  }
}

