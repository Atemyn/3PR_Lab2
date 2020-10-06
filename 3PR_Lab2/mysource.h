#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define MYSOURCE
// Структура здания.
typedef struct {
	// Длина стороны основания.
	float sideLength;
	// Высота фундамента.
	float basementHeight;
	// Высота этажа.
	float floorHeight;
	// Количество этажей.
	unsigned floorAmount;
	// Коэффициент устойчивости.
	float stabilityFactor;
}Building;

void buildingInit(Building* b);

void buildingInput(Building* b);

void buildingDisplay(Building* b);

Building buildingsAdd(Building* b1, Building* b2);

void addFloors(Building* b);

void removeFloors(Building* b);

