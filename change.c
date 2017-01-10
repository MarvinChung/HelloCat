#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
int main()
{
	int HalfSize = 25;
	int mode;
	printf("0 : Do nothing.\n");
	printf("1 : Reverse left to right.\n");
	printf("Please input the operation mode :\n");
	scanf("%d", &mode);

	FILE *fp1;
	FILE *fp2;
	int a[50][50];
	fp1 = fopen("cat_1.c","r");
	fp2 = fopen("Cat.jack","a");
	assert(fp1 != NULL && fp2 != NULL);
	fprintf(fp2, "	method void draw(int x, int y, boolean mode)\n");
	fprintf(fp2, "	{\n		if(mode)\n		{\n");
	fprintf(fp2,"			do Screen.setColor(1);\n");
	for(int y = 0; y < 50; y++)
		for(int x = 0; x < 50; x++)
		{
			if(!mode)
				fscanf(fp1, "%d", &a[x][y]);
			else	
				fscanf(fp1, "%d", &a[49 - x][y]);
		}
	for(int x = 0; x < 50; x++)
		for(int y = 0; y < 50; y++)
			if(a[x][y] == 1)
				fprintf(fp2, "			do Screen.drawPixel(%d + x - %d, %d + y - %d);\n", x, HalfSize, y, HalfSize);
	fprintf(fp2, "		}\n		else\n		{\n");
	fprintf(fp2, "			do Screen.setColor(0);\n");
	fprintf(fp2, "			do Screen.drawRectangle(x - %d, y - %d, x + %d, y + %d);\n",HalfSize,HalfSize,HalfSize,HalfSize);
	fprintf(fp2, "		}\n	return;\n	}\n}");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
