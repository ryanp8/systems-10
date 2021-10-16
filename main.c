#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    int id;
    struct node *next;
};

struct node * make_person(char n[20], int a) {
    struct node *p = malloc(sizeof(struct node));
    strncpy(p->name, n, sizeof(p->name));
    p->id = a;
    p->next = NULL;
    return p;
}

void print_person(struct node *p) {
    printf("name: %s\n", p->name);
    printf("id: %d\n", p->id);
}

void print_list(struct node *p) {
    while(p) {
        print_person(p);
        p = p->next;
    }
}

struct node * insert_front(struct node *p, char n[20], int a) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->id = a;
    strncpy(new_node->name, n, sizeof(new_node->name));
    new_node->next = p;
    
    return new_node;
}

struct node * free_list(struct node *p) {
    if (p->next) {
        free_list(p->next);
    }
    p->next = NULL;
    free(p);    
    return p;
}

int main() {

    struct node *head = make_person("Chandler", 0);

    head = insert_front(head, "Joey", 1);
    head = insert_front(head, "Monica", 2);
    head = insert_front(head, "Ross", 3);
    head = insert_front(head, "Rachel", 4);
    head = insert_front(head, "Phoebe", 5);

    print_list(head);


    free_list(head);
    return 0;
}