#include "mysource.h"

void main()
{
	// Подключение русского консольного ввода.
	SetConsoleCP(1251);
	// Подключение русского консольного вывода.
	SetConsoleOutputCP(1251);

	Building* zdanie, * domik, newB;

	zdanie = (Building*)malloc(sizeof(Building));
	domik = (Building*)malloc(sizeof(Building));

	buildingInit(domik);
	buildingInput(zdanie);
	buildingDisplay(zdanie);

	newB = buildingsAdd(zdanie, domik);

	addFloors(&newB);
}
