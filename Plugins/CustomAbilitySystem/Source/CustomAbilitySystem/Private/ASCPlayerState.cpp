// Fill out your copyright notice in the Description page of Project Settings.


#include "ASCPlayerState.h"
#include "CustomAbilitySystemComponent.h"
#include "ASCAttributeSet.h"

AASCPlayerState::AASCPlayerState()
{
	CustomAbilitySystemComponent = CreateDefaultSubobject<UCustomAbilitySystemComponent>(TEXT("CustomAbilitySystemComponent"));
	CustomAbilitySystemComponent->SetIsReplicated(true);
	CustomAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	SetNetUpdateFrequency(100);
	PlayerAttributes = CreateDefaultSubobject<UASCAttributeSet>(TEXT("PlayerAttributes"));
}

UAbilitySystemComponent* AASCPlayerState::GetAbilitySystemComponent() const
{
	return CustomAbilitySystemComponent;
}
