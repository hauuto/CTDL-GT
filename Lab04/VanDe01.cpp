//
// Created by thanh on 9/23/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "VanDe01.h"



//function prototype
void init(list &l);
node *getNode(float heSo, int soMu);
void addTail(list &l, node *p);
void inputPolynomial(list &l);
void printList(list l);
void sum(list l1, list l2, list &l3);




int main(void){
    list l1, l2, l3;
    init(l1);
    init(l2);
    init(l3);
    printf("Enter the first polynomial\n");
    inputPolynomial(l1);
    printf("Enter the second polynomial\n");
    inputPolynomial(l2);
    printf("The first polynomial: ");
    printList(l1);
    printf("The second polynomial: ");
    printList(l2);
    sum(l1, l2, l3);
    printf("The sum of two polynomials: ");
    printList(l3);

}

//function definition
void init(list &l){
    l.head = l.tail = NULL;
}

node *getNode(float heSo, int soMu){
    node *p = (node*)malloc(sizeof(node));
    if(p == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->heSo = heSo;
    p->soMu = soMu;
    p->link = NULL;
    return p;
}

void addTail(list &l, node *p){
    if(l.head == NULL){
        l.head = l.tail = p;
    }else{
        l.tail->link = p;
        l.tail = p;
    }
}

void inputPolynomial(list &l){
    float heSo;
    int soMu;
    printf("Enter the coefficient and exponent of the polynomial: (0, 0 to end)\n");
    do{
        printf("Enter the coefficient: ");
        scanf("%f", &heSo);
        printf("Enter the exponent: ");
        scanf("%d", &soMu);
        if(heSo != 0){
            addTail(l, getNode(heSo, soMu));
        }
    }while(heSo != 0);
    printf("Adding polynomial successfully\n");
}



void printList(list l){
    node *p = l.head;
    while(p != NULL){
        printf("%.2f*x^%d", p->heSo, p->soMu);
        if(p->link != NULL){
            printf(" + ");
        }
        p = p->link;
    }
    printf("\n");
}

void sum(list l1, list l2, list &l3){
    node *p1 = l1.head;
    node *p2 = l2.head;
    while(p1 != NULL && p2 != NULL){
        if(p1->soMu == p2->soMu){
            addTail(l3, getNode(p1->heSo + p2->heSo, p1->soMu));
            p1 = p1->link;
            p2 = p2->link;
        }else if(p1->soMu > p2->soMu){
            addTail(l3, getNode(p1->heSo, p1->soMu));
            p1 = p1->link;
        }else{
            addTail(l3, getNode(p2->heSo, p2->soMu));
            p2 = p2->link;
        }
    }
    while(p1 != NULL){
        addTail(l3, getNode(p1->heSo, p1->soMu));
        p1 = p1->link;
    }
    while(p2 != NULL){
        addTail(l3, getNode(p2->heSo, p2->soMu));
        p2 = p2->link;
    }
}