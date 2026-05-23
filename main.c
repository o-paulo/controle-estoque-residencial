#include <stdio.h>
#include <stdlib.h>

struct Produto { // Definindo como os produtos devem ser registrados ao serem guardados
    int id;
    char nome_produto[100];
    int quantidade_estoque;
    float preco;
};

int main(){
    struct Produto estoque[50]; // Criando a caixa para armazenar os produtos
    int total_produtos = 0;
    int opcao;

    FILE *arquivo = fopen("estoque.txt", "r");

    if(arquivo != NULL){
        printf("--- Produtos Carregados do Estoque ---\n");
        
        while(fscanf(arquivo, "ID: %d\n", &estoque[total_produtos].id) != EOF) {
            fscanf(arquivo, "Nome do produto: %s\n", estoque[total_produtos].nome_produto);
            fscanf(arquivo, "Quantidade: %d\n", &estoque[total_produtos].quantidade_estoque);
            fscanf(arquivo, "Preco: %f\n", &estoque[total_produtos].preco);
            
            printf("ID: %d | Nome: %s | Qtd: %d | Preco: %.2f\n", 
                   estoque[total_produtos].id, 
                   estoque[total_produtos].nome_produto, 
                   estoque[total_produtos].quantidade_estoque, 
                   estoque[total_produtos].preco);

            total_produtos++;
        }
        fclose(arquivo);
        printf("--------------------------------------\n\n");
    } else {
        printf("Arquivo de estoque nao encontrado. Criando um novo ao sair.\n\n");
    }

    do{
        system("clear");
        printf("Selecione uma das opcoes abaixo:\n\n");
        printf("1. Cadastrar produtos\n");
        printf("2. Listar produtos\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);

        switch (opcao){
            case 1:
                printf("CADASTRAR PRODUTO\n\n");
                printf("Digite o nome do produto: ");
                scanf(" %s", estoque[total_produtos].nome_produto);

                printf("Digite a quantidade que deseja armazenar: ");
                scanf(" %d", &estoque[total_produtos].quantidade_estoque);

                printf("Agora, digite o preco do produto: ");
                scanf(" %f", &estoque[total_produtos].preco);

                printf("\n\n");

                estoque[total_produtos].id = total_produtos + 1;
                total_produtos++;
            break;
            case 2:
                printf("LISTAR PRODUTOS\n\n");

                for(int i = 0; i < total_produtos; i++){
                    printf("ID: %d\n", estoque[i].id);
                    printf("Nome do produto: %s\n", estoque[i].nome_produto);
                    printf("Quantidade: %d\n", estoque[i].quantidade_estoque);
                    printf("Preco: %.1f\n", estoque[i].preco);
                }
            break;
            case 3:
                printf("Salvando registros e saindo...");

                arquivo = fopen("estoque.txt", "w");

                for(int i = 0; i < total_produtos; i++){
                    fprintf(arquivo, "ID: %d\n", estoque[i].id);
                    fprintf(arquivo, "Nome do produto: %s\n", estoque[i].nome_produto);
                    fprintf(arquivo, "Quantidade: %d\n", estoque[i].quantidade_estoque);
                    fprintf(arquivo, "Preco: %.1f\n", estoque[i].preco);
                }

                
                fclose(arquivo);
            break;
            default:
                printf("Opcao invalida!");
            break;
        };
        } while (opcao != 3);
}