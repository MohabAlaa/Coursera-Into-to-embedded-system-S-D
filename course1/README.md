


 @author Mohab Gouda
 @date   1-4-2020
 

 @file Final_Programming_Assignment


In this programming assignment, you will get more experience with Git Version control, write more C-programming code, and integrate your code with your build system. You will reuse your version control repository and add some new c-programming functions that manipulate memory. You will test your code on your host machine, but your code should compile for both the target platform and host platform.



 @Deal With The Program:

1- Build System Target on Host Machine: 

                                       $ make build PLATFORM=HOST COURSE=COURSE1 VERBOSE=VERBOSE
2- Run The Test Code: 


                                       $ ./course1.out
3- Build System Target For ARM: 


                                       $ make build PLATFORM=MSP432 COURSE=COURSE1 VERBOSE=VERBOSE
4- Delete All Created Files: 


                                       $ make clean


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
