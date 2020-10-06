#include "mysource.h"

void main()
{
	// Подключение русского консольного ввода.
	SetConsoleCP(1251);
	// Подключение русского консольного вывода.
	SetConsoleOutputCP(1251);

	Building* zdanie, * domik, newB;
	// Динамическое выделение памяти под экземпляры структуры Building.
	zdanie = (Building*)malloc(sizeof(Building));
	domik = (Building*)malloc(sizeof(Building));
	
	buildingInit(domik);
	buildingInput(zdanie);
	buildingDisplay(zdanie);
	// Сложение двух зданий.
	newB = buildingsAdd(zdanie, domik);
	// Добавление этажей.
	addFloors(&newB);
	// Удаление этажей.
	removeFloors(&newB);
}
