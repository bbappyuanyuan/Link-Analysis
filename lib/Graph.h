//
// Created by Zifeng Yuan on 11/28/15.
//

#ifndef LINK_ANALYSIS_GRAPH_H
#define LINK_ANALYSIS_GRAPH_H


#include <vector>
#include <string>

using std::vector;
using std::string;

class Graph {

    void add_edge(int x, int y);

public:
    int n;
    vector<int> in_degree, out_degree;
    vector<int> link;
    vector<int> v, next;
    vector<int> inv_link;
    vector<int> inv_v, inv_next;

    Graph(string dataset);
};


#endif //LINK_ANALYSIS_GRAPH_H
