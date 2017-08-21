#include "graph/dense_graph.h"
#include <stdlib.h>

int main(){
    dense_graph dg;
    dense_graph_construct(&dg,10,0);
    dense_graph_add_edge(&dg,0,2);
    dense_graph_add_edge(&dg,0,3);
    dense_graph_add_edge(&dg,2,5);
    dense_graph_add_edge(&dg,2,4);
    dense_graph_print_graph(&dg);
    list* lst;
    lst = dense_graph_get_adj(&dg,2);
    dense_graph_dfs(&dg,0);
    free(lst);
    dense_graph_destruct(&dg);
}

