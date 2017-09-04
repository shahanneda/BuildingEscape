// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenTheDoor();
	void CloseTheDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere) 
	ATriggerVolume* myTriggerVolume = NULL;

	UPROPERTY(VisibleAnywhere)
	APawn* objectsThatCanOpen = NULL;

	UPROPERTY(VisibleAnywhere)
	bool isover;

	UPROPERTY(EditAnywhere)
	float angle = 60;

	float timeWhenOpened;
	
	UPROPERTY(EditAnywhere)
	float timeDoorStaysOpen = 1.3 ;

};
