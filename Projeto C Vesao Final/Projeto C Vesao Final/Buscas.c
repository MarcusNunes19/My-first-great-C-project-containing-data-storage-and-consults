#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Vendas.h"
#include "Buscas.h"

void reimprimirPassagem()
{

    char fim;
    bool resultado;
    int convesor, numeroPassagem;
    Passagem a;

    printf("Digite o codigo da passagem: "); 
    scanf("%d", &numeroPassagem);

    FILE *arquivoPassagem = fopen("passagens.txt", "r");
    if (arquivoPassagem == NULL)
    {
        perror("Erro ao abrir o arquivo de passagens");
        exit(EXIT_FAILURE);
    }

    for (resultado = false; resultado != true;)
    {
        fim = fgetc(arquivoPassagem);
        fscanf(arquivoPassagem, " %[^\t] %[^\t] %[^\t] %[^\n]", a.nomeCliente, a.codigo, a.assento, a.horario);
        convesor = atoi(a.codigo);
        if (numeroPassagem == convesor)
        {
            printf("----------------------------\n");
            printf("Cliente: %s\n", a.nomeCliente);
            printf("Codigo: %s\n", a.codigo);
            printf("Assento: %s\n", a.assento);
            printf("Horario: %s\n", a.horario);
            printf("----------------------------\n");
            resultado = true;
        }
        else if (fim == EOF)
        {
            printf("passagem não encontrada\n");
            resultado = true;
        }
    }
    fclose(arquivoPassagem);
}

void chamarListaCliente()
{
    Cliente cliente;
    char save[12];
    FILE *arq = fopen("Dados Clientes.bin", "rb");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (bool resultado = false; resultado != true;)
    {

        fscanf(arq, " %[^\t] %[^\t] %[^\t] %d", cliente.cpf, cliente.nome, cliente.rg, &cliente.idade);
        if (strcmp(save, cliente.cpf))
        {
            printf("Cliente: %s, CPF:%s, RG:%s e idade: %d\n", cliente.nome, cliente.cpf, cliente.rg, cliente.idade);
            printf("-------------------------------------------\n");
        }
        if (feof(arq) != 0)
        {
            resultado = true;
        }
        strcpy(save, cliente.cpf);
    }
}

void consultarCliente()
{

    bool resultado;
    char fim, save[10];
    int convert1, b;
    Cliente a;
    Passagem c;

    FILE *arquivoPassagem = fopen("passagens.txt", "r");
    if (arquivoPassagem == NULL)
    {
        perror("Erro ao abrir o arquivo de passagens");
        exit(EXIT_FAILURE);
    }

    FILE *arqClientes = fopen("Dados clientes.bin", "rb");
    if (arqClientes == NULL)
    {
        perror("Erro ao abrir o arquivo de clientes");
        exit(EXIT_FAILURE);
    }

    printf("Digite o CPF do cliente Procurado: ");
    scanf("%d", &b);

    for (resultado = false; resultado != true;)
    {
        fim = fgetc(arqClientes);
        fscanf(arqClientes, " %[^\t] %[^\t] %[^\t] %d", a.cpf, a.nome, a.rg, &a.idade);
        convert1 = atoi(a.cpf);
        if (convert1 == b)
        {
            printf("-----------------------\n");
            printf("Nome: %s\n", a.nome);
            printf("Idade: %d\n", a.idade);
            printf("CPF: %s\n", a.cpf);
            printf("RG: %s\n", a.rg);
            printf("Passagens:\n");
            printf("----------------------------\n");
            for (char f = fgetc(arquivoPassagem); f != EOF; f = fgetc(arquivoPassagem))
            {
                fscanf(arquivoPassagem, " %[^\t] %[^\t] %[^\t] %[^\n]", c.nomeCliente, c.codigo, c.assento, c.horario);
                if (strcmp(a.nome, c.nomeCliente) == 0 && strcmp(save, c.codigo) != 0)
                {
                    printf("Codigo: %s\n", c.codigo);
                    printf("Assento: %s\n", c.assento);
                    printf("Horario: %s\n", c.horario);
                    printf("----------------------------\n");
                    strcpy(save, c.codigo);
                }
            }
            resultado = true;
        }
        else if (fim == EOF)
        {
            printf("Nenhum cliente encontrado com este CPF\n");
            resultado = true;
        }
    }
    fclose(arqClientes);
    fclose(arquivoPassagem);
}
