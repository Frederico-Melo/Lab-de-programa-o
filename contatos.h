#ifndef CONTATOS_H
#define CONTATOS_H

//definindo a estrutura do contato
typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} Contato;

//funções do código
void cadastrarContato(Contato *agenda, int *total);
void listarContatos(Contato *agenda, int total);
void buscarContato(Contato *agenda, int total);
void editarContato(Contato *agenda, int total);
void removerContato(Contato *agenda, int *total);
int estatisticasRecursivo(Contato *agenda, int total, int indice, int tamanhoN);

#endif