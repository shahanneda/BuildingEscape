// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	objectsThatCanOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	
		
	// ...

	
}




// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	

	if (objectsThatCanOpen == NULL || myTriggerVolume == NULL)
	{
		return;
	}
	isover = myTriggerVolume->IsOverlappingActor(objectsThatCanOpen);
	if (isover) {
		//UE_LOG(LogTemp, Warning, TEXT("Calling tope THE DOOR "));
		OpenTheDoor();

	}

	if (GetWorld()->GetTimeSeconds() > timeWhenOpened + timeDoorStaysOpen) {
		CloseTheDoor();
	};
	 
	
}


void UOpenDoor::OpenTheDoor()
{
	
	//UE_LOG(LogTemp, Warning, TEXT("OPENING THE DOOR "));

	//Find the owning Actor
	AActor* Owner = GetOwner();

	// Create a rotator
	FRotator NewRotation = FRotator(0.f, angle, 0.f);

	// Set the door rotation
	Owner->SetActorRotation(NewRotation);
	
	timeWhenOpened = GetWorld()->GetTimeSeconds();
}

void UOpenDoor::CloseTheDoor()
{
	isover = false;
	
	//Find the owning Actor
	AActor* Owner = GetOwner();

	// Create a rotator
	FRotator NewRotation = FRotator(0.f, 90.f, 0.f);

	// Set the door rotation
	Owner->SetActorRotation(NewRotation);

}


