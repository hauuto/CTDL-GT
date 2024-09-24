//
// Created by thanh on 9/23/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "VanDe01.h"

void subtract(list &l1, list &l2, list &l3);
void multiply(list &l1, list &l2, list &l3);
void divide(list &l1, list &l2, list &l3);



int main(void){
    list l1, l2, l3;
    init(l1);
    init(l2);
    init(l3);
    printf("Enter the first polynomial\n");
    inputPolynomial(l1);
    interchangeSort(l1);

    printf("Enter the second polynomial\n");
    inputPolynomial(l2);
    interchangeSort(l2);


    printf("The first polynomial: ");
    printList(l1);
    printf("The second polynomial: ");
    printList(l2);


    subtract(l1, l2, l3);
    printf("The subtract of two polynomials: ");
    printList(l3);


    multiply(l1, l2, l3);
    printf("The multiply of two polynomials: ");
    printList(l3);


    divide(l1, l2, l3);
    printf("The divide of two polynomials: ");
    printList(l3);

}

void subtract(list &l1, list &l2, list &l3){
    node *p = l1.head;
    node *q = l2.head;
    while(p != NULL && q != NULL){
        if(p->soMu == q->soMu){
            float heSo = p->heSo - q->heSo;
            if(heSo != 0){
                node *temp = getNode(heSo, p->soMu);
                addTail(l3, temp);
            }
            p = p->link;
            q = q->link;
        }else if(p->soMu > q->soMu){
            node *temp = getNode(p->heSo, p->soMu);
            addTail(l3, temp);
            p = p->link;
        }else{
            node *temp = getNode(-q->heSo, q->soMu);
            addTail(l3, temp);
            q = q->link;
        }
    }
    while(p != NULL){
        node *temp = getNode(p->heSo, p->soMu);
        addTail(l3, temp);
        p = p->link;
    }
    while(q != NULL){
        node *temp = getNode(-q->heSo, q->soMu);
        addTail(l3, temp);
        q = q->link;
    }
}

void multiply(list &l1, list &l2, list &l3){
    node *p = l1.head;
    node *q = l2.head;
    while(p != NULL){
        while(q != NULL){
            float heSo = p->heSo * q->heSo;
            int soMu = p->soMu + q->soMu;
            node *temp = getNode(heSo, soMu);
            addTail(l3, temp);
            q = q->link;
        }
        p = p->link;
        q = l2.head;
    }
}

void divide(list &l1, list &l2, list &l3){
    node *p = l1.head;
    node *q = l2.head;
    while(p != NULL){
        while(q != NULL){
            float heSo = p->heSo / q->heSo;
            int soMu = p->soMu - q->soMu;
            node *temp = getNode(heSo, soMu);
            addTail(l3, temp);
            q = q->link;
        }
        p = p->link;
        q = l2.head;
    }
}