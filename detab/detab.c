/*********************************************************** 
 * 	Descriptions:
 *
 *	This program expands tab characters to the nearest
 *	tab stop which occurs every 8 spaces. 
 *
 *
 *      Author: Vincent Pierce
 *      Date  : May 1, 2024
 **********************************************************/



/* FILE INCLUSION *****************************************/
#include <stdint.h>
#include <stdio.h>

int main()
{
	int c, cnt = 0;
	while((c = getchar()) != EOF) 
	{
		if(c == '\t')
		{
			while(cnt < 8)
			{
				putchar(' ');
				++cnt;
			}
			cnt = 0;
			continue;
		}
		if(c == '\b') 
		{
			if(cnt > 0)
				--cnt;
			continue;
		}
		if(c == '\n' || c == '\r') 
		{
			cnt = 0;
			putchar(c);
			continue;
		}
		
		putchar(c);
	        cnt++;	
	}	
}
