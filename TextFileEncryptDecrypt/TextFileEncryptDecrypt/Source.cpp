#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fileIn, *fileOut;
	char p, c;

	// 開啟檔案
	if (!(fileIn = fopen("plane.txt", "r"))) { printf("無法開啟plane.txt\n"); system("pause"); return 0; } // 輸入
	if (!(fileOut = fopen("cypher.txt", "w"))) { printf("無法開啟cypher.txt\n"); system("pause"); return 0; } // 輸出

	// 從明文文字檔案一個字元一個字元讀取
	while ((p = fgetc(fileIn)) != EOF)
	{
		printf("%c", p); // 顯示讀取到的字元

		// 輸出一個字元一個字元到密文文字檔案
		if (p == 13 || p == 10)
		{
			fputc(p, fileOut);
			continue;
		}
		c = ((113 * (p - 32) + 45) % 94) + 32; // 加密公式
		fputc(c, fileOut);
	}
	printf("\n");

	// 關閉已開啟的檔案
	fclose(fileIn);
	fclose(fileOut);

	// 開啟檔案
	if (!(fileIn = fopen("cypher.txt", "r"))) { printf("無法開啟cypher.txt\n"); system("pause"); return 0; } // 輸入
	if (!(fileOut = fopen("decry.txt", "w"))) { printf("無法開啟decry.txt\n"); system("pause"); return 0; } // 輸出
	
	// 從密文文字檔案一個字元一個字元讀取
	while ((c = fgetc(fileIn)) != EOF)
	{
		printf("%c", c); // 顯示讀取到的字元

		// 輸出一個字元一個字元到明文文字檔案
		if (c == 13 || c == 10)
		{
			fputc(c, fileOut);
			continue;
		}
		p = ((5 * (c - 32) + 57) % 94) + 32; // 解密公式
		fputc(p, fileOut);
	}
	printf("\n");

	// 關閉已開啟的檔案
	fclose(fileIn);
	fclose(fileOut);

	system("pause");
	return 0;
}