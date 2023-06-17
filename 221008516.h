#ifndef _221008516_H_
#define _221008516_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_MAX 50

struct usina
{
    char nome[TAM_MAX]; 
    float potencia;
    char cnpj[TAM_MAX];
    int mes, dia, ano;
};

struct consumidor
{
    char id[TAM_MAX];
    char nome[TAM_MAX];
};

struct contrato
{
    char cnpj_usina[TAM_MAX];
    char id_consumidor[TAM_MAX];
    int dia, mes, ano;
    float potencia;
};


//----------
//------------------------------------------- Funcoes
//----------

int validaUcnpj(char *cnjp) //Funcao - verifica no arquivo usina.txt se o cnpj  ja foi cadastrado
{
    FILE *fp;
    struct usina usina;

    fp = fopen("usina.txt", "r+b"); //Abertura do arquivo onde as usinas estao cadastradas (leitura)

    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo
        
        while (fread(&usina, sizeof(usina), 1, fp) == 1)
        {
           
            if (strcmp(usina.cnpj, cnjp) == 0)
            {
                fclose(fp);
                return 1; //se o cnpj for encontrado no arquivo 
            } //condicional verdadeira significa que o cnpj foi encontrado no arquivo

        } //loop que le, linha por linha, as variaveis da usina, até o final do arquivo

    }

    fclose(fp);
    return 0; //se o cnpj não for encontrado no arquivo
 
}
//-------------------------------------------
int validaUnome(char *nome) //Funcao - verifica no arquivo usina.txt se o nome ja foi cadastrado
{
    FILE *fp;
    struct usina usina;

    fp = fopen("usina.txt", "r+b"); //Abertura do arquivo onde as usinas estao cadastradas (leitura)


    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        while (fread(&usina, sizeof(usina), 1, fp) == 1)
        {

            if (strcmp(usina.nome, nome) == 0)
            {
                fclose(fp);
                return 1; //se o nome for encontrado no arquivo
            } //condicional verdadeira significa que o nome foi encontrado no arquivo

        } //loop que le, linha por linha, as variaveis da usina, até o final do arquivo
    }

    fclose(fp);
    return 0; //se o cnpj não for encontrado no arquivo 
}
//-------------------------------------------
int validaCadastroConsumidor(char *id) //Funcao - verifica no arquivo consumidor.txt se o cnpj/cpf ja foi cadastrado
{
    FILE *fp;
    struct consumidor consumidor;

    fp = fopen("consumidor.txt", "r+b"); //abertura do arquivo onde os consumidores estao cadastrados (leitura)

    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        while (fread(&consumidor, sizeof(consumidor), 1, fp) == 1)
        {
            if (strcmp(consumidor.id, id) == 0)
            {
                fclose(fp);
                return 1; //se o cnpj/cpf for encontrado no arquivo 
            }

        }
        
    }

    fclose(fp);
    return 0; //se o cnpj ou cpf não for encontrado no arquivo 
}
//-------------------------------------------
int validaData(int dia, int mes, int ano) //Funcao - verificar a data 
{
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        d[1] = 29;

    if (ano >= 0 && ano < 3000 && (mes > 0 && mes <= 12) && (dia > 0 && dia <= d[mes - 1]))
        return 1;

    return 0;
}
//-------------------------------------------
int validaCnpj(char *cnpj) //Funcao - validar CNPJ
{
    char aux[2];

    int soma1 = 0, soma2 = 0, j = 0, n1, n2;

    int lista1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int lista2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    
    if (strlen(cnpj) != 18)
        return 0;

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
//-------------------------------------------
int validaCpf(char *cpf) //Funcao - validar CPF
{
    char aux[2]; 

    int soma1 = 0, soma2 = 0, j = 0, n1, n2;

    int lista1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int lista2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

    if (strlen(cpf) != 14)
        return 0;
    else if ((strcmp(cpf,"000.000.000-00") == 0) || (strcmp(cpf,"111.111.111-11") == 0) || (strcmp(cpf,"222.222.222-22") == 0) ||
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
//-------------------------------------------
float listaContratosUsinas(char *id) //Funcao - Procura Usinas vinculadas a Consumidores e retorna aux
{
    FILE *fpcontrato;

    struct contrato contrato;
    float aux = 0;

    fpcontrato = fopen("contratos.txt", "r+b"); //abertura do arquivo contratos.txt para leitura

    if (fpcontrato != NULL)
    {
        fseek(fpcontrato, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        while(fread(&contrato, sizeof(contrato), 1, fpcontrato) == 1)
        {
            if (strcmp(id, contrato.id_consumidor) == 0) //a comparacao e verdadeira quando o cnpj/cpf e encontrado
            {
                printf("\nCNPJ da Usina: %s | INICIO DO CONTRATO: %.2d/%.2d/%.4d | POTENCIA CONTRATADA: %.4f MW\n", contrato.cnpj_usina, contrato.dia, contrato.mes, contrato.ano, contrato.potencia);

                aux += contrato.potencia; //somando as potências contradas
            } //se o cnpj ou cpf do consumidor for encontrado no arquivo 

        }
    }

    fclose(fpcontrato);  //fecha o arquivo 
    return aux; //Retorno da soma das potências contratadas pelo consumidor consultado

}
//-------------------------------------------
float listaContratosConsumidores(char *cnpj) //Função - Procura consumidores vinculados à Usina e retorna aux
{
    FILE *fpcontrato;

    struct contrato contrato;

    float aux = 0;

    fpcontrato = fopen("contratos.txt", "r+b"); //abertura do arquivo contratos para leitura

    if (fpcontrato != NULL)
    {
        fseek(fpcontrato, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        while(fread(&contrato, sizeof(contrato), 1, fpcontrato) == 1)
        {
            if (strcmp(cnpj, contrato.cnpj_usina) == 0) //se o cnpj da usina for encontrado no arquivo 
            {
                printf("\n\nID DO CONSUMIDOR: %s | INICIO DO CONTRATO: %.2d/%.2d/%.4d | POTENCIA CONTRATADA: %.4f MW\n", contrato.id_consumidor, contrato.dia, contrato.mes, contrato.ano, contrato.potencia);

                aux += contrato.potencia; //somando as potências contradas 
            }
        }
    }

    fclose(fpcontrato);  //fecha o arquivo 
    return aux; //Retorno da soma das potências contratadas pelos consumidores  

}
//-------------------------------------------
int validaDataContrato(char *cnpj, int dia, int mes, int ano) //Funcao - compara a data do contrato com a data do incio de operação da usina
{
    FILE *fpusina;

    struct contrato contrato;
    struct usina usina;

    fpusina = fopen("usina.txt", "r+b"); //abertura do arquivo usina.txt para leitura

    if (fpusina != NULL)
    {
        fseek(fpusina, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        while(fread(&usina, sizeof(usina), 1, fpusina) == 1)
        {
            //se o cnpj da usina for encontrado no arquivo
            if (strcmp(cnpj, usina.cnpj) == 0) 
            {
                if (usina.ano == ano && usina.mes == mes && usina.dia <= dia)
                {
                    fclose(fpusina);  //fecha o arquivo 
                    return 1;
                }
                else if (usina.ano == ano && usina.mes < mes)
                {
                    fclose(fpusina);  //fecha o arquivo 
                    return 1;
                }
                else if (usina.ano < ano)
                {
                    fclose(fpusina);  //fecha o arquivo 
                    return 1;
                }
                    
            }   
        }

        fclose(fpusina);  //fecha o arquivo 
        return 0;  //retorna 0 se a data for invalida
    }

    
}
//-------------------------------------------
int potenciaContratada(char *cnpj, float potencia) //Funcao - calucula e valida a potência disponível para contratar
{
    FILE *fpcontrato, *fpusina;

    struct contrato contrato;
    struct usina usina;
    float aux = 0;

    fpcontrato = fopen("contratos.txt", "r+b"); //abertura do arquivo contratos.txt para leitura
    fpusina = fopen("usina.txt", "r+b"); //abertura do arquivo usina.txt para leitura

    if (fpcontrato != NULL && fpusina != NULL)
    {
        fseek(fpcontrato, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        while(fread(&contrato, sizeof(contrato), 1, fpcontrato) == 1)
        {
            //se o cnpj da usina for encontrado no arquivo
            if (strcmp(cnpj, contrato.cnpj_usina) == 0) 
                aux += contrato.potencia; //soma das potências contradas  
        }

        aux += potencia;

        fseek(fpusina, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        while(fread(&usina, sizeof(usina), 1, fpusina) == 1)
        {
            //se o cnpj da usina for encontrado no arquivo
            //se a soma das potencias contratadas forme menor ou igual a potência de geração da usina
            if ((strcmp(cnpj, usina.cnpj) == 0) && usina.potencia >= aux)
            {
                fclose(fpcontrato);  //fecha o arquivo 
                fclose(fpusina);  //fecha o arquivo 
                return 1;
            }      
                
        }

        fclose(fpcontrato);  //fecha o arquivo 
        fclose(fpusina);  //fecha o arquivo 
        return 0;  
    }

}

//----------
//------------------------------------------- Procedimentos SGC
//----------

void menu() //Procedimento - exibir Menu
{
   printf("\n1) Cadastrar Usina\n"
      "2) Cadastrar Consumidor\n"
      "3) Cadastrar Contrato entre Consumidor e Usina\n"
      "4) Consultar Usina Cadastrada\n"
      "5) Consultar Consumidor Cadastrado\n"
      "6) Excluir Usina\n"
      "7) Excluir Consumidor\n"
      "8) Encerrar Programa\n"
      "\n");
}
//-------------------------------------------
void cadastroUsina() //Procedimento - cadastrar a Usina
{
    FILE *fp;
    int aux;
    struct usina usina; //struct com variáveis da Usina

    fp = fopen("usina.txt", "a+b"); //abertura do arquivo onde as usinas estao cadastradas (escrever)

    if(fp != NULL)
    {

        do
        {
            printf("Digite o CNPJ da usina (xx.xxx.xxx/xxxx-xx):\n");
            fflush(stdin);
            scanf("%s", usina.cnpj); //Le e armazena o cnpj da usina

            if (!validaCnpj(usina.cnpj)) //valida o cnpj da usina a ser cadastrada
                printf("CNPJ invalido, digite novamente\n");

            if (validaUcnpj(usina.cnpj)) //verifica se a usina ja esta cadastrada
                printf("Usina ja cadastrada, digite novamente\n");

        } while (!validaCnpj(usina.cnpj) || validaUcnpj(usina.cnpj));
        //loop que verifica se o cnpj digiado é valido ou se o cnpj da usina já foi cadastrado 
        

        do
        {
            fflush(stdin);
            printf("Digite o Nome da Usina:\n");
            fgets(usina.nome, 100, stdin); //Le e armazena o nome da usina
            
            if (usina.nome[0] == 0x0A) //verfica se o nome digitado não foi apenas um \n
                printf("nome invalido! Digite novamente\n");
            else
                usina.nome[strcspn(usina.nome, "\n")] = 0; //troca o valor da posição do \n por 0, no vetor da string

            if (validaUnome(usina.nome))//verifica se o nome ja esta cadastrado
                    printf("nome ja cadastrado! Digite novamente\n");

        } while (validaUnome(usina.nome) || usina.nome[0] == 0x0A);
        //loop que verifica se o nome já foi cadastrado anteriormente

        do
        {
            fflush(stdin);
            printf("Digite a Data de Inicio de Operacao (xx/xx/xxxx):\n");
            aux = scanf("%d/%d/%d", &usina.dia, &usina.mes, &usina.ano); //Le e armazena a data

            if (!validaData(usina.dia, usina.mes, usina.ano) || aux == 0) //verfica se a data existe
                printf("Data invalida, digite novamente\n");

        } while (aux == 0 || !validaData(usina.dia, usina.mes, usina.ano));
        //loop que verifica se a data é valida

        do
        {
            fflush(stdin);
            printf("Digite a Potencia estimada (em MW):\n");
            aux = scanf("%f", &usina.potencia); //Le e armazena a potencia

            if (aux == 0 || usina.potencia < 1) 
                printf("Potencia invalida, digite novamente\n");

        } while (aux == 0 || usina.potencia < 1);
        //loop que verifica se a potencia é valida

        fseek(fp, 0, SEEK_END); //posicionando ponteiro no final do arquivo
        fwrite(&usina, sizeof(usina), 1, fp);
        //escreve no arquivo usina.txt os dados do cadastro, caso estejam corretos

        printf("\nUsina cadastrada com sucesso!\n");
    }

    fclose(fp);  //fecha o arquivo 
    
}
//-------------------------------------------
void cadastroConsumidor() //Procedimento - cadastrar o consumidor 
{
    FILE *fp;
    struct consumidor consumidor; //struct com variáveis do consumidor
    int opt, aux;

    fp = fopen("consumidor.txt", "a+b"); //abertura do arquivo onde os consumidores estao cadastrados (escrever)

    if (fp != NULL)
    {  
        fseek(fp, 0, SEEK_END); //posicionando ponteiro no final do arquivo
            
        do
        {
            printf("Digite a identificacao CNPJ ou CPF do consumidor:\n");
            fflush(stdin);
            scanf("%s", consumidor.id); //Le e armazena a id do consumidor 

            if (validaCadastroConsumidor(consumidor.id) == 1) //verifica se o consumidor ja esta cadastrado
                printf("Consumidor ja cadastrado, digite novamente\n");
            
            if (validaCnpj(consumidor.id) == 0 && validaCpf(consumidor.id) == 0) //valida o cnpj/cpf do consumidor a ser cadastrado
                printf("CNPJ/CPF invalido, digite novamente\n");

        } while (validaCadastroConsumidor(consumidor.id) == 1 || (validaCnpj(consumidor.id) == 0 && validaCpf(consumidor.id) == 0));
        //loop para verificar a identificacao do consumidor
        
        do
        {
            fflush(stdin);
            printf("Digite o Nome do Consumidor:\n");
            fgets(consumidor.nome, 50, stdin); //Le e armazena o nome do consumidor
        
            if (consumidor.nome[0] == 0x0A) //verfica se o nome digitado não foi apenas um \n
                printf("nome invalido! Digite novamente\n");
            else
                consumidor.nome[strcspn(consumidor.nome, "\n")] = 0; //troca o valor da posição do \n por 0, no vetor da string          

        } while (consumidor.nome[0] == 0x0A);
        //loop que verifica se o nome é diferente de um \n

        //escreve no arquivo os dados requisitados
        fwrite(&consumidor, sizeof(consumidor), 1, fp); //escrevendo toda a struct   
        printf("\nConsumidor cadastrado com sucesso!\n");
    }

    fclose(fp);  //fecha o arquivo 
     
}
//-------------------------------------------
void cadastroContrato() //Procedimento - cadastrar contrato entre consumidor e usina
{
    FILE *fp;
    struct contrato contrato;
    int aux, opt;

    fp = fopen("contratos.txt", "a+b"); //abertura do arquivo onde os contratos estao cadastrados (escrever)

    //Verfica se o arquivo existe, como foi aberto para escrita, se ainda não existir ele será criado
    if(fp != NULL)
    {
        fseek(fp, 0, SEEK_END); //posicionando ponteiro no final do arquivo

        do //Cadastro Contrato: Usina
        {
            printf("Digite o CNPJ da usina (xx.xxx.xxx/xxxx-xx):\n");
            fflush(stdin);
            scanf("%s", &contrato.cnpj_usina); //Le e armazena o cnpj da usina
            
            if (!validaUcnpj(contrato.cnpj_usina)) //verifica se a usina ja esta cadastrada
                printf("Usina nao cadastrada, digite novamente\n");

        } while (!validaUcnpj(contrato.cnpj_usina));
        //loop que checa se a usina já foi cadastrada

        do //Cadastro Contrato: Consumidor 
        {
            printf("Digite a identificacao CNPJ ou CPF do consumidor:\n");
            fflush(stdin);
            scanf("%s", &contrato.id_consumidor); 

            if (!validaCadastroConsumidor(contrato.id_consumidor))  //verifica se o consumidor ja foi cadastrado
                printf("Consumidor nao cadastrado, digite novamente\n");

        } while (!validaCadastroConsumidor(contrato.id_consumidor));
        //loop que verifica se o cnpj do consumidor já foi cadastado

        do
        {
            fflush(stdin);
            printf("Digite a Data de Inicio de Contrato (xx/xx/xxxx):\n");
            aux = scanf("%d/%d/%d", &contrato.dia, &contrato.mes, &contrato.ano);

            if (!validaData(contrato.dia, contrato.mes, contrato.ano) || aux == 0) //verifica se a data e valida
                printf("Data invalida, digite novamente\n");

            if (!validaDataContrato(contrato.cnpj_usina, contrato.dia, contrato.mes, contrato.ano)) //verifica se a data e posterior ao incio da usina
                printf("Data invalida, digite novamente\n");

        } while (aux == 0 || !validaData(contrato.dia, contrato.mes, contrato.ano) || !validaDataContrato(contrato.cnpj_usina, contrato.dia, contrato.mes, contrato.ano));
        //loop que verifica se a data existe 

        do
        {
            fflush(stdin);
            printf("Digite a Potencia contrada (em MW):\n");
            aux = scanf("%f", &contrato.potencia);

            if (aux == 0 || contrato.potencia < 1 || potenciaContratada(contrato.cnpj_usina, contrato.potencia) == 0)
                printf("Potencia invalida, digite novamente\n");

        } while (aux == 0 || contrato.potencia < 1 || potenciaContratada(contrato.cnpj_usina, contrato.potencia) == 0);
        //loop que valida a potencia
        
        fwrite(&contrato, sizeof(contrato), 1, fp);
        printf("\nContrato cadastrado com sucesso!\n");

    }

    fclose(fp);  //fecha o arquivo 
}
//-------------------------------------------
void consultaUsinasCadastradas() //Procedimento - Consulta de usina
{
    FILE *fpusina; 

    struct usina usina;
    struct contrato contrato;
    
    float aux=0;
    int achei = 0;

    fpusina = fopen("usina.txt", "r+b"); //abertura do arquivo usinas estao cadastradas (leitura)

    if(fpusina == NULL) //Arquivo vazio é porque não tem usina cadastrada ainda
        printf("Nenhuma usina cadastrada ainda!\n"); 
    else
    {
        fseek(fpusina, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        printf("Digite o CNPJ da usina a ser consultada (xx.xxx.xxx/xxxx-xx):\n");
        fflush(stdin);
        scanf("%s", &contrato.cnpj_usina); //lendo cnpj da consultada
               
        while (fread(&usina, sizeof(usina), 1, fpusina) == 1)
        {

            if (strcmp(usina.cnpj, contrato.cnpj_usina) == 0) //procurando no arquivo o cnpj
            {
                printf("\nDADOS DA USINA:\n");
                printf("CNPJ da Usina: %s | Nome da Usina: %s | Inicio de Operacao: %.2d/%.2d/%.4d | Potencia total: %.4f MW\n", usina.cnpj, usina.nome, usina.dia, usina.mes, usina.ano, usina.potencia);

                aux = listaContratosConsumidores(contrato.cnpj_usina); //lista os consumidores vinculados

                printf("\nPotencia disponivel na Usina Consultada: %.2f %%\n", (usina.potencia - aux)/usina.potencia *100);

                achei = 1;
            } //se o cnpj da usina for encontrado no arquivo   

        } // loop que vai ler o arquivo todo

        if (achei == 0)
            printf("Usina nao cadastrada!\n");
        
    }      
    
    fclose(fpusina);  //fecha o arquivo  
}
//-------------------------------------------
void consultaConsumidoresCadastrados() //Procedimento - Consulta de consumidor
{
    FILE *fpconsumidor; 

    float aux = 0;
    int achei = 0;

    struct contrato contrato;
    struct consumidor consumidor;

    fpconsumidor = fopen("consumidor.txt", "r+b"); //abertura do arquivo onde os consumidores estao cadastrados (leitura)

    if(fpconsumidor == NULL)
        printf("Nenhum consumidor cadastrado ainda!\n"); //Arquivo vazio é porque não tem consumidor cadastrado ainda
    else
    {
        fseek(fpconsumidor, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo

        printf("Digite o CNPJ ou CPF do Consumidor a ser consultado:\n");
        fflush(stdin);
        scanf("%s", &contrato.id_consumidor); //lendo cnpj/cpf do consultado
        
        while (fread(&consumidor, sizeof(consumidor), 1, fpconsumidor) == 1)
        {

            if (strcmp(consumidor.id, contrato.id_consumidor) == 0)
            {
                printf("\nDADOS DO CONSUMIDOR:\n");
                printf("ID do Consumidor: %s | Nome do Consumidor: %s", consumidor.id, consumidor.nome);

                printf("\n");
                
                aux = listaContratosUsinas(contrato.id_consumidor);

                printf("\nPotencia total contratada por %s: %.4f MW\n", consumidor.nome, aux);

                achei = 1;

                printf("\n");
            } //se o cnpj ou cpf do consumidor for encontrado no arquivo             
            
        }

        if (achei == 0)
            printf("Consumidor nao cadastrado!\n");

    }
         
    fclose(fpconsumidor);  //fecha o arquivo    
}
//-------------------------------------------
void excluirUsina() //Procedimento - exclui usina
{
    
    FILE *fp, *Tfp, *Cfp, *TCfp; //ponteiro para aquivo
    char excluida[TAM_MAX];
    int achei = 0;

    struct usina usina;
    struct contrato contrato;

    fp = fopen("usina.txt", "r+b"); //abrindo o arquivo binário consumidores.txt para leitura/escrita 
    Tfp = fopen("usina.temp", "a+b"); //criando o arquivo binário usinas.temporario para leitura/escrita
    

    if (fp != NULL && Tfp != NULL) //se os arquivos não estiverem vazios ou criados
    {
        fseek(fp, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo
        fseek(Tfp, 0, SEEK_END); //posicionando ponteiro no final do arquivo

        printf("Digite o CNPJ da usina que vai ser excluida: ");
        scanf("%s", &excluida); //leitura do cnpj/cpf que vai ser excluido

        while (fread(&usina, sizeof(usina), 1, fp) == 1) //Leitura até o final do arquivo
        {
            if (strcmp(excluida, usina.cnpj) != 0) //escrever todos os dados dos consumidores exceto do consumidor excluido
                fwrite(&usina, sizeof(usina), 1, Tfp); //escrevendo toda a struct
            else
                achei = 1;
        }

        if (achei == 1)
            printf("Usina excluida com sucesso!\n");
        else
            printf("Usina nao cadastrada!");

        fclose(fp); //fechando o arquivo binário usina.txt
        fclose(Tfp); //fechando o arquivo binário usina.temporario

        remove("usina.txt"); //removendo o arquivo binário consumidor.txt
        rename("usina.temp", "usina.txt"); //renomeando o arquivo binário consumidor.temporario para consumidores.txt

        Cfp = fopen("contratos.txt", "r+b"); //abrindo o arquivo binário contratos.txt para leitura/escrita
        TCfp = fopen("contratos.temp", "a+b"); //criando o arquivo binário contratos.temporario para leitura/escrita

        if (Cfp != NULL && TCfp != NULL) //se os arquivos não estiverem vazios ou criados
        {
            fseek(Cfp, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo
            fseek(TCfp, 0, SEEK_END); //posicionando ponteiro no final do arquivo

            while (fread(&contrato, sizeof(contrato), 1, Cfp) == 1) //Leitura até o final do arquivo
            {
                if (strcmp(excluida, contrato.cnpj_usina) != 0) //escrever todos os dados dos consumidores exceto do consumidor excluido
                    fwrite(&contrato, sizeof(contrato), 1, TCfp); //escrevendo toda a struct
            }

            fclose(Cfp); //fechando o arquivo binário contratos.txt
            fclose(TCfp); //fechando o arquivo binário contratos.temporario

            remove("contratos.txt"); //removendo o arquivo binário contratos.txt
            rename("contratos.temp", "contratos.txt"); //renomeando o arquivo binário contratos.temporario para contratos.txt
        }
        else
        {
            fclose(Cfp); //fechando o arquivo binário contratos.txt
            fclose(TCfp); //fechando o arquivo binário contratos.temporario
            remove("contratos.temp");
        }
        
    }
    else //mostra na tela quando o arquivo de usinas não existe ainda
    {
        printf("\nCadastre consumidores primeiro!\n");  
        fclose(fp); 
        fclose(Tfp);
        remove("usina.temp"); 
    }   

}
//-------------------------------------------
void excluirConsumidor() //Procedimento - exclui consumidor
{
    
    FILE *fp, *Tfp, *Cfp, *TCfp; //ponteiro para aquivo
    char excluida[TAM_MAX];
    int achei = 0;

    struct consumidor consumidor;
    struct contrato contrato;

    fp = fopen("consumidor.txt", "r+b"); //abrindo o arquivo binário consumidores.txt para leitura/escrita 
    Tfp = fopen("consumidor.temp", "a+b"); //criando o arquivo binário usinas.temporario para leitura/escrita
    
    if (fp != NULL && Tfp != NULL) //se os arquivos não estiverem vazios ou criados
    {
        fseek(fp, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo
        fseek(Tfp, 0, SEEK_END); //posicionando ponteiro no final do arquivo

        printf("Digite o CPF/CNPJ do consumidor que vai ser excluido: ");
        scanf("%s", &excluida); //leitura do cnpj/cpf que vai ser excluido

        while (fread(&consumidor, sizeof(consumidor), 1, fp) == 1) //Leitura até o final do arquivo
        {
            if (strcmp(excluida, consumidor.id) != 0) //escrever todos os dados dos consumidores exceto do consumidor excluido
                fwrite(&consumidor, sizeof(consumidor), 1, Tfp); //escrevendo toda a struct
            else
                achei = 1;
        }

        if (achei == 1)
            printf("Consumidor excluido com sucesso!\n");
        else
            printf("Consumidor nao cadastrado!");

        fclose(fp); //fechando o arquivo binário consumidor.txt
        fclose(Tfp); //fechando o arquivo binário consumidor.temporario

        remove("consumidor.txt"); //removendo o arquivo binário consumidor.txt
        rename("consumidor.temp", "consumidor.txt"); //renomeando o arquivo binário consumidor.temporario para consumidores.txt

        Cfp = fopen("contratos.txt", "r+b"); //abrindo o arquivo binário contratos.txt para leitura/escrita
        TCfp = fopen("contratos.temp", "a+b"); //criando o arquivo binário contratos.temporario para leitura/escrita

        if (Cfp != NULL && TCfp != NULL) //se os arquivos não estiverem vazios ou criados
        {
            fseek(Cfp, 0, SEEK_SET); //posicionando ponteiro no inicio do arquivo
            fseek(TCfp, 0, SEEK_END); //posicionando ponteiro no final do arquivo

            while (fread(&contrato, sizeof(contrato), 1, Cfp) == 1) //Leitura até o final do arquivo
            {
                if (strcmp(excluida, contrato.id_consumidor) != 0) //escrever todos os dados dos consumidores exceto do consumidor excluido
                    fwrite(&contrato, sizeof(contrato), 1, TCfp); //escrevendo toda a struct
            }

            fclose(Cfp); //fechando o arquivo binário contratos.txt
            fclose(TCfp); //fechando o arquivo binário contratos.temporario

            remove("contratos.txt"); //removendo o arquivo binário contratos.txt
            rename("contratos.temp", "contratos.txt"); //renomeando o arquivo binário contratos.temporario para contratos.txt
        }    
        else 
        {
            fclose(Cfp);
            fclose(TCfp);
            remove("contratos.temp");
        }
        
    }
    else //mostra na tela quando o arquivo de consumidores não existe ainda
    {
        printf("\nCadastre consumidores primeiro!\n");  
        fclose(fp); 
        fclose(Tfp);
        remove("consumidor.temp"); 
    }       

}

#endif /*_221008516_H_*/