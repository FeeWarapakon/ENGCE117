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
    struct studentNode *start, **now;
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
        if (newNode == NULL) return;
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
            printf("Deleted successfully.\n");
        }
    }

    void GoNext() {
        if (*now != NULL && (*now)->next != NULL) {
            now = &((*now)->next);
        }
    }

    void GoFirst() {
        now = &start;
    }

    void GoLast() {
        now = &start;
        while (*now != NULL && (*now)->next != NULL) {
            now = &((*now)->next);
        }
    }

    void ShowAll() {
        struct studentNode *temp = start;
        printf("\n%-20s | %-3s | %-3s | %-5s\n", "Name", "Age", "Sex", "GPA");
        printf("--------------------------------------------\n");
        while (temp != NULL) {
            printf("%-20s | %-3d | %-3c | %-5.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
    }

    int FindNode(char n[]) {
        GoFirst();
        while (*now != NULL) {
            if (strcmp((*now)->name, n) == 0) return 1;
            now = &((*now)->next);
        }
        return 0;
    }

    struct studentNode *NowNode() {
        return *now;
    }

    void EditNode(char n[], int a, char s, float g) {
        if (*now != NULL) {
            strcpy((*now)->name, n);
            (*now)->age = a;
            (*now)->sex = s;
            (*now)->gpa = g;
        }
    }
};

void AddData(LinkedList *ll) {
    char n[20], s;
    int a;
    float g;
    printf("Enter Name, Age, Sex, GPA: ");
    scanf("%s %d %c %f", n, &a, &s, &g);
    ll->GoLast();
    ll->InsNode(n, a, s, g);
}

void EditData(LinkedList *ll) {
    char n[20], s;
    int a;
    float g;
    printf("Search name to edit: ");
    scanf("%s", n);
    if (ll->FindNode(n)) {
        printf("Enter New Name, Age, Sex, GPA: ");
        scanf("%s %d %c %f", n, &a, &s, &g);
        ll->EditNode(n, a, s, g);
        printf("Edit completed.\n");
    } else {
        printf("Not found.\n");
    }
}

void FindData(LinkedList *ll) {
    char n[20];
    printf("Search Name: ");
    scanf("%s", n);
    if (ll->FindNode(n)) {
        struct studentNode *node = ll->NowNode();
        printf("Found: %s %d %c %.2f\n", node->name, node->age, node->sex, node->gpa);
    } else {
        printf("Name not found.\n");
    }
}

void readfile(LinkedList *ll) {
    FILE *fp = fopen("student_data.bin", "rb");
    if (fp == NULL) return;
    struct studentNode temp;
    while (fread(&temp, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp)) {
        ll->GoLast();
        ll->InsNode(temp.name, temp.age, temp.sex, temp.gpa);
    }
    fclose(fp);
}

void writefile(LinkedList *ll) {
    FILE *fp = fopen("student_data.bin", "wb"); 
    if (fp == NULL) return;
    ll->GoFirst();
    while (ll->NowNode() != NULL) {
        struct studentNode *node = ll->NowNode();
        fwrite(node, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp);
        ll->GoNext(); 
    }
    fclose(fp);
    printf("\n[System] Data saved to student_data.bin\n");
}

int main() {
    LinkedList listA;
    int menu;
    readfile(&listA);
    
    do {
        printf("\nMenu: (1)Add (2)Edit (3)Delete (4)Find (5)Show (0)Exit : ");
        if (scanf("%d", &menu) != 1) break;
        
        switch(menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: 
                char n[20];
                printf("Enter name to delete: ");
                scanf("%s", n);
                if (listA.FindNode(n)) listA.DelNode();
                else printf("Not found.\n");
                break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
        }
    } while (menu != 0);

    writefile(&listA);
    return 0;
}