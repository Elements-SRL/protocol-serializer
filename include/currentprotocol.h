#ifndef CURRENTPROTOCOL_H
#define CURRENTPROTOCOL_H

#include <algorithm>

#include "yaml.h"
#include "phase.h"
#include "control.h"
#include "cursor.h"
#include "analysis.h"
#include "global_defines.h"

namespace YAML {
typedef struct CurrentProtocol {
    std::string name;
    int shortcutindex;
    YAML::OperationMode operationmode;
    double ihold;
    bool iholdref;
    int sweeps;
    std::string currentrange;
    std::string voltagerange;
    std::string samplingrate;

    std::vector<Phase_t> phases;
    std::vector<Control_t> controls;
    std::vector<Cursor_t> cursors;
    std::vector<Analysis_t> analysis;
} CurrentProtocol_t;

template<>
struct convert<CurrentProtocol>{
    static Node encode(const CurrentProtocol& rhs) {
        Node node;

        node["name"] = rhs.name;
        node["shortcutindex"] = rhs.shortcutindex;
        node["operationmode"] = operationModeStrings[rhs.operationmode];
        node["ihold"] = rhs.ihold;
        node["iholdref"] = rhs.iholdref;
        node["sweeps"] = rhs.sweeps;
        node["currentrange"] = rhs.currentrange;
        node["voltagerange"] = rhs.voltagerange;
        node["samplingrate"] = rhs.samplingrate;
        node["phases"] = rhs.phases;
        node["controls"] = rhs.controls;
        node["cursors"] = rhs.cursors;
        node["analysis"] = rhs.analysis;

        Node key;
        key["currentprotocol"] = node;
        return key;
    }

    static bool decode(const Node& n, CurrentProtocol& rhs) {
        if(!n.IsMap() || !n["currentprotocol"]) {
            return false;
        }
        Node node = n["currentprotocol"];

        rhs.name = node["name"].as<std::string>();
        rhs.shortcutindex = node["shortcutindex"].as<int>();
        rhs.operationmode = (OperationMode)(std::find(operationModeStrings.begin(), operationModeStrings.end(), node["operationmode"].as<std::string>())-operationModeStrings.begin());
        rhs.ihold = node["ihold"].as<double>();
        rhs.iholdref = node["iholdref"].as<bool>();
        rhs.sweeps = node["sweeps"].as<int>();
        rhs.currentrange = node["currentrange"].as<std::string>();
        rhs.voltagerange = node["voltagerange"].as<std::string>();
        rhs.samplingrate = node["samplingrate"].as<std::string>();
        rhs.phases = node["phases"].as<std::vector<Phase_t>>();
        rhs.controls = node["controls"].as<std::vector<Control_t>>();
        rhs.cursors = node["cursors"].as<std::vector<Cursor_t>>();
        rhs.analysis = node["analysis"].as<std::vector<Analysis_t>>();
        return true;
    }
};
}
#endif // CURRENTPROTOCOL_H
