//
// Created by thanh on 9/20/2024.
//

#include <stdio.h>
#include <stdlib.h>

//Define node structure
typedef struct node node;
struct node{
    int data;
    node *link;
};

//Create new node
node* makeNode(int n){
    node *newNode = (node*)malloc(sizeof(node)); //Allocate memory for new node
    newNode->data = n;   //Assign value to new node
    newNode->link = NULL; //Set link to NULL
    return newNode; //Return new node
}

//Iterate through the list
void iterateList(node *head){
    int count=0; //Count number of nodes
    while(head != NULL){
        ++count; //Increment count
        printf("%d ",head->data);
        head = head->link;
    }
}


//Insert new node in the beginning of the list
void insertFirstNode(node **head, int x){
    node *newNode = makeNode(x); //Create new node


    //Buoc 1: Link cua newNode tro den head hien tai
    newNode->link = *head; //Set link of new node to head


    //Buoc 2: Head hien tai tro den newNode tro thanh head moi
    *head = newNode; //Set head to new node
}


//Inser new node in the end of the list
/*Idea: iterate through list.
 * When the link of the node is null -> the link of the node = direction of newNode*/
void insertLastNode(node **head, int x){
    node *newNode = makeNode(x); //Create new node
    node *temp = *head; //Create temporary node

    //If the list is empty -> set head to new node
    if (*head==NULL){
        *head= newNode;
        return;
    }
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = newNode;


}


int main(void){
    node *head = NULL; //Initialize head of node

    for (int i = 1;i<=5; ++i){
        insertFirstNode(&head,i); //Insert new node in the beginning of the list
    }
    iterateList(head); //Iterate through the list

    printf("\n");
    for (int i = 1;i<=5; ++i){

        insertLastNode(&head,i); //Insert new node in the last of the list
    }
    iterateList(head); //Iterate through the list

}