// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); //Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{  
    if(bGameOver){
        ClearScreen();
        SetupGame();
    }
    else //Checking PlayGuess
    {
        if(Input == HiddenWord){
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The Hidden Word is %i characters long. \nYou have lost!"), HiddenWord.Len());
                EndGame();
            }
        }
    }
    
    
    //Check if Isogram
    //Prompt To Guess Again
    //Check Right Number of Characters
    //Prompt To Guess Again
    
    //Remove Life

    //Check If Lives > 0
    //If Yes GuessAgain
    // Show Lives Left
    //If No Show GameOver and HiddenWord?
    //Prompt To Play Again
    //Check User Input
    //PlayAgain Or Quit

}

void UBullCowCartridge::SetupGame()
{
    //Welcoming The Player
    PrintLine(TEXT("Welcome to Bull Cow!"));
    
    HiddenWord = TEXT("loved"); //Set the HiddenWord
    Lives = 4;//Set Lives 
    bGameOver = false;
     
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("Type in your guess. \n Press enter to continue... "));//Prompt Player For Guess
    
    
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again. "));
}