#ifndef __CHILD__
#define __CHILD__

typedef struct {
	int id;
	int age;
} Child;
#define BYTE 1

void readChild(FILE* fp, Child* pChild, int opt);
void getChildFromUser(Child* pChild, int id);
void showChild(const Child* pChild);
void writeChild(FILE* fp, const Child* pChild, int opt);
void birthday(Child* pChild);
int compareById(const void * child1, const void * child2);
int findChildById(Child** pChildList, int count, int id);

#endif
