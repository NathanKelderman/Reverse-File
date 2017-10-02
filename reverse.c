/******************************************************************
 *
 * Nathan Kelderman
 * CIS 343
 * Professor Woodring
 * Homework 1 - Reverse a given file and write it to another file
 *
 *****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int read_file( char* filename, char** buffer);
int write_file(char* filename, char* buffer, int size);

/****************************************************************
 *
 * This function is given an integer representing an error and 
 * prints out the error corresponding error message.
 *
 ****************************************************************/
void usage(int err) {
    if (err == 0) {
        fprintf(stderr, "ERROR MESSAGE");
	fputs(" Usage: ./reverse <filename> <filename>\n", stderr);
	exit(1);
    }
    if (err == -1) {
	fprintf(stderr, "ERROR MESSAGE");
        fputs(" Usage: Input file does not exist.\n", stderr);
        exit(1);
    }
}

/****************************************************************
 *
 * Takes in 2 files, writes the first to a buffer, reverses the 
 * buffer and then writes it to a file with the name of the second
 * input filename. Calls the error funtion if needed.
 * 
 ****************************************************************/

int main(int argc, char** argv) {
    int fileSize;
    char* buf;
	
    // checks if there are enough imputs
    if ( argc < 3) {
	usage(0);
    }

    fileSize = read_file(argv[1], &buf);
 
    if ( fileSize == -1) {
	usage(-1);
    }
	
    //switch char stored at first and last position, then second
    //and second last position etc until it reaches the middle
    for (int i = 0; i < (fileSize+1)/2; i++) {
	char c = buf[i];
	buf[i] = buf[fileSize-1-i];
	buf[fileSize-1-i] = c;
    }	
    int s = write_file(argv[2], buf, fileSize);

    free(buf);	
    return 0;
}
