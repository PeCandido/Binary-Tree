#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.c"
#include "binary_tree.h"

int main(){
    char representation [100];
    printf("Digite a representacao de arvore:\n");
    gets(representation);
    
    t_binary_tree *tree = create(representation);  
    print_tree(tree->root,0);
    
    int opcao = 0;
    do{
        printf("Escolha a ordenacao: \n 1 - pre order\n 2 - in order\n 3 - pos order\n 4 - altura do no\n 0 - exit\n");
        scanf("%d", &opcao);

        choosed_option(opcao, tree);
    } 
    while(opcao != 0);

    free_tree(tree->root);
}