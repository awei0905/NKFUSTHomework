#ifdef __GG__


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

void Shuffle(Cards[]);
void Deal(Cards[], Cards[], Cards[]);
void Sort(Cards[]);
void ShowaCard(Cards);
void ShowCards(Cards[], Cards[]);
char *faceCharacter(int);

int main()
{
	/*const char accountAndPassword[] = "u0451054";
	char enteredAccountAndPassword[100] = {0};
	printf("請輸入帳號：");
	scanf("%s", enteredAccountAndPassword);
	if (strcmp(accountAndPassword, enteredAccountAndPassword))
	{
	printf("帳號錯誤\n");
	system("pause");
	return 0;
	}
	printf("請輸入密碼：");
	scanf("%s", enteredAccountAndPassword);
	if (strcmp(accountAndPassword, enteredAccountAndPassword))
	{
	printf("密碼錯誤\n");
	system("pause");
	return 0;
	}*/
	Cards deck[24], player[5], computer[5];

	Shuffle(deck);
	Deal(deck, player, computer);
	ShowCards(player, computer);

	system("pause");
	return 0;
}

void Shuffle(Cards deck[])
{
	int i, j;
	Cards temp;
	srand(time(NULL));

	for (i = 0; i < 24; i++)
	{
		deck[i].face = 9 + i % 6;
		deck[i].suit = 3 + i / 6;
	}

	for (i = 0; i < 24; i++)
	{
		j = rand() % 24;
		temp.face = deck[i].face;
		temp.suit = deck[i].suit;
		deck[i].face = deck[j].face;
		deck[i].suit = deck[j].suit;
		deck[j].face = temp.face;
		deck[j].suit = temp.suit;
	}
	return;
}

void Deal(Cards cards[], Cards userA[], Cards userB[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		userA[i] = cards[i];
		userB[i] = cards[5 + i];
	}
	Sort(userA);
	Sort(userB);
	return;
}

void Sort(Cards cards[])
{
	Cards temp;
	int i, j, suitA, suitB;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4 - i; j++)
		{
			switch (cards[j].suit)
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
			switch (cards[j + 1].suit)
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
			if ((cards[j].face > cards[j + 1].face) || (suitA > suitB))
			{
				temp.face = cards[j].face;
				temp.suit = cards[j].suit;
				cards[j].face = cards[j + 1].face;
				cards[j].suit = cards[j + 1].suit;
				cards[j + 1].face = temp.face;
				cards[j + 1].suit = temp.suit;
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
	printf("%c", a.suit);
}

void ShowCards(Cards userCards[], Cards computerCards[])
{
	int i;
	printf("玩家的牌：");
	for (i = 0; i < 4; i++)
	{
		printf("%s%c, ", faceCharacter(userCards[i].face), userCards[i].suit);
	}
	printf("%s%c", faceCharacter(userCards[i].face), userCards[i].suit);
	printf("\n電腦的牌：");
	for (i = 0; i < 4; i++)
	{
		printf("%s%c, ", faceCharacter(computerCards[i].face), computerCards[i].suit);
	}
	printf("%s%c", faceCharacter(computerCards[i].face), computerCards[i].suit);
	printf("\n");
	return;
}

char *faceCharacter(int suit)
{
	switch (suit)
	{
	case 9:
		return "9";
	case 10:
		return "10";
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	case 14:
		return "A";
	default:
		return "";
	}
}

#endif