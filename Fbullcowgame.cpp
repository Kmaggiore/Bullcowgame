#include "Fbullcowgame.h"
#include <map>
#define TMap std::map
#pragma once

using int32 = int;


int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }
FBullCowGame::FBullCowGame(){reset();}
int FBullCowGame::GetMaxTires() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,5},{4,7},{5,10},{6,15} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}
void FBullCowGame::reset()
{

	const FString Hidden_Word = "donkey";
	MyHiddenWord = Hidden_Word;
	MyCurrentTry = 1;
	bIsGameWon = false;
	return;
}

EWordStatus FBullCowGame::CheckGuess(FString Guess) const
{
	if (!Isisogram(Guess))// if guess is not isogram 
		{
			return EWordStatus::Not_Isogram;
		}
	else if (!Islowercase(Guess))// if guess is not lower case 
		{
			return EWordStatus::Not_Lowercase;
		}
	else if (Guess.length() != GetHiddenWordLength())// if guess length is wrong
		{
			return  EWordStatus::Wrong_Length;
		}
	else
		{
			return EWordStatus::OK;
		}
}

FBullCowCount FBullCowGame::SumbmitGuess(FString Guess)
{
	MyCurrentTry++;
	int32 HiddenWordLegth = MyHiddenWord.length();
	FBullCowCount BullCowCount;
	for (int32 MHWChar = 0; MHWChar < HiddenWordLegth; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLegth; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLegth)
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::Isisogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;
	for (auto Letter: Word)
	{
		Letter = tolower(Letter); // handle mixed case 
		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}
	return true;
}

bool FBullCowGame::Islowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) { return false; }
	
	}
	return true;
}
