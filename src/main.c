/*
*******************
file: main.c
*******************
*/

#include "../include/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    int i;
    for(i = 2; i <= n / 2; i++)
        if(n % i == 0)
            return FALSE;
    return TRUE;
}

int main() {
    list* lst = create_list();
    node* curr = NULL;
    int i;
    for(i = 0; i < 20; i++)
        lst = append(lst, rand() % 100);
    print(lst);

    curr = lst->start;

    for(i = 0; i < lst->size; i++) {
        if(is_prime(curr->data))
            printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    free_list(lst);
    return 0;
}