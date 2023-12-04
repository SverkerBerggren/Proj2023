// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerHUD.h"
#include "GameFramework/Actor.h"
#include "BuildPopup.h"
#include "Blueprint/WidgetTree.h"
#include "ClickableFarmTile.generated.h"

UCLASS()
class PROJ2023_API AClickableFarmTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClickableFarmTile();

	


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UUserWidget> buildPopUp; 

	UPROPERTY()
	UPlayerHUD* playerHUD; 

	UFUNCTION(BlueprintCallable)
	void CreateBuildPopup();

	UFUNCTION(BlueprintCallable)
	void SetPlayerHUD();




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
