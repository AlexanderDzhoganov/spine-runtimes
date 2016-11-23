// Fill out your copyright notice in the Description page of Project Settings.

#include "SpinePluginPrivatePCH.h"

// Sets default values for this component's properties
USpineSkeletonComponent::USpineSkeletonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
    PrimaryComponentTick.bCanEverTick = true;
}

void USpineSkeletonComponent::Reload() {
    if (stateData) {
        spAnimationStateData_dispose(stateData);
        stateData = nullptr;
    }
    if (state) {
        spAnimationState_dispose(state);
        state = nullptr;
    }
    if (skeleton) {
        spSkeleton_dispose(skeleton);
        skeleton = nullptr;
    }
    
    spSkeletonData* data = skeletonData->GetSkeletonData(atlas->GetAtlas(true), true);
    skeleton = spSkeleton_create(data);
    stateData = spAnimationStateData_create(data);
    state = spAnimationState_create(stateData);
}

#if WITH_EDITOR
void USpineSkeletonComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    bool hasAtlasAndData = atlas && skeletonData;
    if (hasAtlasAndData) Reload();
    Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif


// Called when the game starts
void USpineSkeletonComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpineSkeletonComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

