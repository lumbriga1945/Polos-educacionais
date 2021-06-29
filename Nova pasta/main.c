#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	int retorno, num=0, cont=0, tamanho=0;
	char info[100];
	
	FILE *arq = fopen("banco.txt", "r");
	FILE *arq2 = fopen("Banco - Copia.txt", "w");
	
	fprintf(arq2, "%c\n", 123);
	fprintf(arq2, "\t%cescolas_polo%c: [\n", 34, 34);
	while( (fgets(info, sizeof(info), arq))!=NULL ){
		retorno = strcmp(info, "*\n");
		if(retorno==0){
			cont=0;
			fprintf(arq2, "\t\t\t%]\n", 34 ,34);	
			fprintf(arq2, "\t\t%c,\n", 125);
		}else if(cont==0){
			fprintf(arq2, "\t\t%c\n", 123);
			fprintf(arq2, "\t\t\t%csigla%c: %cAreia_Branca%c,\n", 34, 34, 34, 34);
			fprintf(arq2, "\t\t\t%cnome%c: %c%s%c,\n", 34 ,34, 34, info, 34);
			fprintf(arq2, "\t\t\t%cinfo%c: [\n", 34 ,34);
			cont++;
		}else if(cont==1 && info!="*"){
			fprintf(arq2, "\t\t\t\t%c%s%c,\n", 34, info, 34);
		}
	}
	fprintf(arq2, "\t\t\t%]\n", 34 ,34);
	fprintf(arq2, "\t\t%c\n", 125);
	fprintf(arq2, "\t]\n");
	fprintf(arq2, "%c\n", 125);
	
	fclose(arq);
	fclose(arq2);
}
