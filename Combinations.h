#pragma once

#include <vector>
#include "Header.h"

Combination isHighcard(array<Card, 2>& hand, array<Card, 5>& table)	//возвращает значене старшей карты
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	if (hand[0].value > hand[1].value)
	{
		combination.rank = highCard;
		combination.value = hand[0].value;
		return combination;
	}
	else if (hand[0].value < hand[1].value)
	{
		combination.rank = highCard;
		combination.value = hand[1].value;
		return combination;
	}
	else
		return combination;
}

Combination isPair(array<Card, 2>& hand, array<Card, 5>& table)	//возвращает значение пары
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	int counter = 1;
	if (hand[0].value == hand[1].value)
		counter++;
	for (int i = 0; i < 5; i++)
	{
		if (hand[0].value == table[i].value || hand[1].value == table[i].value)
			counter++;
	}
	if (counter == 2)
	{
		if (hand[0].value == hand[1].value)
		{
			combination.value = hand[0].value;
			combination.rank = Rankings::pair;
			return combination;
		}
		for (int i = 0; i < 5; i++)
		{
			if (hand[0].value == table[i].value)
			{
				combination.value = hand[0].value;
				combination.rank = Rankings::pair;
				return combination;
			}
		}
		combination.value = hand[1].value;
		combination.rank = Rankings::pair;
		return combination;
	}
	return combination;
}

Combination isSet(array<Card, 2>& hand, array<Card, 5>& table)	//возвращает значение сета
{
	Combination combination, combinationMax;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	combinationMax.value = two;
	int counter1 = 1, counter2 = 1, counter3 = 1;
	if (hand[0].value == hand[1].value)
	{
		counter1++;
		for (int i = 0; i < 5; i++)
		{
			if (hand[0].value == table[i].value)
				counter1++;
		}
	}
	if (counter1 == 3)
	{
		if (hand[0].value >= combinationMax.value)
			combinationMax.value = hand[0].value;
		combination.rank = set;
	}
	if (hand[0].value != hand[1].value)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[0].value == table[i].value)
			{
				counter2++;
			}
		}
	}
	if (counter2 == 3)
	{
		if (hand[0].value >= combinationMax.value)
			combinationMax.value = hand[0].value;
		combination.rank = set;
	}
	if (hand[0].value != hand[1].value)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[1].value == table[i].value)
			{
				counter3++;
			}
		}
	}
	if (counter3 == 3)
	{
		if (hand[1].value >= combinationMax.value)
			combinationMax.value = hand[1].value;
		combination.rank = set;
	}
	combination.value = combinationMax.value;
	return combination;
}

Combination isSquare(array<Card, 2>& hand, array<Card, 5>& table)
{
	Combination combination, combinationMax;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	combinationMax.value = two;
	int counter1 = 1, counter2 = 1, counter3 = 1;
	if (hand[0].value == hand[1].value)
	{
		counter1++;
		for (int i = 0; i < 5; i++)
		{
			if (hand[0].value == table[i].value)
				counter1++;
		}
	}
	if (counter1 == 4)
	{
		if (hand[0].value >= combinationMax.value)
			combinationMax.value = hand[0].value;
		combination.rank = set;
	}
	if (hand[0].value != hand[1].value)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[0].value == table[i].value)
			{
				counter2++;
			}
		}
	}
	if (counter2 == 4)
	{
		if (hand[0].value >= combinationMax.value)
			combinationMax.value = hand[0].value;
		combination.rank = set;
	}
	if (hand[0].value != hand[1].value)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[1].value == table[i].value)
			{
				counter3++;
			}
		}
	}
	if (counter3 == 4)
	{
		if (hand[1].value >= combinationMax.value)
			combinationMax.value = hand[1].value;
		combination.rank = set;
	}
	combination.value = combinationMax.value;
	return combination;
}

Combination isTwoPair(array<Card, 2>& hand, array<Card, 5>& table) //возвращает значение двух пар
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	if (hand[0].value == hand[1].value)
		return combination;
	int card0 = 1, card1 = 1;
	for (int i = 0; i < 5; i++)
	{
		if (hand[0].value == table[i].value)
			card0++;
		if (hand[1].value == table[i].value)
			card1++;
	}
	if (card0 == 2 && card1 == 2)
	{
		combination.rank = twoPair;
		combination.value = max(hand[0].value, hand[1].value);
		return combination;
	}
	return combination;
}

Combination isStreet(array<Card, 2>& hand, array<Card, 5>& table) //возвращает занчение двух пар
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	vector<Card>sort;
	int difference = 0;
	for (int i = 0; i < 2; i++)
	{
		sort.push_back(hand[i]);
	}
	for (int i = 2; i < 7; i++)
	{
		sort.push_back(table[i - 2]);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (sort[j].value > sort[i].value)
				swap(sort[j], sort[i]);
		}
	}
	for (int i = 0; i < sort.size() - 1; i++)
	{
		if (sort[i].value == sort[i + 1].value && (sort[i + 1].suit != hand[0].suit || sort[i + 1].suit != hand[1].suit))
		{
			sort.erase(sort.end() - sort.size() + 1 + i);
			i--;
		}
		else if (sort[i].value == sort[i + 1].value)
		{
			sort.erase(sort.end() - sort.size() + i);
			i--;
		}
	}
	for (int i = sort.size() - 1; i >= 4; i--)
	{
		bool flag = 0;
		int difference = 0;
		for (int j = i; j > i - 4; j--)
		{
			difference = sort[j].value - sort[j - 1].value;
			if ((sort[j].value == hand[0].value) || (sort[j].value == hand[1].value))
				flag = 1;
			if (difference != 1)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if (flag)
		{
			combination.rank = street;
			combination.value = sort[i].value;
			return combination;
		}
	}
	return combination;
}

Combination isFlush(array<Card, 2>& hand, array<Card, 5>& table)
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = two;
	for (int i = 0; i < 2; i++)
	{
		int counter = 1;
		for (int j = 0; j < 5; j++)
		{
			if (hand[i].suit == table[j].suit)
			{
				counter++;
				if (table[j].value > combination.value)
					combination.value = table[j].value;
			}
		}
		if (hand[0].suit == hand[1].suit && counter >= 4)
		{
			combination.rank = Rankings::flush;
			if (hand[0].value > combination.value)
				combination.value = hand[0].value;
			else if (hand[1].value > combination.value)
				combination.value = hand[1].value;
			return combination;
		}
		if (counter >= 5)
		{
			if (hand[0].value > combination.value)
				combination.value = hand[0].value;
			else if (hand[1].value > combination.value)
				combination.value = hand[1].value;
			combination.rank = Rankings::flush;
			return combination;
		}
	}
	return combination;
}

Combination isFullHouse(array<Card, 2>& hand, array<Card, 5>& table)
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	if (hand[0].value == hand[1].value)
		return combination;
	int counter0 = 1, counter1 = 1;
	for (int i = 0; i < 5; i++)
	{
		if (hand[0].value == table[i].value)
			counter0++;
		if (hand[1].value == table[i].value)
			counter1++;
	}
	if ((counter0 >= 2 && counter1 >= 3) || (counter0 >= 3 && counter1 >= 2))
	{
		combination.rank = fullHouse;
		combination.value = max(hand[0].value, hand[1].value);
		return combination;
	}
	return combination;
}

Combination isFlushroyale(array<Card, 2>& hand, array<Card, 5>& table)
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	vector<Card>sort;
	for (int i = 0; i < 2; i++)
	{
		sort.push_back(hand[i]);
	}
	for (int i = 2; i < 7; i++)
	{
		sort.push_back(table[i - 2]);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (sort[j].value > sort[i].value)
				swap(sort[j], sort[i]);
		}
	}
	for (int i = 0; i < sort.size() - 1; i++)
	{
		if (sort[i].value == sort[i + 1].value)
		{
			if (sort[i].suit == sort[sort.size() - 1].suit)
			{
				sort.erase(sort.end() - sort.size() + 1 + i);
				i--;
			}
		}
	}
	Card Ace;
	Ace.value = ace;
	for (int i = sort.size() - 1; i >= 4; i--)
	{
		if (sort[i].value != ace)
			continue;
		bool flag = 1, flag2 = 0;
		int difference = 0;
		for (int j = i; j > i - 4; j--)
		{
			difference += sort[j].value - sort[j - 1].value;
			if (sort[j].suit != sort[j - 1].suit)
			{
				flag = 0;
				break;
			}
			if ((sort[j].value == hand[0].value && sort[j].suit == hand[0].suit) || (sort[j].value == hand[1].value && sort[j].suit == hand[1].suit))
				flag2 = 1;
		}
		if (flag && flag2 && difference == 4)
		{
			combination.rank = flushRoyal;
			combination.value = ace;
			return combination;
		}
	}
	return combination;
}

Combination isStreetFlush(array<Card, 2>& hand, array<Card, 5>& table)
{
	Combination combination;
	combination.rank = endOfRankings;
	combination.value = endOfValues;
	vector<Card>sort;
	int difference = 0;
	for (int i = 0; i < 2; i++)
	{
		sort.push_back(hand[i]);
	}
	for (int i = 2; i < 7; i++)
	{
		sort.push_back(table[i - 2]);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (sort[j].value > sort[i].value)
				swap(sort[j], sort[i]);
		}
	}
	for (int i = 0; i < sort.size() - 1; i++)
	{
		if (sort[i].value == sort[i + 1].value && (sort[i + 1].suit != hand[0].suit || sort[i + 1].suit != hand[1].suit))
		{
			sort.erase(sort.end() - sort.size() + 1 + i);
			i--;
		}
		else if (sort[i].value == sort[i + 1].value)
		{
			sort.erase(sort.end() - sort.size() + i);
			i--;
		}
	}
	for (int i = sort.size() - 1; i >= 4; i--)
	{
		bool flag = 0;
		int difference = 0;
		for (int j = i; j > i - 4; j--)
		{
			difference = sort[j].value - sort[j - 1].value;
			if (sort[j].suit != sort[j - 1].suit)
			{
				flag = 0;
				break;
			}
			if ((sort[j].value == hand[0].value) || (sort[j].value == hand[1].value))
				flag = 1;
			if (difference != 1)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if (flag)
		{
			combination.rank = streetFlush;
			combination.value = sort[i].value;
			return combination;
		}
	}
	return combination;
}

Combination combinationCheck(array<Card, 2>& hand, array<Card, 5>& table) //функция вызова проверки комбинаций и поределение победителя
{
	Combination combination, combinationMax;
	combinationMax.rank = highCard;
	combinationMax.value = two;

	combination = isHighcard(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == highCard)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isPair(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == Rankings::pair)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isTwoPair(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == twoPair)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isSet(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == set)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isStreet(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == street)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isFlush(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == Rankings::flush)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isFullHouse(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == fullHouse)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isSquare(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == square)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isStreetFlush(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == streetFlush)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	combination = isFlushroyale(hand, table);
	if (combination.rank >= combinationMax.rank && combination.rank == flushRoyal)
	{
		combinationMax.value = combination.value;
		combinationMax.rank = combination.rank;
	}
	return combinationMax;
}