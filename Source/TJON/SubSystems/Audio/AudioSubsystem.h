#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Sound/SoundCue.h"
#include "AudioSubsystem.generated.h"

UCLASS()
class TJON_API UAudioSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    // Initialize the subsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    // Deinitialize the subsystem
    virtual void Deinitialize() override;

    // Function to play sound by name
    UFUNCTION(BlueprintCallable, Category = "Audio")
        void PlaySoundByName(FName SoundName);

    // Function to add sound to the map
    UFUNCTION(BlueprintCallable, Category = "Audio")
        void AddSound(FName SoundName, USoundCue* SoundCue);

private:
    // A map to store sound cues
    UPROPERTY(EditAnywhere, Category = "Audio")
        TMap<FName, USoundCue*> SoundCueMap;
};