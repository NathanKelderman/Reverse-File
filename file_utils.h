/*
 *
 * This header contains 2 functions. The sole purpose of this program is to
 * read in a given file to the given buffer or to write a given buffer to a
 * given file.
 *
 */


#ifndef file_utils
#define file_utils

/*
 *
 * This function takes in a filename and a buffer and reads the file into the
 * buffer. The caller must free the buffer.
 *
 * @param filename - this is a pointer to where the file is located
 * @param buffer   - this is a double pointer to the buffer so this function
 *                   edit the buffer without losing the changes
 *
 * @return int     - returns a -1 if it failed or else the size of the file
 *                   if the read was successful
 *
 */
int read_file( char* filename, char **buffer );

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
int write_file( char* filename, char *buffer, int size);

#endif
