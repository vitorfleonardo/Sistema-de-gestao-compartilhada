#include <stdio.h>
#include "221008516.h"


int main()
{
    int opt, aux;

    do
    {
        menu();

        do
        {
            printf("Escolha uma opcao: ");
            fflush(stdin);
            aux = scanf("%d", &opt);

            if (aux == 0 || opt < 1 || opt > 8) 
                printf("valor invalido, digite novamente\n");

        }while(aux == 0 || opt < 1 || opt > 8);
        //Loop para verificar a opção escolhida

        system("cls || clear"); //limpatela

        switch(opt)
        {
            case 1:
                cadastroUsina(); 
                break;

            case 2:
                cadastroConsumidor();
                break;
                
            case 3:
                cadastroContrato();
                break;

            case 4:
                consultaUsinasCadastradas();
                break;
            
            case 5:
                consultaConsumidoresCadastrados();
                break;

            case 6:
                excluirUsina();
                break;

            case 7:
                excluirConsumidor();
                break;
        }


    } while (opt != 8);

    return 0;
}