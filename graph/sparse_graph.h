//
// Created by axoford12 on 8/20/17.
//

#ifndef STUDY_SPARSE_GRAPH_H
#define STUDY_SPARSE_GRAPH_H

#include <stddef.h>
#include "../list/list.h"

typedef struct {
    list **graph;
    int* visited;
    int directed;
    int edge_num;
    int vertex_num;
}sparse_graph;

/**
 *
 * @param sg
 * 构造的sparse_graph
 * @param num
 * 顶点数目
 * @param directed
 * 是否为有向图
 */
void sparse_graph_construct(sparse_graph *sg, unsigned int num, int directed);

/**
 * 打印一个稀疏图（邻接表）
 * @param sg
 *
 */
void sparse_graph_print_graph(sparse_graph *sg);

/**
 * 链接x->y
 * @param sg
 * sparse_graph指针
 * @param x
 *
 * @param y
 */
void sparse_graph_add_edge(sparse_graph *sg, unsigned int x, unsigned int y);

/**
 * 析构
 * @param sg
 */
void sparse_graph_destruct(sparse_graph *sg);

list* sparse_graph_get_adj(sparse_graph *sg, unsigned int vertex);

/**
 * 对图进行深度优先遍历
 * @param sg
 * @param vertex
 */
void sparse_graph_dfs(sparse_graph *sg,unsigned int vertex);
#endif //STUDY_SPARSE_GRAPH_H
