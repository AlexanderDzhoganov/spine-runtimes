#include "SpinePluginPrivatePCH.h"
#include "Engine.h"
#include "spine/spine.h"

USpineSkeletonRendererComponent::USpineSkeletonRendererComponent(const FObjectInitializer& ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.	
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

#if WITH_EDITOR
	bTickInEditor = true;
	bAutoActivate = true;
#endif
}

// Called when the game starts
void USpineSkeletonRendererComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USpineSkeletonRendererComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	UClass* skeletonClass = USpineSkeletonComponent::StaticClass();
	AActor* owner = GetOwner();
	if (owner) {
		skeleton = Cast<USpineSkeletonComponent>(owner->GetComponentByClass(skeletonClass));
		if (skeleton->skeleton) {
			spSkeleton_updateWorldTransform(skeleton->skeleton);
		}
	}
}

