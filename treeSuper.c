#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore
typedef struct _node {
  char data;
  struct _node *left;
  struct _node *right;
} t_node;

// Estrutura de uma árvore binária
typedef struct {
  t_node *root;
} t_binary_tree;

// Estrutura de um nó da pilha
typedef struct __node {
  t_node *node;
  struct __node *next;
} s_node;

// Estrutura de uma pilha
typedef struct {
  s_node *top;
} t_stack;

// Função auxiliar para criar um novo nó da árvore
t_node *create_node(char data) {
  t_node *new = (t_node *)malloc(sizeof(t_node));

  if (!new) {
    printf("Erro na alocação de memória\n");
    exit(1);
  }

  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

// Funções da pilha
t_stack *create_stack() {
  t_stack *stack = (t_stack *)malloc(sizeof(t_stack));

  if (!stack) {
    printf("Erro na alocação de memória\n");
    exit(1);
  }

  stack->top = NULL;
  return stack;
}

void push(t_stack *stack, t_node *tree_node) {
  s_node *new = (s_node *)malloc(sizeof(s_node));

  if (!new) {
    printf("Erro na alocação de memória\n");
    exit(1);
  }

  new->node = tree_node;
  new->next = stack->top;
  stack->top = new;
}

t_node *pop(t_stack *stack) {
  if (stack->top == NULL) {
    return NULL;
  }

  s_node *top_node = stack->top;
  t_node *tree_node = top_node->node;
  stack->top = top_node->next;

  free(top_node);
  return tree_node;
}

void free_stack(t_stack *stack) {
  while (stack->top != NULL) {
    s_node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
  }
  free(stack);
}

// Função para criar a árvore binária a partir de uma string
t_binary_tree *create(const char *str) {
  t_binary_tree *tree = (t_binary_tree *)malloc(sizeof(t_binary_tree));
  if (!tree) {
    printf("Erro na alocação de memória\n");
    exit(1);
  }
  tree->root = NULL;

  char *p = (char *)str;
  if (!isalpha(*p))
    return tree;

  tree->root = create_node(*p);
  p++;

  t_stack *stack = create_stack();
  t_node *current_node = tree->root;
  t_node *parent_node = NULL;

  while (*p) {
    if (*p == '(') {
      p++;
      if (*p == ')') {
        p++;
        continue;
      }
      if (isalpha(*p)) {
        parent_node = current_node;
        current_node = create_node(*p);
        if (parent_node->left == NULL) {
          parent_node->left = current_node;
        } else {
          parent_node->right = current_node;
        }
        push(stack, parent_node);
      }
      p++;
    } else if (*p == ')') {
      current_node = pop(stack);
      p++;
    } else if (*p == ',') {
      p++;
    } else {
      p++;
    }
  }

  free_stack(stack);
  return tree;
}

// Função para imprimir a árvore binária
void print_tree(t_node *node, int depth) {
  if (node == NULL)
    return;

  print_tree(node->right, depth + 1);

  for (int i = 0; i < depth; i++) {
    printf("   ");
  }

  printf("%c\n", node->data);

  print_tree(node->left, depth + 1);
}

// Função para percorrer a árvore binária em ordem
void inOrder(t_node *root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
  }
}

// Função para calcular a altura da árvore
int height(t_node *node) {
  if (node == NULL) {
    return 0;
  } else {
    int left_height = height(node->left);
    int right_height = height(node->right);
    if (left_height > right_height) {
      return (left_height + 1);
    } else {
      return (right_height + 1);
    }
  }
}

// Função para liberar a memória da árvore
void free_tree(t_node *node) {
  if (node == NULL) {
    return;
  }
  free_tree(node->left);
  free_tree(node->right);
  free(node);
}
