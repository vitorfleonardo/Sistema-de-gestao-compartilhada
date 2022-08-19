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
      case  1: //Cadastro Usina - recebimento de dados
         
         cadastro_usina();

         //Cadastro Usina - verificacao de dados
         if (!valida_cnpj(usina))
            return (NULL);
         if (!valida_potencia(usina))
            return (NULL);
         if (!valida_data(usina))
            return (NULL);
         
         break;

      case 2: //Cadastro Consumidor
          printf("oi2");
         break;

      }

   } while (opt != 8);
}

