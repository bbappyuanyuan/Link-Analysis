//
// Created by Zifeng Yuan on 11/28/15.
//

#ifndef LINK_ANALYSIS_UNIONSET_H
#define LINK_ANALYSIS_UNIONSET_H


#include <vector>

using std::vector;

class UnionSet {

    vector<int> f;

public:
    UnionSet(int n);

    void _union(int x, int y);

    int get_f(int x);
};

int UnionSet::get_f(int x) {
    return f[x] = f[x] == x ? x : get_f(f[x]);
}

UnionSet::UnionSet(int n) {
    f.resize(n);
    for (int i = 0; i < n; ++i)
        f[i] = i;
}

void UnionSet::_union(int x, int y) {
    int fx = get_f(x);
    int fy = get_f(y);
    if (fx != fy) f[fx] = fy;
}


#endif //LINK_ANALYSIS_UNIONSET_H