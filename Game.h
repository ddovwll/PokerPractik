#pragma once

#include "Header.h"

void bet(bool first, array<Card, 2>& computer, array<Card, 5>& table, int& playerBank, int& computerBank, int& bank)
{
	Combination computerCombination = combinationCheck(computer, table);
	if (first)
	{
		cout << "������� ���� ������" << endl;
		int bet, computerBet = 0;
		cin >> bet;
		if (playerBank <= bank)
		{
			bet = playerBank;
		}
		else
		{
			while (bet > playerBank && bet < bank)
			{
				cout << "������� ���� ������" << endl;
				cin >> bet;
			}
		}
		playerBank -= bet;
		bank += bet;
		computerBet = static_cast<int>(50 * sqrt(2) * (computerCombination.rank + 1));
		if (computerBet < bank && computerBank > bank)
		{
			computerBet = bank;
		}
		computerBank -= computerBet;
		bank += computerBet;
		cout << endl;
		cout << "������ ���������� " << computerBet << endl;
		cout << "���� ������ " << playerBank << endl;
		cout << "���� " << bank << endl;
	}
	else
	{
		int bet, computerBet = 0;
		computerBet = static_cast<int>(50 * sqrt(2) * (computerCombination.rank + 1));
		if (computerBet < bank && computerBank > bank)
		{
			computerBet = bank;
		}
		if (computerBank < bank)
		{
			computerBet = computerBank;
		}
		computerBank -= computerBet;
		bank += computerBet;
		cout << "������ ���������� " << computerBet << endl;
		cout << "���� " << bank << endl;
		cout << "������� ���� ������ " << endl;
		cin >> bet;
		while (bet > playerBank || bet < bank)
		{
			cout << "������� ���� ������" << endl;
			cin >> bet;
		}
		playerBank -= bet;
		bank += bet;
		cout << "���� ������ " << playerBank << endl;
	}
}

void startGame(array<Card, 52>& deck, int& playerBank, int& computerBank, int& bank);

void winner(array<Card, 2>& player, array<Card, 2>& computer, array<Card, 5>& table, array<Card, 52>& deck, int& playerBank, int& computerBank, int& bank)
{
	Combination playerCombination = combinationCheck(player, table);
	Combination computerCombination = combinationCheck(computer, table);
	if (playerCombination.rank > computerCombination.rank)
	{
		playerBank += bank;
		cout << "����� �������: ";
		printCombination(playerCombination);
	}
	if (playerCombination.rank < computerCombination.rank)
	{
		computerBank += bank;
		cout << "��������� �������: ";
		printCombination(computerCombination);
	}
	if (playerCombination.rank == computerCombination.rank && playerCombination.value > computerCombination.value)
	{
		playerBank += bank;
		cout << "����� �������: ";
		printCombination(playerCombination);
	}
	if (playerCombination.rank == computerCombination.rank && playerCombination.value < computerCombination.value)
	{
		computerBank += bank;
		cout << "��������� �������: ";
		printCombination(computerCombination);
	}
	if (playerCombination.rank == computerCombination.rank && playerCombination.value == computerCombination.value)
	{
		playerBank += bank / 2;
		computerBank += bank / 2;
		cout << "�����: ";
		printCombination(computerCombination);
	}
	bank = 0;
	cout << endl << endl;
	char yn;
	cout << "���������� ����? Y/N" << endl;
	cin >> yn;
	if (yn == 'Y')
		startGame(deck, playerBank, computerBank, bank);
	else return;
}

void startGame(array<Card, 52>& deck, int& playerBank, int& computerBank, int& bank)	//������ ����
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	array<Card, 2>player;
	array<Card, 2>computer;
	array<Card, 5>table;
	int cardCount = 0;
	bool first = rand() % 2;
	char yn, yn2;
	cout << "���� ����������: " << computerBank << " ���� ������: " << playerBank << endl;
	cout << endl;
	if (playerBank == 0 || computerBank == 0)
	{
		cout << "���� ��������" << endl;
		if (playerBank == 0)
		{
			cout << "������� ���������" << endl;
			return;
		}
		else
		{
			cout << "����� �������" << endl;
			return;
		}
	}
	shuffleDeck(deck);
	cardDistribution(deck, player, computer, table);
	Combination computerCombination = combinationCheck(computer, table);
	cout << "�����" << endl;
	for (int i = 0; i < 2; i++)
	{
		printCard(player[i]);
		cout << endl;
	}
	cout << endl;
	cout << "���? Y/N" << endl;
	cin >> yn;
	if (yn == 'Y')
	{
		cout << "������ ����� ����? Y/N" << endl;
		cin >> yn2;
		if (yn2 == 'Y')
		{
			computerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	bet(first, computer, table, playerBank, computerBank, bank);
	if (bank > rand()%4000+6000)
	{
		cout << "��������� ��������, ������ ����� ����? Y/N" << endl;
		cin >> yn;
		if (yn == 'Y')
		{
			playerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	cout << endl;
	cout << "����" << endl;
	for (cardCount = 0; cardCount < 3; cardCount++)
	{
		printCard(table[cardCount]);
		cout << endl;
	}
	cout << endl;
	cout << "���? Y/N" << endl;
	cin >> yn;
	if (yn == 'Y')
	{
		cout << "������ ����� ����? Y/N" << endl;
		cin >> yn2;
		if (yn2 == 'Y')
		{
			computerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	bet(first, computer, table, playerBank, computerBank, bank);
	if (computerCombination.rank < Rankings::pair || bank>rand()%10000+25000)
	{
		cout << "��������� ��������, ������ ����� ����? Y/N" << endl;
		cin >> yn2;
		if (yn2 == 'Y')
		{
			playerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	cout << endl;
	cout << "����" << endl;
	for (cardCount = 0; cardCount < 3; cardCount++)
	{
		printCard(table[cardCount]);
		cout << endl;
	}
	printCard(table[cardCount]);
	cout << endl;
	cout << endl;
	cout << "���? Y/N" << endl;
	cin >> yn;
	if (yn == 'Y')
	{
		cout << "������ ����� ����? Y/N" << endl;
		cin >> yn2;
		if (yn2 == 'Y')
		{
			computerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	bet(first, computer, table, playerBank, computerBank, bank);
	if (computerCombination.rank < Rankings::pair || bank>rand()%20000+40000)
	{
		cout << "��������� ��������, ������ ����� ����? Y/N" << endl;
		cin >> yn2;
		if (yn2 == 'Y')
		{
			playerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	cout << endl;
	cout << "����" << endl;
	for (cardCount = 0; cardCount < 3; cardCount++)
	{
		printCard(table[cardCount]);
		cout << endl;
	}
	printCard(table[cardCount]);
	cout << endl;
	printCard(table[cardCount + 1]);
	cout << endl;
	cout << "���? Y/N" << endl;
	cin >> yn;
	if (yn == 'Y')
	{
		cout << "������ ����� ����? Y/N" << endl;
		cin >> yn2;
		if (yn2 == 'Y')
		{
			computerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	bet(first, computer, table, playerBank, computerBank, bank);
	if (computerCombination.rank < Rankings::pair || bank>rand()%10000+90000)
	{
		cout << "��������� ��������, ������ ����� ����? Y/N" << endl;
		cin >> yn2;
		if (yn2 == 'Y')
		{
			playerBank += bank;
			bank = 0;
			startGame(deck, playerBank, computerBank, bank);
		}
		return;
	}
	cout << endl;
	winner(player, computer, table, deck, playerBank, computerBank, bank);
}
