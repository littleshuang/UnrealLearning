// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HowToUMGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HOWTOUMG_API AHowToUMGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    /** 在游戏开始时调用。 */
    virtual void BeginPlay() override;
    
    /** 移除当前菜单控件并且如果可能，从指定类中创建新控件。 */
    UFUNCTION(BlueprintCallable, Category = "UMG Game")
    void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
    
    /** 调用GVoice服务 */
    UFUNCTION(BlueprintCallable, Category = "UMG Game")
    FString TestGVoice();
    
protected:
    /** 在游戏开始时我们将作为菜单使用的控件类。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
    TSubclassOf<UUserWidget> StartingWidgetClass;
    
    /** 用作为菜单的控件实例。 */
    UPROPERTY()
    UUserWidget* CurrentWidget;
};
