#include <stdio.h>
#include <stdlib.h>
#include "../include/livro.h"
#include "../include/menu.h"
#include "../include/usuario.h"

int main(){
    slivro sent;
    sent.amount=0;
    sent.head=NULL;
    sent.tail=NULL;
    menu(sent);
    return 0;
}