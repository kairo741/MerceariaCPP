#ifndef _arquivo_cliente_h_
#define _arquivo_cliente_h_

struct Cliente
{
    int id;
    char nome[20];
    char idade[2];

    
    int operator==(const Cliente& cli){
        return cli.id == id && !strcmp(cli.nome, nome) && !strcmp(cli.idade, idade);
    }
};

#endif