//
// Created by axoford12 on 8/20/17.
//

#ifndef STUDY_LIST_H
#define STUDY_LIST_H
struct node{
    int value;
    struct node* next_addr;
}node;

typedef struct{
    unsigned int len;
    struct node* first;
}list;

void list_construct(list *,unsigned int len);
void list_destruct(list* lst);
void list_delete(list *lst, unsigned int pos);
void list_print(list* lst);
list* list_append(list* lst,int value);
void list_set(list* lst,int num,unsigned int pos);
list* list_insert(list* lst,int value,unsigned int pos);
struct node* list_iterator_start(list* lst);
int list_iterator_end(struct node* n);
struct node* list_iterator_next(struct node *n);
#endif //STUDY_LIST_H
