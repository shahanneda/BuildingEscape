// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/physicsHandleComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/PrimitiveComponent.h"


#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "Containers/Array.h"
#include "OpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

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
	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnCloseRequest;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float angle = 60;

private:

	float GetTotalMassOFActorsOnPlate();

	UPROPERTY(EditAnywhere) 
	ATriggerVolume* myTriggerVolume = NULL;

	UPROPERTY(VisibleAnywhere)
	APawn* objectsThatCanOpen = NULL;

	UPROPERTY(VisibleAnywhere)
	bool isover;

	

	float timeWhenOpened;
	
	UPROPERTY(EditAnywhere)
	float timeDoorStaysOpen = 1.3 ;



};
