#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define MYSOURCE

typedef struct {
	float sideLength;
	float basementHeight;
	float floorHeight;
	unsigned floorAmount;
	float stabilityFactor;
}Building;

void buildingInit(Building* b);

void buildingInput(Building* b);

void buildingDisplay(Building* b);

Building buildingsAdd(Building* b1, Building* b2);

void addFloors(Building* b);

