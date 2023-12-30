#ifndef VEICULOS_H
#define VEICULOS_H

typedef struct vec
{

    char motorista[100];
    char placa[8];
    int qtdL;
    int qtdC;
    int **assentos;

} veiculo;

#endif // VEICULOS_H