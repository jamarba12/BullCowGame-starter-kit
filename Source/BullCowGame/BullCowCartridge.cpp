// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); //Debug Line
    
    //Welcoming The Player
    PrintLine(TEXT("Welcome to Bull Cow!")); 
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("Type in your guess and press enter to continue... "));
    
    //Prompt Player For Guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{  
    ClearScreen();
    
    //If the Game is not over then do CleanScreen() and SetupGame() the game
    //else Checking PlayerGuess
    
    if(Input == HiddenWord){
        PrintLine(TEXT("You have won!"));
        // bGameOver = true;
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The Hidden Word is %i characters long, try again!"), HiddenWord.Len());
        }
        PrintLine(TEXT("You have Lost!"));
        //bGameOver = true;
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
    HiddenWord = TEXT("loved"); //Set the HiddenWord
    Lives = 4;//Set Lives
    // bGameOver = false;
}