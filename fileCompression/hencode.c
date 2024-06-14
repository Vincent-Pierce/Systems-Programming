/***************************************************************************************
 *
 * Author:	Vincent Pierce
 * Date: 	6/13/2024
 *
 * Hencode is a file compression program that reads strings from standard input or text 
 * files and converts them to binary Huffman-coded values (binary tree). 
 *
 * ***********************************************************************************/





#include "hencode.h"

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
		fprintf(stderr, "Failed to open inFile\n");
		fclose(inFile);	
		return 1;
	}
	if(argc == 2)
	{
		if(!(outFile = fopen(stdout, "w")))
		{
			fprintf(stderr, "Failed to open stdin\n");
			fclose(outFile);
			return 1;	
		}	
	}
	else if(argc == 3)
	{
		if(!(outFile = fopen(argv[2], "w")))
		{
			fprintf(stderr, "Failed to open outFile\n");
			fclose(outFile);
			return 1;
		}
	}

	struct linkedList* myListPtr = linkedListInit();
	
}
