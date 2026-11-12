#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    char email[100], nome[50];
}tusuario;

struct usuario{
    tusuario info;
    struct usuario *next, *prev;
};
typedef struct usuario Usuario;
typedef struct{
    Usuario *head, *tail;
    int amount;
}susuario;
struct snode{
    int ID;
    struct snode *left, *right;
};
typedef struct snode Snode;
typedef struct{
    Snode *root;
}Sentnodeuser;
#endif