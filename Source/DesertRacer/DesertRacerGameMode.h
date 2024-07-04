// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/TimerHandle.h"
#include "DesertRacerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DESERTRACER_API ADesertRacerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoseResetTime = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WinResetTime = 3.f;

	FTimerHandle ResetGameTimer;

	void ResetLevel(float IsWin);

	void OnResetGameTimerTimeout();
	
};
