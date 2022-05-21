#include<stdio.h>
#include"Util.h"
#include"filme.h"
#include <list>

#ifndef _arquivo_filme_controller_cpp_
#define _arquivo_filme_controller_cpp_

#include <cstring>

using namespace std;

list<Filme> filmes;

auto getPosFilmeById(int id) {
    for (auto it = filmes.begin(); it != filmes.end(); it++) {
        if (it->id == id) {
            return it;

        }
    }

}

Filme getFilmeById(int id) {
    for (Filme const &f: filmes) {
        if (f.id == id) {
            return f;
        }
    }
    return Filme();
}

Filme makeFilmeTeste() {
    Filme filme;
    filme.id = Util::getNextId();
    strcpy(filme.titulo, "Kairo O Filme");
    strcpy(filme.genero, "Kairo Amorim");
    filme.valorLocacao = 15;

    return filme;
}

void cadastrarFilme() {
    Filme filme{};

    filme.id = Util::getNextId();

    printf("Digite o nome do filme: ");
    scanf("%s", filme.titulo);
    printf("Digite o genero do filme: ");
    scanf("%s", filme.genero);
    printf("Digite o valor de locação do filme: ");
    scanf("%d", &filme.valorLocacao);

    filmes.push_front(filme);
}

void listarAcervo() {
    for (Filme const &fm: filmes) {
        printf("-------");
        printf("   Id: %d\n", fm.id);
        printf("   Titulo:  %s\n", fm.titulo);
        printf("   Gênero:  %s\n", fm.genero);
        printf("   Valor da Locação: R$%d", fm.valorLocacao);
        printf("-------");
    }
}

void alterarFilme() {

    listarAcervo();

    int escolha;

    printf("Escolha o filme que sera modificado pelo numero dele: ex: 1, 2, 3...");
    scanf("%d", &escolha);

    auto filmeIterator = getPosFilmeById(escolha);

    printf("Digite o nome do filme: ");
    scanf("%s", &filmeIterator->titulo);
    printf("Digite o genero do filme: ");
    scanf("%s", &filmeIterator->genero);
    printf("Digite o valor de locação do filme: ");
    scanf("%d", &filmeIterator->valorLocacao);

}

void excluirFilme() {
    listarAcervo();

    int id;

    printf("Digite o ID do filme para excluir: ");
    scanf("%d", &id);

    filmes.remove(getFilmeById(id));
}

#endif

