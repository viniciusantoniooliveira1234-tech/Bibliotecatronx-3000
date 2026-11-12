#ifndef LIVRO_H
#define LIVRO_H

typedef struct{
    char autor[50], titulo[50], email[100];
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
struct lnode{
    int ID;
    struct lnode *left, *right;
};
typedef struct lnode Lnode;
typedef struct{
    Lnode *root;
}Sentnodebook;
#endif