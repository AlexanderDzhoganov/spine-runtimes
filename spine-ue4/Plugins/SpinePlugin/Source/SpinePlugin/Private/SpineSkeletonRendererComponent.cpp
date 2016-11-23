// Fill out your copyright notice in the Description page of Project Settings.

#include "SpinePluginPrivatePCH.h"


// Sets default values for this component's properties
USpineSkeletonRendererComponent::USpineSkeletonRendererComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	skeleton = CreateDefaultSubobject<USpineSkeletonComponent>(FName(TEXT("skeleton")));
	// ...
}


// Called when the game starts
void USpineSkeletonRendererComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpineSkeletonRendererComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

