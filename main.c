#include <stdio.h>
#include <string.h>

//definindo a estrutura do contato
typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} Contato;

//1)cadastrar
void cadastrarContato(Contato *agenda, int *total) {
    if (*total >= 100) { //limite exigido de 100 registros [cite: 23]
        printf("Agenda lotada!\n");
        return;
    }

    int i = *total; //proxima posição vazia da agenda

    printf("\n--- Novo Contato ---\n");
    
    printf("Nome: ");
    scanf(" %[^\n]", agenda[i].nome); //lê o texto com espaços e ignora lixo do teclado

    printf("Telefone: ");
    scanf(" %[^\n]", agenda[i].telefone);

    printf("E-mail: ");
    scanf(" %[^\n]", agenda[i].email);

    *total = *total + 1; //aumenta a contagem de contatos
    printf("Cadastrado com sucesso!\n");
}

//2)listar
void listarContatos(Contato *agenda, int total) {
    printf("\n--- Lista de Contatos ---\n");
    int i;
    for (i = 0; i < total; i++) {
        printf("[%d] Nome: %s | Tel: %s | Email: %s\n", i+1, agenda[i].nome, agenda[i].telefone, agenda[i].email);
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
        //arruma a sequência da agenda
        int i;
        for (i = indice; i < *total - 1; i++) {
            agenda[i] = agenda[i + 1];
        }
        *total = *total - 1; //diminui o total de contatos
        printf("Excluido com sucesso!\n");
    } else {
        printf("Indice invalido.\n");
    }
}

//6)estatisticas
int estatisticasRecursivo(Contato *agenda, int total, int indice, int tamanhoN) {
    //se chegou no fim da agenda, para de contar
    if (indice == total) {
        return 0;
    }
    
    int contaAtual = 0;
    if (strlen(agenda[indice].nome) > tamanhoN) {
        contaAtual = 1;
    }//se o nome  for maior que o tamanhoN, conta mais 1
    
    //soma o resultado de agora com a busca no próximo contato
    return contaAtual + estatisticasRecursivo(agenda, total, indice + 1, tamanhoN);
}

//função principal
int main() {
    Contato agenda[100]; 
    int totalContatos = 0; 
    int opcao = 0;

    while (opcao != 7) {
        printf("\n=== MENU ===\n");
        printf("1) Cadastrar\n2) Listar\n3) Buscar\n4) Editar\n5) Excluir\n6) Estatisticas\n7) Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrarContato(agenda, &totalContatos); //passa com & para a função poder alterar o total, usando ponteiros
        } 
        else if (opcao == 2) {
            listarContatos(agenda, totalContatos);
        } 
        else if (opcao == 3) {
            buscarContato(agenda, totalContatos);
        } 
        else if (opcao == 4) {
            editarContato(agenda, totalContatos);
        } 
        else if (opcao == 5) {
            removerContato(agenda, &totalContatos);
        } 
        else if (opcao == 6) {
            int tamanhoAlvo = 10;
            int qtd = estatisticasRecursivo(agenda, totalContatos, 0, tamanhoAlvo);
            printf("Existem %d contatos com nomes maiores que %d letras.\n", qtd, tamanhoAlvo);
        } 
        else if (opcao != 7) {
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}
