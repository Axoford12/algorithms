#include "graph/sparse_graph.h"

int main(){
    sparse_graph sg;
    sparse_graph_construct(&sg,10,0);
    sparse_graph_add_edge(&sg,0,3);
    sparse_graph_add_edge(&sg,2,4);
    sparse_graph_add_edge(&sg,3,2);
    sparse_graph_print_graph(&sg);
    sparse_graph_dfs(&sg,0);

    sparse_graph_destruct(&sg);
}

