//
// Created by thanh on 9/23/2024.
//

#ifndef LAB04_VANDE01_H
#define LAB04_VANDE01_H

typedef struct node node;
typedef struct list list;
struct node{
    float heSo;
    int soMu;
    node *link;
};

struct list{
    node *head;
    node *tail;
};


//from VanDe01.cpp
void init(list &l);
node *getNode(float heSo, int soMu);
void addTail(list &l, node *p);
void inputPolynomial(list &l);
void printList(list l);
void sum(list l1, list l2, list &l3);


//from VanDe02.cpp
void interchangeSort(list &l);

//from BaiTapLamThem.cpp
void subtract(list &l1, list &l2, list &l3);
void multiply(list &l1, list &l2, list &l3);
void divide(list &l1, list &l2, list &l3);

#endif //LAB04_VANDE01_H
