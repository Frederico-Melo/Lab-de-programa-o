#include <stdio.h>
#include "contatos.h" //importa a nossa biblioteca de contatos

//função principal
int main() {
    Contato agenda[100]; 
    int totalContatos = 0; 
    int opcao = 0;

    while (opcao != 7) {
        printf("\n=== MENU ===\n");
        printf("1) Cadastrar\n2) Listar\n3) Buscar\n4) Editar\n5) Excluir\n6) Estatisticas\n7) Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            
        fflush(stdin); 
            
        opcao = 0;
		}

        if (opcao == 1) {
            cadastrarContato(agenda, &totalContatos); 
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
} // mudando algo para testar

