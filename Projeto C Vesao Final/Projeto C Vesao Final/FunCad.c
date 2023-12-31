#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "FunCad.h"
#include "Vendas.h"

void checar_carac(char *vet, int tam)
{ // FUN��O PARA CHECAR QUANTIDADE DE CARACTERES

    int qtd2;

    qtd2 = strlen(vet);

    while (qtd2 != tam)
    {
        printf("O numero de caracteres nao condiz!\n");
        printf("Digite novamente:");
        scanf("%s", vet);

        qtd2 = strlen(vet);
    }
}

void cadastrar_cliente()
{
    FILE *clientes;
    struct cliente cadastroCliente;

    printf("Informe o nome do Cliente: "); // INFORMAR NOME E GARANTIR QUANTIDADE CORRETA DE CARACTERES
    scanf(" %[^\n]", cadastroCliente.nome);

    printf("Informe o cpf do Cliente: "); // INFORMAR CPF E GARANTIR QUANTIDADE CORRETA DE CARACTERES
    scanf(" %[^\n]", cadastroCliente.cpf);

    checar_carac(cadastroCliente.cpf, 11); // Fun��o que faz a checagem

    printf("Informe o RG do Cliente: "); // INFORMAR RG E GARANTIR QUANTIDADE CORRETA DE CARACTERES
    scanf(" %[^\n]", cadastroCliente.rg);

    checar_carac(cadastroCliente.rg, 7); // Fun��o que faz a checagem

    printf("Informe a idade do passageiro: ");
    scanf(" %d", &cadastroCliente.idade);

    clientes = fopen("Dados Clientes.bin", "ab+");
    if (clientes == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    fprintf(clientes, "%s\t %s\t%s\t%d\n", cadastroCliente.cpf, cadastroCliente.nome, cadastroCliente.rg, cadastroCliente.idade);
    fclose(clientes);
}

void passagem()
{

    int resposta;
    int resposta2;
    bool loop = true;
    bool loop2 = true;

    while (loop == true)
    {

        printf("SELECIONE UMA ROTA: \n");
        printf("[1]STA HELENA --> FOZ DO IGUACU PRECO: R$39,50\n");
        printf("[2]STA HELENA --> MEDIANEIRA PRECO: R$25,00 \n");
        printf("[3]STA HELENA --> TOLEDO PRECO: R$30,00 \n");
        printf("[4]STA HELENA --> TUCURUI PRECO: R$519,00 \n");
        printf("[5]RETORNAR AO MENU PRINCIPAL\n");

        printf("Escolha:");
        scanf("%d", &resposta);

        if (resposta == 1)
        { // ESCOLHA DA PRIMEIRA ROTA
            loop2 = true;

            system("cls");
            while (loop2 == true)
            {

                printf("STA HELENA --> FOZ DO IGUACU PRECO: R$39,50\n");
                printf("[1]Comprar\n");
                printf("[2]Retornar\n");

                printf("Escolha:");
                scanf("%d", &resposta2);

                if (resposta2 == 1)
                {
                    confirmar_venda();
                    loop2 = false;
                }

                else if (resposta2 == 2)
                {
                    loop2 = false;
                    system("cls");
                }

                else
                {
                    printf("Coloque somente valores validos!\n");
                }
            }
        }

        else if (resposta == 2)
        { // ESCOLHA DA SEGUNDA ROTA
            loop2 = true;

            system("cls");
            while (loop2 == true)
            {

                printf("STA HELENA --> MEDIANEIRA PRECO: R$25,00\n");
                printf("[1]Comprar\n");
                printf("[2]Retornar\n");

                printf("Escolha:");
                scanf("%d", &resposta2);

                if (resposta2 == 1)
                {
                    confirmar_venda();
                    loop2 = false;
                }

                else if (resposta2 == 2)
                {
                    loop2 = false;
                    system("cls");
                }
                else
                {
                    system("cls");
                    printf("Coloque somente valores validos!\n");
                }
            }
        }

        if (resposta == 3)
        { // ESCOLHA DA TERCEIRA ROTA
            loop2 = true;
            system("cls");
            while (loop2 == true)
            {

                printf("STA HELENA --> TOLEDO PRECO: R$30,00\n");
                printf("[1]Comprar\n");
                printf("[2]Retornar\n");

                printf("Escolha:");
                scanf("%d", &resposta2);

                if (resposta2 == 1)
                {
                    confirmar_venda();
                    loop2 = false;
                }

                else if (resposta2 == 2)
                {
                    loop2 = false;
                    system("cls");
                }
                else
                {
                    system("cls");
                    printf("Coloque somente valores validos!\n");
                }
            }
        }
        else if (resposta == 4)
        { // ESCOLHA DA QUARTA ROTA
            loop2 = true;
            system("cls");
            while (loop2 == true)
            {

                printf("STA HELENA --> TUCURUI PRECO: R$519,00\n");
                printf("[1]Comprar\n");
                printf("[2]Retornar\n");

                printf("Escolha:");
                scanf("%d", &resposta2);

                if (resposta2 == 1)
                {
                    confirmar_venda();
                    loop2 = false;
                }
                else if (resposta2 == 2)
                {
                    loop2 = false;
                    system("cls");
                }
            }
        }

        else if (resposta == 5)
        {
            loop = false;
            system("cls");
        }

        else if (resposta > 5)
        {
            system("cls");
            printf("Coloque somente valores validos!\n");
        }
    }
}
