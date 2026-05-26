/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} ItemCarrinho;

ItemCarrinho carrinho[50];
int totalCarrinho = 0;

void adicionarProduto() {
    Produto p;
    printf("Nome do produto: ");
    scanf("%s", p.nome);
    printf("Preco: ");
    scanf("%f", &p.preco);
    p.id = totalCarrinho + 1;
    carrinho[totalCarrinho].produto = p;
    carrinho[totalCarrinho].quantidade = 1;
    totalCarrinho++;
    printf("Produto adicionado ao carrinho!\n");
}

void visualizarCarrinho() {
    float total = 0;
    printf("\n--- Carrinho ---\n");
    for(int i=0; i<totalCarrinho; i++) {
        printf("%d - %s (R$ %.2f)\n", i+1, carrinho[i].produto.nome, carrinho[i].produto.preco);
        total += carrinho[i].produto.preco;
    }
    printf("Total: R$ %.2f\n", total);
}

int main() {
    int opcao;
    do {
        printf("\n1 - Adicionar Produto\n2 - Visualizar Carrinho\n0 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: adicionarProduto(); break;
            case 2: visualizarCarrinho(); break;
        }
    } while(opcao != 0);
    return 0;
}
*/

/* ====================================================================
 * EMPRESA: SUPLEMENTOS PURE GOLD
 * COMPONENTE: Sistema de Simulação de Carrinho de Compras (Console)
 * INTEGRANTES DO GRUPO: [Insira os nomes dos integrantes aqui]
 * ====================================================================
 * Elementos de Lógica Atendidos:
 * - Estruturas (Structs) para Produtos e Carrinho
 * - Vetores para armazenamento dos itens
 * - Estruturas de Repetição (do-while e for)
 * - Estruturas de Decisão (switch-case)
 * ====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    float preco;
} Produto;

typedef struct
{
    Produto produto;
    int quantidade;
} ItemCarrinho;

ItemCarrinho carrinho[50];
int totalCarrinho = 0;

void adicionarProduto()
{
    if (totalCarrinho >= 50)
    {
        printf("\n[AVISO] Limite do carrinho atingido!\n");
        return;
    }

    Produto p;
    int qtd;

    printf("\n--- ADICIONAR ITEM AO CARRINHO ---\n");
    printf("Nome do produto (ex: Whey Protein): ");
    scanf(" %[^\n]", p.nome);

    printf("Preco unitario (R$): ");
    scanf("%f", &p.preco);

    printf("Quantidade desejada: ");
    scanf("%d", &qtd);

    p.id = totalCarrinho + 1;

    carrinho[totalCarrinho].produto = p;
    carrinho[totalCarrinho].quantidade = qtd;
    totalCarrinho++;

    printf("\n[SUCESSO] %d unidade(s) de '%s' adicionada(s)!\n", qtd, p.nome);
}

void visualizarCarrinho()
{
    float totalGeral = 0;

    printf("\n======================================================\n");
    printf("               SUPLEMENTOS PURE GOLD - CARRINHO       \n");
    printf("======================================================\n");
    printf(" ID  | PRODUTO               | QTD | PRECO UN. | TOTAL \n");
    printf("------------------------------------------------------\n");

    if (totalCarrinho == 0)
    {
        printf("          O seu carrinho esta vazio.                  \n");
    }
    else
    {
        for (int i = 0; i < totalCarrinho; i++)
        {
            float totalItem = carrinho[i].produto.preco * carrinho[i].quantidade;
            totalGeral += totalItem;

            printf(" %02d  | %-21s | %3d | R$%7.2f | R$%7.2f\n",
                   carrinho[i].produto.id,
                   carrinho[i].produto.nome,
                   carrinho[i].quantidade,
                   carrinho[i].produto.preco,
                   totalItem);
        }
    }

    printf("======================================================\n");
    printf(" TOTAL DA COMPRA: R$ %.2f\n", totalGeral);
    printf("======================================================\n");
}

int main()
{
    int opcao;

    do
    {
        printf("\n=== MENU CONSOLE PURE GOLD ===\n");
        printf("1 - Adicionar Produto ao Carrinho\n");
        printf("2 - Visualizar Carrinho e Total\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarProduto();
            break;
        case 2:
            visualizarCarrinho();
            break;
        case 0:
            printf("\nEncerrando sistema do carrinho Pure Gold...\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}