// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

#define OUT
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
	
	//objectsThatCanOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	
		
	// ...

	
}




// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	


	isover = GetTotalMassOFActorsOnPlate() > 50.f;
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

	OnOpenRequest.Broadcast();
	
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
	OnCloseRequest.Broadcast();

}

float UOpenDoor::GetTotalMassOFActorsOnPlate()
{
	float TotalMass = 0.f;

	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	myTriggerVolume->GetOverlappingActors(OUT OverlappingActors);

	// Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}

	return TotalMass;
}


