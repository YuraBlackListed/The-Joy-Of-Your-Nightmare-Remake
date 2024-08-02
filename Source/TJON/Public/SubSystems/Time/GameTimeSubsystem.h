#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameTimeSubsystem.generated.h"

UCLASS()
class TJON_API UGameTimeSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual void Tick(float DeltaTime) override;

#pragma region Getters

	UFUNCTION(BlueprintPure, Category = "Game Time Subsystem Getters")
	int GetHours() const;

	UFUNCTION(BlueprintPure, Category = "Game Time Subsystem Getters")
	int GetMinutes() const;

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
	const int MinTime = 0.0f;
	const int MaxTime = 7.0f * 3600.0f;

	float TimeScale = 1.0f;
	float TimeInSeconds = 0.0f;
};
