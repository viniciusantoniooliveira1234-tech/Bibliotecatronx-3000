#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/livro.h"

void cadastrolivro(tlivro dados,slivro *sent){
    //criando novo elemento lista e salvando os dados
    Livro *livro;
    livro=(Livro *)malloc(sizeof(Livro));
    livro->prev=NULL;
    livro->next=NULL;
    livro->info.ano=dados.ano;
    strcpy(livro->info.autor,dados.autor);
    strcpy(livro->info.email, "Nem um email cadastrado ainda");
    livro->info.ID=sent->amount+1;
    livro->info.status=0;
    strcpy(livro->info.titulo,dados.titulo);
    //caso não seja possível alocar memória
    if(livro==NULL){
        return;
    }
    //caso seja o primeiro
    if (sent->head==NULL){
        sent->head=livro;
        sent->tail=livro;
        return;
    }
    //
    sent->tail->next=livro;
    livro->prev=sent->tail;
    sent->tail=livro;
    return;
}

void buscacodigo(int id, slivro sent){
    Livro *aux;
    aux=sent.head;
    while (aux!=NULL){
        if(aux->info.ID==id){
            printf("Livro encontrado:\nnome:%s\nautor:%s\nemail:%s\nano:%d\nID:%d\nstatus:%d\n",aux->info.titulo,aux->info.autor,aux->info.email,aux->info.ano,aux->info.ID,aux->info.status);
            break;;
        }
        aux=aux->next;
    }
    if (aux==NULL){
        printf("Livro não encontrado\n");
    }
}

void buscaautor(char *autor, slivro sent){
    Livro *aux=sent.head;
    int i=0;
    while(aux!=NULL){
        
        if (strcmp(autor,aux->info.autor)==0){
            printf("Livro encontrado:\nnome:%s\nautor:%s\nemail:%s\nano:%d\nID:%d\nstatus:%d\n",aux->info.titulo,aux->info.autor,aux->info.email,aux->info.ano,aux->info.ID,aux->info.status);
            i++;
        }
        aux=aux->next;
    }
    if (i==0){
        printf("Nem um livro com esse autor encontrado :()");
    }
}
void buscaempresitomo(char *email,slivro sent){
    Livro *aux=sent.head;
    int i=0;
    while(aux!=NULL){
        
        if (strcmp(email,aux->info.email)==0){
            printf("Livro encontrado:\nnome:%s\nautor:%s\nemail:%s\nano:%d\nID:%d\nstatus:%d\n",aux->info.titulo,aux->info.autor,aux->info.email,aux->info.ano,aux->info.ID,aux->info.status);
            i++;
        }
        aux=aux->next;
    }
    if (i==0){
        printf("Nem um emprestimo encontrado :()");
    }   
}

void atualizarlivro(slivro sent, int id){
    Livro *aux = sent.head;
    while (aux!= NULL){
        if (aux->info.ID==id){
            printf("Digite qual dado deseja alterar?(1-título|2-Autor|3-Ano):");
            int op;
            scanf("%d",&op);
            if (op==1){
                printf("Digite o novo título:");
                scanf(" %149[^\n]",aux->info.titulo);
            }
            if (op==2){
                printf("Digite o novo autor:");
                scanf(" %149[^\n]",aux->info.autor);
            }
            if (op==3){
                printf("Digite o novo ano:");
                scanf("%d",&aux->info.ano);
            }
            break;
        }
        aux= aux->next;
    }
    if (aux==NULL){
        printf("ID não encontrado tente novamente!\n");
    }
}
//deletar livro
void deletarlivro(slivro *sent, int id) {
    if (sent->head == NULL) {
        return;
    }
    Livro *aux = sent->head;
    while (aux != NULL) {

        if (aux->info.ID == id) {
            //ponteiro anterior ou é o primeiro
            if (aux->prev != NULL) {
                aux->prev->next = aux->next;
            } else {
                sent->head = aux->next;
            }
            //proximo ponteiro ou é o ultumo
            if (aux->next != NULL) {
                aux->next->prev = aux->prev;
            } else {
                sent->tail = aux->prev;
            }

            free(aux);
            return;
        }
        aux = aux->next;
    }
    if(aux==NULL){
        printf("Id não encontrado");
    }
}
//buscar livro para fazer emprestimo
Livro* buscarlivro(slivro sent, int id){
    Livro *aux=sent.head;
    for(;aux!=NULL;aux=aux->next){
        if(aux->info.ID==id){
            return aux;
        }
    }
    return NULL;
}