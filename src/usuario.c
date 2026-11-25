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

void buscausuarioemail(Usuario *root,char *email){
    if(root==NULL){
        printf("Usuario não encontrado\n");
        return;
    }
    if(strcasecmp(root->info.email,email)==0){
        printf("Email encontrado:\nNome:%s\n",root->info.nome);
        return;
    }
    if (strcasecmp(email,root->info.email)<0){
        buscausuarioemail(root->left,email);
    }
    if (strcasecmp(email,root->info.email)>0){
        buscausuarioemail(root->right,email);
    }
}
void buscarusuarionome(Usuario *root,char *nome){
    if(root==NULL){
        printf("Usuario não encontrado\n");
        return;
    }
    if(strcasecmp(root->info.nome,nome)==0){
        printf("Email encontrado:\nEmail:%s\n",root->info.email);
        return;
    }
    if (strcasecmp(nome,root->info.nome)<0){
        buscausuarioemail(root->left,nome);
    }
    if (strcasecmp(nome,root->info.nome)>0){
        buscausuarioemail(root->right,nome);
    }
}
int buscaemail(Usuario *root,char *email){
        if(root==NULL){
        return 0;
    }
    if(strcasecmp(root->info.email,email)==0){
        return 1;
    }
    if (strcasecmp(email,root->info.email)<0){
        buscausuarioemail(root->left,email);
    }
    if (strcasecmp(email,root->info.email)>0){
        buscausuarioemail(root->right,email);
    }
    return 2;
}