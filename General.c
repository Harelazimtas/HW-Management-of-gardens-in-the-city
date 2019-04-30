#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "General.h"

const char* optionStr[NofOptions] = { "Exit", "Read City information from file",
		"Show all Kindergartens", "Show a specific Kindergarten",
		"Save City information to file", "Add a Kindergarten", "Add a Child",
		"Birthday to a Child", "Count Hova childres",
		"sort with name of garden", "sort child in garden by id of child",
		"sort by type of garden and number of child",
		"find child by id by sort and binary search",
		"create linked list with city and chose type of garden" };

/**************************************************/
int menu()
/**************************************************/
/**************************************************/
{
	int option, i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for (i = 0; i < NofOptions; i++)
		printf("\n\t%d. %s.", i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr) {
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*) malloc(len * sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p) {
	if (!p) {
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

void insertionSort(void *arr, int size, int typeSize,
		int (*compare)(const void *, const void*)) {
	int i, j, index = 0;
	for (i = 1; i < size; i++) {
		index = i;
		j = i - 1;
		for (;
				j >= 0
						&& (compare((char *) arr + j * typeSize,
								(char *) arr + index * typeSize)) > 0; j--) {
			swap((char *) arr + j * typeSize, (char *) arr + index * typeSize,
					typeSize);
			index--;
		}
	}
}

void swap(void * a, void * b, int typeSize) {
	int i;
	char temp;
	char* first = (char*) a;
	char* second = (char*) b;
	for (i = 0; i < typeSize; i++) {
		temp = *(first + i);
		*(first + i) = *(second + i);
		*(second + i) = temp;
	}
}

void vardicFunction(char *str, int num, ...) {
	va_list list;
	int size;
	size = num;
	va_start(list, num);
	while (str != NULL) {
		printf("%s", str);
		printf("----%d", size);
		str = va_arg(list, char*);
		size = va_arg(list, int);
		printf("\n");
	}
	va_end(list);
}

List* createLinkedListForKindergartenType(const City *c, GardenType type) {
	List *list;
	D_NODE *ptr;
	int i;
	list = (List *) malloc(sizeof(List));
	if (!list) {
		return NULL;
	}
	list->head.next = NULL;
	ptr = &list->head;
	for (i = 0; i < c->count; i++) {
		if (c->pGardenList[i]->type == type) {
			ptr = createNode(ptr, c->pGardenList[i]);
		}
	}
	return list;
}

D_NODE* createNode(D_NODE* ptr, Garden* g) {
	D_NODE *d;
	d = (D_NODE *) malloc(sizeof(D_NODE));
	if (!d) {
		return NULL;
	}
	ptr->next = d;
	d->next = NULL;
	d->garden = g;
	return d;
}

void displayKindergartenFromList(List *list) {
	D_NODE *d;
	d = list->head.next;
	while (d) {
		showGarden(d->garden);
		d = d->next;
	}
	freeList(list);
}

void freeList(List *list) {
	List *l;
	D_NODE *d, *d2;
	l = list;
	d = &list->head;
	while (d) {
		d2 = d;
		free(d);
		d = d2->next;
	}
	free(l);
}

