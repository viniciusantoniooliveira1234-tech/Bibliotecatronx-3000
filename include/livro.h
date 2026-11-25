#ifndef LIVRO_H
#define LIVRO_H
//structs dos livros, listas e arvores relacionadas
typedef struct{
    char autor[150], titulo[150], email[150];
    int ano,ID,status;
}tlivro;

struct livro{
    tlivro info;
    struct livro *next, *prev;
};
typedef struct livro Livro;
typedef struct{
    Livro *head, *tail;
    int amount;
}slivro;
//funcoes relacionadas aos livros
void cadastrolivro(tlivro dados,slivro *sent);
void buscacodigo(int id, slivro sent);
void buscaautor(char *autor, slivro sent);
void buscaempresitomo(char *email,slivro sent);
void atualizarlivro(slivro sent, int id);
void deletarlivro(slivro *sent,int id);
#endif