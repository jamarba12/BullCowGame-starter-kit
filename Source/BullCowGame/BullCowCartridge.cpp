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
        ProcessGuess(Input);    
    }
}

void UBullCowCartridge::SetupGame()
{
    //Welcoming The Player
    PrintLine(TEXT("Welcome to Bull Cow!"));
    
    HiddenWord = TEXT("cakes"); //Set the HiddenWord
    Lives = HiddenWord.Len();//Set Lives 
    bGameOver = false;
     
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue... "));//Prompt Player For Guess

    // const TCHAR HW[] = TEXT("plums");
    // PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]); // print "c"
    // PrintLine(TEXT("The 4th character of HW is: %c"), HW[3]); //prints "m"
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again. "));
}

void UBullCowCartridge::ProcessGuess(FString Guess){
    if(Guess == HiddenWord){
        PrintLine(TEXT("You have won!"));
        EndGame();
        return;
    }
    
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
        return;
    }
    
    //Check if Isogram
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }
    //Remove Life
    PrintLine(TEXT("Lost a life"));
    --Lives;

    if(Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;           
    }
    
    //Show the player Bulls and Cows
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString Word) const
{
    // For each letter.
    // Start at element [0].
    // Compare against the next letter.
    // Until We reach [Word.Len() -1]
    // if any are the same return false 
    
    return true;
}