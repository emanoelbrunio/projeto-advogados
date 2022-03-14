#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//estrutura de advogado
typedef struct {
   char nome_adv [50];
   int numero_adv;
   char email_adv[50];
   int inscricao_adv;
   char username_adv[50];
   char senha_adv[50];
} advogado;

//estrutura de clientes
typedef struct {
    char nome_cli[40];
    int numero_cli;
    char email_cli[40];
    int cpf;
} cliente;

//estrutura de endereços
typedef struct {
    char pais [20];
    char estado[20];
    char cidade[30];
    char rua[40];
    int num_casa;
    char ponto_referencia [50];
    char complemento[40];
} endereco;

//funcao para cadastrar advogados
advogado *cadastrar_adv (advogado *v_adv){
    //alocando dinamicamente o vetor
    v_adv = (advogado*) malloc (sizeof (advogado));

    //recebendo as informaçoes e colocando no vetor
    printf("|========================================|\n");
    printf("| Insira seu nome: ");
    scanf("%s", v_adv->nome_adv);
    printf("|----------------------------------------|\n");
    printf("| Numero de celular: ");
    scanf("%d", &v_adv->numero_adv);
    printf("|----------------------------------------|\n");
    printf("| Insira seu e-mail: ");
    scanf("%s", v_adv->email_adv);
    printf("|----------------------------------------|\n");
    printf("| Inscricao de Advogado/Numero da OAB: ");
    scanf("%d", &v_adv->inscricao_adv);
    printf("|----------------------------------------|\n");
    printf("| Username: ");
    scanf("%s", v_adv->username_adv);
    printf("|----------------------------------------|\n");
    printf("| Insira sua senha: ");
    scanf("%s", v_adv->senha_adv);
    printf("|========================================|\n");

    int num_de_clientes = 0;
    FILE *cont = fopen("./contador.txt", "w");
    if (cont == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        system("pause");
        exit(1);
    }
    fprintf(cont, "%d", num_de_clientes);
    fclose(cont);

    //fazendo um arquivo para armazenar os dados do advogado
    FILE *file = fopen("./cadastroAdvogado.txt", "w");

    //veriicando se houve erro ao abrir
    if (file == NULL){
        printf("Ocorreu erro ao abrir arquivo\n");
        system("pause");
        exit(1);
    }

    //arquivo para colocar username e senha
    FILE *arquivos = fopen("./login.txt", "w");

    //verificando se houve erro ao abrir
    if (arquivos == NULL){
        printf("Ocorreu erro ao abrir arquivo\n");
        system("pause");
        exit(1);
    }

    //imprimindo todos os dados nos arquivos
    fprintf(file, "%s\n", v_adv->nome_adv);
    fprintf(file, "%d\n", v_adv->numero_adv);
    fprintf(file, "%s\n", v_adv->email_adv);
    fprintf(file, "%d\n", v_adv->inscricao_adv);
    fprintf(file, "%s\n\n", v_adv->username_adv);
    
    //obrigando a implementação dos dados no arquivo
    fflush(file);

    fprintf(arquivos, "%s\n", v_adv->username_adv);
    fprintf(arquivos, "%s\n", v_adv->senha_adv);
    fflush(arquivos);

    //congelando a tela por 1000mls
    Sleep(1000);

    //limpando a tela
    system("cls");

    //fechando os arquivos
    fclose(arquivos);
    fclose(file);

    //retornando o vetor
    return v_adv;
}

//funcao para imprimir cadastro de advogado
void imprimir (advogado *v_adv){

    //abrindo para ler o arquivo de cadastro de advogado
    FILE *fi = fopen("./cadastroAdvogado.txt", "r");

    //vendo se houve erros ao abrir
    if (fi == NULL){
        printf("Ocorreu erro ao abrir arquivo\n");
        system("pause");
        exit(1);
    }

    //passando os dados do arquivo para o vetor
    fscanf(fi, "%s\n", v_adv->nome_adv);
    fscanf(fi, "%d\n", &v_adv->numero_adv);
    fscanf(fi, "%s\n", v_adv->email_adv);
    fscanf(fi, "%d\n", &v_adv->inscricao_adv);
    fscanf(fi, "%s\n", v_adv->username_adv);

    //imprimindo no terminal os valores que o vetor recebeu
    printf("|==============================================|\n");
    printf("| Nome: %s\n", v_adv->nome_adv);
    printf("|----------------------------------------------|\n");
    printf("| Numero de celular: %d\n", v_adv->numero_adv);
    printf("|----------------------------------------------|\n");
    printf("| E-mail: %s\n", v_adv->email_adv);
    printf("|----------------------------------------------|\n");
    printf("| Inscricao de Advogado/Numero da OAB: %d\n", v_adv->inscricao_adv);
    printf("|----------------------------------------------|\n");
    printf("| Username: %s\n", v_adv->username_adv);
    printf("|==============================================|\n");
    
    //fechando o arquivo
    fclose(fi);
}

//funcao de exemplo de cadastro
void exemplo (advogado exemplos){
    //imprimindo um exemplo de cadastro de advogado
    printf("|             EXEMPLO DE CADASTRO              |\n");
    printf("|==============================================|\n");
    printf("| Nome: %s\n", exemplos.nome_adv);
    printf("|----------------------------------------------|\n");
    printf("| Numero de celular: %d\n", exemplos.numero_adv);
    printf("|----------------------------------------------|\n");
    printf("| E-mail: %s\n", exemplos.email_adv);
    printf("|----------------------------------------------|\n");
    printf("| Inscricao de Advogado/Numero da OAB: %d\n", exemplos.inscricao_adv);
    printf("|----------------------------------------------|\n");
    printf("| Username: %s\n", exemplos.username_adv);
    printf("|----------------------------------------------|\n");
    printf("| Senha: %s\n", exemplos.senha_adv);
    printf("|==============================================|\n\n");
}

//funcao para fazer login
int logar (){

    int resp;    
    //criando var para auxiliar o processo de login
    char login[50];
    char senha[50];
    char verificacao_login[50];
    char verificacao_senha[50];

    //lendo o arquivo de login
    FILE *arq = fopen("./login.txt", "r");

    //verificando de houve erros ao abrir
    if (arq == NULL){
        printf("Ocorreu erro ao abrir arquivo\n");
        system("pause");
        exit(1);
    }

    //passando os dados do arquivo para as var auxiliares
    fscanf(arq, "%s\n", login);
    fscanf(arq, "%s\n", senha);

    //fechando o arquivo
    fclose(arq);
    
    //pedindo que o usuario digite os dados e passando para as var auxiliares
    printf("|====================================|\n");
    printf("|         Username / E-mail          |\n");
    printf("|====================================|\n");
    printf("|RESPOSTA: ");
    scanf("%s", verificacao_login);
    printf("|====================================|\n");
    printf("|                Senha               |\n");
    printf("|====================================|\n");
    printf("|RESPOSTA: ");
    scanf("%s", verificacao_senha);

    //verificando se o que o usuario digitou é igual aos dados do arquivo
    //se for igual, resp recebe 1 e ele retorna
    //se for diferente, retorna 0

    if (strcmp (verificacao_login, login) != 0 || strcmp (verificacao_senha, senha) != 0){
        resp = 0;
    }
    else if (strcmp (verificacao_login, login) == 0 && strcmp (verificacao_senha, senha) == 0){
        resp = 1;
    }
    
    return resp;
}

//funcao para mostrar o menu
int menu () {
    //mostrando o menu e pedindo a resposta do usuario
    // e retornando a escolha feita por ele
    int resposta;
    printf("|===========================================|\n");
    printf("|          O que voce deseja fazer          |\n");
    printf("|===========================================|\n");
    printf("| 1- Cadastrar Cliente                      |\n");
    printf("|-------------------------------------------|\n");
    printf("| 2- Pesquisar Cliente                      |\n");
    printf("|-------------------------------------------|\n");
    printf("| 3- Ver pendencias do dia                  |\n");
    printf("|-------------------------------------------|\n");
    printf("| 4- Cadastrar novo processo                |\n");
    printf("|-------------------------------------------|\n");
    printf("| 5- Atualizar processo existente           |\n");
    printf("|===========================================|\n");
    printf("|  SOBRE AS LISTAS, VEJA AS OPCOES ABAIXO   |\n");
    printf("|===========================================|\n");
    printf("| 6- Adicionar cliente no inico da lista    |\n");
    printf("|-------------------------------------------|\n");
    printf("| 7- Exibir lista                           |\n");
    printf("|-------------------------------------------|\n");
    printf("| 8- Pesquisar por um cliente dessa lista   |\n");
    printf("|-------------------------------------------|\n");
    printf("| 9- Excluir cliente do inicio              |\n");
    printf("|===========================================|\n\n");

    printf("|=============|\n");
    printf("| Resposta: ");
    scanf("%d", &resposta);
    printf("|=============|\n\n\n");
    return resposta;
}

//funcao para cadastrar novos clientes
void cadastrarcliente(cliente *v_cli, int n){

    int i;  //var para controle
    int j; //var para auxiliar o controle

    FILE *contador = fopen("./contador.txt", "r");
    if (contador == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        system("pause");
        exit(1);
    }
    fscanf(contador, "%d", &j);
    fclose(contador);
    
    int tamanho = j + n;

    FILE *cont = fopen("./contador.txt", "w");
    fprintf(cont, "%d", tamanho);
    fclose(cont);

    //o vetor de clientes agora recebe o tamanho que realmente precisa
    v_cli = (cliente*) malloc (tamanho * sizeof(cliente));

    //preenchendo os dados dos vetores a partir de onde está vazio
    // i = j: começa onde a ultima atuallização terminou
    //i < tamanho: enquanto for menor que o novo tamanho
    for (i = j; i < tamanho; i++){
        printf("|========================================|\n");
        printf("| Nome do cliente: ");
        scanf("%s", v_cli[i].nome_cli);
        printf("|----------------------------------------|\n");
        printf("| Numero de celular: ");
        scanf("%d", &v_cli[i].numero_cli);
        printf("|----------------------------------------|\n");
        printf("| E-mail do cliente: ");
        scanf("%s", v_cli[i].email_cli);
        printf("|----------------------------------------|\n");
        printf("| CPF do cliente: ");
        scanf("%d", &v_cli[i].cpf);
        printf("|========================================|\n\n");
    }

    //criando um arquivo para escrever nele os dados dos
    //clientes que foi preenchido anteriormente
    FILE *clientes_arq = fopen("./clientes.txt", "a");
    if (clientes_arq == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        system("pause");
        exit(1);
    }

    //imprimindo esses dados no arquivo
    for (i = j; i < tamanho; i++){
        fprintf(clientes_arq, "%s\n", v_cli[i].nome_cli);
        fprintf(clientes_arq, "%d\n", v_cli[i].numero_cli);
        fprintf(clientes_arq, "%s\n", v_cli[i].email_cli);
        fprintf(clientes_arq, "%d\n", v_cli[i].cpf);   
    }

    //fechando o arquivo
    fclose(clientes_arq);
}

//funcao para pesquisar um cliente no arquivo
void pesquisar(cliente *v_cli, int n, int cpf) {

    //var para iniciar contagem
    int i;

    //var para verificar se foi encontrado algum cliente ou nao
    int v = 0;

    //alocando o vetor que foi recebido como parametro
    v_cli = (cliente*) malloc (n * sizeof(cliente));

    //lendo o arquivo onde tem os dados dos clientes
    FILE *clientes_busca = fopen("./clientes.txt", "r");
    if (clientes_busca == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        system("pause");
        exit(1);
    }

    //adicionando os dados dos clientes do arquivo no vetor
    for (i = 0; i < n; i++){
        fscanf(clientes_busca, "%s", v_cli[i].nome_cli);
        fscanf(clientes_busca, "%d", &v_cli[i].numero_cli);
        fscanf(clientes_busca, "%s", v_cli[i].email_cli);
        fscanf(clientes_busca, "%d", &v_cli[i].cpf);
    }

    fclose(clientes_busca);
    

    //imprimindo os dados do cliente solicitado

    for (i = 0; i < n; i++) {
        //verificando se o cpf da busca é igual o do cliente
        if (v_cli[i].cpf == cpf){
            printf("|========================================|\n");
            printf("| Nome: %s\n", v_cli[i].nome_cli);
            printf("|----------------------------------------|\n");
            printf("| Numero: %d\n", v_cli[i].numero_cli);
            printf("|----------------------------------------|\n");
            printf("| E-mail: %s\n", v_cli[i].email_cli);
            printf("|----------------------------------------|\n");
            printf("| CPF: %d\n", v_cli[i].cpf);
            printf("|========================================|\n");
            //se tiver algum cliente com o cpf de busca, altera o valor de v
            v = 1;
        }
    }

    //se tiver algum cliente
    if (v == 1){
        printf("|======================================|\n");
        printf("| Esse foi o unico cliente encontrado! |\n");
        printf("|======================================|\n");
    }
    //se nao tiver nenhum cliente, informa isso para o usuario
    else if (v == 0){
        printf("|=====================|\n");
        printf("|         OPS!        |\n");
        printf("| CPF nao encontrado  |\n");
        printf("|=====================|\n");  
    }
    
}

//funcao para chamar quando o usuario digitar a senha errada
void esqueci_senha(){
    int teste = 0;
    FILE *cadastro = fopen("./cadastroAdvogado.txt", "r");
    if (cadastro == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        system("pause");
        exit(1);
    }
    advogado adv;
    advogado v;
    fscanf(cadastro, "%s", adv.nome_adv);
    fscanf(cadastro, "%d", &adv.numero_adv);
    fscanf(cadastro, "%s", adv.email_adv);
    fscanf(cadastro, "%d", &adv.inscricao_adv);
    fscanf(cadastro, "%s", adv.username_adv);
    fclose(cadastro);
    
    while (teste == 0){
        printf("| DIGITE AS SUAS INFORMACOES CORRETAS PARA FAZER OUTRA SENHA:\n");
        printf("|========================================|\n");
        printf("| Insira seu nome: ");
        scanf("%s", v.nome_adv);
        printf("|----------------------------------------|\n");
        printf("| Numero de celular: ");
        scanf("%d", &v.numero_adv);
        printf("|----------------------------------------|\n");
        printf("| Insira seu e-mail: ");
        scanf("%s", v.email_adv);
        printf("|----------------------------------------|\n");
        printf("| Inscricao de Advogado/Numero da OAB: ");
        scanf("%d", &v.inscricao_adv);
        printf("|----------------------------------------|\n");
        printf("| Username: ");
        scanf("%s", v.username_adv);
        printf("|----------------------------------------|\n");
        Sleep(1500);
        system("cls");

        if (strcmp(adv.nome_adv, v.nome_adv) == 0 && adv.numero_adv == v.numero_adv &&
        strcmp(adv.email_adv, v.email_adv) == 0 && adv.inscricao_adv == v.inscricao_adv
        && strcmp(adv.username_adv, v.username_adv) == 0){
            
            char novo_login[50];
            char nova_senha[50];
            printf("|-----------------------------------------------|\n");
            printf("| ESCREVA SEU USERNAME NOVAMENTE: ");
            scanf("%s", novo_login);
            printf("|-----------------------------------------------|\n");
            printf("| ESCREVA SUA NOVA SENHA: ");
            scanf("%s", nova_senha);
            printf("|-----------------------------------------------|\n\n");

            FILE *senha = fopen("./login.txt", "w");
            if (senha == NULL){
                printf("ERRO AO ABRIR O ARQUIVO!\n");
                system("pause");
                exit(1);
            }

            fprintf(senha, "%s\n", novo_login);
            fprintf(senha, "%s", nova_senha);
            fclose(senha);

            printf("|=====================================|\n");
            printf("| SUA SENHA FOI ALTERADA COM SUCESSO! |\n");
            printf("|=====================================|\n\n");
            teste = 1;
        }
        else {
            printf("|===========================|\n");
            printf("| ALGUM DADO ESCRITO ERRADO |\n");
            printf("|     RESPONDA NOVAMENTE    |\n");
            printf("|===========================|\n\n");
            teste = 0;
        }
    }
}

int pesquisar_e_cadastrar (cliente *v_cli, int n, int cpf){
    //var para iniciar contagem
    int i;

    //var auxiliar
    int aux = 0;

    //var para verificar se foi encontrado algum cliente ou nao
    int v = 0;

    //alocando o vetor que foi recebido como parametro
    v_cli = (cliente*) malloc (n * sizeof(cliente));

    //lendo o arquivo onde tem os dados dos clientes
    FILE *clientes_busca = fopen("./clientes.txt", "r");
    if (clientes_busca == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        system("pause");
        exit(1);
    }

    //adicionando os dados dos clientes do arquivo no vetor
    for (i = 0; i < n; i++){
        fscanf(clientes_busca, "%s", v_cli[i].nome_cli);
        fscanf(clientes_busca, "%d", &v_cli[i].numero_cli);
        fscanf(clientes_busca, "%s", v_cli[i].email_cli);
        fscanf(clientes_busca, "%d", &v_cli[i].cpf);
    }

    //fechando o arquivo
    fclose(clientes_busca);

    //imprimindo os dados do cliente solicitado
    for (i = 0; i < n; i++){

        //verificando se o cpf da busca é igual o do cliente
        if (v_cli[i].cpf == cpf){
            printf("|========================================|\n");
            printf("| Nome: %s\n", v_cli[i].nome_cli);
            printf("|----------------------------------------|\n");
            printf("| Numero: %d\n", v_cli[i].numero_cli);
            printf("|----------------------------------------|\n");
            printf("| E-mail: %s\n", v_cli[i].email_cli);
            printf("|----------------------------------------|\n");
            printf("| CPF: %d\n", v_cli[i].cpf);
            printf("|========================================|\n\n");

            //se tiver algum cliente com o cpf de busca, altera o valor de v
            aux = i;
            v = 1;
        }
    }
    //se tiver algum cliente

    if (v == 1){
        printf("|======================================|\n");
        printf("| Esse foi o unico cliente encontrado! |\n");
        printf("|======================================|\n");
    }
    //se nao tiver nenhum cliente, informa isso para o usuario
    else if (v == 0){
        printf("|=====================|\n");
        printf("|         OPS!        |\n");
        printf("| CPF nao encontrado  |\n");
        printf("|=====================|\n");  
    }

    return aux;
}

int main (void){
    int menu1;
    int lgn;
    //Lista lista;
    //lista.inicio =  NULL;
    
    //var para entrar no laço de saber o que fazer
    int resp_fazer;
    //vetor de advogado e cliente
    advogado *v_adv;
    cliente *v_cli;
    //var para saber se o login foi efetuado
    int efetuado = 0;
    //var para receber o cpf para busca
    int cpf;
    //numero de elementos
    int n;
    //para garantir que vai entrar no menu
    int rodar_menu = 1;
    //var para receber resposta ao perguntar se quer rodar o menu
    int resp_menu;
    do {
        printf("\n");
        printf("|====================================|\n");
        printf("|         O que deseja fazer?        |\n");
        printf("|====================================|\n");
        printf("| 1- Login                           |\n");
        printf("|------------------------------------|\n");
        printf("| 2- Cadastro                        |\n");
        printf("|------------------------------------|\n");
        printf("| 3- Esqueci minha senha             |\n");
        printf("|====================================|\n\n");
        printf("|=============|\n");
        printf("| Resposta: ");
        scanf("%d", &resp_fazer);
        printf("|=============|\n\n");

        if(resp_fazer != 1 && resp_fazer != 2 && resp_fazer != 3){
            printf("|====================|\n");
            printf("|   Opcao invalida   |\n");
            printf("| Responda novamente |\n");
            printf("|====================|\n");
        }
        Sleep(1000);
        system("cls"); 
    } while (resp_fazer != 1 && resp_fazer != 2 && resp_fazer != 3);
        
    if (resp_fazer == 1){
        do {
            lgn = logar();
            
            if (lgn != 0) {
                printf("|=====================|\n");
                printf("|    login efetuado   |\n");
                printf("|     com sucesso!    |\n");
                printf("|=====================|\n");
                efetuado = 1;
                Sleep(1000);
                system("cls");
            } 
            else if (lgn == 0){
                printf("|=====================|\n");
                printf("|     Username ou     |\n");
                printf("|    senha invalida   |\n");
                printf("|=====================|\n");

                Sleep(1000);
                system("cls");
            }
        } while (lgn == 0);
    }

    else if (resp_fazer == 2){

        //chamando a funcao de exemplo e passando um ex como parametro
        advogado ex = {"Meu nome", 922313129, "Meuemail.com", 123, "MeuUsername", "Umasenhaforte"};
        exemplo(ex);

        //chamando funcao para cadastrar um advogado
        advogado *cad = cadastrar_adv(v_adv);
        printf("|==============================================|\n");
        printf("|        SEU ARQUIVO GRAVOU ESSES DADOS:       | \n");
        imprimir(cad);
        
        Sleep(3000);
        system("cls");

        //fazer login agora
        do {
            int lgn = logar();
            
            if (lgn != 0) {
                printf("|=====================|\n");
                printf("|    login efetuado   |\n");
                printf("|     com sucesso!    |\n");
                printf("|=====================|\n");
                efetuado = 1;
                Sleep(1000);
                system("cls");
            } 
            else if (lgn == 0){
                printf("|=====================|\n");
                printf("|     Username ou     |\n");
                printf("|    senha invalida   |\n");
                printf("|=====================|\n");

                Sleep(1000);
                system("cls");
            }
        } while (lgn == 0);
    }

    else if (resp_fazer == 3){
        esqueci_senha();
        //fazer login agora
        do {
            int lgn = logar();
            
            if (lgn != 0) {
                printf("|=====================|\n");
                printf("|    login efetuado   |\n");
                printf("|     com sucesso!    |\n");
                printf("|=====================|\n");
                efetuado = 1;
                Sleep(1000);
                system("cls");
            } 
            else if (lgn == 0){
                printf("|=====================|\n");
                printf("|     Username ou     |\n");
                printf("|    senha invalida   |\n");
                printf("|=====================|\n");

                Sleep(1000);
                system("cls");
            }
        } while (lgn == 0);
    }

    if (efetuado == 1){
       
        while (rodar_menu == 1){
            
            do {
                menu1 = menu();  
                if (menu1 < 0 || menu1 > 9){
                    printf("|=====================|\n");
                    printf("|        OPS!!!       |\n");
                    printf("|    opcao invalida   |\n");
                    printf("|=====================|\n");
                    Sleep(1500);
                    system("cls");
                }

            } while (menu1 < 0 || menu1 > 9);
            
            if (menu1 == 1){
                printf("|======================================|\n");
                printf("| QUANTOS CLIENTES DESEJA CADASTRAR: ");
                scanf("%d", &n);
                printf("|=====================================|\n");
                cadastrarcliente(v_cli, n);

                Sleep(1500);
                system("cls");

                do {
                    printf("|==============================|\n");
                    printf("| Deseja voltar ao menu        |\n");
                    printf("|------------------------------|\n");
                    printf("| 1 - Sim                      |\n");
                    printf("|------------------------------|\n");
                    printf("| 2 - Nao                      |\n");
                    printf("|==============================|\n");
                    printf("|=============|\n");
                    printf("| Resposta: ");
                    scanf("%d", &resp_menu);
                    printf("|=============|\n\n");

                    Sleep(1500);
                    system("cls");

                    if (resp_menu == 1){
                        rodar_menu = 1;
                    }
                    else if (resp_menu == 2){
                        rodar_menu = 0;
                    }
                    else {
                        printf("RESPOSTAS INVALIDA, RESPONDA NOVAMENTE\n\n");
                        Sleep(1500);
                        system("cls");
                    }
                } while (resp_menu != 1 && resp_menu != 2);
            }

            if (menu1 == 2){
                // fazer busca
                printf("|=======================================|\n");
                printf("|                  BUSCA                |\n");
                printf("|---------------------------------------|\n");
                printf("| Numero do CPF do cliente: ");
                scanf("%d", &cpf);
                printf("|=======================================|");
                printf("\n\n");
   
                FILE *conta = fopen("./contador.txt", "r");
                if (conta == NULL){
                    printf("ERRO AO ABRIR O ARQUIVO!\n");
                    system("pause");
                    exit(1);
                }
                fscanf(conta, "%d", &n);
                fclose(conta);

                pesquisar(v_cli, n, cpf);
                
                cpf = 0;
                n = 0;

                do {
                    printf("|==============================|\n");
                    printf("| Deseja voltar ao menu        |\n");
                    printf("|------------------------------|\n");
                    printf("| 1 - Sim                      |\n");
                    printf("|------------------------------|\n");
                    printf("| 2 - Nao                      |\n");
                    printf("|==============================|\n");
                    printf("|=============|\n");
                    printf("| Resposta: ");
                    scanf("%d", &resp_menu);
                    printf("|=============|\n\n");

                    Sleep(1500);
                    system("cls");

                    if (resp_menu == 1){
                        rodar_menu = 1;
                    }
                    else if (resp_menu == 2){
                        rodar_menu = 0;
                    }
                    else {
                        printf("RESPOSTAS INVALIDA, RESPONDA NOVAMENTE\n\n");
                        Sleep(1500);
                        system("cls");
                    }
                } while (resp_menu != 1 && resp_menu != 2);
                       
            }
           
            if (menu1 == 3){
                //pendencias();
                printf("PENDENCIAS INDISPONIVEIS NO MOMENTO!\n");
            }
            
            if (menu1 == 4){
                printf("|=======================================|\n");
                printf("|   ANTES DE INSERIR UM NOVO PROCESSO   |\n");
                printf("|     PRECISAMOS BUSCAR UM USUARIO!     |\n");
                printf("|=======================================|\n\n");

                printf("|=======================================|\n");
                printf("|                  BUSCA                |\n");
                printf("|---------------------------------------|\n");
                printf("| Numero do CPF do cliente: ");
                scanf("%d", &cpf);
                printf("|=======================================|");
                printf("\n\n");
   
                FILE *contadores = fopen("./contador.txt", "r");
                if (contadores == NULL){
                    printf("ERRO AO ABRIR O ARQUIVO!\n");
                    system("pause");
                    exit(1);
                }
                fscanf(contadores, "%d", &n);
                fclose(contadores);
                //int pesquisa = pesquisar_e_cadastrar(v_cli, n, cpf);

                do {
                    printf("|==============================|\n");
                    printf("| Deseja voltar ao menu        |\n");
                    printf("|------------------------------|\n");
                    printf("| 1 - Sim                      |\n");
                    printf("|------------------------------|\n");
                    printf("| 2 - Nao                      |\n");
                    printf("|==============================|\n");
                    printf("|=============|\n");
                    printf("| Resposta: ");
                    scanf("%d", &resp_menu);
                    printf("|=============|\n\n");

                    Sleep(1500);
                    system("cls");

                    if (resp_menu == 1){
                        rodar_menu = 1;
                    }
                    else if (resp_menu == 2){
                        rodar_menu = 0;
                    }
                    else {
                        printf("RESPOSTAS INVALIDA, RESPONDA NOVAMENTE\n\n");
                        Sleep(1500);
                        system("cls");
                    }
                } while (resp_menu != 1 && resp_menu != 2);
    
            }
            
            if (menu1 == 5){
                //atualizarprocesso();
                printf("ATUALIZAR PROCESSO INDISPONIVEL NO MOMENTO!\n");
            }   
        }     
    }
    return 0;
}

/*
    char nomea[200];
    scanf("%s", nomea);
    strcat(nomea, ".txt");
    FILE *nomesim = fopen(nomea, "w");

    var para ajudar a ordenar
    int j;

    //var para auxiliar na troca
    cliente auxiliar;

    //percorrendo o vetor e ordenando
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (v_cli[j].cpf > v_cli[j + 1].cpf){
                auxiliar = v_cli[j + 1];
                v_cli[j + 1] = v_cli[j];
                v_cli[j] = auxiliar;
            }
        }
    }

*/