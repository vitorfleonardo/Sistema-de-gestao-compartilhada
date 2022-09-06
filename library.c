#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

//**********Geral**********
void menu(void) //Procedimento - exibir Menu
{
   printf("\n1) Cadastrar Usina\n");
   printf("2) Cadastrar Consumidor\n");
   printf("3) Cadastrar Contrato entre Consumidor e Usina\n");
   printf("4) Consultar Usina Cadastrada\n");
   printf("5) Consultar Consumidor Contratado\n");
   printf("6) Excluir Usina\n");
   printf("7) Excluir Consumidor\n");
   printf("8) Encerrar Programa\n");
   printf("\n");
}

void procedimento_sucesso(void) //Procedimento - definir fim e sucesso do procedimento selecionado pelo usuario
{
    printf("\nProcedimento realizado com sucesso!\n");
}

//**********validacoes**********
int valida_cnpj(char *cnpj) //Funcao - validar CNPJ
{
    char aux[2];

    int soma1 = 0, soma2 = 0, j = 0, n1, n2;

    int lista1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int lista2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    
    for (int i = 0; i < 19; i++)
    {

        if (i != 2 && i != 6 && i != 10 && i != 15)
        {

            if ((int)cnpj[i] >= 48 && (int)cnpj[i] <= 57)
            {
                aux[0] = cnpj[i];
            
                if (j < 12)
                    soma1 += atoi(aux) * lista1[j];
                else if (j == 12)
                    n1 = atoi(aux);

                if (j < 13)    
                    soma2 += atoi(aux) * lista2[j];
                else if (j == 13)
                    n2 = atoi(aux);

                j++;
            }
        }
    }

    if (soma1 != 0)
    {
        if ((soma1 % 11 < 2 && n1 == 0) || (n1 == 11 - (soma1 % 11)))
        {
            if ((soma2 % 11 < 2 && n2 == 0) || (n2 == 11 - (soma2 % 11)))
                return 1;
        }
    }
        

    return 0;

}

int valida_potencia(float pot) //Funcao - validar potencia estimada
{
   if (pot > 0 )
      return 1;
    else
      return 0;
}

int valida_data(int dia, int mes, int ano) //Funcao - validar a data de inicio de operacao
{
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        d[1] = 29;

    if (ano >= 0 && (mes > 0 && mes <= 12) && (dia > 0 && dia <= d[mes - 1]))
        return 1;

    return 0;
}

int valida_cpf(char *cpf) //Funcao - validar CPF
{
    char aux[2]; //077.749.951-70

    int soma1 = 0, soma2 = 0, j = 0, n1, n2;

    int lista1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int lista2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

    if ((strcmp(cpf,"000.000.000-00") == 0) || (strcmp(cpf,"111.111.111-11") == 0) || (strcmp(cpf,"222.222.222-22") == 0) ||
        (strcmp(cpf,"333.333.333-33") == 0) || (strcmp(cpf,"444.444.444-44") == 0) || (strcmp(cpf,"555.555.555-55") == 0) ||
        (strcmp(cpf,"666.666.666-66") == 0) || (strcmp(cpf,"777.777.777-77") == 0) || (strcmp(cpf,"888.888.888-88") == 0) ||
        (strcmp(cpf,"999.999.999-99") == 0))
        return 0;
    else
    {
        for (int i = 0; i < 14; i++)
        {

            if ((int)cpf[i] >= 48 && (int)cpf[i] <= 57)
            {
                aux[0] = cpf[i];
                
                if (j < 9)
                    soma1 += atoi(aux) * lista1[j];
                else if (j == 9)
                    n1 = atoi(aux);

                if (j < 10)    
                    soma2 += atoi(aux) * lista2[j];
                else if (j == 10)
                    n2 = atoi(aux);

                j++;
            }  
        } 
        
        if ((soma1 % 11 < 2 && n1 == 0) || (n1 == 11 - (soma1 % 11)))
        {
            if ((soma2 % 11 < 2 && n2 == 0) || (n2 == 11 - (soma2 % 11)))
                return 1;
        }
    }
    
    return 0;
}

//**********Usina**********
void cadastro_usina_arquivo(char *cnpj, int dia, int mes, int ano, float potencia, char *nome) //Procedimento arquivar informacoes da Usina
{
    FILE *fp; // Arquivando informacoes do Usina

    fp=fopen("cadastro-usina.txt", "a");
    if(fp != NULL)
        fprintf(fp, "%s;%d;%d;%d;%f;%s", cnpj, dia, mes, ano, potencia, nome);
    fclose(fp);    
}

int recebimento_dados_usina(void) //Funcao - recebimento de dados para CADASTRO USINA
{
   printf("Digite o CNPJ (xx.xxx.xxx/xxxx-xx):\n");
   fflush(stdin);
   fgets(usina.cnpj, 19, stdin);

   if (!valida_cnpj(usina.cnpj))
   {
        printf("CNPJ invalido\n");
        return 0;
   }
   else
   {
        printf("Digite o Nome:\n");
        fflush(stdin);
        fgets(usina.nome, 21, stdin);

        printf("Digite a Data de Inicio de Operacao (xx/xx/xxxx):\n");
        fflush(stdin);
        scanf("%d/%d/%d", &usina.data.dia, &usina.data.mes, &usina.data.ano);

      if (!valida_data(usina.data.dia, usina.data.mes, usina.data.ano))
      {
        printf("Data invalida\n");
        return 0;
      }
      else
      {
        printf("Digite a Potencia estimada (em MW):\n");
        fflush(stdin);
        scanf("%f", &usina.potencia);

        if (!valida_potencia(usina.potencia))
        {
            printf("Potencia invalida\n");
            return 0;
        }
        else
            return 1;
      }    
   }      
}

void cadastro_usina(void) //Procedimento - valida o recebimento de dados e chama procedimento de arquivar
{
    if (recebimento_dados_usina() == 1)
    {
        cadastro_usina_arquivo(usina.cnpj, usina.data.dia, usina.data.mes, usina.data.ano, 
        usina.potencia, usina.nome);
        procedimento_sucesso();
    }
    
}

void consulta_usinas_cadastradas(void) //Procedimento - le o arquivo com usinas cadastradas e exibe elas
{
    FILE *fp; // Arquivando informacoes do Usina

    fp=fopen("cadastro-usina.txt", "rt");

    if(fp != NULL)
    {
        char linha[100];

        while (!feof(fp))
        {
            fgets(linha, 100, fp);
            puts(linha);
        }
    }
    
    fclose(fp);    
}

//**********Consumidor**********
void cadastro_consumidor_arquivo(char *cnpj, char *cpf, char *nome) //Arquivando informacoes da Consumidor
{
    FILE *fp; // Arquivando informacoes do consumidor

    fp=fopen("cadastro-consumidor.txt", "a");
    if(fp != NULL)
        fprintf(fp, "%s%s;%s", cpf, cnpj, nome);
    fclose(fp);    
}

void recebimento_dados_consumidor(void) //Procedimento - recebimento de dados para CADASTRO Consumidor
{
    int opt;

    printf("\n1) Cadastrar usando CNPJ\n");
    printf("2) Cadastrar usando CPF\n");
    printf("\nEscolha o numero da opcao desejada:\n");
    scanf("%d", &opt);

    if (opt == 1) //Cadastro Conumidor - usando CNPJ
    {
        printf("\nDigite o CNPJ (xx.xxx.xxx/xxxx-xx):\n");
        fflush(stdin);
        fgets(consumidor.cnpj, 19, stdin);
    }  
    else if (opt == 2) //Cadastro Conumidor - usando CPF
    {
        printf("\nDigite o CPF (xxx.xxx.xxx-xx):\n");
        fflush(stdin);
        fgets(consumidor.cpf, 15, stdin);
    } 
    

    if ((opt == 1 && !valida_cnpj(consumidor.cnpj)) || (opt == 2 && !valida_cpf(consumidor.cpf)))
        printf("identificacao invalida\n");
    else
    {
        printf("\nDigite o Nome:\n");
        fflush(stdin);
        fgets(consumidor.nome, 21, stdin);

        cadastro_consumidor_arquivo(consumidor.cnpj, consumidor.cpf, consumidor.nome);
        procedimento_sucesso();
    }              
}



//**********Contrato**********
void cadastro_contrato_arquivo(char *usina_cnpj, char *consumidor_cnpj, char *consumidor_cpf, int dia, int mes, int ano, float potencia) //Procedimento arquivar informacoes do contrato
{
    FILE *fp; // Arquivando informacoes do Usina

    fp=fopen("cadastro-contrato.txt", "a");
    if(fp != NULL)
        fprintf(fp, "%s;%s%s;%d;%d;%d;%f", usina_cnpj, consumidor_cnpj, consumidor_cpf, dia, mes, ano, potencia);
    fclose(fp);    
}

void cadastro_contrato(void) //Procedimento - recebimento de dados para Contrato
{
    printf("\nInforme os dados da parte contratada (usina)\n");

    if (recebimento_dados_usina() == 1)
    {
        printf("\nInforme os dados da parte contratante (consumidor)\n");
        if (recebimento_dados_consumidor() == 1)
        {
            printf("Digite a Data de Inicio do Contrato entre as partes (xx/xx/xxxx):\n");
            fflush(stdin);
            scanf("%d/%d/%d", &contrato.dia, &contrato.mes, &contrato.ano);

            if (!valida_data(contrato.dia, contrato.mes, contrato.ano))
                printf("Data invalida\n");
            else
            {
                printf("Digite a Potencia Contratada (em MW):\n");
                fflush(stdin);
                scanf("%f", &contrato.potencia);

                if (!valida_potencia(contrato.potencia))
                    printf("Potencia invalida\n");
                else
                {
                    cadastro_contrato_arquivo(usina.cnpj, consumidor.cnpj, consumidor.cpf, contrato.dia, 
                    contrato.mes, contrato.ano, contrato.potencia);
                    procedimento_sucesso();
                }
            }
        }
    }
}