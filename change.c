#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fp1;
	FILE *fp2;
	int a[50][50];
	fp1=fopen("kan.c","r");
	fp2=fopen("kan.jack","w");
	fprintf(fp2,"class kan.jack{\n");
	for(int i=0;i<50;i++)
		for(int k=0;k<50;k++)
			fscanf(fp1,"%d", &a[i][k]);
	for(int i=0;i<50;i++)
		for(int k=0;k<50;k++){
			if(a[i][k]==1)
				fprintf(fp2,"Enemy.draw(%d,%d,1);\n",i,k);	
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
