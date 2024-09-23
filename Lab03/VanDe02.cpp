//
// Created by thanh on 9/20/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"



//function prototype
node *getNode(int data);
void initList(list &l);


bool checkEmptyList(list &l);


void addFirst(list &l, node *newNode);
void insertFirst(list &l, int data);
void createListFirst(list &l);
void printList(list &l);

long sumEvenNumber(list &l);
void addLast(list &l, node *p);
void insertLast(list &l, int x);
void createListLast(list &l);


void separatingList(list &l, list &l1, int x);




int main(void){
    list l;
    initList(l);
    createListFirst(l);
    printList(l);
    printf("Sum of even numbers: %ld\n", sumEvenNumber(l));
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    list l1;
    initList(l1);
    separatingList(l, l1, x);
    printf("List 1: \n");
    printList(l1);
    printf("List 2: \n");
    printList(l);
    return 0;

}

//Create a new empty list
void initList(list &l){
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


bool checkEmptyList(list &l){
    if(l.head == NULL && l.tail == NULL){
        return true;
    }
    return false;
}

void addFirst(list &l, node *newNode){
    if(checkEmptyList(l)){
        l.head = l.tail = newNode;
    }else{
        newNode->next = l.head;
        l.head = newNode;
    }
}

void insertFirst(list &l, int data){
    node *newNode = getNode(data);
    if (newNode == NULL){
        return;
    }
    addFirst(l, newNode);
}


void createListFirst(list &l){
    do {
        int data;
        printf("Enter data (Enter -1 to end):");
        scanf("%d", &data);
        if(data == -1){
            break;
        }
        node *newNode = getNode(data);
        insertFirst(l, data);

    }while(1);
    printf("Data entered successfully\n");
}

void printList(list &l){
    node *p = l.head;
    while(p != NULL){
        printf("Data: %d ,Direction: %u\n", p->data,p);
        p = p->next;
    }
    printf("\n");
}

long sumEvenNumber(list &l){
    long sum = 0;
    node *p = l.head;
    while (p!=NULL){
        if(p->data % 2 == 0){
            sum += p->data;
        }
        p = p->next;
    }
    return sum;
}

node *Search(list &l, int x){
    node *p = l.head;
    while(p != NULL){
        if(p->data == x){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void addLast(list &l, node *p){
    if(checkEmptyList(l)){
        l.head = l.tail = p;
    }else{
        l.tail->next = p;
        l.tail = p;
    }
}

void insertLast(list &l, int x){
    node *p = getNode(x);
    if(p == NULL){
        return;
    }
    addLast(l, p);
}

void createListLast(list &l){
    do {
        int data;
        printf("Enter data (Enter -1 to end):");
        scanf("%d", &data);
        if(data == -1){
            break;
        }
        node *newNode = getNode(data);
        insertLast(l, data);

    }while(1);
    printf("Data entered successfully\n");
}

void separatingList(list &l, list &l1, int x) {
    node *p = l.head;
    list temp;
    initList(temp);
    while (p != NULL) {
        node *next = p->next; // Save the next node
        p->next = NULL; // Disconnect the current node from the list
        if (p->data < x) {
            addLast(l1, p);
        } else {
            addLast(temp, p);
        }
        p = next; // Move to the next node
    }
    l = temp;
}




