// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\GameStateLogic.h"
#include "Action.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */


UCLASS()
class PROJ2023_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	/**Widget to use to display current money */
	//UPROPERTY(EditAnywhere, meta = (BindWidget))
	//class UImage* MoneyImage;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* MoneyText;

	UFUNCTION(BlueprintCallable)
	void SetGameStateLogic();

	void Refresh();
	
	bool IsActionValid();
	void DoAction(Action action);

private: 

	void UpdateResources();

	AGameStateLogic* gameState;
	
};
