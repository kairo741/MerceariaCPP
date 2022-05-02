#ifndef _arquivo_filme_h_
#define _arquivo_filme_h_

struct Filme
{
    int id;
    char titulo[20];
    char genero[25];
    int valorLocacao;

    
    int operator==(const Filme &f){
        return f.id == id && !strcmp(f.titulo, titulo) && !strcmp(f.genero, genero) && f.valorLocacao == valorLocacao;
    }
};

#endif