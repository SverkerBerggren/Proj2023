// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\GameStateLogic.h"
#include "WorkerPosition.h"
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
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* Money;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* MoneyText;

	UPROPERTY(meta = (BindWidget))
	class UButton* EndTurnBtn;

	UFUNCTION(BlueprintCallable)
	void SetGameStateLogic();

	void Refresh();

	UFUNCTION(BlueprintCallable)
	void EndTurnClick();

	bool IsActionValid();
	void DoAction(Action action);


	UFUNCTION(BlueprintCallable)
	void CreateCards();


private: 

	void UpdateResources();
	void FindWorkerPositions();

	void PlaceCards();


	void SetWorkerPositions();
	
	TArray<TArray<AWorkerPosition*>> workerPositions; 

	AGameStateLogic* gameState;
	
protected:
	void NativeOnInitialized() override;

};
