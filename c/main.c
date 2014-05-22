#include <stdio.h>
#include <stdlib.h>

#include "binTree.h"

void header() {

    system("clear");

    puts("+--------------------------------------------------+");
    puts("| Programa para teste da árvore binária            |");
    puts("+--------------------------------------------------+");

}

void menu() {

    puts("| Menu                                             |");
    puts("| (1) Inserção de elementos                        |");
    puts("| (2) Busca de de elementos                        |");
    puts("| (3) Listagem da árvore                           |");
    puts("| (0) Sair do programa                             |");
    puts("+--------------------------------------------------+");

}

void wait() {
    while(getchar() != '\n');
    fflush(stdin);
}

char getOption() {

    char op;

    header();
    menu();

    op = getchar();

    fflush(stdin);

    return op;

}

void insertOption() {

    int newVal;

    header();

    puts("\n\tInsira um número para ser adicionado na árvore:");
    scanf("%d", &newVal);

    insert(newVal);

}

void searchOption() {

    int searchVal;

    header();

    puts("\n\tDigite um número para procurar na árvore:");
    scanf("%d", &searchVal);

    search(searchVal);

}

void printOption() {

    header();

    puts("\n\tA árvore:");

    if (root != NULL) {
        putchar('\n');
        putchar('\t');

        printTree(root);
    } else {
        puts("Árvore vazia");
    }

    wait();

}

int main()
{

    int keep = 1;

    while(keep) {

        switch(getOption()) {

            case '1':
                insertOption();
                break;
            case '2':
                searchOption();
                break;
            case '3':
                printOption();
                break;
            case '0':
                keep = 0;
                break;

        }

    }

    return 0;
}