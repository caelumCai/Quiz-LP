#ifndef CONSULTA_H
#define CONSULTA_H

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;


void carregar_recorde(Jogador *recordista);
void salvar_recorde(Jogador recordista);

#endif // CONSULTA_H

