#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameTimeSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameTimeEvent);

UCLASS()
class TJON_API UGameTimeSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FGameTimeEvent OnMinutesChanged;
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FGameTimeEvent OnHoursChanged;

#pragma region Getters

	UFUNCTION(BlueprintPure, Category = "Game Time Subsystem Getters")
	int GetHours() const;

	UFUNCTION(BlueprintPure, Category = "Game Time Subsystem Getters")
	int GetMinutes() const;

	UFUNCTION(BlueprintPure, Category = "Game Time Subsystem Getters")
	int GetSeconds() const;

	UFUNCTION(BlueprintPure, Category = "Game Time Subsystem Getters")
	bool ItsMaxTime() const;

#pragma endregion

#pragma region Setters

	UFUNCTION(BlueprintCallable, Category = "Game Time Subsystem Setters")
	void ChangeTimeScale(float NewTimeScale);

	UFUNCTION(BlueprintCallable, Category = "Game Time Subsystem Setters")
	void AddSeconds(float SecondsToAdd);

	UFUNCTION(BlueprintCallable, Category = "Game Time Subsystem Setters")
	void AddMinutes(float MinutesToAdd);

	UFUNCTION(BlueprintCallable, Category = "Game Time Subsystem Setters")
	void AddHours(float HoursToAdd);

	UFUNCTION(BlueprintCallable, Category = "Game Time Subsystem Setters")
	void RemoveSeconds(float SecondsToRemove);

	UFUNCTION(BlueprintCallable, Category = "Game Time Subsystem Setters")
	void RemoveMinutes(float MinutesToRemove);

	UFUNCTION(BlueprintCallable, Category = "Game Time Subsystem Setters")
	void RemoveHours(float HoursToRemove);

#pragma endregion

private:
	const int MinTime = 0;
	const int MaxTime = 7 * 3600;
	const float SpeedScale = 60.0f;

	int Minutes = 0;
	int Hours = 0;

	float TimeScale = 1.0f;
	float Seconds = 0.0f;

	void SetMinutes(int NewMinutes);
	void SetHours(int NewHours);
};
