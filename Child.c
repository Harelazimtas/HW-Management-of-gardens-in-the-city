#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"

/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild, int opt) {
	//Child ID
	if (opt == 0) {
		fscanf(fp, "%d", &pChild->id);
		fscanf(fp, "%d", &pChild->age);
	} else {
		int data = 0;
		fread(&data, BYTE * 2, 1, fp);
		pChild->age = data >> 13;
		pChild->id = data & 0X1FFF;
	}
}

/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild) {
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}

/**************************************************/
void getChildFromUser(Child* pChild, int id)
/**************************************************/
/**************************************************/
{
	pChild->id = id;

	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}

/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp, const Child* pChild, int opt) {
	if (opt == 0)
		fprintf(fp, "%d %d\n", pChild->id, pChild->age);
	else {
		int data = 0;
		data = (pChild->age << 13) | (pChild->id & 0X1FFF);
		fwrite(&data, BYTE * 2, 1, fp);
	}
}

//linear search
int findChildById(Child** pChildList, int count, int id) {
	int *found;
	Child *c;
	c = (Child*) malloc(sizeof(Child));
	c->id = id;
	qsort(pChildList, count, sizeof(Child**), compareById);
	found = bsearch(&c, pChildList, count, sizeof(Child**), compareById);
	free(c);
	if (!found)
		return 0;
	return *found;
}

void birthday(Child* pChild) {
	pChild->age++;
}

int compareById(const void * child1, const void * child2) {
	const Child* c1 = *(Child**) child1;
	const Child* c2 = *(Child**) child2;
	return c1->id - c2->id;
}
