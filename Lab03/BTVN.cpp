//
// Created by thanh on 9/16/2024.
//

#include <stdio.h>



struct Node{
    int data;
    Node *link;
};

struct List{
    Node *first;
    Node *last;
};

void Init(List &l){
    l.first = l.last = NULL;
}

Node *GetNode(int x){
    Node *p = new Node;
    if(p == NULL){
        return NULL;
    }
    p->data = x;
    p->link = NULL;
    return p;
}

void AddFirst(List &l, Node *p){
    if(l.first == NULL){
        l.first = l.last = p;
    }else{
        p->link = l.first;
        l.first = p;
    }
}


void InsertFirst (List &l, int x){
    Node *p = GetNode(x);
    if(p == NULL){
        return;
    }
    AddFirst(l, p);
}

void CreateListFirst(List &l){
    do {
        int x;
        printf("Nhap x (Nhap -1 de ket thuc): ");
        scanf("%d", &x);
        if(x == -1){
            break;
        }
        InsertFirst(l, x);
    }while(1);
    printf("Nhap du lieu thanh cong\n");
}

void PrinttList(List l){
    Node *p;
    p = l.first;
    while(p != NULL){
        printf("%5d", p->data);
        p = p->link;
    }
}

long SumEvenNumber(List l){
    long sum = 0;
    Node *p = l.first;
    while(p != NULL){
        if(p->data % 2 == 0){
            sum += p->data;
        }
        p = p->link;
    }
    return sum;
}

Node *Search(List l, int x){
    Node *p = l.first;
    while(p != NULL){
        if(p->data == x){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

void AddLast(List &l, Node *p){
    if(l.first == NULL){
        l.first = l.last = p;
    }else{
        l.last->link = p;
        l.last = p;
    }
}

void InsertLast(List &l, int x){
    Node *p = GetNode(x);
    if(p == NULL){
        return;
    }
    AddLast(l, p);
}

void CreateListLast(List &l){
    do {
        int x;
        printf("Nhap x (Nhap -1 de ket thuc): ");
        scanf("%d", &x);
        if(x == -1){
            break;
        }
        InsertLast(l, x);
    }while(1);
    printf("Nhap du lieu thanh cong\n");
}

int main(void){
    List l;
    Init(l);
    CreateListFirst(l);
    PrinttList(l);

    printf("\nTong cac so chan trong danh sach la: %ld\n", SumEvenNumber(l));

    int x;
    printf("Nhap x can tim: ");
    scanf("%d", &x);
    Node *p = Search(l, x);
    if(p != NULL){
        printf("Tim thay x = %d\n", x);
    }else{
        printf("Khong tim thay x = %d\n", x);
    }

    CreateListLast(l);
    PrinttList(l);
    return 0;


}
