#include <stdio.h>
#include <string.h>
#include "contatos.h" //importa a estrutura e as funções

//1)cadastrar
void cadastrarContato(Contato *agenda, int *total) {
    if (*total >= 100) { 
        printf("Agenda lotada!\n");
        return;
    }

    int i = *total; 

    printf("\n--- Novo Contato ---\n");
    
    printf("Nome: ");
    scanf(" %[^\n]", agenda[i].nome); 

    printf("Telefone: ");
    scanf(" %[^\n]", agenda[i].telefone);

    printf("E-mail: ");
    scanf(" %[^\n]", agenda[i].email);

    *total = *total + 1; 
    printf("Cadastrado com sucesso!\n");
}

//2)listar
void listarContatos(Contato *agenda, int total) {
    printf("\n--- Lista de Contatos ---\n");
    int i;
    for (i = 0; i < total; i++) {
        printf("[%d] Nome: %s | Tel: %s | Email: %s\n", i, agenda[i].nome, agenda[i].telefone, agenda[i].email);
    }
}

//3)buscar
void buscarContato(Contato *agenda, int total) {
    char nomeBusca[100];
    printf("\nQual nome deseja buscar? ");
    scanf(" %[^\n]", nomeBusca);
    
    int i;
    for (i = 0; i < total; i++) {
        if (strstr(agenda[i].nome, nomeBusca) != NULL) {
            printf("[%d] Encontrado: %s | Tel: %s\n", i, agenda[i].nome, agenda[i].telefone);
        }
    }
}

//4)editar
void editarContato(Contato *agenda, int total) {
    int indice;
    listarContatos(agenda, total);
    
    printf("\nDigite o numero (indice) do contato para editar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < total) {
        printf("Novo Nome: ");
        scanf(" %[^\n]", agenda[indice].nome);

        printf("Novo Telefone: ");
        scanf(" %[^\n]", agenda[indice].telefone);

        printf("Novo E-mail: ");
        scanf(" %[^\n]", agenda[indice].email);

        printf("Editado com sucesso!\n");
    } else {
        printf("Indice invalido.\n");
    }
}

//5)excluir
void removerContato(Contato *agenda, int *total) {
    int indice;
    listarContatos(agenda, *total);
    
    printf("\nDigite o numero (indice) do contato para excluir: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < *total) {
        int i;
        for (i = indice; i < *total - 1; i++) {
            agenda[i] = agenda[i + 1];
        }
        *total = *total - 1; 
        printf("Excluido com sucesso!\n");
    } else {
        printf("Indice invalido.\n");
    }
}

//6)estatisticas
int estatisticasRecursivo(Contato *agenda, int total, int indice, int tamanhoN) {
    if (indice == total) {
        return 0;
    }
    
    int contaAtual = 0;
    if (strlen(agenda[indice].nome) > tamanhoN) {
        contaAtual = 1;
    }
    
    return contaAtual + estatisticasRecursivo(agenda, total, indice + 1, tamanhoN);
}