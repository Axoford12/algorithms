//
// Created by axoford12 on 8/20/17.
//

#ifndef STUDY_SPARSE_GRAPH_H
#define STUDY_SPARSE_GRAPH_H

#include <stddef.h>
#include "../list/list.h"

typedef struct {
    list **graph;
    int directed;
    int edge_num;
    int vertex_num;
}sparse_graph;

void sparse_graph_construct(sparse_graph *sg, unsigned int num, int directed);

void sparse_graph_print_graph(sparse_graph *sg);

void sparse_graph_add_edge(sparse_graph *sg, unsigned int x, unsigned int y);

void sparse_graph_destruct(sparse_graph *sg);


#endif //STUDY_SPARSE_GRAPH_H
