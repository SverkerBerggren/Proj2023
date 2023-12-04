// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprint/WidgetBlueprintLibrary.h"

#include "ClickableFarmTile.h"

// Sets default values
AClickableFarmTile::AClickableFarmTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AClickableFarmTile::SetPlayerHUD()
{
	
		//UWorld* world = GetWorld();
		//
		//TArray<UUserWidget*> widgetsToFind;
		//TSubclassOf<UPlayerHUD> widgetClass;
		//
		//UWidgetBlueprintLibrary::GetAllWidgetsOfClass(world, widgetsToFind, widgetClass, true);
		//
		//
		//UE_LOG(LogTemp, Warning, TEXT("den blev player huddad innan"));
		//
		//if (widgetsToFind.Num() == 1)
		//{
		//	playerHUD = (UPlayerHUD*)widgetsToFind[0];
		//
		//	UE_LOG(LogTemp, Warning, TEXT("den blev player huddad"));
		//}
}

void AClickableFarmTile::CreateBuildPopup()
{
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();

	UPanelWidget* RootWidget = Cast<UPanelWidget>(playerHUD->GetRootWidget());
	UWidgetTree* tree = playerHUD->WidgetTree;
	TSubclassOf<UBuildPopup> klassen;

	UBuildPopup* buildPopup = tree->ConstructWidget<UBuildPopup>(klassen, FName("hej"));

	RootWidget->AddChild(buildPopup);

}

// Called when the game starts or when spawned
void AClickableFarmTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClickableFarmTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

