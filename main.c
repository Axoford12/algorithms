#include "graph/dense_graph.h"
#include<stdio.h>
int main(){
    dense_graph sg;
    dense_graph_construct(&sg,10,0);
    dense_graph_add_edge(&sg,0,3);
    dense_graph_add_edge(&sg,2,4);
    dense_graph_add_edge(&sg,3,2);
    dense_graph_print_graph(&sg);
    printf("Component: %d",dense_graph_component(&sg));
    dense_graph_destruct(&sg);
}

