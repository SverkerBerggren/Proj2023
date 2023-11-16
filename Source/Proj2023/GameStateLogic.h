// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Worker.h"
#include "FarmTile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStateLogic.generated.h"


enum WorkType
{
	build,harvest,slaughter,unassigned
};

enum Resource
{
	wheat, apple, cotton, pigMeat
};
UCLASS()
class PROJ2023_API AGameStateLogic : public AActor
{
	GENERATED_BODY()

private: 
	void Setup();
	void StartTurnUpkeep();

	void AddWorker();
	void AddResources(Resource resource, int32 amount);
	void AddMoney(int32 amount);



	int32 maxActions = 0; 
	int32 currentActions = 0;

	int32 actionLevel = 0; 
	int32 storageLevel = 0; 
	int32 currentStorage = 0;

	int32 moneyStored = 0;

	int32 wheatStored = 0;
	int32 appleStored = 0; 
	int32 cottonStored = 0; 
	int32 pigMeatStored = 0; 

	

	TMap<int32, AWorker> workerRegistry = TMap<int32, AWorker>();
	TMap<int32, AFarmTile> farmtileRegistry = TMap<int32, AFarmTile>();
	

public:	
	// Sets default values for this actor's properties
	AGameStateLogic();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor>WorkerToSpawn;

	

};
