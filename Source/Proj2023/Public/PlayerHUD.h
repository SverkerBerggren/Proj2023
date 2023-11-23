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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<AActor> workerBluePrintToSpawn;



private: 

	void UpdateResources();
	void FindWorkerPositions();

	void PlaceCards();
	bool ContainsForTArrayWorker(TArray<Worker>& arrayToExamine, Worker& workerToFind);

	void SetWorkerPositions();
	void ResetWorkerPositions();
	void PlaceWorker(int32 farmTileIndex, int32 workerId);
	
	TArray<TArray<AWorkerPosition*>> workerPositions; 
	TSortedMap<int32, AActor*> workerToBePlacedRegistry;


	AGameStateLogic* gameState;
	
protected:
	void NativeOnInitialized() override;

};
