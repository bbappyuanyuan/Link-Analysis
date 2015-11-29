//
// Created by Zifeng Yuan on 11/29/15.
//

#define DEBUG

#include <iostream>
#include <cmath>
#include "Graph.h"

using std::cout;
using std::endl;

double gap(const vector<double> &a, const vector<double> &b);

int main() {
    Graph *g = new Graph("test");
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

    vector<double> authority(g->n, 0);
    for (int i = 0; i < g->n; ++i)
        if (g->in_degree[i])
            authority[i] = 1.0 / authority_size;
    vector<double> next_authority(g->n, 0);
    while (true) {
        for (int u = 0, v, w; u < g->n; ++u)
            if (g->in_degree[u]) {
                next_authority[u] = 0;
                for (int j = g->inv_link[u]; j != -1; j = g->inv_next[j]) {
                    v = g->inv_v[j];
                    for (int k = g->link[v]; k != -1; k = g->next[k]) {
                        w = g->v[k];
                        next_authority[u] += authority[w] / (g->out_degree[v] * g->in_degree[w]);
                    }
                }
            }
        if (gap(authority, next_authority) < 1e-8) break;
        authority = next_authority;
    }

    for (int i = 0; i < g->n; ++i)
        cout << "Authority " << i << " = " << authority[i] << endl;

    return 0;
}

inline double sqr(double x) {
    return x * x;
}

double gap(const vector<double> &a, const vector<double> &b) {
    double ret = 0;
    for (auto it1 = a.begin(), it2 = b.begin(); it1 != a.end() && it2 != b.end(); ++it1, ++it2)
        ret += sqr(*it1 - *it2);
    ret = sqrt(ret);
    return ret;
}