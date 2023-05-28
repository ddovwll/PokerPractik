#include <stdlib.h>
#include <vector>
#include <iostream>
#include <array>
#include "Header.h"


int main()
{
	srand(time(NULL));
	array<Card, 52> deck;
	int counter = 0;
	for (int i = clubs; i < endOfSuits; ++i)	//создание колоды карт
	{
		for (int j = two - 1; j < endOfValues - 1; ++j)
		{
			deck[counter].suit = static_cast<Suits>(i);
			deck[counter].value = static_cast<Values>(j + 1);
			++counter;
		}
	}
	int playerBank = 100000, computerBank = 100000, bank = 0;
	startGame(deck, playerBank, computerBank, bank);
	return 0;
}