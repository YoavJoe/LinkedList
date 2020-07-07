/*
*******************
file: LinkList.h
*******************
*/
#ifndef _LINKLIST_H
#define _LINKLIST_H

#define TRUE 1
#define FALSE 0

typedef struct list list;
typedef struct node node;


struct node {
   int data;
   node* next;
};

struct list {
    node* start;
    node* end;
    int size;
};

/*This function create a empty list*/
list* create_list();

/*This function receive data and put it in the new node*/
node* make_new_node(int data);

/*This function add the data to the first node*/
list* add_from_start(list* head, int data);

/*This function add the data to the last node*/
list* append(list* head, int data);

/*This function get the node by it's index*/
node* get_by_index(list* head, int index);

/*This function print in python style - the list*/
void print(list* head);

/*This function free the list*/
void free_list(list* head);

/*This function chack if list contains the data*/
int is_contains(list* head, int data);


/* main:
/ create list with random numbers, and calcuate for each number
/ if it's prime or not 

/ >>>> [1, 7, 9, 25, 100, 17]
/ >>>> [7,17]*/

#endif