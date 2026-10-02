#include <stdio.h>
#include <locale.h>
#define MAX 100

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j, aux, cont, TAM = 0; // variaveis do Bubblesort.
    int prioridade[MAX];          // Variavel de prioridade.
    int idade[MAX];
    int resposta, resposta2;
    int I = 0, DNV = 0, E = 0;
    char nome[MAX][80];
    i = 0;

    // Loop para cadastro de pessoas.
    do
    {

        printf("Digite seu nome:");
        scanf(" %[^\n]", nome[i]);
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
                    printf("Opção inválida!\n");
                    I = 1;
                }
            } while (I == 1);
        }
        TAM++;
        E = 0;
        do
        {
            printf("Deseja cadastrar mais pessoas? (1-Sim/2-Não):");
            scanf("%d", &resposta2);
            switch (resposta2)
            {
            case 1:
                DNV = 1;
                E = 0;
                i++;
                break;
            case 2:
                DNV = 0;
                E = 0;
                break;
            default:
                printf("Opção inválida!\n");
                E = 1;
            }

        } while (E == 1);
    } while (DNV == 1 && TAM < MAX);
for(i=0;i<TAM;i++)
{
    printf("Nome: %s\n", nome[i]);
    printf("Idade: %d\n", idade[i]);
    printf("Prioridade: %d\n", prioridade[i]);
    printf("Numero da senha: %d\n", i + 1);
   
}
 printf("Tamanho do vetor %d",TAM);




}


