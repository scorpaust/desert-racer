// Fill out your copyright notice in the Description page of Project Settings.


#include "DesertRacerGameMode.h"
#include "Kismet/GameplayStatics.h"

void ADesertRacerGameMode::ResetLevel(float IsWin)
{
	float ResetTime = LoseResetTime;

	if (IsWin)
	{
		ResetTime = WinResetTime;
	}

	GetWorldTimerManager().SetTimer(ResetGameTimer, this, &ADesertRacerGameMode::OnResetGameTimerTimeout, 1.f, false, ResetTime);
}

void ADesertRacerGameMode::OnResetGameTimerTimeout()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainLevel"));
}
