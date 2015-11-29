//
// Created by Zifeng Yuan on 11/29/15.
//

#include "export_service.h"

void file_export(string reporter, string dataset, Graph *g, const vector<double> &p) {
    ofstream file;
    file.open("dataset/" + dataset + "/" + reporter + "_output");
    file << g->n << endl;
    file.setf(std::ios::left);
    for (int i = 0; i < g->n; ++i)
        file << std::setw(8) << i << std::setw(5) << g->type[i] << std::setw(10) << p[i] << endl;
    file.close();

    vector<pair<double, int>> data(g->n);
    for (int i = 0; i < g->n; ++i)
        data[i] = make_pair(p[i], i);
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    file.open("dataset/" + dataset + "/" + reporter + "_descending_output");
    file << g->n << endl;
    file.setf(std::ios::left);
    for (int i = 0; i < g->n; ++i)
        file << std::setw(8) << data[i].second << std::setw(5) << g->type[data[i].second] << std::setw(10) <<
        data[i].first << endl;
    file.close();
}