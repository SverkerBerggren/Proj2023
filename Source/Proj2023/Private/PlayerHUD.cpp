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
void UPlayerHUD::FindWorkerPositions()
{
	TArray<AActor*> workerPositionsToFind;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWorkerPosition::StaticClass(), workerPositionsToFind);

	workerPositions.Add(TArray<AWorkerPosition>());

	

	for (AActor* actorsFound : workerPositionsToFind)
	{
		AWorkerPosition* workerPosition = (AWorkerPosition*)actorsFound;

		workerPositions[workerPosition->farmTileIndex].Add(*workerPosition);
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


void UPlayerHUD::Refresh()
{
	UpdateResources();

}


