//
// Created by axoford12 on 8/20/17.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "sparse_graph.h"

void sparse_graph_construct(sparse_graph* sg,unsigned int num,int directed){
    sg->visited = malloc(sizeof(int) * num);
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
    free(sg->visited);
}

void sparse_graph_add_edge(sparse_graph *sg, unsigned int x, unsigned int y) {
    if(x > sg->vertex_num || y > sg->vertex_num) return;
    sg->graph[x] = list_append(sg->graph[x],y);
    if(!sg->directed){
        sg->graph[y] = list_append(sg->graph[y],x);
    }
    sg->edge_num++;
}

list *sparse_graph_get_adj(sparse_graph *sg, unsigned int vertex) {
    assert(vertex < sg->vertex_num);
    return sg->graph[vertex];
}

void sparse_graph_dfs(sparse_graph *sg, unsigned int vertex) {
    printf("Visit %d\n",vertex);
    sg->visited[vertex] = 1;
    for (struct node* n = list_iterator_start(sparse_graph_get_adj(sg,vertex));!list_iterator_end(n);n=list_iterator_next(n)) {
        if(!sg->visited[n->value]){
            sparse_graph_dfs(sg,(unsigned)n->value);
        }
    }
}

int sparse_graph_component(sparse_graph *sg) {
    for (int j = 0; j < sg->vertex_num; ++j) {
        sg->visited[j] = 0;
    }
    int count = 0;
    for (int i = 0; i < sg->vertex_num; ++i) {
        printf("Count: %d\n",count);
        if(!sg->visited[i]){
            sparse_graph_dfs(sg,i);
            count++;
        }
    }
    return count;

}

