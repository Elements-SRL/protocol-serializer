#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <variant>

#include "global_defines.h"
#include "yaml.h"

using namespace std;

struct Analysis {
    YAML::AnalysisType type;
    vector <int> timepoints;
};

namespace YAML {
template<>
struct convert<Analysis>{
    static Node encode(const Analysis& rhs) {
        Node node;
        node["type"] = analysisStrings[rhs.type];
        node["timepoints"] = rhs.timepoints;
        return node;
    }

    static bool decode(const Node& node, Analysis& rhs) {
        if(node.size() != 2) {
            return false;
        }
        rhs.type = (AnalysisType)(find(analysisStrings.begin(), analysisStrings.end(), node["type"].as<string>())-analysisStrings.begin());
        rhs.timepoints = node["timepoints"].as<vector<int>>();
        return true;
    }
};
}

#endif // ANALYSIS_H
