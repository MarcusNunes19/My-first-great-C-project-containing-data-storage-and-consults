#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Veiculos.h"
#include "Vendas.h"

veiculo registrarVeic(veiculo Veic, int qtdFila, int qtdCol, char motorista[100], char placa[8])
{
    printf("Rodando 1\n");
    char vago[2] = "V", resevado[2] = "R", situacao[2];
    FILE *arqVeic = fopen("veiculos.txt", "a");
    if(arqVeic == NULL){
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    printf("Rodando 2\n");
    Veic.assentos = malloc(qtdFila * sizeof(int*));
    for (int i = 0; i < qtdFila; i++)
    {
        Veic.assentos[i] = malloc(qtdCol * sizeof(int));
    }

    printf("Rodando 3\n");
    for (int x = 0; x < qtdFila; x++)
    {
        for (int y = 0; y < qtdCol; y++)
        {
            Veic.assentos[x][y] = 0;
        }
    }
    Veic.qtdL = qtdFila;
    Veic.qtdC = qtdCol;

    strcpy(Veic.placa, placa);
    strcpy(Veic.motorista, motorista);

    printf("Rodando 4\n");
    fprintf(arqVeic, " %s\t%s\t%d\t%d\n", Veic.motorista, Veic.placa, Veic.qtdL, Veic.qtdC);
    for(int x = 0; x < Veic.qtdL; x++){
    printf("Rodando 5, %d\n", x);
        for(int y = 0; y < Veic.qtdC; y++){
        printf("Rodando 5, %d\n", y);
            if(Veic.assentos[x][y] == 0){
                strcpy(situacao, vago);
                fprintf(arqVeic, " %s\t", situacao);
            } else {
                strcpy(situacao, resevado);
                fprintf(arqVeic, " %s\t", situacao);
            }
        }
        fprintf(arqVeic, "\n");
    }
    fclose(arqVeic);

    return Veic;
}

// exibe as informações do veiculo selecionado
void mostrarInfo(veiculo Veic)
{
    printf("placa: %s\n", Veic.placa);
    printf("Motorista: %s\n", Veic.motorista);
    printf("Assentos:\n");
    for (int x = 0; x < Veic.qtdL; x++)
    {
        for (int y = 0; y < Veic.qtdC; y++)
        {
            printf("(%d,%d) = ", x + 1, y + 1);
            printf("%d", Veic.assentos[x][y]);
        }
        printf("\n");
    }
}
// ignorem este por agr estou tentando fazer o padrão de 'a1', 'a2', 'b1'... se transformarem em 2 numeros para poder gerar uma coordenada de matriz
void converterBanco(char pos[3], int *x, int *y)
{
    char a = pos[1];
    
    if (pos[0] == 'a' || pos[0] == 'A')
    {
        *x = 0;
    }
    else if (pos[0] == 'b' || pos[0] == 'B')
    {
        *x = 1;
    }
    else if (pos[0] == 'c' || pos[0] == 'C')
    {
        *x = 2;
    }
    else if (pos[0] == 'd' || pos[0] == 'D')
    {
        *x = 3;
    }
    else if (pos[0] == 'e' || pos[0] == 'E')
    {
        *x = 4;
    }
    else if (pos[0] == 'f' || pos[0] == 'F')
    {
        *x = 5;
    }
    else
    {
        printf("erro posição desconhecida"); 
    }

    if(a == '1'){
        *y = 0;
    }else if(a == '2'){
        *y = 1;
    }else if(a == '3'){
        *y = 2;
    }else if(a == '4'){
        *y = 3;
    }else{
        printf("erro posição desconhecida");
    }
}
void registra(veiculo *Veic, int lPol, int cPol, int passagem)
{
    Veic->assentos[lPol][cPol] = passagem;
}

bool aprovaPassagem(int linha, int col, int numPassagem, char placa){
    
    bool resultado;
    char fim;
    char assento[2];
    veiculo Veic;
    FILE *arqVeic = fopen("veiculos.txt", "r");
    if(arqVeic == NULL){
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    for (resultado = false; resultado != true;)
    {
        fim = fgetc(arqVeic);
        fscanf(arqVeic, " %[^\t] %[^\t] %d %d", Veic.motorista, Veic.placa, &Veic.qtdL, &Veic.qtdC);
        if (strcmp(Veic.placa, placa) == 0)
        {
            for(int x = 0; x < Veic.qtdL; x++){
                for(int y = 0; y < Veic.qtdC; y++){
                    
                    fscanf(arqVeic, " %[^\t]", assento);
                    if(x == linha && y == col){
                        if(strcmp(assento, "R") == 0){
                            return false;
                            fclose(arqVeic);
                        }
                    }   
                }
            }
            resultado = true;
        }
        else if (fim == EOF)
        {
            printf("veiculo não encontrada\n");
            resultado = true;
        }
    }
    fclose(arqVeic);
    
    return true;
}


void registroCadeia(veiculo Veic, int qtdClientes)
{
    int x, lpol, cpol, passagem;
    FILE *arq = fopen("passagens.txt", "r");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    for (x = 0; x < qtdClientes; x++)
    {

        printf("Digite a fileira: ");
        scanf("%d", &lpol);
        printf("Digite a Coluna: ");
        scanf("%d", &cpol);
        printf("Digite o codigo da passagem: ");
        scanf("%d", &passagem);
        if (lpol < Veic.qtdL && cpol < Veic.qtdC && passagem > 0)
        {
            registra(&Veic, lpol, cpol, passagem);
        }
        else
        {
            printf("erro\n");
            x--;
        }
    }
}

void imprimirLista(char placa[8])
{
    char fim;
    bool resultado;
    veiculo Veic;
    Passagem pass;
    FILE *arq = fopen("passagens.txt", "r");
    if(arq == NULL){
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    FILE *arqVeic = fopen("veiculos.txt", "r");
    if(arq ==  NULL){
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    } 

    for (resultado = false; resultado != true;)
    {
        fim = fgetc(arqVeic);
        fscanf(arqVeic, " %[^\t] %[^\t] %d %d", Veic.motorista, Veic.placa, &Veic.qtdL, &Veic.qtdC);
        if (1 == 1) //em processo...
        {
           
            resultado = true;
        }
        else if (fim == EOF)
        {
            
            resultado = true;
        }
    }
    fclose(arq);
    

    for (int x = 0; x < Veic.qtdL; x++)
    {
        for (int y = 0; y < Veic.qtdC; y++)
        {
            if (Veic.assentos[x][y] != 0)
            {
                printf("---------------------------------------------------------------\n");
                printf("Nome do Cliente: %s, passagem n %d, assento (%d, %d)\n", pass.nomeCliente, Veic.assentos[x][y], x, y); // juntar com o cod do andre e do marcos
                printf("---------------------------------------------------------------\n");
            }
        }
    }
}

