#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Estrutura do nó
typedef struct t_node {
    char data;
    struct t_node *left;
    struct t_node *right;
} t_node;

// Estrutura da árvore
typedef struct {
    t_node *root;
} t_binary_tree;

// nó para pilha
typedef struct __node {
    t_node *node;
    struct __node *next;
} s_node;

// Estrutura da pilha
typedef struct {
    s_node *top;
} t_stack;

// Funções da pilha
t_stack* create_stack();
void push(t_stack *stack, t_node *tree_node);
t_node* pop(t_stack *stack);
void free_stack(t_stack *stack);

// Funções da árvore
t_binary_tree* create(const char *representation);
void pre_order(t_node *node);
void in_order(t_node *node);
void post_order(t_node *node);
void print_tree(t_node *node, int depth);
void free_tree(t_node *node);

t_node* find_node(t_node* root, char node);
int height(t_node* node);
int height_of_node(t_node* root, char node);

#endif // BINARY_TREE_H


