#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/usuario.h"

void cadastrousuario(susuario *sent, tusuario data){
    Usuario *user;
    user=(Usuario *)malloc(sizeof(Usuario));
    if (user==NULL) return;
    strcpy(user->info.email,data.email);
    strcpy(user->info.nome, data.nome);
    user->left=NULL;
    user->right=NULL;

    cadastrousuariobst(&sent->root,user);
    return;
}

void cadastrousuariobst(Usuario **root, Usuario *user){
    if(*root==NULL){
        *root=user;
        return;
    }
    if(strcasecmp(user->info.email,(*root)->info.email)==0){
        printf("Ja existe um usuário cadastrado com esse email, tente novamente.\n");
        free(user);
        return;
    }
    if (strcasecmp(user->info.email,(*root)->info.email) < 0){
        cadastrousuariobst(&(*root)->left,user);
    }
    if (strcasecmp(user->info.email,(*root)->info.email)>0){
        cadastrousuariobst(&(*root)->right,user);
    }
}