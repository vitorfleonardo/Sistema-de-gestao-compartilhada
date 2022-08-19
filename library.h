#ifndef _LIBRARY_H_
#define _LIBRARY_H_

struct cadastro_usina
{
    char nome[61];
    float potencia;
    char cnpj[14];
    char data[8];
};
struct cadastro_usina usina;

struct cadastro_consumidor
{
    char cnpj[14];
    char cpf[11]; 
    char nome[61];
};
struct cadastro_consumidor consumidor;

//**********Geral**********
void menu(void); //Procedimento - exibir Menu



//**********Usina**********
int cadastro_usina(); //Procedimento - recebimento de dados

int valida_cnpj(usina); //Funcao - validar o CNPJ 

int valida_data(usina); //Funcao - validar a data de inicio de operacao

int valida_potencia(usina); //Funcao - validar potencia estimada

//**********Consumidor**********
int valida_cnpj(consumidor); //Funcao - validar o CNPJ

int valida_cpf(consumidor); //Funcao - validar o CPF





#endif /*_LIBRARY_H_*/
