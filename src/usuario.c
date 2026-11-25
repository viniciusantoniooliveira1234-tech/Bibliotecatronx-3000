#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/usuario.h"
//cadastrar usuario
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
//funcao recursiva para cadastrar o usuario com os dados da funcao acima
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
//buscar usuario de forma recursiva 
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
//buscar usuario de forma recursiva
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
//buscar email para utilizar em outras funcoes, 1 caso encontre, 0 caso não encontre o email
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
//funcao atualizar usuario
void atualizaruser(Usuario *root,char *email){
    if (root==NULL){
        printf("Email não encontrado\n");
        return;
    }
    if (strcasecmp(email,root->info.email)==0){
        printf("Email encontrado digite o novo nome:");
        scanf(" %149[^\n]",root->info.nome);
        return;
    }
    if (strcasecmp(email,root->info.email)<0){
        atualizaruser(root->left,email);
    }
    if (strcasecmp(email,root->info.email)>0){
        atualizaruser(root->right,email);
    }
}
//pegar valor para substituir o que vai ser excluido
Usuario* organizarexlusao(Usuario *left){
    Usuario *aux=left;
    while (aux->right!=NULL){
        aux=aux->right;
    }
    return aux;
}
//encontrar usuario para deletar
Usuario* deletaruser(Usuario *root, char *email){
    if (root==NULL){
        printf("Email não encontrado\n");
        return NULL;
    }
    if(strcasecmp(email,root->info.email)<0){
        root->left=(deletaruser(root->left,email));
    }else if (strcasecmp(email,root->info.email)>0){
        root->right=(deletaruser(root->right,email));
    }else{
        //caso filho direita
        if(root->left==NULL){
            Usuario *temp = root->right;
            free(root);
            return temp;
        //caso filho esquerda
        }else if (root->right==NULL){
            Usuario *temp=root->left;
            free(root);
            return temp;
        }

        //caso 2 filhos
        Usuario *temp=organizarexlusao(root->left);
        root->info=temp->info;
        root->left=deletaruser(root->left,temp->info.email);
    }
    return root;
}