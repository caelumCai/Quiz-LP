#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Quiz.h"
#include "Consulta.h"

int main()
{
    setlocale(LC_ALL, "");
    Pergunta teste[5];
    carregar_perguntas(teste, "Perguntas.txt");
    int PontAtual = 0;
    int selecaoMenu = 0;
    int pontos;
    while (selecaoMenu != 3)
    {
        system("cls");
        printf("\n\n                         BEM-VINDO AO NOSSO QUIZ DE CONHECIMENTOS GERAIS   \n\n");
        printf("\n                                         ----- MENU ----- \n");
        printf("\n\n                    1-Iniciar Quiz     |     2-Consultar recorde     |     3-Sair\n\n\n");
        printf("Selecione uma opção do menu: ");
        scanf("%d", &selecaoMenu);
        if (selecaoMenu == 1)
        {
            Jogador recorde;
            carregar_recorde(&recorde);
            iniciar_quiz(teste, 5, &pontos);
            system("cls");
            printf("\n\n    Sua pontuação foi %d\n\n", pontos);
            if (pontos > recorde.pontuacao){
                 printf("\nNOVO RECORDE!\nDigite seu nome: ");
                 scanf("%s", recorde.nome);
                 printf("\n\n");
                 recorde.pontuacao = pontos;
                 salvar_recorde(recorde);
            }
            else
            {
                FILE *f = fopen("recorde.txt", "r");
                printf("\n\n Infelizmente não foi o suficiente para para bater o recorde de %d\n\n", recorde.pontuacao);
            }
            system("pause");
        }
        if (selecaoMenu == 2)
        {
            system("cls");
            Jogador j;
            carregar_recorde(&j);
            printf("\n\n ---- RECORDE ATUAL ---- \n\n\n");
            printf("Nome: %s\n", j.nome);
            printf("Pontuação: %d\n", j.pontuacao);
            printf("\n\n     ---- Seu ultimo jogo ----");
            printf("\n\nPontuação: %d/5\n\n", pontos);
            system("pause");
        }
    }
    exit(0);
    return 0;

}

