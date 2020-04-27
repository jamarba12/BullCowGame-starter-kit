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
            PrintLine(TEXT("Lost a life"));
            PrintLine(TEXT("%i"), --Lives);
            if(Lives > 0){
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
                }   
            }
            else
            {
                PrintLine(TEXT("You have no lives left!"));
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
    Lives = HiddenWord.Len();//Set Lives 
    bGameOver = false;
     
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue... "));//Prompt Player For Guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again. "));
}