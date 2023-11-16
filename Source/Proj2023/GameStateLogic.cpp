// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStateLogic.h"
#include "Worker.h"
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
	//GetWorld()->SpawnActor<AActor>(WorkerToSpawn, GetActorTransform());
	//TArray<AActor*> ActorsToFind;
	//
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWorker::StaticClass(), ActorsToFind);
	//
	//for (AActor* foundWorker : ActorsToFind)
	//{
	//	AWorker* workerFound = static_cast<AWorker*>(foundWorker);
	//
	//	FString message = FString::FromInt(workerFound->workRate);
	//
	//	
	//	
	//	UE_LOG(LogTemp, Warning, TEXT("message %s"), *message);
	//
	//}
}

void AGameStateLogic::Setup()
{
	AddWorker();

	AddMoney(1500);
}

void AGameStateLogic::AddMoney(int32 amount)
{
	moneyStored += amount;
}

void AGameStateLogic::AddWorker()
{	
	AWorker newWorker = AWorker();
	workerRegistry.Add(workerRegistry.Num() + 1, newWorker)
}

// Called every frame
void AGameStateLogic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

