#include <stdio.h>
#include "../include/menu.h"
#include "../include/livro.h"
#include "../include/usuario.h"

void cadastro(){
    
}

void menu(slivro sent){
    int loop=1;
    printf("Bibliotecatron-3000\n");
    //loop principal
    while(loop){
        printf("==============================\n|  escolha umas das opções:  |\n|  1-Cadastro                |\n|  2-Consulta                |\n|  3-Atualização             |\n|  4-Exclusão                |\n|  5-Empréstimo              |\n|  6-Devolução               |\n|  0-Sair                    |\n==============================\n");
        scanf("%d",&loop);
        if (loop==0) break;
        if (loop==1){
            int opcoes;
            printf("==========================================\n|  escolha umas das opções de cadastro:  |\n|  1-Livros                              |\n|  2-Usuários                            |\n|  0-Voltar                              |\n==========================================\n");
            scanf("%d",&opcoes);
            if (opcoes==0)continue;
            if (opcoes==1){
                //coletar os dados
                tlivro dados;
                printf("Digite o nome do livro:");
                scanf("%s",dados.titulo);
                printf("Digite o autor do livro:");
                scanf("%s",dados.autor);
                printf("Digite o ano de publicação do livro:");
                scanf("%d",&dados.ano);
                cadastrolivro(dados,&sent);
                continue;
            }
        }
    }
}