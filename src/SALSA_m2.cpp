//
// Created by Zifeng Yuan on 11/28/15.
//

//#define DEBUG

#include <iostream>
#include "basic_service.hpp"
#include "Graph.hpp"
#include "UnionSet.hpp"

using namespace std;

const vector<string> datasets = get_datasets();

int main() {
    for (string dataset : datasets) {
        cout << "runnning for dataset " << dataset << endl;
        Graph *g = new Graph(dataset);
#ifdef DEBUG
        cout << "V = " << g->n << endl;
        cout << "|E| = " << g->v.size() << endl;
#endif

        int hub_size = 0, authority_size = 0;
        for (int i = 0; i < g->n; ++i) {
            if (g->out_degree[i])
                ++hub_size;
            if (g->in_degree[i])
                ++authority_size;
        }
#ifdef DEBUG
        cout << "|HUB| = " << hub_size << endl;
        cout << "|AUTHORITY| = " << authority_size << endl;
#endif
        UnionSet *s = new UnionSet(g->n << 1);
        for (int i = 0; i < g->n; ++i)
            for (int j = g->link[i]; j != -1; j = g->next[j]) {
#ifdef DEBUG
                cout << "union " << i << " - auth(" << g->v[j] << ")" << endl;
#endif
                s->_union(i, g->n + g->v[j]);
            }

        vector<int> authority_block_size(g->n << 1, 0);
        vector<int> authority_block_in_degree(g->n << 1, 0);
        for (int i = 0; i < g->n; ++i)
            if (g->in_degree[i])
                ++authority_block_size[s->get_f(g->n + i)];
        for (int i = 0; i < g->n; ++i)
            for (int j = g->link[i]; j != -1; j = g->next[j])
                ++authority_block_in_degree[s->get_f(g->n + g->v[j])];
        vector<double> authority(g->n, 0);
        for (int i = 0; i < g->n; ++i)
            if (g->in_degree[i]) { // authority
                authority[i] = authority_block_size[s->get_f(g->n + i)] / (double) authority_size * g->in_degree[i] /
                               (double) authority_block_in_degree[s->get_f(g->n + i)];
//                cout << "Authority " << i << " = " << authority[i] << endl;
#ifdef DEBUG
                cout << "\tauthority_block_size: " << authority_block_size[s->get_f(g->n + i)] << endl;
                cout << "\tauthority_size: " << authority_size << endl;
                cout << "\tauthority_in_degree: " << g->in_degree[i] << endl;
                cout << "\tauthority_block_in_degree: " << authority_block_in_degree[s->get_f(g->n + i)] << endl;
#endif
            } else {
//                cout << "Authority " << i << " = " << 0 << endl;
            }

        file_export("SALSA_m2", dataset, g->n, g->type, authority);
        delete g;
    }

    return 0;
}