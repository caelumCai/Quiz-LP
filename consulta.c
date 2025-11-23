#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Consulta.h"

void carregar_recorde(Jogador *recordista) {
    FILE *f = fopen("recorde.txt", "r");

    if (f == NULL) {
        strcpy(recordista->nome, "Sem recorde");
        recordista->pontuacao = 0;
        return;
    }

    fscanf(f, "%s %d", recordista->nome, &recordista->pontuacao);

    fclose(f);
};

void salvar_recorde(Jogador recordista) {
    FILE *f = fopen("recorde.txt", "w");

    if (f == NULL) {
        printf("Erro ao salvar recorde\n");
        return;
    }

    fprintf(f, "%s\n", recordista.nome);
    fprintf(f, "%d\n", recordista.pontuacao);

    fclose(f);
};
