#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct card
{
	int face;
	char suit;
};

typedef struct card Cards;

void Create(Cards[]);
void Shuffle(Cards[], int);
void Deal(Cards[], Cards[], Cards[]);
void Sort(Cards[], int);
void ShowaCard(Cards);
void ShowCards(Cards[], int);

int main()
{
	Cards cards[24], p[5], c[5];
	Create(cards);
	Shuffle(cards, 24);
	Deal(cards, p, c);
	Sort(p, 5);
	Sort(c, 5);
	printf("玩家的牌：");
	ShowCards(p, 5);
	printf("\n電腦的牌：");
	ShowCards(c, 5);
	printf("\n");
	system("PAUSE");
	return 0;
}

void Create(Cards d[24])
{
	int i;
	for (i = 0; i < 24; i++)
	{
		d[i].face = 9 + i % 6;
		d[i].suit = 3 + i / 6;
	}
	return;
}

void Shuffle(Cards d[], int size)
{
	int i, j;
	Cards temp;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		j = rand() % 24;
		temp.face = d[i].face;
		temp.suit = d[i].suit;
		d[i].face = d[j].face;
		d[i].suit = d[j].suit;
		d[j].face = temp.face;
		d[j].suit = temp.suit;
	}
	return;
}

void Deal(Cards d[24], Cards p[], Cards c[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			p[i / 2] = d[i];
		else
			c[i / 2] = d[i];
	}
	return;
}

void Sort(Cards c[], int size)
{
	Cards temp;
	int i, j, suitA, suitB;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			switch (c[j].suit)
			{
			case '\6':
				suitA = 3;
				break;
			case '\3':
				suitA = 2;
				break;
			case '\4':
				suitA = 1;
				break;
			case '\5':
				suitA = 0;
				break;
			}
			switch (c[j + 1].suit)
			{
			case '\6':
				suitB = 3;
				break;
			case '\3':
				suitB = 2;
				break;
			case '\4':
				suitB = 1;
				break;
			case '\5':
				suitB = 0;
				break;
			}
			if ((c[j].face > c[j + 1].face) || ((c[j].face == c[j + 1].face) && (suitA > suitB)))
			{
				temp.face = c[j].face;
				temp.suit = c[j].suit;
				c[j].face = c[j + 1].face;
				c[j].suit = c[j + 1].suit;
				c[j + 1].face = temp.face;
				c[j + 1].suit = temp.suit;
			}
		}
	}
}

void ShowaCard(Cards a)
{
	switch (a.face)
	{
	case 9:
	case 10:
		printf("%d", a.face);
		break;
	case 11:
		printf("J");
		break;
	case 12:
		printf("Q");
		break;
	case 13:
		printf("K");
		break;
	case 14:
		printf("A");
		break;
	}
	printf("%c, ", a.suit);
	return;
}

void ShowCards(Cards c[], int size)
{
	int k;
	for (k = 0; k < size; k++)
	{
		ShowaCard(c[k]);
	}
	return;
}