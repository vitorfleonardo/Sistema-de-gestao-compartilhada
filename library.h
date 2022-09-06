#ifndef _LIBRARY_H_
#define _LIBRARY_H_

struct data_inicio_operacao
{
    int mes;
    int dia;
    int ano;
};

struct cadastro_usina
{
    char nome[21]; 
    float potencia;
    char cnpj[19];
    
    struct data_inicio_operacao data;
};
struct cadastro_usina usina;

struct cadastro_consumidor
{
    char cnpj[19];
    char cpf[15]; 
    char nome[21];
};
struct cadastro_consumidor consumidor;

struct cadastro_contrato
{
    int mes;
    int dia;
    int ano;
    float potencia;
};
struct cadastro_contrato contrato;

//**********Geral**********
void menu(void); //Procedimento - exibir Menu

void procedimento_sucesso(void); //Procedimento - definir fim e sucesso do procedimento selecionado pelo usuario

//**********validacoes**********
int valida_cnpj(char *cnpj); //Funcao - validar CNPJ

int valida_potencia(float pot); //Funcao - validar potencia estimada

int valida_data(int dia, int mes, int ano); //Funcao - validar a data de inicio de operacao

int valida_cpf(char *cpf); //Funcao - validar CPF

//**********Usina**********
void cadastro_usina_arquivo(char *cnpj, int dia, int mes, int ano, float potencia, char *nome); //Procedimento arquivar informacoes da Usina

int recebimento_dados_usina(void); //Procedimento - recebimento de dados Usina

void cadastro_usina(void); //Procedimento - valida o recebimento de dados e chama procedimento de arquivar

void consulta_usinas_cadastradas(void); //Procedimento - le o arquivo com usinas cadastradas e exibe elas

//**********Consumidor**********
void cadastro_consumidor_arquivo(char *cnpj, char *cpf, char *nome); //Arquivando informacoes da Consumidor

void recebimento_dados_consumidor(void); //Funcao - recebimento de dados Consumidor

void cadastro_consumidor(void); //Procedimento - valida o recebimento de dados e chama procedimento de arquivar

//**********Contrato**********
void cadastro_contrato(void); //Procedimento - recebimento de dados para Contrato














#endif /*_LIBRARY_H_*/
