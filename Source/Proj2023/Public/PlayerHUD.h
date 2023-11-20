// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	/**Widget to use to display current health */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* Money;
	
};
