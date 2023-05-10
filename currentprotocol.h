#ifndef CURRENTPROTOCOL_H
#define CURRENTPROTOCOL_H

#include <variant>
#include <algorithm>

#include "yaml.h"
#include "phase.h"
#include "control.h"
#include "cursor.h"
#include "analysis.h"
#include "global_defines.h"

using namespace std;

struct CurrentProtocol {
    string name;
    int shortcutindex;
    YAML::OperationMode operationmode;
    double vhold;
    bool vholdref;
    int sweeps;
    string currentrange;
    string voltagerange;
    string samplingrate;

    vector<Control> controls;
    vector<Phase> phases;
    vector<Cursor> cursors;
    vector<Analysis> analysis;
};

namespace YAML {
template<>
struct convert<CurrentProtocol>{
    static Node encode(const CurrentProtocol& rhs) {
        Node node;

        node["name"] = rhs.name;
        node["shortcutindex"] = rhs.shortcutindex;
        node["operationmode"] = operationModeStrings[rhs.operationmode];
        node["vhold"] = rhs.vhold;
        node["vholdref"] = rhs.vholdref;
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

        rhs.name = node["name"].as<string>();
        rhs.shortcutindex = node["shortcutindex"].as<int>();
        rhs.operationmode = (OperationMode)(find(operationModeStrings.begin(), operationModeStrings.end(), node["operationmode"].as<string>())-operationModeStrings.begin());
        rhs.vhold = node["vhold"].as<double>();
        rhs.vholdref = node["vholdref"].as<bool>();
        rhs.sweeps = node["sweeps"].as<int>();
        rhs.currentrange = node["currentrange"].as<string>();
        rhs.voltagerange = node["voltagerange"].as<string>();
        rhs.samplingrate = node["samplingrate"].as<string>();
        rhs.phases = node["phases"].as<vector<Phase>>();
        rhs.controls = node["controls"].as<vector<Control>>();
        rhs.cursors = node["cursors"].as<vector<Cursor>>();
        rhs.analysis = node["analysis"].as<vector<Analysis>>();
        return true;
    }
};
}
#endif // CURRENTPROTOCOL_H
