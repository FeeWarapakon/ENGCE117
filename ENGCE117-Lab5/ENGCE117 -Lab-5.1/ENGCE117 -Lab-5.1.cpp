#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct studentNode* AddNode(struct studentNode **walk, char n[], int a, char s, float g);
void InsNode(struct studentNode *now, char n[], int a, char s, float g);
void DelNode(struct studentNode *now);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11); 
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); 
    ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33); 
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); 
    ShowAll(start);
    DelNode(now); 
    ShowAll(start);

    return 0;
}//end main

struct studentNode* AddNode(struct studentNode **walk, char n[], int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*walk == NULL) {
        *walk = newNode;
    } else {
        struct studentNode *temp = *walk;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return newNode;
}//end function AddNode

void InsNode(struct studentNode *now, char n[], int a, char s, float g) {
    if (now == NULL) return;
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = now->next;
    now->next = newNode;
}//end function InsNode

void DelNode(struct studentNode *now) {
    if (now == NULL || now->next == NULL) return;
    struct studentNode *temp = now->next;
    now->next = temp->next;
    free(temp);
}//end function DelNode

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}//end function ShowAll