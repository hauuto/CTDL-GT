//
// Created by thanh on 9/20/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <rpcndr.h>
#include "SingleLinkedList.h"



//function prototype
node *getNode(int data);
void initList(list l);


int main(void){


}

//Create a new empty list
void initList(list l){
    l.head = NULL;
    l.tail = NULL;
}

//Create a new node
node *getNode(int data){
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Insert a new node at head of the list

boolean checkEmptyList(list l){
    if(l.head ==)
}





