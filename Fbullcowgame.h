#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus 
{
	Invaild_status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase

};

class FBullCowGame
{
public:
	FBullCowGame(); // construtor 

	void reset();
	int32 GetMaxTires() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuess(FString) const;
	FBullCowCount SumbmitGuess(FString);
private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bIsGameWon;
	
	bool Isisogram(FString) const;
	bool Islowercase(FString) const;

};