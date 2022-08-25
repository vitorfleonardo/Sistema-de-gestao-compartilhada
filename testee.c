#include "stdio.h"
#include "stdlib.h"

int valida_cnpj(char *cnpj) 
{
  int soma, i, result, num, mult;
  char dig13, dig14;

  // Primeiro dígito
  soma = 0; 
  mult = 2;
  
  for (i = 11; i >= 0; i--) {
    num = cnpj[i] - 48;

    soma = soma + (num * mult);
    mult = mult + 1;
    if (mult == 10)
      mult = 2;
  }
  
  result = soma % 11;
  if ((result == 0) || (result == 1))
    dig13 = '0';
  else
    dig13 = (11 - result) + 48;

  // Segundo dígito
  soma = 0; mult = 2;
  for (i=12; i>=0; i--) {
    num = cnpj[i] - 48;
    soma = soma + (num * mult);
    mult = mult + 1;
    if (mult == 10){
      mult = 2;
    }
  }
  
  result = soma % 11;
  if ((result == 0) || (result == 1)){
     dig14 = '0';
    }
  else{
     dig14 = (11 - result) + 48;
    }

  // Compara os dígitos calculados com os dígitos informados
  if ((dig13 == cnpj[12]) && (dig14 == cnpj[13])){
     return 1;
  }
  else{
     return 0;
    }
}

int main()
{
    char cnpj[14];
    printf("Informe o valor do CNPJ:\n");
    scanf("%s",cnpj);

    if (valida_cnpj(cnpj) == 1);
        printf("ta bomzin");

    return 0;
}

