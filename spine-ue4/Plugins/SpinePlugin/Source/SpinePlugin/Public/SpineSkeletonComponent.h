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
    
	// Sets default values for this component's properties
	USpineSkeletonComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
