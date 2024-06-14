/*********************************************************************************
* Author:   Vincent Pierce
* Date:     06/09/2024
* 
* A singly linked list implementation using Nodes with a pointer to the head  
********************************************************************************/
/* Library includes */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h> 

/******************************************************************************/

struct node
{
	struct node* next;
	uint32_t val;
	char ch;
};

struct linkedList 
{
	struct node* head;
};

struct linkedList* linkedListInit(void);
struct node* nodeInit(uint32_t val);
void insertNode(struct node* newNode, struct linkedList* myList);

struct node* nodeInit(uint32_t val) 
{
	struct node* newNode = calloc(1, sizeof(struct node));
	if(!newNode)
		printf("Failed to allocate new Node structure\n");
	newNode -> val = val;
	newNode -> next = 0;		// Redundant b/c calloc 
	newNode -> ch = 0;
	return newNode;
}

struct linkedList* linkedListInit(void)
{
	struct linkedList* newList = calloc(1, sizeof(struct linkedList));
	if(!newList)
		printf("Failed to allocate new List structure\n");
	return newList;
}
void insertNode(struct node* newNode, struct linkedList* myList)
{
	uint32_t val = newNode->val;
	uint8_t tiebreaker = newNode->ch;
	struct node* curNode = myList->head;
	if(val < curNode->val)				// Insert node at head
	{
		newNode->next = myList->head;
		myList->head = newNode;
	}
	else
	{
		while(val > curNode->val)		// Find where to insert node
		{
			curNode = curNode->next;
			if((curNode->val == newNode->val) && (curNode->ch < newNode->ch)) // When tiebreaker wins
			{
				newNode->next = curNode->next;
				curNode->next = newNode; 
				return;
			}
		}

		newNode->next = curNode->next;
		curNode->next = newNode;
		return;
	}
}

#endif
