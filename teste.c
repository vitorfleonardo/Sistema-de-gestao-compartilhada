#include <stdio.h>
#include <stdlib.h>



void cadastro_usina_arquivo(char *cnpj, char *nome, char *data, float potencia)
{
    FILE *fp;

    fp=fopen("test.txt", "a");
    if(fp == NULL)
        exit(-1);

    /* Arquivando CNPJ válido da usina */
    fprintf(fp, "CNPJ da Usina: %s\n", cnpj);

    /* Arquivando Nome da usina */
    fprintf(fp, "Nome da Usina: %s\n", nome);
    
    /* Arquivando a data de Inicio de Operacao */
    fprintf(fp, "Data de Inicio de Operacao: %s\n", data);

    /* print integers and floats */
    fprintf(fp, "Potencia estimada da Usina: %f\n", potencia);

    fclose(fp);
}

int main()
{
    char cad[] = "hello", name[] = "sla", date[] = "22/22";
    float pot = 3.5;

    cadastro_usina_arquivo(cad, name, date, pot);

    return 0;


}