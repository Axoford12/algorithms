#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include <stdio.h>
#include <assert.h>

//
// Created by axoford12 on 8/20/17.
//
struct node *__list_pos(list *lst, unsigned int pos) {
    if (pos > lst->len - 1) exit(1);
    struct node *current;
    current = lst->first;
    for (int i = 0; i < pos; ++i) {
        current = current->next_addr;
    }
    return current;
}

void __list_print(struct node *node) {
    if (node->next_addr == NULL) {
        printf("%d", node->value);
        return;
    }
    printf("%d ", node->value);
    __list_print(node->next_addr);
}

void list_construct(list* lst,unsigned int len) {
    if (len == 0) {
        return;
    }
    struct node *first = malloc(sizeof(node));
    first->value = 0;


    lst->first = first;
    lst->len = len;
    struct node *next_p = NULL;
    for (int i = len - 1; i > 0; i--) {
        struct node *next = malloc(sizeof(node));
        next->value = 0;
        next->next_addr = next_p;
        next_p = next;
    }
    first->next_addr = next_p;
}

void list_destruct(list *lst) {
    if (lst == NULL) {
        return;
    }
    for (int i = 0; i < lst->len; i++) {
        lst->first = lst->first->next_addr;
        free(lst->first);
    }
}

void list_delete(list *lst, unsigned int pos) {

    struct node *before = __list_pos(lst, pos - 1);
    struct node *after = __list_pos(lst, pos + 1);
    free(__list_pos(lst, pos));
    before->next_addr = after;
    lst->len--;

}


void list_print(list *lst) {
    if (lst == NULL) {
        return;
    }
    __list_print(lst->first);
}


void list_set(list *lst, int num, unsigned int pos) {
    struct node *current;
    current = __list_pos(lst, pos);
    current->value = num;
}

list* list_insert(list *lst, int value, unsigned int pos) {
    if (lst == NULL && pos == 0) {
        lst = malloc(sizeof(list));
        lst->first = malloc(sizeof(node));
        lst->first->value = value;
        lst->len = 1;
        return lst;
    }
    assert(lst != NULL);
    struct node *new_node = malloc(sizeof(node));
    new_node->value = value;
    struct node *before;
    struct node *after = __list_pos(lst, pos);
    if (pos == 0) {
        lst->first = new_node;
    } else {
        before = __list_pos(lst, pos - 1);
        before->next_addr = new_node;
    }


    new_node->next_addr = after;
    lst->len++;

}

list* list_append(list* lst, int value) {
    struct node* new = malloc(sizeof(node));
    new->value = value;
    if(lst == NULL){
        lst  = list_insert(lst,value,0);
        return lst;
    }
    struct node* last = __list_pos(lst,lst->len - 1);
    last->next_addr = new;
    lst->len++;
}

struct node *list_iterator_start(list *lst) {
    return lst->first;
}

int list_iterator_end(struct node *n) {
    return n == NULL;
}

struct node *list_iterator_next(struct node *n) {
    return n->next_addr;
}
