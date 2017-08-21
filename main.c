#include "graph/dense_graph.h"
#include<stdio.h>

int main(){
    dense_graph sg;
    dense_graph_construct(&sg,10,0);
    dense_graph_add_edge(&sg,0,3);
    dense_graph_add_edge(&sg,2,4);
    dense_graph_add_edge(&sg,3,2);

    list* lst = NULL;
    lst =  dense_graph_find_path(&sg,0,4,lst);

    for (struct node* n = list_iterator_start(lst);!list_iterator_end(n);n=list_iterator_next(n)) {
        printf("%d => ",n->value);
    }
    list_destruct(lst);

    //printf("Component: %d",dense_graph_component(&sg));
    dense_graph_destruct(&sg);

}

