// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "ASCAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMABILITYSYSTEM_API UASCAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	UASCAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CustomAbilitySystemComponent, Replicated)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UASCAttributeSet, Health);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CustomAbilitySystemComponent, Replicated)
	FGameplayAttributeData HealthMax;
	ATTRIBUTE_ACCESSORS_BASIC(UASCAttributeSet, HealthMax);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CustomAbilitySystemComponent, Replicated)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS_BASIC(UASCAttributeSet, Mana);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CustomAbilitySystemComponent, Replicated)
	FGameplayAttributeData ManaMax;
	ATTRIBUTE_ACCESSORS_BASIC(UASCAttributeSet, ManaMax);
	
	UPROPERTY(VisibleAnywhere)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS_BASIC(UASCAttributeSet, Damage);
	
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
