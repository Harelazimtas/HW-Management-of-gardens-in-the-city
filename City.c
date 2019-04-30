#include <stdio.h>

#include "City.h"
#include "Kindergarten.h"

void readCity(City* pCity, int opt) {
	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}
	if (opt == 0)
		pCity->pGardenList = readAllGardensFromFile(DATA_FILE, &pCity->count,
				opt);
	else
		pCity->pGardenList = readAllGardensFromFile(DATA_FILEB, &pCity->count,
				opt);
	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void showCityGardens(City* pCity) {
	showAllGardens(pCity->pGardenList, pCity->count);
}

void showSpecificGardenInCity(City* pCity) {
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity, int opt) {
	if (opt == 0)
		writeGardensToFile(pCity->pGardenList, pCity->count, DATA_FILE, opt);
	else
		writeGardensToFile(pCity->pGardenList, pCity->count, DATA_FILEB, opt);
}

void cityAddGarden(City* pCity) {
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL) //Allocation error
		printf("Error adding kindergarten\n");
}

void addChildToSpecificGardenInCity(City* pCity) {
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void birthdayToChild(City* pCity) {
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int countChova(City* pCity) {
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++) {
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void releaseCity(City* pCity) {
	release(pCity->pGardenList, pCity->count);
}
