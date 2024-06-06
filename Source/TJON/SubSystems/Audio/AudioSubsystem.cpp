#include "AudioSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void UAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    // Optionally, initialize sound map here if needed
}

void UAudioSubsystem::Deinitialize()
{
    Super::Deinitialize();
}

void UAudioSubsystem::PlaySoundByName(FName SoundName)
{
    if (USoundCue** FoundSoundCue = SoundCueMap.Find(SoundName))
    {
        if (FoundSoundCue && *FoundSoundCue)
        {
            UGameplayStatics::PlaySound2D(GetWorld(), *FoundSoundCue);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Sound with name %s not found in SoundCueMap!"), *SoundName.ToString());
    }
}

void UAudioSubsystem::AddSound(FName SoundName, USoundCue* SoundCue)
{
    if (SoundCue)
    {
        SoundCueMap.Add(SoundName, SoundCue);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot add a null SoundCue for name %s"), *SoundName.ToString());
    }
}