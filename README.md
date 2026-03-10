#  Gerenciador de Contatos em C

**Universidade Evangélica de Goiás (UNIEVANGÉLICA)** **Curso:** Engenharia de Software - 3º Período  
**Disciplina:** Laboratório de Programação – Ciclo 1  
**Professor:** Renato Luan de Sousa Araújo  

---

##  Sobre o Projeto
Este sistema é um Gerenciador de Contatos desenvolvido inteiramente em linguagem C, operando em modo texto. O objetivo principal é consolidar fundamentos da programação como o uso de estruturas, manipulação avançada de *strings*, passagem por referência usando ponteiros, modularização de arquivos e recursividade. 

O sistema possui capacidade de armazenamento em memória para até 100 registros.

##  Integrantes e Contribuições

A equipe é formada por 4 acadêmicos, com as seguintes divisões de responsabilidade no desenvolvimento[cite: 69]:

**Frederico:** Responsável pela arquitetura e modularização do código, além da implementação da função recursiva de estatísticas.
**Ruan:** Desenvolvimento da lógica de dados, funções de Cadastro e Listagem sequencial dos contatos.
**Kauã:** Implementação dos algoritmos de Busca por nome, Edição de dados e a lógica de Exclusão.
**João Vitor:** Estruturação da `main.c`, criação do Menu Interativo em modo texto, tratamento de erros de entrada de usuário e redação desta documentação técnica.

##  Decisões de Projeto e Justificativas
Conforme as boas práticas exigidas, destacamos as seguintes decisões técnicas:
* **Tamanho dos Campos:** O limite do telefone foi definido em `20` caracteres para acomodar com segurança a formatação internacional e o caractere terminador nulo (`\0`) nativo do C.
**Modularização:** O código foi separado em `main.c`, `contatos.c` e `contatos.h`. Isso garante que a interface de usuário fique isolada da lógica de negócios, facilitando a escalabilidade.


##  Como Compilar e Executar

Este projeto foi escrito em C padrão e pode ser compilado no `gcc`. Siga as instruções abaixo:

### Opção 1: Usando o Dev-C++ (Para Windows)
1. Crie um novo **Projeto** do tipo *Console Application* (selecionando linguagem C).
2. Adicione os arquivos `main.c`, `contatos.c` e `contatos.h` ao seu projeto.
3. Pressione `F11` para compilar e executar.

