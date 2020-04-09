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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdlib.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

unsigned char* my_memmove(unsigned char* src, unsigned char* dst, unsigned long length){
	if(src == dst){
			return dst;
	}
	else if(src < dst){
		for(unsigned long i = 0; i < length; i++){
			*(dst + ((length - 1) - i)) = *(src + ((length - 1) - i));
		}
	}
	else{
		for(unsigned long i = 0; i <= length; i++){
			*(dst + i) = *(src + i);
		}
	}

	return dst;
}
unsigned char* my_memcopy(unsigned char* src, unsigned char* dst, unsigned long length){
	for(unsigned long i=0;i<length;i++){
		*(dst+i)=*(src+i);
	}
	return dst;
}
unsigned char* my_memset(unsigned char* src, unsigned long length, unsigned char value){
	for(unsigned long i = 0; i < length; i++){
		*(src + i) = value;
	}

	return src;
}
unsigned char* my_memzero(unsigned char* src, unsigned long length){
	for(unsigned long i = 0; i < length; i++){
		*(src + i) = 0;
	}

	return src;
}
unsigned char* my_reverse(unsigned char * src, unsigned long length){
	unsigned char temp;
	for(unsigned long i = 0; i < ((length - 1) - i); i++){
		temp = *(src + i);
		*(src + i) = *(src + (length - 1) - i);
		*(src + (length - 1) - i) = temp;
	}
	return src;
}
uint32_t* reserve_words(unsigned long length){
	return malloc(sizeof(int)*length);
}
void free_words(uint32_t* src){
	free(src);
}
