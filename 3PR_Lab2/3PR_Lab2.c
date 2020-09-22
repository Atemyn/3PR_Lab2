#include "mysource.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Building* zdanie, * domik;

	zdanie = (Building*)malloc(sizeof(Building));
	domik = (Building*)malloc(sizeof(Building));

	buildingInit(domik);
	buildingInput(zdanie);

	return 0;
}
