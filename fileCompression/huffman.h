/******************************************************************
* Author:	Vincent Pierce
* Date: 	6/13/2024
*
* Huffman encoding and decoding used by hencode and hdecode.
*******************************************************************
* Library includes */

#include "linkedList.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFSIZE 255


/*****************************************************************/
char* readWord(int file);

/****************************************************************/

char* readWord(int file)
{
	ssize_t n_read = 0;
	ssize_t total_read = 0;
	uint32_t buffer_size = BUFSIZE;	
	char* buf = calloc(1, sizeof(char)*buffer_size); /* Have to free later */
	while((n_read = read(file, buf, 1)))
	{
		if(n_read == -1)
		{
			printf("Value of errno: %d\n", errno);
			return buf;
		}
		if(buf[total_read] == ' ' || buf[total_read] == '\n' || buf[total_read] == '\t')
		{
			buf[total_read] = '\0';
			// call function to generate linked list from tree
			// free pointer	
			// so long as we increment by 1 byte no need to return total bytes read because file descriptor keeps our place in the file	
			return buf;
		}
		if(total_read == buffer_size)
		{	
			buffer_size *= 2;
			realloc(buf, buffer_size); 
		} 	
		total_read += n_read;
	}	
	return buf;
}


