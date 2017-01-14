#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
int number[1000][1000];
int main()
{
	int LenthX, LenthY, n;
	char filename[10][50];
	FILE *fp[10];
	printf("Please input the lenth of x-direction and y-direction :\n");
	scanf("%d%d", &LenthX, &LenthY);
	printf("Please input the number of the sourse files:\n");
	scanf("%d", &n);
	printf("Please input the names of the sourse files:\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%s", filename[i]);
		fp[i] = fopen(filename[i], "r");
		assert(fp[i] != NULL);
	}
	printf("Please input the name of the function:\n");
	scanf("%s", filename[9]);
	fp[9] = fopen("Draw.jack", "a");
	assert(fp[9] != NULL);
	fprintf(fp[9], "	function void draw%s(int mode)\n	{\n", filename[9]);
	fprintf(fp[9], "		do Screen.setColor(1);\n");
	for(int i = 0; i < n; i++)
	{
		fprintf(fp[9], "		if(mode = %d)\n		{\n", i + 1);
		for(int y = 0; y < LenthY; y++)
			for(int x = 0; x < LenthX; x++)
			{
				fscanf(fp[i], "%d", &number[x][y]);
			}
		for(int x = 0; x < LenthX; x++)
			for(int y = 0; y < LenthY; y++)
				if(number[x][y] == 1)
					fprintf(fp[9], "			do Screen.drawPixel(%d+x-%d,%d+y-%d);\n", x, LenthX/2, y, LenthY/2);
		fprintf(fp[9], "		}\n");
		fclose(fp[i]);
	}
	fprintf(fp[9], "		return;\n	}\n");
	fclose(fp[9]);
	return 0;
}
