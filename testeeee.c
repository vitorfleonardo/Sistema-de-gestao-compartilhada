#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char num[14] = "11111111111111";// = cnpj[]
    char aux[2] = "1a";
    int i=0, j=5, k=9, soma1, soma2, soma, val, cnpj[14];

    for (i; i<13; i++)
    {
        aux[0] = num[i];
        cnpj[i] = atoi(aux);
        val = cnpj[i];
    }

    for (j, i; j>1; j--, i++)
        soma1 += cnpj[i] * j;

    for (k, i; k>1; k--, i++)
        soma2 += cnpj[i+4] * k;

    
    

    return 0;
}

//digito 1---------------------------------------------------
//       for(i = 0, j = 10; i < strlen(cnpj)-2; i++, j--) 
 //           digito1 += (cnpj[i]-48) * j;
 //       digito1 %= 11;
 //       if(digito1 < 2)
 //           digito1 = 0;
  //      else
  //          digito1 = 11 - digito1;
   //     if((cpf[9]-48) != digito1)
    //        return 0; ///se o digito 1 não for o mesmo que o da validação CNPJ é inválido
