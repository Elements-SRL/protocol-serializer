#ifndef VOLTAGEPROTOCOL_H
#define VOLTAGEPROTOCOL_H

#include <variant>

#include "yaml.h"
#include "phase.h"
#include "control.h"
#include "global_defines.h"

using namespace std;

struct VoltageProtocol {
    string name;
    int shortcutindex;
    int operationmode;
    double vhold;
    bool vholdref;
    int sweeps;
    string currentrange;
    string voltagerange;
    string samplingrate;

    vector<Control> controls;
    vector<Phase> phases;
};

namespace YAML {
template<>
struct convert<VoltageProtocol>{
    static Node encode(const VoltageProtocol& rhs) {
        Node node;

        node["name"] = rhs.name;
        node["shortcutindex"] = rhs.shortcutindex;
        node["operationmode"] = rhs.operationmode;
        node["vhold"] = rhs.vhold;
        node["vholdref"] = rhs.vholdref;
        node["sweeps"] = rhs.sweeps;
        node["currentrange"] = rhs.currentrange;
        node["voltagerange"] = rhs.voltagerange;
        node["samplingrate"] = rhs.samplingrate;
        node["phases"] = rhs.phases;
        node["controls"] = rhs.controls;

        Node key;
        key["voltageprotocol"] = node;
        return key;
    }

    static bool decode(const Node& n, VoltageProtocol& rhs) {
        if(!n.IsMap() || !n["voltageprotocol"]) {
            return false;
        }
        Node node = n["voltageprotocol"];

        rhs.name = node["name"].as<string>();
        rhs.shortcutindex = node["shortcutindex"].as<int>();
        rhs.operationmode = node["operationmode"].as<int>();
        rhs.vhold = node["vhold"].as<double>();
        rhs.vholdref = node["vholdref"].as<bool>();
        rhs.sweeps = node["sweeps"].as<int>();
        rhs.currentrange = node["currentrange"].as<string>();
        rhs.voltagerange = node["voltagerange"].as<string>();
        rhs.samplingrate = node["samplingrate"].as<string>();
        rhs.phases = node["phases"].as<vector<Phase>>();
        rhs.controls = node["controls"].as<vector<Control>>();
        return true;
    }
};
}
#endif // VOLTAGEPROTOCOL_H
