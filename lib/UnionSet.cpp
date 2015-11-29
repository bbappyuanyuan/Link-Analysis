//
// Created by Zifeng Yuan on 11/28/15.
//

#include "UnionSet.h"

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