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
	printf("������� ����� ������� ������ ������: ");
	while (!scanf("%f", &b->sideLength) || b->sideLength <= 0)
	{
		printf("�������� ���� ����� ������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ");
		rewind(stdin);
	}

	printf("������� ������ ���������� ������ ������: ");
	while (!scanf("%f", &b->basementHeight) || b->basementHeight <= 0)
	{
		printf("�������� ���� ������ ���������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ");
		rewind(stdin);
	}

	printf("������� ������ ������ ����� ������ ������: ");
	while (!scanf("%f", &b->floorHeight) || b->floorHeight <= 0)
	{
		printf("�������� ���� ������ ����� - ��� ������ ���� ������������� ������. ���������� ��� ���: ");
		rewind(stdin);
	}

	printf("������� ���������� ������ ������ ������: ");
	while (!scanf("%u", &b->floorAmount) || b->floorAmount <= 0)
	{
		printf("�������� ���� ���������� - ��� ������ ���� ������������� ����� ������. ���������� ��� ���: ");
		rewind(stdin);
	}

	b->stabilityFactor = (float)(b->sideLength * b->sideLength * sqrt(b->basementHeight)) / (b->floorHeight * b->floorAmount);

	if (b->stabilityFactor < 1.0)
	{
		printf("����������� ������������ ������ ������ k = %lf ������ �������. ��� ����� ������� � ������ �� ������. ������ �� ����������� ���?\n", b->stabilityFactor);
		printf("���� ��� - ������� Esc, ���� �� - ����� ������ ������.\n\n");
		if (_getch() != 27)
		{
			buildingInput(b);
		}
		else
		{
			puts("������ �� ������ ������� � �������!\n");
			buildingInit(b);
		}
	}
	else
	{
		printf("�������! ������ ���������� ���������� � ������������� ������������ k = %lf\n", b->stabilityFactor);
	}
}

void buildingDisplay(Building* b)
{
	printf("\n����� �������: %f\n������ ����������: %f\n������ �����: %f\n���������� ������: %u\n����������� ������������: %lf\n",
		b->sideLength, b->basementHeight, b->floorHeight, b->floorAmount, b->stabilityFactor);
}

Building buildingsAdd(Building* b1, Building* b2)
{
	puts("\n��������� ��� ������... �� �������� �����:");
	printf("����� ������ ���������: %.3f � %.3f\n������ ����������� : %.3f � %.3f\n�����s ������ : %.3f � %.3f\n���������� ������ : %u � %u\n������������ ������������ : %.3lf � %.3lf\n\n",
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
		printf("� ���������, ����� ���������� ���� ������ ����� ������ ����� �� �����������, ��� ��� ��� ����������� ������������ k = %lf ������ ����\n\n", resultBuilding.stabilityFactor);
		buildingInit(&resultBuilding);
	}
	else
	{
		printf("�������! ����� ������ �������. ��� �������� �����:\n");
		buildingDisplay(&resultBuilding);
	}

	return resultBuilding;
}