#include "SpineEditorPluginPrivatePCH.h"

#include "SpineAtlasAsset.h"
#include "AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "PackageTools.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "spine/spine.h"

#define LOCTEXT_NAMESPACE "Spine"

USpineAtlasAssetFactory::USpineAtlasAssetFactory (const FObjectInitializer& objectInitializer): Super(objectInitializer) {
    bCreateNew = false;
    bEditAfterNew = true;
    bEditorImport = true;
    SupportedClass = USpineAtlasAsset::StaticClass();
    
    Formats.Add(TEXT("atlas;Spine atlas file"));
}

FText USpineAtlasAssetFactory::GetToolTip () const {
    return LOCTEXT("SpineAtlasAssetFactory", "Animations exported from Spine");
}

bool USpineAtlasAssetFactory::FactoryCanImport (const FString& filename) {
    return true;
}

UObject* USpineAtlasAssetFactory::FactoryCreateFile (UClass * InClass, UObject * InParent, FName InName, EObjectFlags Flags, const FString & Filename, const TCHAR* Parms, FFeedbackContext * Warn, bool& bOutOperationCanceled) {
    FString rawString;
    if (!FFileHelper::LoadFileToString(rawString, *Filename)) {
        return nullptr;
    }
    FString name(InName.ToString());
    name.Append("-atlas");
    USpineAtlasAsset* asset = NewObject<USpineAtlasAsset>(InParent, InClass, FName(*name), Flags);
    asset->SetRawData(rawString);
    asset->SetAtlasFileName(FName(*Filename));
    return asset;
}

bool USpineAtlasAssetFactory::CanReimport(UObject* Obj, TArray<FString>& OutFilenames) {
    USpineAtlasAsset* asset = Cast<USpineAtlasAsset>(Obj);
    if (!asset) return false;
    FString filename = asset->GetAtlasFileName().ToString();
    if (!filename.IsEmpty())
        OutFilenames.Add(filename);
    return true;
}

void USpineAtlasAssetFactory::SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths) {
    USpineAtlasAsset* asset = Cast<USpineAtlasAsset>(Obj);
    if (asset && ensure(NewReimportPaths.Num() == 1))
        asset->SetAtlasFileName(FName(*NewReimportPaths[0]));
}

EReimportResult::Type USpineAtlasAssetFactory::Reimport(UObject* Obj) {
    USpineAtlasAsset* asset = Cast<USpineAtlasAsset>(Obj);
    FString rawString;
    if (!FFileHelper::LoadFileToString(rawString, *asset->GetAtlasFileName().ToString())) return EReimportResult::Failed;
    asset->SetRawData(rawString);
    if (Obj->GetOuter()) Obj->GetOuter()->MarkPackageDirty();
    else Obj->MarkPackageDirty();
    return EReimportResult::Succeeded;
}

#undef LOCTEXT_NAMESPACE