#ifndef USUARIO_H
#define USUARIO_H
//structs dos usuarios, listas relacionadas
typedef struct {
    char email[150], nome[150];
}tusuario;

struct usuario{
    tusuario info;
    struct usuario *left, *right;
};
typedef struct usuario Usuario;
typedef struct{
    Usuario *root;
    int amount;
}susuario;
void cadastrousuario(susuario *sent, tusuario data);
void cadastrousuariobst(Usuario **root, Usuario *user);
void buscausuarioemail(Usuario *root,char *email);
void buscarusuarionome(Usuario *root,char *nome);
int buscaemail(Usuario *root,char *email);
void atualizaruser(Usuario *root,char *email);
#endif