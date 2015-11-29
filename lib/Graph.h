//
// Created by Zifeng Yuan on 11/28/15.
//

#ifndef LINK_ANALYSIS_GRAPH_H
#define LINK_ANALYSIS_GRAPH_H


#include <fstream>
#include <vector>
#include <string>

using std::ifstream;
using std::getline;
using std::vector;
using std::string;

class Graph {

    bool my_getline(ifstream &file, string &line);

    void add_edge(int x, int y);

public:
    int n;
    vector<char> type;
    vector<int> in_degree, out_degree;
    vector<int> link;
    vector<int> v, next;
    vector<int> inv_link;
    vector<int> inv_v, inv_next;

    Graph(string dataset);
};


#endif //LINK_ANALYSIS_GRAPH_H
