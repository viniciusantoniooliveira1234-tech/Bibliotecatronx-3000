#include <stdio.h>
#include "../include/menu.h"
#include "../include/livro.h"
#include "../include/usuario.h"

void cadastro(){
    
}

void menu(slivro sent,susuario sentu){
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
                scanf(" %149[^\n]",dados.titulo);
                printf("Digite o autor do livro:");
                scanf(" %149[^\n]",dados.autor);
                printf("Digite o ano de publicação do livro:");
                scanf("%d",&dados.ano);
                cadastrolivro(dados,&sent);
                sent.amount++;
                continue;
            }
            if (opcoes==2){
                tusuario data;
                printf("Digite o nome do novo usuário:");
                scanf(" %149[^\n]",data.nome);
                printf("Digite o email:");
                scanf(" %149[^\n]",data.email);
                cadastrousuario(&sentu,data);
                sentu.amount++;
            }
        }
        if (loop==2){
            int opcoes;
            printf("==========================================\n|  escolha umas das opções de consulta:  |\n|  1-Livros                              |\n|  2-Usuários                            |\n|  3-empréstimos                         |\n|  0-voltar                              |\n==========================================\n");
            scanf("%d",&opcoes);
            if (opcoes ==0) continue;
            if (opcoes==1){
                printf("==========================================\n|  escolha umas das opções de consulta:  |\n|  1-código                              |\n|  2-autor                               |\n|     0-Voltar                       \n==========================================\n");
                scanf("%d",&opcoes);
                if (opcoes==1){
                    printf("Digite o ID do livro:");
                    int id;
                    scanf("%d",&id);
                    buscacodigo(id,sent);
                }
                if(opcoes==2){
                    printf("Digite o nome do autor:");
                    char autor[50];
                    scanf(" %149[^\n]",autor);
                    buscaautor(autor,sent);
                }
            }
            if (opcoes==2){
                printf("==========================================\n|  escolha umas das opções de consulta:  |\n|  1-email                               |\n|  2-nome                                |\n==========================================\n");
                scanf("%d",&opcoes);
                if (opcoes==0) continue;
                if (opcoes==1){
                    printf("Digite o email:");
                    char email[150];
                    scanf(" %149[^\n]",email);
                    buscausuarioemail(sentu.root,email);
                }
                if (opcoes==2){
                    printf("Digite o nome:");
                    char nome[150];
                    scanf(" %149[^\n]",nome);
                    buscarusuarionome(sentu.root,nome);
                }
            }
            if (opcoes==3){
                printf("Digite o email que deseja buscar empréstimos:");
                char email[150];
                scanf(" %149[^\n]",email);
                if(buscaemail(sentu.root,email)==0){
                    printf("Email não existe!! :( )");
                }else{
                    buscaempresitomo(email,sent);
                }
            }
        }
        if (loop==3){
            printf("==========================================\n|  escolha umas das opções de atualização|\n|  1-Livro                               |\n|  2-Usuário                             |\n|  0-voltar                              |\n==========================================\n");
            int opcoes;
            scanf("%d",&opcoes);
            if (opcoes==0)continue;
            if (opcoes==1){
                printf("Digite o id do livro que deseja alterar:");
                int id;
                scanf("%d",&id);
                atualizarlivro(sent,id);
            }
            if(opcoes==2){
                printf("Digite o email do usuário que deseja alterar:");
                char email[150];
                scanf(" %149[^\n]",email);
                atualizaruser(sentu.root,email);
            }
        }
    }
}