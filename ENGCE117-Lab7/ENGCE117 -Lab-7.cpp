#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start;
    struct studentNode **now;
public:
    LinkedList() {
        start = NULL;
        now = &start;
    }
    
    ~LinkedList() {
        struct studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            free(temp);
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = *now;
        *now = newNode;
    }

    void DelNode() {
        if (*now != NULL) {
            struct studentNode *temp = *now;
            *now = (*now)->next;
            free(temp);
        }
    }

    void GoNext() {
        if (*now != NULL) {
            now = &((*now)->next);
        }
    }

    virtual void ShowNode() {
        if (*now != NULL) {
            printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
        }
    }
};

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = &start;
    }

    void InsertNode(char n[], int a, char s, float g) {
        InsNode(n, a, s, g);
    }

    virtual void ShowNode() {
        struct studentNode *temp = start;
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode((char*)"one", 1, 'A', 1.1);
    listA.InsNode((char*)"two", 2, 'B', 2.2);
    listA.InsNode((char*)"three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsertNode((char*)"four", 4, 'D', 4.4);
    listB.InsertNode((char*)"five", 5, 'E', 5.5);
    listB.InsertNode((char*)"six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}