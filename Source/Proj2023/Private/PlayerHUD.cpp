// Fill out your copyright notice in the Description page of Project Settings.



#include "PlayerHUD.h"
#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "..\\EnumAndStructs.h"
#include "Kismet/GameplayStatics.h"

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

void UPlayerHUD::Refresh()
{
	UpdateResources();

}


