//
// Created by thanh on 8/23/2024.
//
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_MEANING_LENGTH 512

struct WORD {
    char Name[MAX_NAME_LENGTH];
    char Meaning[MAX_MEANING_LENGTH];
};



void nhapTu(struct WORD *tu);
void xuatTu(struct WORD tu);


int main(void){
    WORD tu;
    nhapTu(&tu);
    xuatTu(tu);
}


void nhapTu(struct WORD *tu) {
    printf("Nhap tu tieng Anh: ");
    fgets(tu->Name, MAX_NAME_LENGTH, stdin);
    tu->Name[strcspn(tu->Name, "\n")] = 0;

    printf("Nhap nghia cua tu: ");
    fgets(tu->Meaning, MAX_MEANING_LENGTH, stdin);
    tu->Meaning[strcspn(tu->Meaning, "\n")] = 0;
}

void xuatTu(struct WORD tu) {
    printf("Tu: %s\n", tu.Name);
    printf("Nghia: %s\n", tu.Meaning);
}

