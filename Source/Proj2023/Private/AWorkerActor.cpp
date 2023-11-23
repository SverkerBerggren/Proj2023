// Fill out your copyright notice in the Description page of Project Settings.


#include "AWorkerActor.h"

// Sets default values
AAWorkerActor::AAWorkerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAWorkerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAWorkerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

