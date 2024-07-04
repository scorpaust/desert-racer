// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "DesertRacerGameMode.h"
#include "Sound/SoundBase.h"
#include "Obstacle.generated.h"


UCLASS()
class DESERTRACER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	ADesertRacerGameMode* DesertRacerGameMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* ObstacleSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFinishLine = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool  FromSweep, const FHitResult& SweepResult);

};
