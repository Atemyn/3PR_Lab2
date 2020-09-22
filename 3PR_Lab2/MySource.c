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
