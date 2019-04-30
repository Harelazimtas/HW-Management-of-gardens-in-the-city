#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"

//#define TEXT

#define DATA_FILE "DataFile.txt"

#define DATA_FILEB "DataFile.bin"

typedef struct {
	Garden** pGardenList;
	int count;
} City;

void readCity(City* pCity, int opt);
void showCityGardens(City* pCity);
void showSpecificGardenInCity(City* pCity);
void saveCity(City* pCity, int opt);
void cityAddGarden(City* pCity);
void addChildToSpecificGardenInCity(City* pCity);
void birthdayToChild(City* pCity);
int countChova(City* pCity);
void releaseCity(City* pCity);

#endif
