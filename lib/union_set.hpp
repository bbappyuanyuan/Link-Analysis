//
// Created by Zifeng Yuan on 11/28/15.
//

#ifndef LINK_ANALYSIS_UNION_SET_HPP
#define LINK_ANALYSIS_UNION_SET_HPP


#include <vector>

using namespace std;

class CUnionSet {

    vector<int> f;

public:
    CUnionSet(int n);

    void _union(int x, int y);

    int get_f(int x);
};

int CUnionSet::get_f(int x) {
    return f[x] = f[x] == x ? x : get_f(f[x]);
}

CUnionSet::CUnionSet(int n) {
    f.resize(n);
    for (int i = 0; i < n; ++i)
        f[i] = i;
}

void CUnionSet::_union(int x, int y) {
    int fx = get_f(x);
    int fy = get_f(y);
    if (fx != fy) f[fx] = fy;
}


#endif //LINK_ANALYSIS_UNION_SET_HPP