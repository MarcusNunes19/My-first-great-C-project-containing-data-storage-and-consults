#ifndef VENDAS_H
#define VENDAS_H

typedef struct cliente
{ // Estrutura para cliente
    char nome[100];
    int idade;
    char cpf[12];
    char rg[8];
} Cliente;
typedef struct passagem
{ // Estrutura para passagem
    char nomeCliente[100];
    char codigo[10];
    char rota[50];
    char cpfCliente[12];
    char assento[3];
    char horario[10];
} Passagem;

void confirmar_venda();

#endif // VENDAS_H