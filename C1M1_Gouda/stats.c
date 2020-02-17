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
 * @date   12-2-2020
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

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

void print_statistics(unsigned char stats){

}

void print_array(int* array, int size){

}

unsigned char find_median(int* array, int size){

}

unsigned char find_mean(int* array, int size){

}

unsigned char find_maximum(int* array, int size){

}

unsigned char find_minimum(int* array, int size){

}

void sort_array(int* array, int size){

}

