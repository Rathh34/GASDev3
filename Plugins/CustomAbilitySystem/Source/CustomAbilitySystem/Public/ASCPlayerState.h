// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "ASCPlayerState.generated.h"

class UCustomAbilitySystemComponent;
class UASCAttributeSet;
/**
 * 
 */
UCLASS()
class CUSTOMABILITYSYSTEM_API AASCPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:	
	AASCPlayerState();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<UCustomAbilitySystemComponent> CustomAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<UASCAttributeSet> PlayerAttributes;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
