// Fill out your copyright notice in the Description page of Project Settings.



#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();


	///look for atached physics handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	
	
}


/// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	

	/// Get player view point
	FVector playerPos;
	FRotator playerRot;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(playerPos, playerRot);
	/*UE_LOG(LogTemp, Warning, TEXT("Player At %s facing %s"), *playerPos.ToString(), *playerRot.ToString());*/

	FVector LineTraceEnd = playerPos + (playerRot.Vector() * Reach);
	/// Raycast out to reach distance
	//DrawDebugLine(
	//	GetWorld(),
	//	playerPos,
	//	LineTraceEnd,
	//	FColor(255, 0, 0),
	//	false,
	//	0.f,
	//	0.f,
	//	10
	//);

	///Setup change false to true for more detialed scan;
	FHitResult hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
///Set collision chanel to only physics body

	GetWorld()->LineTraceSingleByObjectType(
		hit,
		playerPos,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	AActor* ActorHit = hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("hitting %s"), *(ActorHit->GetName()));
	}
	// see what we hit
}

