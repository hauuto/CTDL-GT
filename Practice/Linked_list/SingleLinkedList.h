//
// Created by thanh on 9/23/2024.
//

#ifndef LINKED_LIST_SINGLELINKEDLIST_H
#define LINKED_LIST_SINGLELINKEDLIST_H

//Linked list with node and list structure
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

node *getNode(int data);
void initList(list l);

#endif //LINKED_LIST_SINGLELINKEDLIST_H
