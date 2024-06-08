#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binary_tree.h"

t_stack* create_stack() {
    t_stack *stack = (t_stack*) malloc(sizeof(t_stack));
    if (!stack) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void push(t_stack *stack, t_node *tree_node) {
    s_node *new = (s_node*) malloc(sizeof(s_node));
    if (!new) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }
    new->node = tree_node;
    new->next = stack->top;
    stack->top = new;
}

t_node* pop(t_stack *stack) {
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

t_node* create_node(char data) {
    t_node *node = (t_node*)malloc(sizeof(t_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

t_binary_tree* create(const char *representation) {
    t_binary_tree *tree = (t_binary_tree*) malloc(sizeof(t_binary_tree));
    tree->root = NULL;

    if (!isalpha(representation[0])) return tree;
    tree->root = create_node(representation[0]);

    int i = 1;
    t_node *current_node = tree->root;
    t_stack *stack = create_stack();
    push(stack, current_node);

    while (representation[i] != '\0') {
        if (representation[i] == '(') {
            i++;
            if (isalpha(representation[i])) {
                t_node *new_node = create_node(representation[i]);
                if (current_node->left == NULL) {
                    current_node->left = new_node;
                } else {
                    current_node->right = new_node;
                }
                push(stack, current_node);
                current_node = new_node;

            } else if(representation[i] == '(') {
                printf("arvore invalida");
                return tree;

            } else {
                i++;
            }

        } else if (representation[i] == ')') {
            current_node = pop(stack);
            i++;

        } else if (representation[i] == ',') {
            i++;
            if (representation[i] != '(' && representation[i] != ')' && representation[i] != ',') {
                t_node *new_node = create_node(representation[i]);
                if (current_node->left == NULL) {
                    current_node->left = new_node;
                } else {
                    current_node->right = new_node;
                }
                push(stack, current_node);
                current_node = new_node;
            }
        } else {
            i++;

        }
    }

    free_stack(stack);
    return tree;
}

void pre_order(t_node *node) {
    if (node) {
        printf("%c ", node->data);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node *node) {
    if (node) {
        in_order(node->left);
        printf("%c ", node->data);
        in_order(node->right);
    }
}

void post_order(t_node *node) {
    if (node) {
        post_order(node->left);
        post_order(node->right);
        printf("%c ", node->data);
    }
}

void print_tree(t_node *node, int depth) {
    if (node) {
        print_tree(node->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("   ");
        }
        printf("%c\n", node->data);
        print_tree(node->left, depth + 1);
    }
}

void free_tree(t_node *node) {
    if (node) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

t_node* find_node(t_node* root, char node) {
    if (root == NULL) return NULL;
    if (root->data == node) return root;

    t_node* left_node = find_node(root->left, node);
    if (left_node != NULL) return left_node;

    return find_node(root->right, node);
}

int height(t_node* node) {
    if (node == NULL) {
        return -1;
    } else {
        int left_height = height(node->left);
        int right_height = height(node->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

int height_of_node(t_node* root, char node) {
    t_node* found_node = find_node(root, node);
    if (found_node == NULL) 
        return -1;

    return height(found_node);
}

void choosed_option(int option, t_binary_tree *tree){
    char node_data;

    switch(option){
            case 1:
               printf("Pre ordem:\n");
               pre_order(tree->root);
               printf("\n");
               break;

            case 2:
               printf("In ordem:\n");
               in_order(tree->root);
               printf("\n");
               break;

            case 3:
               printf("Pos ordem:\n");
               post_order(tree->root);
               printf("\n");
               break;

            case 4:
                printf("Digite um dos nos da arvore:\n");
                scanf(" %c", &node_data);
                printf("%d\n", height_of_node(tree->root, node_data));
                break;

            case 0:
               printf("Fim do programa\n");
    }
}
