//
// Created by Zifeng Yuan on 11/29/15.
//

#ifndef LINK_ANALYSIS_EXPORT_SERVICE_H
#define LINK_ANALYSIS_EXPORT_SERVICE_H

#include <boost/filesystem.hpp>
#include <dirent.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace boost::filesystem;
using std::string;
using std::vector;
using std::ofstream;
using std::endl;
using std::pair;
using std::make_pair;
using std::sort;
using std::reverse;

string get_nodes_file(string dataset);

string get_adj_list_file(string dataset);

vector<string> get_datasets();

void file_export(string reporter, string dataset, int n, vector<char> type, const vector<double> &point);

string get_nodes_file(string dataset) {
    return "dataset/" + dataset + "/graph/nodes";
}

string get_adj_list_file(string dataset) {
    return "dataset/" + dataset + "/graph/adj_list";
}

vector<string> get_datasets() {
    vector<string> ret;
//    DIR *dir = opendir("dataset");
//    dirent *node;
//    while ((node = readdir(dir)) != NULL)
//        if (node->d_name[0] == '_')
//            ret.push_back(string(node->d_name));
//    closedir(dir);
    path p("dataset");
    for (auto item = directory_iterator(p); item != directory_iterator(); ++item)
        if (is_directory(item->path())) {
            std::cout << item->path().filename().string() << endl;
            ret.push_back(item->path().filename().string());
        }
    return ret;
}

void file_export(string reporter, string dataset, int n, vector<char> type, const vector<double> &point) {
    ofstream file;
    file.open("dataset/" + dataset + "/" + reporter);
    file << n << endl;
    file.setf(std::ios::left);
    for (int i = 0; i < n; ++i)
        file << std::setw(8) << i << std::setw(5) << type[i] << std::setw(10) << point[i] << endl;
    file.close();

    vector<pair<double, int>> data(n);
    for (int i = 0; i < n; ++i)
        data[i] = make_pair(point[i], i);
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    file.open("dataset/" + dataset + "/" + reporter + "_descending");
    file << n << endl;
    file.setf(std::ios::left);
    for (int i = 0; i < n; ++i)
        file << std::setw(8) << data[i].second << std::setw(5) << type[data[i].second] << std::setw(10) <<
        data[i].first << endl;
    file.close();
}

#endif //LINK_ANALYSIS_EXPORT_SERVICE_H
