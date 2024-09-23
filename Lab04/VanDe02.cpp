//
// Created by thanh on 9/23/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "VanDe01.h"

void interchangeSort(list &l);

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

    sum(l1, l2, l3);
    printf("The sum of two polynomials: ");
    printList(l3);


}


void interchangeSort(list &l){
    node *p, *q;
    for(p = l.head; p != l.tail; p = p->link){
        for(q = p->link; q != NULL; q = q->link){
            if(p->soMu < q->soMu){
                node *temp = getNode(p->heSo, p->soMu);
                p->heSo = q->heSo;
                p->soMu = q->soMu;
                q->heSo = temp->heSo;
                q->soMu = temp->soMu;
            }
        }
    }
}