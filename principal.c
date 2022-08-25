#include <stdio.h>
#include <conio.h>
#include "library.h"

//compilar com a library: gcc -o a principal.c library.c

int main()
{
   int opt;

   do
   {
      menu();

      scanf("%d", &opt);

      switch (opt)
      {
      case  1: //Cadastro Usina - recebimento de dados e verificações
         
         cadastro_usina();
         break;

      case 2: //Cadastro Consumidor - recebimento de dados e verificações
          
         cadastro_consumidor();
         break;
      
      case 3: //Cadastro Contrato - recebimento de dados se Usina e consumidor cadastrados
          
         cadastro_contrato();
         break;
      
      case 4: //Cadastro Contrato - recebimento de dados se Usina e consumidor cadastrados
          
         consulta_usinas_cadastradas();
         break;

      }

   } while (opt != 8);
}

