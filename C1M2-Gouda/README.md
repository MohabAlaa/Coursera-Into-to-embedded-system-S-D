


 @author Mohab Gouda
 @date   1-3-2020
 

 @file Week2_Programming_Assignment


In this programming assignment you will create a build system using the GNU tools, GCC and GNU Make. This assignment will require you to compile multiple files, link them together and create a final output executable. Some files will be provided for you, but you will need   to support two platforms; the host environment and the target embedded system MSP432. The host system will allow you to simulate software on a host platform. The target system will be used in upcoming assignments as we begin to create our microcontroller applications.


 @Deal With The Program:

1- Build System Target on Host Machine: $ make build PLATFORM=HOST

2- Run the Host Machine Code: $ ./c1m2.out

3- Build System Target For ARM: $ make build PLATFORM=MSP321

4- Build Some System Files: $ make memory.o PLATFORM=HOST

			    $ make memory.i PLATFORM=MSP432
			    
			    $ make main.asm PLATFORM=MSP432
			    
5- Delete All Created Files: $ make clean


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
