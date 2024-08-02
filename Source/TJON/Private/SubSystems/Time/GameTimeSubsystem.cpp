#include "SubSystems/Time/GameTimeSubsystem.h"

#pragma region Life cycle

void UGameTimeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TimeScale = 0.0f;
}

void UGameTimeSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UGameTimeSubsystem::Tick(float DeltaTime)
{
	TimeInSeconds += DeltaTime * TimeScale;
}

#pragma endregion

#pragma region Getters

int UGameTimeSubsystem::GetHours() const
{
	return (int)(TimeInSeconds / 3600);
}

int UGameTimeSubsystem::GetMinutes() const
{
	return (int)TimeInSeconds % 3600;
}

#pragma endregion

#pragma region Setters

void UGameTimeSubsystem::ChangeTimeScale(float NewTimeScale)
{
	TimeScale = NewTimeScale;
}

void UGameTimeSubsystem::AddSeconds(float SecondsToAdd)
{
	TimeInSeconds = FMath::Clamp(TimeInSeconds + SecondsToAdd, MinTime, MaxTime);
}

void UGameTimeSubsystem::AddMinutes(float MinutesToAdd)
{
	AddSeconds(MinutesToAdd * 60);
}

void UGameTimeSubsystem::AddHours(float HoursToAdd)
{
	AddSeconds(HoursToAdd * 3600);
}

void UGameTimeSubsystem::RemoveSeconds(float SecondsToRemove)
{
	TimeInSeconds = FMath::Clamp(TimeInSeconds - SecondsToRemove, MinTime, MaxTime);
}

void UGameTimeSubsystem::RemoveMinutes(float MinutesToRemove)
{
	RemoveSeconds(MinutesToRemove * 60);
}

void UGameTimeSubsystem::RemoveHours(float HoursToRemove)
{
	RemoveSeconds(HoursToRemove * 3600);
}

#pragma endregion



