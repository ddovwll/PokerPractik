#pragma once

#include <iostream>
#include <array>

using namespace std;

enum Suits	//перечислитель мастей карт
{
	clubs,
	diamonds,
	hearts,
	spades,
	endOfSuits
};

enum Values //перечислитель достоинств карт
{
	two = 1,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,
	endOfValues
};

enum Rankings	//перечислитель карточных комбинаций
{
	highCard,
	pair,
	twoPair,
	set,
	street,
	flush,
	fullHouse,
	square,
	streetFlush,
	flushRoyal,
	endOfRankings
};

struct Card	//структура, содержащая масть и достоинство карты
{
	Suits suit;
	Values value;
};

struct Combination	//структура карточных комбинаций
{
	Rankings rank;
	Values value;
};

void printCard(const Card& card)	//вывод карты на экран
{
	switch (card.value)
	{
	case two: cout << "2 "; break;
	case three: cout << "3 "; break;
	case four: cout << "4 "; break;
	case five: cout << "5 "; break;
	case six: cout << "6 "; break;
	case seven: cout << "7 "; break;
	case eight: cout << "8 "; break;
	case nine: cout << "9 "; break;
	case ten: cout << "10 "; break;
	case jack: cout << "J "; break;
	case queen: cout << "Q "; break;
	case king: cout << "K "; break;
	case ace: cout << "A "; break;
	}
	switch (card.suit)
	{
	case clubs: cout << "Крести"; break;
	case diamonds: cout << "Буби"; break;
	case hearts: cout << "Черви"; break;
	case spades: cout << "Пики"; break;
	}
}

void printCombination(const Combination& combination)
{
	switch (combination.rank)
	{
	case highCard:cout << "старшая карта "; break;
	case Rankings::pair:cout << "пара "; break;
	case twoPair:cout << "две пары "; break;
	case Rankings::set:cout << "сет "; break;
	case street:cout << "стрит "; break;
	case Rankings::flush:cout << "флеш "; break;
	case fullHouse:cout << "фулл хаус "; break;
	case square:cout << "каре "; break;
	case streetFlush:cout << "стрит флеш "; break;
	case flushRoyal:cout << "флеш рояль "; break;
	}
	switch (combination.value)
	{
	case two: cout << "2"; break;
	case three: cout << "3"; break;
	case four: cout << "4"; break;
	case five: cout << "5"; break;
	case six: cout << "6"; break;
	case seven: cout << "7"; break;
	case eight: cout << "8"; break;
	case nine: cout << "9"; break;
	case ten: cout << "10"; break;
	case jack: cout << "J"; break;
	case queen: cout << "Q"; break;
	case king: cout << "K"; break;
	case ace: cout << "A"; break;
	}
}

void printDeck(const array<Card, 52>& deck)	//вывод колоды на экран(используется для отладки)
{
	for (const auto& card : deck)
	{
		printCard(card);
		cout << endl;
	}
}


void swapCard(Card& a, Card& b)	//меняет карты местами
{
	Card temp = a;
	a = b;
	b = temp;
}

void shuffleDeck(array<Card, 52>& deck)	//перемешка колоды
{
	for (int i = 0; i < 52; i++)
	{
		swapCard(deck[i], deck[rand() % 52]);
	}
}

void cardDistribution(array<Card, 52>& deck, array<Card, 2>& player, array<Card, 2>& computer, array<Card, 5>& table)	//раздача карт
{
	int counter = 0;
	for (int i = 0; i < 2; i++)
	{
		player[i] = deck[counter];
		counter++;
		computer[i] = deck[counter];
		counter++;
	}
	for (int i = 0; i < 5; i++)
	{
		table[i] = deck[counter];
		counter++;
	}
}