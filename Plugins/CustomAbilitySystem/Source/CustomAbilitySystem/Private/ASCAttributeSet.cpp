// Fill out your copyright notice in the Description page of Project Settings.


#include "ASCAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UASCAttributeSet::UASCAttributeSet()
{
	InitHealth(100);
	InitHealthMax(100);
	InitMana(50);
	InitManaMax(0);
	InitDamage(0);
}

void UASCAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UASCAttributeSet, Health);
	DOREPLIFETIME(UASCAttributeSet, HealthMax);
	DOREPLIFETIME(UASCAttributeSet, Mana);
	DOREPLIFETIME(UASCAttributeSet, ManaMax);
}

void UASCAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		const float CurrentDamage = GetDamage();
		const float OldHealthValue = GetHealth();
		const float MaxHealthValue = GetHealthMax();
		const float NewHealthValue = FMath::Clamp(OldHealthValue- CurrentDamage, 0, MaxHealthValue);
		
		if (OldHealthValue != NewHealthValue)
		{
			SetHealth(NewHealthValue);
		}
		SetDamage(0);
	}
}
