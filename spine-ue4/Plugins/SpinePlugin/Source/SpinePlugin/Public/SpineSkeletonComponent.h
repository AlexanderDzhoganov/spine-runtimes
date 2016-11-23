// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "SpineSkeletonComponent.generated.h"

class USpineAtlasAsset;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPINEPLUGIN_API USpineSkeletonComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spine)
    USpineAtlasAsset* atlas;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spine)
    USpineSkeletonDataAsset* skeletonData;
    
    void Reload ();
    	
	USpineSkeletonComponent();
	
	virtual void BeginPlay() override;
		
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
    
protected:
    spAnimationStateData* stateData;
    spAnimationState* state;
    spSkeleton* skeleton;
	
};
