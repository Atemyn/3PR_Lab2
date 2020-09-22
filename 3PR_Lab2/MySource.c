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
