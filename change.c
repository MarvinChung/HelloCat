#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
int number[1000][1000];
int main()
{
	int LenthX, LenthY, mode;
	char filename1[50], filename2[50];
	printf("0 : Do nothing.\n");
	printf("1 : Reverse left to right.\n");
	printf("Please input the operation mode :\n");
	scanf("%d", &mode);
	printf("Please input the lenth of x-direction and y-direction :\n");
	scanf("%d%d", &LenthX, &LenthY);
	printf("Please input the name of the sourse filen and the target file :\n");
	scanf("%s%s", filename1, filename2);

	FILE *fp1;
	FILE *fp2;
	fp1 = fopen(filename1,"r");
	fp2 = fopen(filename2,"a");
	assert(fp1 != NULL && fp2 != NULL);
	fprintf(fp2, "	method void draw(int x, int y, boolean mode)\n");
	fprintf(fp2, "	{\n		if(mode)\n		{\n");
	fprintf(fp2,"			do Screen.setColor(1);\n");
	for(int y = 0; y < LenthY; y++)
		for(int x = 0; x < LenthX; x++)
		{
			if(!mode)
				fscanf(fp1, "%d", &number[x][y]);
			else	
				fscanf(fp1, "%d", &number[LenthX - 1 - x][y]);
		}
	for(int x = 0; x < LenthX; x++)
		for(int y = 0; y < LenthY; y++)
			if(number[x][y] == 1)
				fprintf(fp2, "			do Screen.drawPixel(%d + x - %d, %d + y - %d);\n", x, LenthX/2, y, LenthY/2);
	fprintf(fp2, "		}\n		else\n		{\n");
	fprintf(fp2, "			do Screen.setColor(0);\n");
	fprintf(fp2, "			do Screen.drawRectangle(x-%d,y-%d,x+%d,y+%d);\n",LenthX/2+1,LenthY/2+1,LenthX/2+1,LenthY/2+1);
	fprintf(fp2, "		}\n	return;\n	}\n}");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
