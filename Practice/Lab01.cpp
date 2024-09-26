//
// Created by thanh on 9/26/2024.
//

#include <stdio.h>
#include <String.h>
#define MAXN 1000

typedef struct WORD WORD;

struct WORD{
    char Name[256];
    char Meaning[512];
};

//function prototypes

int main(void){
    int count =0;
    WORD words[MAXN];
    WORD word;

    int choice;
    do{
        printf("1. Add a word\n");
        printf("2. Print a word\n");
        printf("3. Sort words\n");
        printf("4. Search a word\n");
        printf("5. Export words\n");
        printf("6. Import words\n");
        printf("7. Update a word\n");
        printf("8. Delete a word\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);

        FILE *file = fopen("words.txt","w+");
        if (file == NULL){
            printf("Cannot open file\n");
        }
        switch (choice){
            case 1:
                printf("Enter a word: ");
                fflush(stdin);
                gets(word.Name);
                printf("Enter meaning: ");
                fflush(stdin);
                gets(word.Meaning);
                words[count++] = word;
                break;
            case 2:
                printf("Enter a word: ");
                fflush(stdin);
                gets(word.Name);
                for (int i=0; i<count; ++i){
                    if (strcmp(words[i].Name,word.Name)==0){
                        printf("Meaning: %s\n",words[i].Meaning);
                        break;
                    }
                }
                break;
            case 3:
                for (int i=0; i<count-1; ++i){
                    for (int j=i+1; j<count; ++j){
                        if (strcmp(words[i].Name,words[j].Name)>0){
                            WORD temp = words[i];
                            words[i] = words[j];
                            words[j] = temp;
                        }
                    }
                }
                break;
            case 4:
                printf("Enter a word: ");
                fflush(stdin);
                gets(word.Name);
                for (int i=0; i<count; ++i){
                    if (strcmp(words[i].Name,word.Name)==0){
                        printf("Meaning: %s\n",words[i].Meaning);
                        break;
                    }
                }
                break;
            case 5:
                for (int i=0; i<count; ++i){
                    fprintf(file,"%s: %s\n",words[i].Name,words[i].Meaning);
                }
                fclose(file);
                break;
            case 6:
                while (fscanf(file,"%s: %s\n",word.Name,word.Meaning)!=EOF){
                    words[count++] = word;
                }
                fclose(file);
                break;
            case 7:
                printf("Enter a word: ");
                fflush(stdin);
                gets(word.Name);
                for (int i=0; i<count; ++i){
                    if (strcmp(words[i].Name,word.Name)==0){
                        printf("Enter meaning: ");
                        fflush(stdin);
                        gets(words[i].Meaning);
                        break;
                    }
                }
                break;
            case 8:
                printf("Enter a word: ");
                fflush(stdin);
                gets(word.Name);
                for (int i=0; i<count; ++i){
                    if (strcmp(words[i].Name,word.Name)==0){
                        for (int j=i; j<count-1; ++j){
                            words[j] = words[j+1];
                        }
                        count--;
                        break;
                    }
                }
                break;
        }
    }while (choice !=9);

}

//implementations



