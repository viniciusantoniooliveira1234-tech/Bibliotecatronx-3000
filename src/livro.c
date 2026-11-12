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
    if(livro==NULL){
        return;
    }
    if (sent->head==NULL){
        sent->head=livro;
        sent->tail=livro;
        return;
    }
    sent->tail->next=livro;
    livro->prev=sent->tail;
    sent->tail=livro;
    return;
}