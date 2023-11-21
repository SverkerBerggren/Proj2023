// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "EnumAndStructs.h"
#include "Worker.h"
#include "CoreMinimal.h"

/**
 * 
 */
class PROJ2023_API FarmTile
{
public:
	FarmTile();
	~FarmTile();

	bool buildingOnTile = false;

	Resource resourceOnTile = Resource::wheat;

	int32 maxStoredResources = 120; 
	int32 storedResources = 0; 

	int32 productionRate = 40; 

	TArray<Worker> workersOnTile = TArray<Worker>();
	


};
