// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStateLogic.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AGameStateLogic::AGameStateLogic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameStateLogic::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < 9; i++)
	{

	}
}
void AGameStateLogic::AddMoney(int32 amount)
{
	moneyStored += amount;
}

void AGameStateLogic::AddWorker()
{	
	Worker newWorker = Worker();
	workerRegistry.Add(workersCreated + 1, newWorker);

	workersCreated += 1;
//	workerRegistry.Add(workerRegistry.Num() +1, ny);

}

void AGameStateLogic::Setup()
{	
	for (int i = 0; i < 9; i++)
	{
		farmTileRegistry.Add(i, FarmTile());
	}

	AddWorker();
	AddMoney(1500);
}

int32& AGameStateLogic::GetStorageFromResource(Resource resource)
{
	if (resource == wheat)
	{
		return wheatStored;
	}

	if (resource == apple)
	{
		return appleStored;
	}
	if (resource == cotton)
	{
		return cottonStored;
	}
	if (resource == pigMeat)
	{
		return pigMeatStored;
	}

	return wheatStored;
}

void AGameStateLogic::AddResources(Resource resource, int32 amount)
{
	int32 resourceStored = GetStorageFromResource(resource);

	

}

void AGameStateLogic::ProductionPhase()
{
	for (auto& farmTilePair : farmTileRegistry)
	{

		farmTilePair.Value.storedResources += farmTilePair.Value.productionRate;

		if (farmTilePair.Value.storedResources > farmTilePair.Value.maxStoredResources)
		{
			farmTilePair.Value.storedResources = farmTilePair.Value.maxStoredResources;
		}
	}
}

void AGameStateLogic::WorkPhase()
{
	for (auto& farmTilePair : farmTileRegistry)
	{
		for (Worker workerOnTile : farmTilePair.Value.workersOnTile)
		{
			if (workerOnTile.workType == harvesting)
			{
				if (farmTilePair.Value.storedResources < workerOnTile.workrate)
				{
					AddResources(farmTilePair.Value.resourceOnTile, farmTilePair.Value.storedResources);
					farmTilePair.Value.storedResources = 0;
				}
				else
				{
					AddResources(farmTilePair.Value.resourceOnTile, workerOnTile.workrate);
					farmTilePair.Value.storedResources = farmTilePair.Value.storedResources - workerOnTile.workrate;
				}
			}
		}
	}
}

void AGameStateLogic::StartTurnUpkeep()
{
	ProductionPhase();
}

// Called every frame
void AGameStateLogic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

