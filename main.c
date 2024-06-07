#include "treeSuper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
  printf("\nMenu:\n");
  printf("1. Criar arvore\n");
  printf("2. Imprimir arvore\n");
  printf("3. Exibir InOrder\n");
  printf("4. Exibir altura da arvore\n");
  printf("5. Sair\n");
  printf("Escolha uma opcao: ");
}

int main() {
  t_binary_tree *tree = NULL;
  char input[100];
  int option;

  do {
    print_menu();
    scanf("%d", &option);

    switch (option) {
    case 1:
      if (tree != NULL) {
        free_tree(tree->root);
        free(tree);
      }
      printf("Digite a string de criacao da arvore: ");
      scanf("%s", input);
      tree = create(input);
      printf("Arvore criada.\n");
      break;

    case 2:
      if (tree != NULL) {
        printf("Arvore:\n");
        print_tree(tree->root, 0);
      } else {
        printf("nenhuma arvore criada\n");
      }
      break;

    case 3:
      if (tree != NULL) {
        printf("InOrder: ");
        inOrder(tree->root);
        printf("\n");
      } else {
        printf("nenhuma arvore criada\n");
      }
      break;

    case 4:
      if (tree != NULL) {
        int tree_height = height(tree->root);
        printf("Altura da arvore: %d\n", tree_height);
      } else {
        printf("nenhuma arvore criada\n");
      }
      break;

    case 5:
      printf("Saindo\n");
      break;

    default:
      printf("Opcao invalida. Tente novamente.\n");
      break;
    }
  } while (option != 5);

  if (tree != NULL) {
    free_tree(tree->root);
    free(tree);
  }

  return 0;
}
