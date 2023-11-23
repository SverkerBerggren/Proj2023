// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cards.generated.h"


UCLASS()
class PROJ2023_API UCards : public UUserWidget{
	GENERATED_BODY()

public:
    UFUNCTION()
    void ChangeButton();

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* CardButton; 

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* CardNameText;

 
};
