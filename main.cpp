#include <iostream>
#include <string>
#include "Fbullcowgame.h"
#pragma once


using FText = std::string;
using int32 = int;

void Printintro();
FText Getguess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main()
{
	bool bPlayAgain = false;
	do {
		Printintro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		} while (bPlayAgain);
		system("Pause");
		return 0;
} 
void Printintro()
{
	// into to game 
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram, I am thinking of?" << std::endl;
}

FText Getguess()
{
	FText Guess = "";
	EWordStatus Status = EWordStatus::Invaild_status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry(); 
		//get a guess from player 
		std::cout << std::endl;
		std::cout << "Try " << CurrentTry << " Of " << BCGame.GetMaxTires();
		std::cout << " Enter you guess: ";
		getline(std::cin, Guess);
		 Status = BCGame.CheckGuess(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Length:
			std::cout << "Plese enter a " << BCGame.GetHiddenWordLength() << " letter word" << std::endl;
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Please enter a word without repreating letters" << std::endl;
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Plese enter letters in lowercase" << std::endl;
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EWordStatus::OK);
	return Guess;
}

void PlayGame()
{
	BCGame.reset();
	int32 MaxTries = BCGame.GetMaxTires();
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = Getguess();
		FBullCowCount BullCowCount = BCGame.SumbmitGuess(Guess);
		std::cout << "Bulls = "<< BullCowCount.Bulls << " Cows = "<< BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
	PrintGameSummary();
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congratz you have won!!!" << std::endl;
	}
	else
	{
		std::cout << "You lose. Better Luck next time." << std::endl;
	}
}
