#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vendas.h"

void confirmar_venda()
{
    int encontrado = 0;
    char fim;
    struct passagem passagem;
    struct cliente busca, a;

    FILE *arqCliente = fopen("Dados Clientes.bin", "rb"); // Busca de CPF
    if (arqCliente == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    printf("Informe o CPF do cliente: ");
    scanf(" %s", busca.cpf);
    printf("CPF buscado: %s\n", busca.cpf); // Linha teste, apagar quando o codigo estiver funcional

    // Procura de Cliente de CPF encontrado no arquivo
    fseek(arqCliente, 0, SEEK_CUR);

    while (encontrado == 0)
    {
        fim = fgetc(arqCliente);
        fscanf(arqCliente, " %[^\t] %[^\t] %[^\t] %d", a.cpf, a.nome, a.rg, &a.idade);
        int i = atoi(a.cpf);
        int f = atoi(busca.cpf);
        if (i == f)
        {
            encontrado = 1;
            // fscanf(arqCliente, " %[^\t] %[^\t] %d", busca.nome, busca.rg, &busca.idade);
        }
        else if (fim == EOF)
        {
            encontrado = 2;
        }
    }
    fclose(arqCliente);

    if (encontrado == 2)
    {
        printf("Cliente nao encontrado.\n");
        return;
    }
    else
    {

        printf("\n-------------------------\n");
        printf("CPF: %s\nNome: %s\nRG: %s\nIdade: %d\n", a.cpf, a.nome, a.rg, a.idade);
        strcpy(passagem.nomeCliente, a.nome);

        printf("Informe o assento: "); // Leitura de informa��es da passagem
        scanf(" %s", passagem.assento);

        printf("Informe o horario de saida: ");
        scanf(" %s", passagem.horario);

        int cod; // Le o c�digo de passagem anterior
        FILE *codigo;
        codigo = fopen("codigo.txt", "r");
        if (codigo == NULL)
        {
            perror("Erro ao abrir o arquivo de codigos");
            return;
        }
        while (fscanf(codigo, "%d", &cod) != EOF)
        {
            // printf("%d", cod);
        }
        fclose(codigo);
        cod++; // Incrementa em 1 o codigo de passagem
        codigo = fopen("codigo.txt", "w");
        if (codigo == NULL)
        {
            perror("Erro ao abrir o arquivo de codigos");
            return;
        }
        fprintf(codigo, "%08d", cod); // Imprime o novo c�digo de passagem no arquivo
        fclose(codigo);
        sprintf(passagem.codigo, "%d", cod);

        // Abertura do arquivo de passagens para escrita (substitua pelo seu arquivo real)
        FILE *arquivoPassagem = fopen("passagens.txt", "a");
        if (arquivoPassagem == NULL)
        {
            perror("Erro ao abrir o arquivo de passagens");
            exit(EXIT_FAILURE);
        }

        // Escrita da passagem no arquivo
        // OBS: tive que adicionar os '\t' para conseguir dividir cada info no momento de pegar as informaçoes

        fprintf(arquivoPassagem, " %s\t%s\t%s\t%s\t%s\n", passagem.nomeCliente, passagem.codigo, passagem.cpfCliente, passagem.assento, passagem.horario);

        fclose(arquivoPassagem);

        printf("Passagem vendida com sucesso. Codigo da passagem: %s\n", passagem.codigo);
    }
}
