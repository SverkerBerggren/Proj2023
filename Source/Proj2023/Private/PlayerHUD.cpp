// Fill out your copyright notice in the Description page of Project Settings.



#include "PlayerHUD.h"
#include "CoreMinimal.h"
#include "..\\Public\EndTurnAction.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "..\\EnumAndStructs.h"
#include "UObject/WeakObjectPtr.h"
#include "Kismet/GameplayStatics.h"

void UPlayerHUD::EndTurnClick()
{
	EndTurnAction endTurnAction;

	DoAction(endTurnAction);
	Refresh();


}

void UPlayerHUD::CreateCards()
{
		

}
void UPlayerHUD::FindWorkerPositions()
{
	TArray<AActor*> workerPositionsToFind;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWorkerPosition::StaticClass(), workerPositionsToFind);

	for (int i = 0; i < 9; i++)
	{	

		workerPositions.Add(TArray<AWorkerPosition*>());
		for (int z = 0; z < 3; z++)
		{
			AWorkerPosition* workerPosition = nullptr;
			

			workerPositions[i].Add(workerPosition);
		}
	}


	for (AActor* foundPosition : workerPositionsToFind)
	{
		AWorkerPosition* foundWorkerPosition = (AWorkerPosition*)foundPosition;

		workerPositions[foundWorkerPosition->farmTileIndex][foundWorkerPosition->orderInTile] = foundWorkerPosition;



	//	AActor* actorSpawned = GetWorld()->SpawnActor<AActor>(workerBluePrintToSpawn, foundWorkerPosition->GetActorLocation(), FRotator(0, 0, 0));
	//
	//	if (actorSpawned != nullptr)
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("An Actor's name is %s"), *actorSpawned->GetName())
	//
	//	}
	//	else
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("Actor ar ej Spawnad "))
	//	}
	}

}
void UPlayerHUD::NativeOnInitialized()
{	

	FindWorkerPositions();
	SetGameStateLogic();
}

void UPlayerHUD::SetGameStateLogic()
{
	UWorld* world  = GetWorld();
	
	TArray<AActor*> actorToFind;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGameStateLogic::StaticClass(), actorToFind);


	if (actorToFind.Num() == 1)
	{
		gameState = (AGameStateLogic*)actorToFind[0];
	}
	Refresh();
}

void UPlayerHUD::UpdateResources()
{
	MoneyText->SetText(FText::AsNumber(gameState->GetAmountOfResource(Resource::Money)));
}
void UPlayerHUD::ResetWorkerPositions()
{
	for (int i = 0; i < 9; i++)
	{
		for (int z = 0; z < 3; z++)
		{	
			if (workerPositions[i][z] != nullptr)
			{
				workerPositions[i][z]->workerPlacedHere = false;

			}
		}
	}
}

void UPlayerHUD::PlaceWorker( int32 farmTileIndex, int32 workerId)
{
	TArray<AWorkerPosition*> arrayToLoop = workerPositions[farmTileIndex];
		
	for (int i = 0; i < 3; i++)
	{
		if (arrayToLoop[i]->workerPlacedHere == false)
		{
			arrayToLoop[i]->workerPlacedHere = true;
			AActor* workerToPlace = workerToBePlacedRegistry[workerId];
			workerToPlace->SetActorLocation(arrayToLoop[i]->GetActorLocation());
		}
	}
}

bool  UPlayerHUD::ContainsForTArrayWorker(TArray<Worker>& arrayToExamine, Worker& workerToFind)
{
	for (Worker& worker : arrayToExamine)
	{
		if (worker.workedId == workerToFind.workedId)
		{
			return true;
		}
	}

	return false; 
}

 
void UPlayerHUD::SetWorkerPositions()
{
	TSortedMap<int32, Worker> registredWorkers = gameState->GetWorkerRegistry();

	for (auto& pair : registredWorkers)
	{
		Worker registredWorker = pair.Value; 

		if (workerToBePlacedRegistry.Contains(registredWorker.workedId) == false)
		{
			AActor* spawnedWorker = GetWorld()->SpawnActor<AActor>(workerBluePrintToSpawn, FVector(0,0,0), FRotator(0, 0, 0));
		//	workerToBePlacedRegistry.Add()
			workerToBePlacedRegistry.Add(registredWorker.workedId, spawnedWorker);
		}
	}
	for (auto& pair : workerToBePlacedRegistry)
	{
		int32 workerId = pair.Key;

		if (registredWorkers.Contains(workerId) == false)
		{
			AActor* actorToRemove = workerToBePlacedRegistry[workerId];

			workerToBePlacedRegistry.Remove(workerId);

			actorToRemove->Destroy();
		}
	}
	int32 indexFarmTile = 0; 
	TArray<Worker> workersOnTiles;
	for (auto& pair : gameState->GetFarmTileRegistry())
	{
		
		FarmTile farmTile = pair.Value;
		for (Worker& worker : farmTile.workersOnTile)
		{
			PlaceWorker(indexFarmTile, worker.workedId);
			workersOnTiles.Add(worker);
		}
		indexFarmTile += 1;
	}
	int32 padding = 0;

	for (auto& pair : registredWorkers)
	{
		if (ContainsForTArrayWorker(workersOnTiles,pair.Value) == false)
		{
			workerToBePlacedRegistry[pair.Key]->SetActorLocation(FVector(0 + padding, 0, 0));
			padding += 30;
		}
	}

//	for (auto& pair : workerToBePlacedRegistry)
//	{
//	
//		if (registredWorkers[pair.Key].workType == WorkType::unassigned)
//		{
//			pair.Value->SetActorLocation(FVector(0 + padding, 0, 0));
//			padding += 30;
//		}
//		
//	}


}



void UPlayerHUD::DoAction(Action action)
{
	gameState->DoAction(action);
	Refresh();
}

void UPlayerHUD::Refresh()
{
	ResetWorkerPositions();
	UpdateResources();
	SetWorkerPositions();
}


