/***************************************************************************************
 *
 * Author:	Vincent Pierce
 * Date: 	6/13/2024
 *
 * Hencode is a file compression program that reads strings from standard input or text 
 * files and converts them to binary Huffman-coded values (binary tree). 
 *
 * ***********************************************************************************/

#include "huffman.h"

int main(int argc, char* argv[])
{
	FILE* inFile, *outFile;	
	
	if(argc == 1)
	{
		printf("Incorrect input. \nTry: hencode inFile [outfile}\n");
		return 1;
	}

	if(!(inFile = fopen(argv[1], "r")))
	{
		fprintf(stderr, "Failed to open inFile %s: %s\n", argv[1], strerror(errno));
		exit(errno);	
	}
	errno = 0;
	if(argv[2])
	{
		
		outFile = fopen(argv[2], "w" );
	}
	else 
	{
		outFile = STDOUT_FILENO;	
	}
	
	if(errno)
	{ 
		fprintf(stderr, "Fail to open outFile %s: %s\n", argv[2], strerror(errno));
		exit(errno);
	}	

	printf("%s: test\n", readWord(inFile));	


	struct linkedList* myListPtr = linkedListInit();
	


	fclose(inFile);	
}
