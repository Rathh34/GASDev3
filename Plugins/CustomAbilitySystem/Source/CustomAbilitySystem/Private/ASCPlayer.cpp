// Fill out your copyright notice in the Description page of Project Settings.


#include "ASCPlayer.h"
#include "ASCPlayerState.h"
#include "CustomAbilitySystemComponent.h"

// Sets default values
AASCPlayer::AASCPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AASCPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AASCPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AASCPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


//SERVER
void AASCPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	TObjectPtr<AASCPlayerState> PS = GetPlayerState<AASCPlayerState>();
	if (PS)
	{
		CustomAbilitySystemComponent = Cast<UCustomAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS,this);
	}
}

UAbilitySystemComponent* AASCPlayer::GetAbilitySystemComponent() const
{
	if (const AASCPlayerState* PS = GetPlayerState<AASCPlayerState>())
	{
		return PS->GetAbilitySystemComponent();
	}
	return nullptr;
}

//CLIENT
void AASCPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	TObjectPtr<AASCPlayerState> PS = GetPlayerState<AASCPlayerState>();
	if (PS)
	{
		CustomAbilitySystemComponent = Cast<UCustomAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS,this);
	}
}
