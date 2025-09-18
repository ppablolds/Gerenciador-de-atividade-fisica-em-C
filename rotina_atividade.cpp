#include <stdio.h>

#define DIAS 7

int main() {
    // Vetor para armazenar a quantidade de atividades de cada dia
    int atividades[DIAS] = {0};

    // Vetor de strings com os nomes dos dias da semana
    char *diasSemana[DIAS] = {
        "Segunda-feira",
        "Terca-feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sabado",
        "Domingo"
    };

    int opcao, dia, qtd, i;
    int maior, topDay;

    // Mensagem inicial
    printf("=========================================\n");
    printf("  SISTEMA DE ROTINA DE ATIVIDADE FISICA  \n");
    printf("=========================================\n");
    printf("Este programa permite registrar atividades\n");
    printf("fisicas ao longo da semana, consultar os\n");
    printf("dados e descobrir o 'Top Day' (dia com\n");
    printf("maior numero de atividades registradas).\n");
    printf("=========================================\n\n");

    // Loop principal do menu
    while (1) {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Registrar atividades em um dia\n");
        printf("2. Consultar atividades da semana\n");
        printf("3. Mostrar o Top Day\n");
        printf("4. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Registrar atividades
                printf("\n--- Registro de Atividades ---\n");
                printf("Escolha o dia da semana:\n");
                for (i = 0; i < DIAS; i++) {
                    printf("%d - %s\n", i+1, diasSemana[i]);
                }
                printf("Digite a opcao: ");
                scanf("%d", &dia);

                // Valida  o do dia
                if (dia < 1 || dia > DIAS) {
                    printf("Dia invalido! Escolha de 1 a 7.\n");
                } else {
                    printf("Quantas atividades voce realizou em %s? ", diasSemana[dia-1]);
                    scanf("%d", &qtd);

                    if (qtd < 0) {
                        printf("Quantidade invalida! Nao e possivel registrar valores negativos.\n");
                    } else {
                        atividades[dia-1] += qtd;
                        printf("Registro concluido com sucesso!\n");
                    }
                }
                break;

            case 2: // Consultar atividades
                printf("\n--- Consulta de Atividades ---\n");
                for (i = 0; i < DIAS; i++) {
                    printf("%s: %d atividades\n", diasSemana[i], atividades[i]);
                }
                break;

            case 3: // Top Day
                printf("\n--- Top Day ---\n");
                maior = atividades[0];
                topDay = 0;

                for (i = 1; i < DIAS; i++) {
                    if (atividades[i] > maior) {
                        maior = atividades[i];
                        topDay = i;
                    }
                }

                if (maior > 0) {
                    printf("O dia com mais atividades foi %s com %d atividades!\n",
                           diasSemana[topDay], maior);
                } else {
                    printf("Nenhuma atividade registrada ainda.\n");
                }
                break;

            case 4: // Sair do programa
                printf("\nObrigado por usar o sistema! Ate a proxima!\n");
                return 0; // Encerra o programa

            default: // Entrada inv lida
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
