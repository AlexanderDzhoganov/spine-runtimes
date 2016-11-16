#pragma once

#include "Engine.h"
#include "SpineAtlasAsset.generated.h"

UCLASS()
class USpineAtlasAsset : public UObject {
    GENERATED_BODY()
    
public:
    FString GetRawData () const;
    FName GetAtlasFileName () const;
    
protected:
    UPROPERTY()
    FString rawData;
    
    UPROPERTY()
    FName atlasFileName;
    
#if WITH_EDITORONLY_DATA

public:
    void SetRawData (const FString &rawData);
    void SetAtlasFileName (const FName &atlasFileName);
    
protected:
    UPROPERTY(VisibleAnywhere, Instanced, Category=ImportSettings)
    class UAssetImportData* importData;
    
    virtual void PostInitProperties() override;
    virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;
    virtual void Serialize(FArchive& Ar) override;
#endif
};