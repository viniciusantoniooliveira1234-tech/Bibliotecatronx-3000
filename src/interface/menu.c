#include <stdio.h>
#include <include/menu.h>

void cadastro(){
    
}

void menu(){
    int loop=1;
    printf("Bibliotecatron-3000\n");
    while(loop){
        printf("==============================\n|  escolha umas das opções:  |\n|  1-Cadastro                |\n|  2-Consulta                |\n|  3-Atualização             |\n|  4-Exclusão                |\n|  5-Empréstimo              |\n|  6-Devolução               |\n|  0-Sair                    |\n==============================\n");
        scanf("%d",&loop);
        if (loop==0) break;
    }
}