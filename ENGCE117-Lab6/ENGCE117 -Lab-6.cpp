#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **start, char *n, int a, char s, float g);
void InsNode(struct studentNode *now, char *n, int a, char s, float g);
void GoBack(struct studentNode **now);
void DelNode(struct studentNode *now);

int main() {
    struct studentNode *start, *now;
    start = NULL;

    printf("Add Node 'one': ");
    now = AddNode(&start, "one", 6, 'M', 3.11); 
    ShowAll(start);

    printf("Add Node 'two': ");
    now = AddNode(&start, "two", 8, 'F', 3.22); 
    ShowAll(start);

    printf("Insert 'three' before 'two': ");
    InsNode(now, "three", 10, 'M', 3.33); 
    ShowAll(start);

    printf("Insert 'four' before 'two': ");
    InsNode(now, "four", 12, 'F', 3.44); 
    ShowAll(start);

    printf("GoBack & Delete Nodes:\n");
    GoBack(&now);
    
    DelNode(now); ShowAll(start);
    return 0;
}//end main

struct studentNode *AddNode(struct studentNode **start, char *n, int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*start == NULL) { 
        newNode->back = NULL;
        *start = newNode;
    } else {
        struct studentNode *walk = *start;
        while (walk->next != NULL) walk = walk->next;
        walk->next = newNode;
        newNode->back = walk;
    }
    return newNode;
}//end AddNode

void InsNode(struct studentNode *now, char *n, int a, char s, float g) {
    if (now == NULL) return;
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = now;
    newNode->back = now->back;

    if (now->back != NULL) {
        now->back->next = newNode;
    }
    now->back = newNode;
}//end InsNode

void GoBack(struct studentNode **now) {
    if ((*now) != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}//end GoBack

void DelNode(struct studentNode *now) {
    if (now == NULL) return;
    
    struct studentNode *b = now->back;
    struct studentNode *n = now->next;

    if (b != NULL) b->next = n;
    if (n != NULL) n->back = b;
    free(now);
}//end DelNode

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}//end ShowAll