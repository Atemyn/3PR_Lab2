#include "mysource.h"

// Функция, устананавлиающая все значения структуры по умолчанию в 1.
void buildingInit(Building* b)
{
	b->sideLength = 1.0;
	b->basementHeight = 1.0;
	b->floorHeight = 1.0;
	b->floorAmount = 1;
	b->stabilityFactor = 1.0;
}
// Функция по вводу данных о здании и по расчету коэффициента устойчивости на основе этих данных.
// b - указатель на экземпляр структуры Building.
void buildingInput(Building* b)
{
	// Защиты от дурака для ввода всех необходимых данных.
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
	// Расчет коэффицента устойчивости.
	b->stabilityFactor = (float)(b->sideLength * b->sideLength * sqrt(b->basementHeight)) / (b->floorHeight * b->floorAmount);
	// Если коэффициент устойчивости меньше 1 - здание упадет; необхлдим повторный ввод характеристик
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
			puts("Здание не смогло устоять и рухнуло!\n\n");
			buildingInit(b);
		}
	}
	else
	{
		printf("Отлично! Здание получилось устойчивым с коэффициентом устойчивости k = %lf\n\n", b->stabilityFactor);
	}
}
// Функция по выводу всех данных о здании построчно.
void buildingDisplay(Building* b)
{
	printf("Длина стороны: %f\nВысота фундамента: %f\nВысота этажа: %f\nКоличество этажей: %u\nКоэффициент устойчивости: %lf\n\n",
		b->sideLength, b->basementHeight, b->floorHeight, b->floorAmount, b->stabilityFactor);
}
// Функция по сложению двух зданий и расчету нового коэффициента устойчивости.
// b1, b2 - указатели на два экземпляра структуры Building.
Building buildingsAdd(Building* b1, Building* b2)
{
	puts("Совмещаем два здания... Их свойства такие:");
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
	// Расчет нового коэффициента устойчивости и проверка его корректности.
	resultBuilding.stabilityFactor = (float)(resultBuilding.sideLength * resultBuilding.sideLength * sqrt(resultBuilding.basementHeight)) / (resultBuilding.floorHeight * resultBuilding.floorAmount);
	if (resultBuilding.stabilityFactor < 1)
	{
		printf("К сожалению, после совмещения двух зданий новое здание сразу же развалилось, так как его коэффициент устойчивости k = %lf меньше нуля\n\n", resultBuilding.stabilityFactor);
		buildingInit(&resultBuilding);
	}
	else
	{
		printf("Отлично! Новое здание устояло. Его свойства такие:\n\n");
		buildingDisplay(&resultBuilding);
	}

	return resultBuilding;
}
// Функция по добавлению floorsToAdd этажей к экземпляру структуры Building, на который указывает b.
void addFloors(Building* b)
{
	unsigned floorsToAdd;
	// Защита от дурака для ввода floorsToAdd.
	printf("Введите количество этажей для добавления к вашему зданию: ");
	while (!scanf("%u", &floorsToAdd) || floorsToAdd < 0)
	{
		printf("Неверный ввод количества - оно должно быть неотрицательным целым числом. Попробуйте еще раз: ");
		rewind(stdin);
	}

	b->floorAmount = b->floorAmount + floorsToAdd;
	// Расчет нового коэффициента устойчивости и проверка его корректности.
	b->stabilityFactor = (float)(b->sideLength * b->sideLength * sqrt(b->basementHeight)) / (b->floorHeight * b->floorAmount);
	if (b->stabilityFactor < 1.0)
	{
		printf("Коэффициент стабильности вашего здания k = %lf стал меньше единицы. Оно может рухнуть с минуты на минуту. Попробуйте изменить количество этажей к добавлению (например, на 0)\n\n", b->stabilityFactor);
		b->floorAmount = b->floorAmount - floorsToAdd;
		addFloors(b);
	}
	else
	{
		printf("Отлично! Здание получилось устойчивым с коэффициентом устойчивости k = %lf\n\n", b->stabilityFactor);
	}
	// Отображение информации о здании.
	puts("Свойства здания с доп. этажами: \n");
	buildingDisplay(b);
}
// Функция по удалению floorsToRemove этажей у экземпляра структуры Building, на кторый указывает b.
void removeFloors(Building* b)
{
	unsigned floorsToRemove;
	// Защита от дурака для ввода floorsToRemove.
	printf("Введите количество этажей для удаления с вашего здания: ");
	while (!scanf("%u", &floorsToRemove) || floorsToRemove < 0 || floorsToRemove >= b->floorAmount)
	{
		printf("Неверный ввод количества - оно должно быть неотрицательным целым числом и меньшим общего числа этажей. Попробуйте еще раз: ");
		rewind(stdin);
	}
	// Расчет нового коэффициента устойчивости.
	b->floorAmount = b->floorAmount - floorsToRemove;
	// Отображение информации о здании.
	puts("Свойства урезанного здания: \n");
	buildingDisplay(b);
}