//
// Created by axoford12 on 8/20/17.
//

#include "dense_graph.h"
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

void dense_graph_print_graph(dense_graph *dg) {
    int i;
    for (i = 0; i < dg->vertex_num; i++) {
        int j;
        for (j = 0; j < dg->vertex_num; j++) {
            printf("%d ", dg->graph_data[i][j]);
        }
        printf("\n");
    }
}

void dense_graph_add_edge(dense_graph *dg, unsigned int x, unsigned int y) {
    if (x > dg->vertex_num - 1 || y > dg->vertex_num - 1) {
        return;
    }
    dg->graph_data[x][y] = 1;
    if (!dg->directed) {
        dg->graph_data[y][x] = 1;
    }
    dg->edge_num++;
}

void dense_graph_construct(dense_graph *dg, int vertex_num, int directed) {
    int i;
    dg->from = NULL;
    dg->directed = directed;
    dg->visited = malloc(sizeof(int) * dg->vertex_num); // 分配内存
    for (int k = 0; k < vertex_num; ++k) {
        dg->visited[k] = 0;
    }
    dg->edge_num = 0;
    dg->vertex_num = vertex_num;
    dg->graph_data = malloc((size_t) vertex_num * sizeof(int *));
    for (i = 0; i < vertex_num; i++) {
        int j;
        dg->graph_data[i] = malloc((size_t) vertex_num * sizeof(int));
        for (j = 0; j < i; j++) {
            dg->graph_data[i][j] = 0;
        }
    }
}

void dense_graph_destruct(dense_graph *dg) {
    int i;
    for (i = 0; i < dg->vertex_num; i++) {
        free(dg->graph_data[i]);
    }
    free(dg->graph_data);
    free(dg->visited); // 释放内存
}


void dense_graph_dfs(dense_graph *dg, unsigned int vertex) {
    if (vertex > dg->vertex_num) return;
    dg->visited[vertex] = 1;
    for (struct node *n = list_iterator_start(dense_graph_get_adj(dg, vertex)); !list_iterator_end(
            n); n = list_iterator_next(n)) {

        if (!dg->visited[n->value]) {
            if (dg->from != NULL) {
                dg->from[n->value] = vertex;
            }
            dense_graph_dfs(dg, (unsigned) n->value);
        }
    }

}

list *dense_graph_get_adj(dense_graph *dg, unsigned int vertex) {
    list *lst = NULL;
    list_construct(lst, 0);
    for (int i = 0; i < dg->vertex_num; i++) {
        if (dg->graph_data[vertex][i]) {
            lst = list_append(lst, i);
        }
    }
    return lst;
}

int dense_graph_component(dense_graph *dg) {
    for (int i = 0; i < dg->vertex_num; ++i) {
        dg->visited[i] = 0;
    }
    int count = 0;
    for (int j = 0; j < dg->vertex_num; ++j) {
        if (!dg->visited[j]) {
            dense_graph_dfs(dg, j);
            count++;
        }

    }
    return count;
}

list* __build_path(dense_graph *dg, unsigned int from, int dest,list* lst) {
    if(dg->from[dest] != from){
        lst = list_insert(lst,dest,0);
        __build_path(dg,from,dg->from[dest],lst);
    } else {
        lst = list_insert(lst,dest,0);
        lst = list_insert(lst,from,0);
    }
    return lst;
}

list* dense_graph_find_path(dense_graph *dg, unsigned int x, unsigned int y,list* list) {
    dg->from = malloc(dg->vertex_num * sizeof(int));
    for (int j = 0; j < dg->vertex_num; ++j) {
        dg->from[j] = -2;
    }
    for (int i = 0; i < dg->vertex_num; ++i) {
        dg->visited[i] = 0;
    }
    dense_graph_dfs(dg, x);
    if (!dg->visited[y]) {
        printf("Cannot find path from %d to %d", x, y);
        return NULL;
    }
    free(dg->from);
    return __build_path(dg,x,y,list);
}
