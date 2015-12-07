//
// Created by Zifeng Yuan on 11/29/15.
//

#ifndef LINK_ANALYSIS_BASIC_SERVICE_HPP
#define LINK_ANALYSIS_BASIC_SERVICE_HPP

#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

string get_nodes_file(string dataset);

string get_adj_list_file(string dataset);

vector<string> get_datasets();

void file_export(string reporter, string dataset, int n, const vector<char> &type, const vector<double> &point);

string get_nodes_file(string dataset) {
    return "dataset/" + dataset + "/graph/nodes";
}

string get_adj_list_file(string dataset) {
    return "dataset/" + dataset + "/graph/adj_list";
}

vector<string> get_datasets() {
    using namespace boost::filesystem;
    vector<string> ret;
    path p("dataset");
    for (auto item = directory_iterator(p); item != directory_iterator(); ++item)
        if (is_directory(item->path()))
            ret.push_back(item->path().filename().string());
    return ret;
}

void file_export(string reporter, string dataset, int n, const vector<char> &type, const vector<double> &point) {
    ofstream file;
    file.open("dataset/" + dataset + "/" + reporter);
    file << n << endl;
    file.setf(ios::left);
    for (int i = 0; i < n; ++i)
        file << setw(8) << i << setw(5) << type[i] << setw(10) << point[i] << endl;
    file.close();

    vector<pair<double, int>> data(n);
    for (int i = 0; i < n; ++i)
        data[i] = make_pair(point[i], i);
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    file.open("dataset/" + dataset + "/" + reporter + "_descending");
    file << n << endl;
    file.setf(ios::left);
    for (int i = 0; i < n; ++i)
        file << setw(8) << data[i].second << setw(5) << type[data[i].second] << setw(10) <<
        data[i].first << endl;
    file.close();
}

#endif //LINK_ANALYSIS_BASIC_SERVICE_HPP
