/*
 *
 * This program contains 2 functions. The sole purpose of this program is to 
 * read in a given file to a given buffer or to write a given buffer to a 
 * given file.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
 *
 * This function takes in a filename and a buffer and reads the file into the
 * buffer.
 *  
 * @param filename - this is a pointer to where the file is located
 * @param buffer   - this is a double pointer to the buffer so this function
 *                   edit the buffer without losing the changes
 *
 * @return int     - returns a -1 if it failed or else the size of the file
 * 		     if the read was successful
 *
 */
int read_file( char* filename, char** buffer ){

    FILE* fp;
    long lsize;
    int size;
	
    //create file pointer pointing to the beginning of file and checks if it is populated
    fp = fopen(filename, "rb");
    if ( fp == NULL ) { return -1; }
	
    //seek the end of file to find its size as a long
    fseek( fp, 0L, SEEK_END);
    lsize = ftell( fp );
    rewind( fp );
	
    //allocate memory
    *buffer = malloc(lsize * sizeof(char));
	
	
    if( 1!=fread( *buffer, lsize, 1, fp) )
	return -1;

    //find size of file as an integer
    struct stat st;
    stat( filename, &st);
    size = st.st_size;
	
    return size;
}

/*
 *
 * This function takes in a filename, buffer and the size of the file, and writes the
 * buffer to a file with the name of the given filename.
 *
 * @param filename - the desired name for the new file
 * @param buffer   - the buffer that the information thats to be written is stored in
 * @param size     - the size of the file which is to write the file
 * 
 * @return int     - returns the number of successful characters written to the file
 *
 */
int write_file( char* filename, char *buffer, int size){
    FILE *fp;
    fp = fopen( filename, "w");
    int s =(int) fwrite( buffer, 1, size , fp);
    fclose(fp);
    return s;
}

