//
// Created by Zifeng Yuan on 11/29/15.
//

//#define DEBUG

#include <iostream>
#include <cmath>
#include "basic_service.hpp"
#include "graph.hpp"

using namespace std;

void normalize(vector<double> &a);

double gap(const vector<double> &a, const vector<double> &b);

const vector<string> datasets = get_datasets();

int main() {
    for (string dataset : datasets) {
        cout << "runnning for dataset " << dataset << endl;
        CGraph *g = new CGraph(dataset);
#ifdef DEBUG
        cout << "V = " << g->n << endl;
        cout << "|E| = " << g->v.size() << endl;
#endif

        vector<double> authority(g->n, 1);
        vector<double> hub(g->n, 1);
        normalize(authority);
        normalize(hub);
        vector<double> next_authority(g->n);
        vector<double> next_hub(g->n);
        while (true) {
            for (int i = 0; i < g->n; ++i) {
                next_authority[i] = next_hub[i] = 0;
                for (int j = g->inv_link[i]; j != -1; j = g->inv_next[j])
                    next_authority[i] += hub[g->inv_v[j]];
                for (int j = g->link[i]; j != -1; j = g->next[j])
                    next_hub[i] += authority[g->v[j]];
            }
            normalize(next_authority);
            normalize(next_hub);
#ifdef DEBUG
            cout << "gap = " << gap(authority, next_authority) + gap(hub, next_hub) << endl;
#endif
            if (gap(authority, next_authority) + gap(hub, next_hub) < 1e-8) break;
            authority = next_authority;
            hub = next_hub;
        }

//        for (int i = 0; i < g->n; ++i)
//            cout << "Authority " << i << " = " << authority[i] << endl;

        file_export("HITS", dataset, g->n, g->type, authority);

        delete g;
    }

    return 0;
}

inline double sqr(double x) {
    return x * x;
}

void normalize(vector<double> &a) {
    double s = 0;
    for (auto it = a.begin(); it != a.end(); ++it)
        s += sqr(*it);
    s = sqrt(s);
    for (auto it = a.begin(); it != a.end(); ++it)
        *it /= s;
}

double gap(const vector<double> &a, const vector<double> &b) {
    double ret = 0;
    for (auto it1 = a.begin(), it2 = b.begin(); it1 != a.end() && it2 != b.end(); ++it1, ++it2)
        ret += sqr(*it1 - *it2);
    ret = sqrt(ret);
    return ret;
}
