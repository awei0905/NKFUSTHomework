#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fileIn, *fileOut;
	char p, c;

	// �}���ɮ�
	if (!(fileIn = fopen("plane.txt", "r"))) { printf("�L�k�}��plane.txt\n"); system("pause"); return 0; } // ��J
	if (!(fileOut = fopen("cypher.txt", "w"))) { printf("�L�k�}��cypher.txt\n"); system("pause"); return 0; } // ��X

	// �q�����r�ɮפ@�Ӧr���@�Ӧr��Ū��
	while ((p = fgetc(fileIn)) != EOF)
	{
		printf("%c", p); // ���Ū���쪺�r��

		// ��X�@�Ӧr���@�Ӧr����K���r�ɮ�
		if (p == 13 || p == 10)
		{
			fputc(p, fileOut);
			continue;
		}
		c = ((113 * (p - 32) + 45) % 94) + 32; // �[�K����
		fputc(c, fileOut);
	}
	printf("\n");

	// �����w�}�Ҫ��ɮ�
	fclose(fileIn);
	fclose(fileOut);

	// �}���ɮ�
	if (!(fileIn = fopen("cypher.txt", "r"))) { printf("�L�k�}��cypher.txt\n"); system("pause"); return 0; } // ��J
	if (!(fileOut = fopen("decry.txt", "w"))) { printf("�L�k�}��decry.txt\n"); system("pause"); return 0; } // ��X
	
	// �q�K���r�ɮפ@�Ӧr���@�Ӧr��Ū��
	while ((c = fgetc(fileIn)) != EOF)
	{
		printf("%c", c); // ���Ū���쪺�r��

		// ��X�@�Ӧr���@�Ӧr��������r�ɮ�
		if (c == 13 || c == 10)
		{
			fputc(c, fileOut);
			continue;
		}
		p = ((5 * (c - 32) + 57) % 94) + 32; // �ѱK����
		fputc(p, fileOut);
	}
	printf("\n");

	// �����w�}�Ҫ��ɮ�
	fclose(fileIn);
	fclose(fileOut);

	system("pause");
	return 0;
}