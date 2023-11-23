// Fill out your copyright notice in the Description page of Project Settings.


#include "Cards.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Engine/GameEngine.h"



void UCards::NativeConstruct()
{
	Super::NativeConstruct();


	CardButton->OnClicked.AddDynamic(this, &UCards::ChangeCardText());
	
}

void UCards::ChangeButton(){

	CardButton->RenderTransformPivot.Set(10, 20);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
		
}

