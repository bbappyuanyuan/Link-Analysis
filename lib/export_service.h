//
// Created by Zifeng Yuan on 11/29/15.
//

#ifndef LINK_ANALYSIS_EXPORT_SERVICE_H
#define LINK_ANALYSIS_EXPORT_SERVICE_H

#include <string>
#include <fstream>
#include <iostream>

#include "Graph.h"

using std::string;
using std::ofstream;
using std::endl;

void file_export(string reporter, string dataset, Graph *g, const vector<double> &p);

#endif //LINK_ANALYSIS_EXPORT_SERVICE_H
