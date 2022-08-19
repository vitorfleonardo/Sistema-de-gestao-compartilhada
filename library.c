#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

//**********Geral**********

void menu(void) //Procedimento - exibir Menu
{
   printf("1) Cadastrar Usina\n");
   printf("2) Cadastrar Consumidor\n");
   printf("3) Cadastrar Contrato entre Consumidor e Usina\n");
   printf("4) Consultar Usina Cadastrada\n");
   printf("5) Consultar Consumidor Contratado\n");
   printf("6) Excluir Usina\n");
   printf("7) Excluir Consumidor\n");
   printf("8) Encerrar Programa\n");
   printf("\n");
}

//**********Usina**********
void cadastro_usina() //Procedimento - recebimento de dados
{
   printf("Digite o CNPJ (xxxxxxxxxxxxxx):\n");
   fgets(usina.cnpj, 18, stdin);

   printf("Digite o Nome:\n");
   fgets(usina.nome, 61, stdin);

   printf("Digite a Data de Inicio de Operacao (xxxxxxxx):\n");
   fgets(usina.data, 10, stdin);

   printf("Digite a Potencia estimada (em MW):\n");
   scanf("%f", &usina.potencia);
}





