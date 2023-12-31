#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "FunCad.h"
#include "Vendas.h"
#include "Buscas.h"

int main()
{
    int resposta, resp2;
    int **passageiros;
    bool loop = true;
    bool loop_2 = true;
    bool loop_3 = true;

    // MATRIZ QUE VAI GUARDAR OS PASSAGEIROS
    passageiros = (int **)malloc(4 * sizeof(int *));

    for (int i = 0; i < 4; i++)
    {
        passageiros[i] = (int *)malloc(4 * sizeof(int *));
    }

// SE��O DE MENUS E FUN��ES
MENU00:
    while (loop == true)
    {                                         // MENU PRINCIPAL
        printf("[1]: Cadastro de Cliente\n"); // cadastrar cliente
        printf("[2]: Venda de Passagem\n");   // vender  e cadastrar cliente com rota
        printf("[3]: Relatorios e Listas\n"); // gerar passagem, gerar lista com passageiros.
        printf("[4]: Sair\n");                // Encerrar o programa todo

        printf("Escolha uma das opcoes: "); // NAVEGA��O
        scanf("%d", &resposta);
        system("cls");

        if (resposta == 1)
        { // ACESSO AO CADASTRO DE CLIENTE
            // loop_2 = true;
            cadastrar_cliente();
            system("cls");
        }

    TELA2:
        if (resposta == 2)
        { // ABRIR VENDA DE PASSAGEM
            passagem();
        }

    TELA3:
        if (resposta == 3)
        { // ABRIR RELAT�RIOS E LISTAS
            loop_3 = true;

            while (loop_3 == true)
            {

                printf("[1] Consulta de Cliente \n");       // Consulta de Cliente;
                printf("[2] Reimpress�o de Passagem \n");   // Reimpress�o de passagem;
                printf("[3] Lista de Passageiros \n");      // Impress�o de Lista de Passageiros nas Rotas;
                printf("[4] Retornar ao Menu Anterior \n"); // Retorna ao Menu Principal;

                printf("Escolha uma das opcoes: "); // NAVEGA��O
                scanf("%d", &resp2);

                if (resp2 == 1)
                {
                    consultarCliente();
                }
                else if (resp2 == 2)
                {
                    reimprimirPassagem();
                }
                else if (resp2 == 3)
                {
                    chamarListaCliente();
                }
                else if (resp2 == 4)
                {
                    loop_3 = false;
                    system("cls");
                }
            }
        }

        if (resposta == 4)
        {
            loop = false;
            printf("Programa Encerrado");
        }
    }
    return 0;
}
