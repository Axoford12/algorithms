//
// Created by axoford12 on 8/20/17.
//
#include <stdlib.h>
#include <stdio.h>
#include "sparse_graph.h"

void sparse_graph_construct(sparse_graph* sg,unsigned int num,int directed){
    sg->edge_num = 0;
    sg->directed = directed;
    sg->vertex_num = num;
    sg->graph = malloc(sizeof(sparse_graph*) * num);
    for (int i = 0; i < num; ++i) {
        list_construct(sg->graph[i],0);
    }
}

void sparse_graph_print_graph(sparse_graph *sg) {
    for (int i = 0; i < sg->vertex_num; ++i) {
        printf("%d: ",i);
        list_print(sg->graph[i]);
        printf("\n");
    }
}

void sparse_graph_destruct(sparse_graph *sg) {
    for (int i = 0; i < sg->vertex_num; ++i) {
        list_destruct(sg->graph[i]);
    }
    free(sg->graph);
}

void sparse_graph_add_edge(sparse_graph *sg, unsigned int x, unsigned int y) {
    if(x > sg->vertex_num || y > sg->vertex_num) return;
    sg->graph[x] = list_append(sg->graph[x],y);
    if(!sg->directed){
        sg->graph[x] = list_append(sg->graph[y],x);
    }
    sg->edge_num++;
}
