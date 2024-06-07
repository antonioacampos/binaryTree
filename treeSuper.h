// treeSuper.h
#ifndef TREE_SUPER_H
#define TREE_SUPER_H

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

t_node *createNode(int data);
t_stack *create_stack();
void push(t_stack *stack, t_node *tree_node);
t_node *pop(t_stack *stack);
void free_stack(t_stack *stack);
t_binary_tree *create(const char *str);
void print_tree(t_node *node, int depth);
void inOrder(t_node *root);
int height(t_node *node);
void free_tree(t_node *node);

#endif // TREE_SUPER_H
