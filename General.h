#ifndef __PROTOTYPE__
#define __PROTOTYPE__

#include "City.h"
#include "Kindergarten.h"

typedef enum {
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_NAME_GARDEN,
	SORT_CHILD_ID,
	SORT_TYPE_AND_NUMBER_CHILD,
	FIND_CHILD_ID,
	LINKED_LIST,
	NofOptions
} MenuOptions;

typedef struct d_node {
	Garden *garden;
	struct d_node *next;
} D_NODE;

typedef struct {
	D_NODE head;
} List;

int menu();
char* getStrExactLength(char* inpStr);
int checkAllocation(const void* p);

void insertionSort(void *arr, int size, int typeSize,
		int (*compare)(const void *, const void*));
void swap(void * a, void * b, int typeSize);
void vardicFunction(char *str, int num, ...);

List* createLinkedListForKindergartenType(const City *c, GardenType type);
D_NODE* createNode(D_NODE* ptr, Garden* g);
void displayKindergartenFromList(List *list);
void freeList(List *list);

#endif
