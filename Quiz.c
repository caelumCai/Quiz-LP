#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Quiz.h"

int carregar_perguntas(Pergunta quiz[], const char* nome_arquivo) {
    FILE *f = fopen("Perguntas.txt", "r");
    if (f == NULL) {
        printf("\nErro ao abrir arquivo %s\n\n", nome_arquivo);
        system("pause");
        return 0;
    }
    char linha[256];
        for (int i = 0;i < 5;i++)
        {
                fgets(linha, sizeof(linha), f);
                linha[strcspn(linha, "\n")] ='\0';
                strcpy(quiz[i].enunciado, linha);
                for (int k = 0;k < 5;k++)
                {
                    fgets(linha,sizeof(linha), f);
                    linha[strcspn(linha, "\n")] = '\0';
                    strcpy(quiz[i].opcoes[k], linha);
                }
                fgets(linha, sizeof(linha), f);
                quiz[i].resposta_correta = atoi(linha);
                fgets(linha, sizeof(linha), f);
        }
    fclose(f);
    return 5;
};

void iniciar_quiz(Pergunta quiz[], int total_perguntas, int *pontAtual) {
    setlocale(LC_ALL, "");
    *pontAtual = 0;
    int resposta;
    for (int i = 0; i < total_perguntas;i++)
    {
        system("cls");
        printf("\n--- PERGUNTA NÚMERO %d ---\n", i+1);
        printf("    %s", quiz[i].enunciado);
        for(int j = 0;j < 5;j++)
        {
            printf("\n%s", quiz[i].opcoes[j]);
        }
        printf("\n");
        printf("\nDigite o número da resposta correta(1-5): ");
        scanf("%d", &resposta);
        if (resposta != quiz[i].resposta_correta)
        {
            system("cls");
            printf("\n\n      Não foi dessa vez!! Tente na próxima pergunta!\n\n");
            system("pause");
        }
        else
        {
            (*pontAtual)++;
            system("cls");
            printf("\n\n     Bom!!! Vamos seguir para a próxima\n\n");
            system("pause");
        }
    }

};



