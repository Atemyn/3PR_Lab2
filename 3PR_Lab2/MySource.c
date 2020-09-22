#include "mysource.h"

void buildingInit(Building* b)
{
	b->sideLength = 1.0;
	b->basementHeight = 1.0;
	b->floorHeight = 1.0;
	b->floorAmount = 1;
	b->stabilityFactor = 1.0;
}
void buildingInput(Building* b)
{
	printf("Введите длину стороны вашего здания: ");
	while (!scanf("%f", &b->sideLength) || b->sideLength <= 0)
	{
		printf("Неверный ввод длины стороны - она должна быть положительным числом. Попробуйте еще раз: ");
		rewind(stdin);
	}

	printf("Введите высоту фундамента вашего здания: ");
	while (!scanf("%f", &b->basementHeight) || b->basementHeight <= 0)
	{
		printf("Неверный ввод высоты фундамента - она должна быть положительным числом. Попробуйте еще раз: ");
		rewind(stdin);
	}

	printf("Введите высоту одного этажа вашего здания: ");
	while (!scanf("%f", &b->floorHeight) || b->floorHeight <= 0)
	{
		printf("Неверный ввод высоты этажа - она должна быть положительным числом. Попробуйте еще раз: ");
		rewind(stdin);
	}

	printf("Введите количество этажей вашего здания: ");
	while (!scanf("%u", &b->floorAmount) || b->floorAmount <= 0)
	{
		printf("Неверный ввод количества - оно должно быть положительным целым числом. Попробуйте еще раз: ");
		rewind(stdin);
	}

	b->stabilityFactor = (float)(b->sideLength * b->sideLength * sqrt(b->basementHeight)) / (b->floorHeight * b->floorAmount);

	if (b->stabilityFactor < 1.0)
	{
		printf("Коэффициент стабильности вашего здания k = %lf меньше единицы. Оно может рухнуть с минуты на минуту. Хотите ли перестроить его?\n", b->stabilityFactor);
		printf("Если НЕТ - нажмите Esc, если ДА - любую другую кнопку.\n\n");
		if (_getch() != 27)
		{
			buildingInput(b);
		}
		else
		{
			puts("Здание не смогло устоять и рухнуло!\n");
			buildingInit(b);
		}
	}
	else
	{
		printf("Отлично! Здание получилось устойчивым с коэффициентом устойчивости k = %lf\n", b->stabilityFactor);
	}
}

void buildingDisplay(Building* b)
{
	printf("\nДлина стороны: %f\nВысота фундамента: %f\nВысота этажа: %f\nКоличество этажей: %u\nКоэффициент устойчивости: %lf\n",
		b->sideLength, b->basementHeight, b->floorHeight, b->floorAmount, b->stabilityFactor);
}

Building buildingsAdd(Building* b1, Building* b2)
{
	puts("\nСовмещаем два здания... Их свойства такие:");
	printf("Длины сторон оснований: %.3f и %.3f\nВысоты фундаментов : %.3f и %.3f\nВысотs этажей : %.3f и %.3f\nКоличества этажей : %u и %u\nКоэффициенты устойчивости : %.3lf и %.3lf\n\n",
		b1->sideLength, b2->sideLength, b1->basementHeight, b2->basementHeight, b1->floorHeight, b2->floorHeight, b1->floorAmount, b2->floorAmount, b1->stabilityFactor, b2->stabilityFactor);
	Building resultBuilding;
	if (b1->sideLength > b2->sideLength)
		resultBuilding.sideLength = b1->sideLength;
	else
		resultBuilding.sideLength = b2->sideLength;

	if (b1->basementHeight > b2->basementHeight)
		resultBuilding.basementHeight = b1->basementHeight;
	else
		resultBuilding.basementHeight = b2->basementHeight;

	if (b1->floorHeight > b2->floorHeight)
		resultBuilding.floorHeight = b1->floorHeight;
	else
		resultBuilding.floorHeight = b2->floorHeight;

	resultBuilding.floorAmount = b1->floorAmount + b2->floorAmount;

	resultBuilding.stabilityFactor = (float)(resultBuilding.sideLength * resultBuilding.sideLength * sqrt(resultBuilding.basementHeight)) / (resultBuilding.floorHeight * resultBuilding.floorAmount);
	if (resultBuilding.stabilityFactor < 1)
	{
		printf("К сожалению, после совмещения двух зданий новое здание сразу же развалилось, так как его коэффициент устойчивости k = %lf меньше нуля\n\n", resultBuilding.stabilityFactor);
		buildingInit(&resultBuilding);
	}
	else
	{
		printf("Отлично! Новое здание устояло. Его свойства такие:\n");
		buildingDisplay(&resultBuilding);
	}

	return resultBuilding;
}