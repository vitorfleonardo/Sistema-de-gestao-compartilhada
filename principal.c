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
         
         recebimento_dados_usina();
         break;

      case 2: //Cadastro Consumidor - recebimento de dados e verificações
          
         recebimento_dados_consumidor();
         break;

      }

   } while (opt != 8);
}

