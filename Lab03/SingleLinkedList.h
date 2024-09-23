//
// Created by thanh on 9/23/2024.
//

#ifndef LAB03_SINGLELINKEDLIST_H
#define LAB03_SINGLELINKEDLIST_H

typedef struct node node;
typedef struct list list;

struct node{
    int data;
    node *next;
};

struct list {
    node *head;
    node *tail;
};



//function prototype
node *getNode(int data);
void initList(list &l);


bool checkEmptyList(list &l);


void addFirst(list &l, node *newNode);
void insertFirst(list &l, int data);
void createListFirst(list &l);


#endif //LAB03_SINGLELINKEDLIST_H
