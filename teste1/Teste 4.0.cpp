#include <stdio.h>
#include <locale.h>
#include <string.h>
#define MAX 100

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j, aux, TAM = 0; // variaveis do Bubblesort.
    int prioridade[MAX];    // Variavel de prioridade.
    int idade[MAX];
    int resposta, resposta2, resposta3;            // Variaveis de resposta para as perguntas.
    int I = 0, DNV = 0, E = 0, REP = 0, atual = 0; // Variaveis de controle para os loops.
    char nome[MAX][80];
    int Nsenha[MAX]; // Variavel do numero da senha.
    i = 0;
    int score[MAX]; // Definindo a varivel score com o tamanho do vetor MAX ja definido.

    // ETAPA 1 Cadastro de pessoas.
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
                case 1: prioridade[i] = 2; break;
                case 2: prioridade[i] = 1; break;
                default: printf("Opção inválida!\n"); I = 1;
                }
            } while (I == 1);
        }
        TAM++;
        Nsenha[i] = TAM; 

        E = 0;
        do
        {
            printf("Deseja cadastrar mais pessoas? (1-Sim/2-Não):");
            scanf("%d", &resposta2);
            switch (resposta2)
            {
            case 1: DNV = 1; E = 0; i++; break;
            case 2: DNV = 0; E = 0; break;
            default: printf("Opção inválida!\n"); E = 1;
            }
        } while (E == 1);
    } while (DNV == 1 && TAM < MAX);

    // ETAPA 2 Calculo do SCORE e ordenação inicial.
    for (i = 0; i < TAM; i++) 
    {
        score[i] = (prioridade[i] * TAM) - (i + 1);
    }
    for (j = 0; j < TAM; j++)
    {
        for (i = 0; i < TAM - 1; i++)
        {
            if (score[i] < score[i + 1])
            {
                aux = score[i]; score[i] = score[i + 1]; score[i + 1] = aux;
                aux = idade[i]; idade[i] = idade[i + 1]; idade[i + 1] = aux;
                char tempNome[80];
                strcpy(tempNome, nome[i]); strcpy(nome[i], nome[i + 1]); strcpy(nome[i + 1], tempNome);
                aux = prioridade[i]; prioridade[i] = prioridade[i + 1]; prioridade[i + 1] = aux;
                aux = Nsenha[i]; Nsenha[i] = Nsenha[i + 1]; Nsenha[i + 1] = aux;
            }
        }
    }

    // ETAPA 3 Menu e chamando os pacientes.
    printf("======================\n");
    printf(" Chamado atual:%s\n", nome[0]);
    printf("======================\n");

    printf("Fila de espera:\n");
    for (i = 1; i < TAM; i++)
    {
        printf("Senha: %d | Nome: %s | Idade: %d | Prioridade: %d\n", Nsenha[i], nome[i], idade[i], prioridade[i]);
    }

    do
    {
        REP = 0;
        printf("\n======================\n");
        printf("       MENU\n");
        printf("======================\n");
        printf("1 - Chamar próximo paciente\n");
        printf("2 - Adicione mais pacientes\n");
        printf("3 - Encerrar Expediente\n");
        scanf("%d", &resposta3);

        switch (resposta3)
        {
        case 1:
            // CORREÇÃO AQUI: Primeiro verificamos se o atual pode avançar sem estourar o TAM
            if (atual < TAM - 1)
            {
                atual++; // Agora sim avança com segurança para o próximo índice correto
                printf("======================\n");
                printf(" Chamado atual:%s\n", nome[atual]);
                printf("======================\n");

                printf("Fila de espera:\n");
                for (i = atual + 1; i < TAM; i++) // Mostra o restante da fila a partir do novo atual
                {
                    printf("Senha: %d | Nome: %s | Idade: %d | Prioridade: %d\n", Nsenha[i], nome[i], idade[i], prioridade[i]);
                }
            }
            else
            {
                printf("\nTodos os pacientes cadastrados já foram atendidos!\n");
                atual = TAM; // Garante que a fila está zerada
            }
            REP = 1;
            break; 
            
        case 2:
            i = TAM;
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
                        case 1: prioridade[i] = 2; break;
                        case 2: prioridade[i] = 1; break;
                        default: printf("Opção inválida!\n"); I = 1;
                        }
                    } while (I == 1);
                }

                E = 0;
                do
                {
                    printf("Deseja cadastrar mais pessoas? (1-Sim/2-Não):");
                    scanf("%d", &resposta2);
                    switch (resposta2)
                    {
                    case 1:
                        DNV = 1; E = 0;
                        TAM++;           
                        Nsenha[i] = TAM; 
                        i++;
                        break;
                    case 2:
                        DNV = 0; E = 0;
                        TAM++;           
                        Nsenha[i] = TAM; 
                        REP = 1;
                        break;
                    default:
                        printf("Opção inválida!\n");
                        E = 1;
                    }
                } while (E == 1);
            } while (DNV == 1 && TAM < MAX);
            break;
            
        case 3:
            REP = 0;
            break;
        }

        // REORGANIZAÇÃO FIXA (Mantendo a ordenação estável apenas para quem NÃO foi atendido)
        // Usamos 'atual + 1' na ordenação para proteger quem já está sentadinho na sala do médico (índice 'atual')
        for (i = atual + 1; i < TAM; i++)
        {
            score[i] = (prioridade[i] * TAM) - (i + 1);
        }
        for (j = atual + 1; j < TAM; j++)
        {
            for (i = atual + 1; i < TAM - 1; i++)
            {
                if (score[i] < score[i + 1])
                {
                    aux = score[i]; score[i] = score[i + 1]; score[i + 1] = aux;
                    aux = idade[i]; idade[i] = idade[i + 1]; idade[i + 1] = aux;
                    char tempNome[80];
                    strcpy(tempNome, nome[i]); strcpy(nome[i], nome[i + 1]); strcpy(nome[i + 1], tempNome);
                    aux = prioridade[i]; prioridade[i] = prioridade[i + 1]; prioridade[i + 1] = aux;
                    aux = Nsenha[i]; Nsenha[i] = Nsenha[i + 1]; Nsenha[i + 1] = aux;
                }
            }
        }

    } while (REP == 1);
}

