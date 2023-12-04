// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\\EnumAndStructs.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.h"
#include "BuildPopup.generated.h"

/**
 * 
 */
UCLASS()
class PROJ2023_API UBuildPopup : public UUserWidget
{
	GENERATED_BODY()
public: 
	UPROPERTY(meta = (BindWidget))
	class UButton* BuildWheatBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* BuildAppleBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* BuildCottonBtn;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* BuildPigBtn;

	UPlayerHUD* playerHud; 


};
