#pragma once

#include <iostream>
#include <array>

using namespace std;

enum Suits	//������������� ������ ����
{
	clubs,
	diamonds,
	hearts,
	spades,
	endOfSuits
};

enum Values //������������� ���������� ����
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

enum Rankings	//������������� ��������� ����������
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

struct Card	//���������, ���������� ����� � ����������� �����
{
	Suits suit;
	Values value;
};

struct Combination	//��������� ��������� ����������
{
	Rankings rank;
	Values value;
};

void printCard(const Card& card)	//����� ����� �� �����
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
	case clubs: cout << "������"; break;
	case diamonds: cout << "����"; break;
	case hearts: cout << "�����"; break;
	case spades: cout << "����"; break;
	}
}

void printCombination(const Combination& combination)
{
	switch (combination.rank)
	{
	case highCard:cout << "������� ����� "; break;
	case Rankings::pair:cout << "���� "; break;
	case twoPair:cout << "��� ���� "; break;
	case Rankings::set:cout << "��� "; break;
	case street:cout << "����� "; break;
	case Rankings::flush:cout << "���� "; break;
	case fullHouse:cout << "���� ���� "; break;
	case square:cout << "���� "; break;
	case streetFlush:cout << "����� ���� "; break;
	case flushRoyal:cout << "���� ����� "; break;
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

void printDeck(const array<Card, 52>& deck)	//����� ������ �� �����(������������ ��� �������)
{
	for (const auto& card : deck)
	{
		printCard(card);
		cout << endl;
	}
}


void swapCard(Card& a, Card& b)	//������ ����� �������
{
	Card temp = a;
	a = b;
	b = temp;
}

void shuffleDeck(array<Card, 52>& deck)	//��������� ������
{
	for (int i = 0; i < 52; i++)
	{
		swapCard(deck[i], deck[rand() % 52]);
	}
}

void cardDistribution(array<Card, 52>& deck, array<Card, 2>& player, array<Card, 2>& computer, array<Card, 5>& table)	//������� ����
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