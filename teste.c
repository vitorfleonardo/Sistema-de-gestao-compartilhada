int valida_cnpj(char *cnpj) //Funcao - validar o CNPJ - receber um cnpj = 46990336000112
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cnpj) != 13)
        return 0; //CNPJ tem que ter 14 caracteres no total
    else if((strcmp(cnpj,"0000000000000") == 0) || (strcmp(cnpj,"1111111111111") == 0) || (strcmp(cnpj,"2222222222222") == 0) ||
            (strcmp(cnpj,"3333333333333") == 0) || (strcmp(cnpj,"4444444444444") == 0) || (strcmp(cnpj,"5555555555555") == 0) ||
            (strcmp(cnpj,"6666666666666") == 0) || (strcmp(cnpj,"7777777777777") == 0) || (strcmp(cnpj,"8888888888888") == 0) ||
            (strcmp(cnpj,"9999999999999") == 0))
        return 0; //CNPJ com todos os números iguais é invalido
    else
    {
        //digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        //digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}