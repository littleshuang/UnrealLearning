// Fill out your copyright notice in the Description page of Project Settings.

#include "HowToUMGGameModeBase.h"
#include "HowToUMG.h"
#include "IGCloudVoiceEngine.h"

void AHowToUMGGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
}

void AHowToUMGGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

FString AHowToUMGGameModeBase::TestGVoice(){
    if(GCloud::GVoice::GetVoiceEngine() != nullptr){
        return "success";
    }else{
        return "fail";
    }
}


