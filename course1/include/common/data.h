/**
 * @file data.h
 * @brief Header file for data.c. Performs simple data manipulation
 * 
 * @author Mohab Alaa Gouda
 * @date April 7, 2020
 */

#ifndef __DATA_H__
#define __DATA_H__


//#define MAX_STR_SIZE 2147483647 // 2^31

/**
 * @brief Convert std Int into ASCII string
 *
 * String is NULL terminated.
 *
 * @param data Data to be converted
 * @param ptr Pointer to converted string
 * @param base Base 2-16 supported
 *
 * @return Length of converted data including NULL terminator
 */
unsigned char my_itoa(int data, unsigned char* ptr, unsigned int base);

/**
 * @brief Convert std ASCII into Int string
 *
 * String is NULL terminated.
 *
 * @param data Data to be converted
 * @param ptr Pointer to converted string
 * @param base Base 2-16 supported
 *
 * @return Length of converted data including NULL terminator
 */
int my_atoi(unsigned char* ptr, unsigned char digits, unsigned int base);

#endif
