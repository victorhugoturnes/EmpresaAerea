#include "mainMenuUI.h"

/*!
	@brief mainMenuEscolha, apresenta opções para o usuário e recolhe \
	sua escolha
	@return escolha feita pelo usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
char mainMenuEscolha() {
    char escolha[3], choiceList[] = "0cs";

    /// apresenta tela de menu e lê da entrada padrão a escolha \
	do usuário
    telaMainMenu();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    /// se não é número, retorna a letra minuscula
    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    /// se for número, converte e retorna letra equivalente
    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

/*!
	@brief telaMainMenu, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaMainMenu() {
    ClearScreen();

    printf("Menu Principal:\n\n");

    printf("Escolha uma opcao:\n");
    printf("1) Menu (C)adastros\n");
    printf("2) Menu (S)tatus\n");
    printf("\n");
    printf("0) Sair do Programa\n");
}

void testarCadastros() {
    ClearScreen();

    char *read;

    List *aeronaves = NULL;

    Aeroporto *aeroporto = createAeroporto("aer", "aeroporto de teste 1");
    read = aeroportoToString(aeroporto);
    printf("%s\n", read);
    free(read);

    updateAeroporto(aeroporto, "teste aeroporto 2", "nome");
    read = aeroportoToString(aeroporto);
    printf("%s\n", read);
    free(read);

    updateAeroporto(aeroporto, "teste aeroporto 2", "sigla");
    read = aeroportoToString(aeroporto);
    printf("%s\n", read);
    free(read);

    updateAeroporto(aeroporto, "123", "sigla");
    read = aeroportoToString(aeroporto);
    printf("%s\n", read);
    free(read);

    deleteAeroporto(&aeroporto);
    printf("%p\n", aeroporto);

    Aeronave *aeronave = createAeronave();
    read = aeronaveToString(aeronave);
    printf("%s\n", read);
    free(read);

    aeronaves = insert(aeronaves, aeronave);

    updateAeronave(aeronave, "teste de atualizacao", "modelo");
    read = aeronaveToString(aeronave);
    printf("%s\n", read);
    free(read);

    read = aeronaveToString(aeronaves->info);
    printf("%s\n", read);
    free(read);

    aeronave = createAeronave();
    read = aeronaveToString(aeronave);
    printf("%s\n", read);
    free(read);

    aeronaves = insert(aeronaves, aeronave);

    read = aeronaveToString(aeronaves->info);
    printf("%s\n", read);
    free(read);

    printf("pesquisando todas aronaves com palavra \"teste\"\n");
    List *result = search("teste", aeronaves, (int (*)(void *, void *)) &searchModelo);
    List *tmp = result;

    while (tmp) {
        read = aeronaveToString(tmp->info);
        printf("--> %s\n", read);
        free(read);
        tmp = delete(tmp);
    }

    printf("pesquisando todas aronaves com palavra \"aaaa\"\n");
    result = search("aaaa", aeronaves, (int (*)(void *, void *)) &searchModelo);
    tmp = result;

    while (tmp) {
        read = aeronaveToString(tmp->info);
        printf("--> %s\n", read);
        free(read);
        tmp = delete(tmp);
    }


    printf("pesquisando todas aronaves com palavra \"atual\"\n");
    result = search("atual", aeronaves, (int (*)(void *, void *)) &searchModelo);
    tmp = result;

    while (tmp) {
        read = aeronaveToString(tmp->info);
        printf("%s\n", read);
        free(read);
        tmp = delete(tmp);
    }

    deleteAeronave(&aeronave);
    printf("teste de ponteiro: %p\n", aeronave);

    Pause();
}

/*!
	@brief confirmacaoSaidaMainMenu, pergunta ao usuário se este confirma \
	saída do programa
	@precondition nenhuma
	@postcondition nenhuma
*/
char confirmacaoSaidaMainMenu() {
    char escolha[3] = {0};

    /// pergunta ao usuário se deseja mesmo sair
    ClearScreen();
    printf("Voce deseja sair do programa?\n");
    printf("S / N\n");

    /// lê resposta do usuário
    fflush(stdin);
    fgets(escolha, 2, stdin);
    escolha[0] = (char) tolower(escolha[0]);

    /// enquanto resposta for inválida
    while (escolha[0] != 's' && escolha[0] != 'n') {
        /// limpa tela e pergunta confirmação de saida
        ClearScreen();
        printf("Escolha invalida!\n");
        printf("Voce deseja sair do programa?\n");
        printf("S / N\n");

        /// lê resposta do usuário
        fflush(stdin);
        fgets(escolha, 2, stdin);
        escolha[0] = (char) tolower(escolha[0]);
    }

    /// se usuário deseja sair, retorna 1
    if (escolha[0] == 's') return 1;

    /// caso contrário, retorna 0
    return 0;
}

void populateLists() {
    populateAeroportos();
    populateAeronaves();
    populateClientes();
    populateVoos();
    Pause();
}

void populateAeroportos() {
    FILE *f = fopen("./populate files/aeroportos.txt", "r");
    char line[MAXSTR];
    char sigla[MAXSTR], nome[MAXSTR];

    printf("\nAeroportos:\n");
    while (!feof(f)) {
        fgets(line, MAXSTR, f);
        printf("%s\n", line);
        sscanf(line, "%[^;];%[^;];", sigla, nome);
        if (!contains(sigla, ListaAeroportos, (int (*)(void *, void *)) &searchSigla))
            ListaAeroportos = insert(ListaAeroportos, createAeroporto(sigla, nome));
    }

    fclose(f);
}

void populateAeronaves() {
    FILE *f = fopen("./populate files/aeronaves.txt", "r");
    Aeronave *aeronave = NULL;
    char line[MAXSTR], modelo[MAXSTR];
    double comprimento, altura, envergadura, velocidadeCruzeiro, alcanceMaximo;
    int qntAcentos, qntBanheiros;

    printf("\nAeronaves:\n");
    while (!feof(f)) {
        fgets(line, MAXSTR, f);
        printf("%s\n", line);
        sscanf(line, "%[^;];%lf;%lf;%lf;%lf;%lf;%d;%d;", // NOLINT(cert-err34-c)
               modelo, &comprimento, &altura, &envergadura, &velocidadeCruzeiro, &alcanceMaximo, &qntAcentos,
               &qntBanheiros);
        if (!contains(modelo, ListaAeronaves, (int (*)(void *, void *)) &searchModelo)) {
            aeronave = createAeronave();
            aeronave->modelo = updateString(NULL, modelo);
            aeronave->comprimento = comprimento;
            aeronave->altura = altura;
            aeronave->envergadura = envergadura;
            aeronave->velocidadeCruzeiro = velocidadeCruzeiro;
            aeronave->alcanceMaximo = alcanceMaximo;
            aeronave->qntAcentos = qntAcentos;
            aeronave->qntBanheiros = qntBanheiros;
            ListaAeronaves = insert(ListaAeronaves, aeronave);
        }
    }

    fclose(f);
}

void populateClientes() {
    Cliente *cliente = NULL;
    FILE *f = fopen("./populate files/clientes.txt", "r");
    char line[MAXSTR];
    char nomePrograma[MAXSTR], nomeCliente[MAXSTR];
    char cpf[MAXSTR];
    Categoria categoria;
    int saldoMilhas;

    printf("\nClientes:n");
    while (!feof(f)) {
        fgets(line, MAXSTR, f);
        printf("%s\n", line);
        sscanf(line, "%[^;];%[^;];%[^;];%d;%d", // NOLINT(cert-err34-c)
               nomePrograma, nomeCliente, cpf, &categoria, &saldoMilhas);
        if (!contains(cpf, ListaClientes, (int (*)(void *, void *)) &searchCpf)) {
            cliente = createCliente();
            cliente->nomeCliente = updateString(NULL, nomeCliente);
            cliente->nomePrograma = updateString(NULL, nomePrograma);
            cliente->cpf = updateString(NULL, cpf);
            cliente->categoria = categoria;
            cliente->saldoMilhas = saldoMilhas;
            ListaClientes = insert(ListaClientes, cliente);
        }
    }

    fclose(f);
}

void populateVoos() {
    VooInfo *vooInfo = NULL;
    FILE *f = fopen("./populate files/voos.txt", "r");
    char line[MAXSTR];
    char prefixo[MAXSTR], origem[MAXSTR], destino[MAXSTR];
    int partidaHH, partidaMM, chegadaHH, chegadaMM, duracaoHH, duracaoMM;
    char aeronave[MAXSTR];

    printf("\nVoos:\n");
    while (!feof(f)) {
        fgets(line, MAXSTR, f);
        printf("%s\n", line);
        sscanf(line, "%[^;];%[^;];%[^;];%d:%d;%d:%d;%d:%d;%[^;];", // NOLINT(cert-err34-c)
               prefixo, origem, destino, &partidaHH, &partidaMM, &chegadaHH, &chegadaMM, &duracaoHH, &duracaoMM,
               aeronave);
        if (!contains(prefixo, ListaVoos, (int (*)(void *, void *)) &searchPrefixo)) {
            vooInfo = createVooInfo();
            vooInfo->prefixo = updateString(NULL, prefixo);
            vooInfo->origem = procurarAeroportoSigla(origem);
            vooInfo->destino = procurarAeroportoSigla(destino);
            vooInfo->partida = createHora((char) partidaHH, (char) partidaMM);
            vooInfo->chegada = createHora((char) chegadaHH, (char) chegadaMM);
            vooInfo->duracao = createHora((char) duracaoHH, (char) duracaoMM);
            vooInfo->aeronave = procurarAeronaveModelo(aeronave);

            ListaVoos = insert(ListaVoos, vooInfo);
        }
    }

    fclose(f);
}
