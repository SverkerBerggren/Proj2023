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

	gameState->DoAction(endTurnAction);

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
 
void UPlayerHUD::SetWorkerPositions()
{
	TMap<int32, Worker> registredWorkers = gameState->GetWorkerRegistry();


}

void UPlayerHUD::DoAction(Action action)
{

	Refresh();
}

void UPlayerHUD::Refresh()
{
	UpdateResources();
}


