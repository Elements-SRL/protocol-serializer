#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "global_defines.h"
#include "yaml.h"

namespace YAML {
typedef struct Analysis {
    YAML::AnalysisType type;
} Analysis_t;

template<>
struct convert<Analysis>{
    static Node encode(const Analysis& rhs) {
        Node node;
        node["type"] = analysisStrings[rhs.type];
        return node;
    }

    static bool decode(const Node& node, Analysis& rhs) {
        if(node.size() != 1) {
            return false;
        }
        rhs.type = (AnalysisType)(std::find(analysisStrings.begin(), analysisStrings.end(), node["type"].as<std::string>())-analysisStrings.begin());
        return true;
    }
};
}

#endif // ANALYSIS_H
