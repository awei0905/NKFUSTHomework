#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define SIZE 4096

int main()
{
	FILE* file = fopen("plane.txt", "r");
	char buf[SIZE] = { 0 };
	int i;
	if (file) {
		i = 0;
		while ((buf[i] = fgetc(file)) != EOF)
		{
			printf("%c", buf[i]);
			if (buf[i] == 13 || buf[i] == 10)
			{
				i++;
				continue;
			}
			buf[i++] = ((113 * (buf[i] - 32) + 45) % 94) + 32;
		}
		printf("\n");
		fclose(file);
		file = fopen("cypher.txt", "w");
		fwrite(buf, sizeof(char), i, file);
		fclose(file);
		file = fopen("cypher.txt", "r");
		i = 0;
		while (((buf[i] = fgetc(file)) != EOF))
		{
			printf("%c", buf[i]);
			if (buf[i] == 13 || buf[i] == 10)
			{
				i++;
				continue;
			}
			buf[i++] = ((5 * (buf[i] - 32) + 57) % 94) + 32;
		}
		fclose(file);
		file = fopen("decry.txt", "w");
		fwrite(buf, sizeof(char), i, file);
		fclose(file);
	}
	else printf("µLªk¶}±Òplane.txt\n");
	printf("\n");
	system("pause");
	return 0;
}