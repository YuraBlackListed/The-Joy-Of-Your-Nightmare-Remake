#include "SubSystems/Time/GameTimeSubsystem.h"

#pragma region Life cycle

void UGameTimeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Seconds = 0.0f;
}

void UGameTimeSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UGameTimeSubsystem::Tick(float DeltaTime)
{
	Seconds += DeltaTime * TimeScale * SpeedScale;

	SetMinutes(GetMinutes());
	SetHours(GetHours());
}

TStatId UGameTimeSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGameTimeSubsystem, STATGROUP_Tickables);
}

#pragma endregion

#pragma region Getters

int UGameTimeSubsystem::GetHours() const
{
	return (int)(Seconds / 3600);
}

int UGameTimeSubsystem::GetMinutes() const
{
	return Seconds / 60 - GetHours() * 60;
}

int UGameTimeSubsystem::GetSeconds() const
{
	return (int)Seconds % 60;
}

bool UGameTimeSubsystem::ItsMaxTime() const
{
	return Seconds >= MaxTime;
}

#pragma endregion

#pragma region Setters

void UGameTimeSubsystem::ChangeTimeScale(float NewTimeScale)
{
	TimeScale = NewTimeScale;
}

void UGameTimeSubsystem::AddSeconds(float SecondsToAdd)
{
	Seconds = FMath::Clamp(Seconds + SecondsToAdd, MinTime, MaxTime);
}

void UGameTimeSubsystem::AddMinutes(float MinutesToAdd)
{
	SetMinutes(Minutes + MinutesToAdd * 60);
}

void UGameTimeSubsystem::AddHours(float HoursToAdd)
{
	SetHours(Hours + HoursToAdd * 3600);
}

void UGameTimeSubsystem::RemoveSeconds(float SecondsToRemove)
{
	Seconds = FMath::Clamp(Seconds - SecondsToRemove, MinTime, MaxTime);
}

void UGameTimeSubsystem::RemoveMinutes(float MinutesToRemove)
{
	SetMinutes(Minutes - MinutesToRemove * 60);
}

void UGameTimeSubsystem::RemoveHours(float HoursToRemove)
{
	SetHours(Hours - HoursToRemove * 3600);
}

#pragma endregion

void UGameTimeSubsystem::SetMinutes(int NewMinutes)
{
	if (NewMinutes != Minutes)
	{
		Minutes = NewMinutes;
		OnMinutesChanged.Broadcast();
	}
}

void UGameTimeSubsystem::SetHours(int NewHours)
{
	if (NewHours != Minutes)
	{
		Hours = NewHours;
		OnHoursChanged.Broadcast();
	}
}