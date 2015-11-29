//
// Created by Zifeng Yuan on 11/28/15.
//

#include "Graph.h"

#include <fstream>

using std::ifstream;

void Graph::add_edge(int x, int y) {
    ++in_degree[y];
    ++out_degree[x];
    v.push_back(y);
    next.push_back(link[x]);
    link[x] = v.size() - 1;
    inv_v.push_back(x);
    inv_next.push_back(inv_link[y]);
    inv_link[y] = inv_v.size() - 1;
}

Graph::Graph(string dataset) {
    ifstream file;
    file.open("dataset/" + dataset + "/nodes");
    file >> n;
    in_degree.resize(n, 0);
    out_degree.resize(n, 0);
    link.resize(n, -1);
    v.clear();
    next.clear();
    inv_link.resize(n, -1);
    inv_v.clear();
    inv_next.clear();
    file.close();
    file.open("dataset/" + dataset + "/adj_list");
    int u, v;
    char gap;
    while (file >> u) {
        file >> gap;
        while (file >> v) {
            if (v == -1) break;
            add_edge(u, v);
        }
    }
    file.close();
}
