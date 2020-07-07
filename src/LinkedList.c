/*
*******************
file: LinkList.c
*******************
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"

node* add_to_list(node* curr, node* new_node);

list* create_list() {
    list* lst = (list*)malloc(sizeof(list));
    lst->start = NULL;
    lst->end = NULL;
    lst->size = 0;
    return lst;
}

node* make_new_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* add_to_list(node* start, node* new_node) {
   if(start == NULL)
       return new_node;
    start->next = new_node;
    return start;
}

list* add_from_start(list* head, int data) {
    node* to_add = make_new_node(data);

    head->start = add_to_list(to_add, head->start); 
    if(head->end == NULL)
        head->end = head->start;
    head->size++;

    return head;
}

list* append(list* head, int data) {
    node* to_add = make_new_node(data);

    if(head->start == NULL) {
        head->start = add_to_list(head->start, to_add);
        head->end = head->start;
    }
    else {
        head->end = add_to_list(head->end, to_add);
        head->end = head->end->next;
    }
    head->size++;
    return head;
}

node* get_by_index(list* head, int index) {
    int i;
    node* curr = head->start;
    if(index > head->size) {
        printf("index out of bound -> %d\n", head->size);
        return NULL;
    }
    for(i = 0; i < index; i++)
        curr = curr->next;
    return curr;
}

int is_contains(list* head, int data) {
    int i;
    node* curr = head->start;
    for(i = 0; i < head->size; i++) {
        if(curr->data == data)
            return TRUE;
    }
    printf("%d is not contains in list!\n", data);
    return FALSE;
}

void print(list* head) {
    node* temp = head->start;
    int i;
    printf("[");
    for(i = 0; i < head->size; i++) {
        printf("%d", temp->data);
        if(i < head->size - 1)
            printf(", ");
        temp = temp->next;
    }
    printf("]\n");
}

void free_list(list* head) {
    node* temp = NULL;

    while(head->start != NULL) {
        temp = head->start;
        head->start = head->start->next;
        free(temp);
    }
    free(head);
}




