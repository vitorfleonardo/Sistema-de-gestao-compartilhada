
void casdatro()
{

    int opt;

    printf("\n1) Cadastrar usando CNPJ\n");
    printf("2) Cadastrar usando CPF\n");
    printf("\nEscolha o numero da opcao desejada:\n");
    scanf("%d", &opt);

    if (opt == 1) //Cadastro Conumidor - usando CNPJ
    {
        
        do
        {
            printf("Digite o CNPJ (xx.xxx.xxx/xxxx-xx):\n");
            fflush(stdin);
            fgets(consumidor.cnpj, 19, stdin);


            if (verificaConsumidor()) //verifica se o consumidor ja esta cadastrado
                printf("Consumidor ja cadastrada, digite novamente\n");
            
            if (!validaCnpj(consumidor.cnpj)) //verifica o cnpj do consumidor a ser cadastrado
                printf("CNPJ invalido, digite novamente\n");

        } while (verificaConsumidor() || !validaCnpj(consumidor.cnpj));
        //loop que verifica se o valor digiado é valido ou se o consumidor já foi cadastrado

    }  
    else if (opt == 2) //Cadastro Conumidor - usando CPF
    {
        do
        {
            printf("\nDigite o CPF (xxx.xxx.xxx-xx):\n");
            fflush(stdin);
            fgets(consumidor.cnpj, 19, stdin);


            if (verificaConsumidor()) //verifica se o consumidor ja esta cadastrado
                printf("Consumidor ja cadastrado, digite novamente\n");
            
            if (!validaCpf(consumidor.cpf)) //verifica o cpfda usina a ser cadastrado
                printf("CPF invalido, digite novamente\n");

        } while (verificaConsumidor() || !validaCnpj(consumidor.cnpj));
        //loop que verifica se o valor digiado é valido ou se o consumidor já foi cadastrado
    } 


    do
    {
        fflush(stdin);
        printf("Digite o Nome da Usina:\n");
        aux = scanf("%s", consumidor.nome); 

        if (aux == 0)
            printf("Nome invalido, digite novamente\n");

    } while (aux == 0);
    //receber e verificar nome da Usina
}