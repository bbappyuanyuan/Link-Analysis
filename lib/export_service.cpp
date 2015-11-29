//
// Created by Zifeng Yuan on 11/29/15.
//

#include "export_service.h"

void file_export(string reporter, string dataset, Graph *g, const vector<double> &p) {
    ofstream file;
    file.open("dataset/" + dataset + "/" + reporter + "_out");
    file << g->n << endl;
    for (int i = 0; i < g->n; ++i)
        file << i << "\t\t" << g->type[i] << "\t\t" << p[i] << endl;
    file.close();
}