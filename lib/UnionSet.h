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


#endif //LINK_ANALYSIS_UNIONSET_H
