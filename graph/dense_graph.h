//
// Created by axoford12 on 8/20/17.
//

#ifndef STUDY_DENSE_GRAPH_H
#define STUDY_DENSE_GRAPH_H

#include "../list/list.h"

typedef struct {
    int* visited;
    int directed;
    int edge_num;
    int vertex_num;
    int **graph_data;

} dense_graph;

/**
 *
 * @param dg
 * 要被打印为矩阵的稠密图
 */
void dense_graph_print_graph(dense_graph *dg);


/**
 *
 * @param dg
 *为图增加一条边。
 * @param x
 * @param y
 * x和y指示了有向图中从x->y的边或者无向图的x-y边
 */
void dense_graph_add_edge(dense_graph *dg, unsigned int x, unsigned int y);


/**
 *
 * @param dg
 * 空指针
 * @param vertex_num
 * 顶点数目
 * @param directed
 * 有向图/无向图.
 */
void dense_graph_construct(dense_graph *dg, int vertex_num, int directed);

/**
 *
 * @param dg
 * 析构.释放内存空间.
 */
void dense_graph_destruct(dense_graph *dg);

/**
 *
 * @param dg
 * dense_graph 指针，表示要深度优先搜索的图
 * @param vertex
 * vertex代表顶点.
 */
void dense_graph_dfs(dense_graph *dg, unsigned int vertex);


/**
 *
 * @param dg
 * @param vertex
 * @return 返回临边数组的首指针
 */
list* dense_graph_get_adj(dense_graph *dg, unsigned int vertex);

#endif //STUDY_DENSE_GRAPH_H
