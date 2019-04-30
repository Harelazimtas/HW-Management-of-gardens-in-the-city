#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"

int main(int argc, char *argv[]) {
	City utz = { NULL, 0 };
	int uReq, opt, id, numOfGarden, number, found = 0, type1;
	List *list;
	GardenType type;
	sscanf(argv[1], "%d", &opt);
	//first time read
	readCity(&utz, opt);
	do {
		uReq = menu();
		switch (uReq) {
		case READ_CITY:
			readCity(&utz, opt);
			break;

		case SHOW_CITY:
			showCityGardens(&utz);
			break;

		case SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case WRITE_CITY:
			saveCity(&utz, opt);
			break;

		case ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",
					countChova(&utz));
			break;
		case SORT_NAME_GARDEN:
			insertionSort(utz.pGardenList, utz.count, sizeof(Garden**),
					compareByName);
			break;
		case SORT_CHILD_ID:
			printf("please  chose garden between 1- %d", utz.count);
			number = choseGraden(utz.count);
			if (number == -1)
				break;
			insertionSort(utz.pGardenList[number]->childPtrArr,
					utz.pGardenList[number]->childCount, sizeof(Child**),
					compareById);
			break;
		case SORT_TYPE_AND_NUMBER_CHILD:
			insertionSort(utz.pGardenList, utz.count, sizeof(Garden**),
					compareByTypeAndNuberOfChild);
			break;
		case FIND_CHILD_ID:
			numOfGarden = choseGraden(utz.count);
			if (numOfGarden == -1)
				break;
			printf("please chose id");
			scanf("%d", &id);
			found = findChildById(utz.pGardenList[numOfGarden]->childPtrArr,
					utz.pGardenList[numOfGarden]->childCount, id);
			if (found != 0)
				printf("the address of key %d", found);
			else
				printf("the key don't find");
			break;
		case LINKED_LIST:
			printf("please chose type of garden between 0-2");
			scanf("%d", &type1);
			if (type1 > 2 || type1 < 0) {
				printf("invalid number");
				break;
			}
			type = (GardenType) type1;
			list = createLinkedListForKindergartenType(&utz, type);
			displayKindergartenFromList(list);
			break;
		}
	} while (uReq != EXIT);

	releaseCity(&utz); //free all allocations

	return EXIT_SUCCESS;
}

