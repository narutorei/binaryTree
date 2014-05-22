#include <stdio.h>
#include <stdlib.h>

#ifndef H_BINARY_TREE
#define H_BINARY_TREE

struct node {
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node t_node;

t_node *root = NULL;

void insert(int val) {
    t_node *here, *aux;

    aux = (t_node*) malloc(sizeof(t_node));

    if(aux == NULL)
        return;

    aux->value = val;

    aux->left = aux->right = NULL;

    if(root == NULL)
        root = aux;
    else {
        here = root;

        while(1) {

            if(val < here->value) {
                if(here->left == NULL) {
                    here->left = aux;
                    break;
                } else
                    here = here->left;
            } else {
                if(here->right == NULL) {
                    here->right = aux;
                    break;
                } else
                    here = here->right;
            }

        }

    }

}

void printTree(t_node *here) {

    if(here != NULL) {
        printTree(here->left);
        printf("%d\n", here->value);
        printTree(here->right);
    }

}

void search(int val) {

    t_node *here = root;

    while(here != NULL) {

        if(here->value > val) {
            here = here->right;
        } else if(here->value < val) {
            here = here->left;
        } else {
            printf("O valor %d foi encontrado na árvore", val);
            return;
        }

    }

    printf("O valor %d não foi encontrado na árvore", val);

}

#endif /* H_BINARY_TREE */