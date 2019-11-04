#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	// welcome message to terminal
		std::cout << "\n\nYou are an engineer in a colony spaceship hacking a level " << Difficulty << " locked door to the medical bay to\n";
		std::cout << "retrieve first aid for a life-threatening injury. If you do not break the code, then you will die a bloody death.\n";
		std::cout << "Your engineer apparatus links to the door terminal where the following information appears...\n\n";

}

void PrintLevelPass(int Difficulty)
{
	std::cout << "\n\nThe door terminal security increased to level " << Difficulty << ", and the following information appears...\n";
}

bool PlayGame(int Difficulty)
{
	if (Difficulty == 1)
	{
		PrintIntroduction(Difficulty);
	}
	else
	{
		PrintLevelPass(Difficulty);
	}

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << "+ There are 3 numbers in the code";
	std::cout << "\n+ The codes add up to: " << CodeSum;
	std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

	// store player's guesses
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;
	std::cout << "You entered: " << GuessA << GuessB << GuessC;

	int GuessSum = GuessA + GuessB + GuessC;

	int GuessProduct = GuessA * GuessB * GuessC;

	// check if the player's guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		return true;
	}
	else
	{
		std::cout << "\nCareful another invalid code will lock the door permanently...";
		return false;
	}
}

int main()
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	int const MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) // loop the game until all levels are completed
	{		
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); //clears any errors
		std::cin.ignore(); //discards the buffers

		if (bLevelComplete)
		{
				++LevelDifficulty;
		}		  
	}
	std::cout << "The medbay door unlocked and opened.";

	return 0;
}