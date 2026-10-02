#include <stdio.h>

int main()
{
    int i, j, aux, cont, TAM =6; // variaveis do Bubblesort.
    int prioridade[TAM];      // Variavel de prioridade.
    int idade[TAM];
    int resposta;
    int I = 0;
    char nome[TAM][20];

    for (i = 0; i < TAM; i++)
    {
        printf("Digite seu nome:");
        scanf("%s", nome[i]);
        printf("Digite sua idade:");
        scanf("%d", &idade[i]);
        if (idade[i] >= 80)
        {
            prioridade[i] = 3;
        }
        if (idade[i] < 80)
        {
            do
            {
                printf("Possui algum fator de prioridade? (1-Sim/2-Não):");
                scanf("%d", &resposta);

                I = 0;
                switch (resposta)
                {
                case 1:
                    prioridade[i] = 2;
                    break;
                case 2:
                    prioridade[i] = 1;
                    break;
                default:
                    printf("Opção inválida!");
                    I = 1;
                }
            } while (I == 1);
        }
    }
}
