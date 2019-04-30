#ifndef __KINDERGARTEN__
#define __KINDERGARTEN__

#include "Child.h"

typedef enum {
	Chova, TromChova, TromTromChova, NofTypes
} GardenType;

const char* GardenTypeName[NofTypes];

typedef struct {
	char* name;
	GardenType type;
	Child** childPtrArr;
	int childCount;
} Garden;

Garden** readAllGardensFromFile(char* fileName, int* pGardenCount, int opt);
void readGarden(FILE* fp, Garden* pGarden, int opt);
GardenType getTypeOption();

void showAllGardens(Garden** pGardenList, int count);
void showGarden(const Garden* pGarden);

void writeGardensToFile(Garden** pGardenList, int gardenCount, char* fileName,
		int opt);
void writeGarden(FILE* fp, const Garden* pGarden, int opt);

void addChildToGarden(Garden** pGardenList, int gardenCount);
Garden** addGarden(Garden** pGardenList, int* pGardenCount);

void showGardenMenu(Garden** pGardenList, int count);
Garden* getGardenAskForName(Garden** pGardenList, int count);

Garden* findGardenByName(Garden** pGardenList, int count, const char* name);

Child* getChildAskForId(Garden* pGarden);

void getGardenFromUser(Garden* pGarden, Garden** pGardenList, int count);
void getChildCheckIdFromUser(Child* pChild, const Garden* pGarden);

void handleBirthdayToChild(Garden** pGardenList, int count);

void release(Garden** pGardenList, int count);

int compareByName(const void* garden, const void* garden2);
int compareByTypeAndNuberOfChild(const void* garden, const void* garden2);
int choseGraden(const int numOfGarden);

#endif
