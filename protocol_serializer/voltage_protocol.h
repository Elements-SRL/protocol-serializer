#ifndef VOLTAGE_PROTOCOL_H
#define VOLTAGE_PROTOCOL_H

#define VOLTAGE_PROTOCOL "voltage_protocol"

#include <string>
#include <variant>
#include <iostream>
#include <cursor.h>
#include "yaml.h"
#include "phase.h"

enum operation_mode{
    GapFree, Episodic
};

using namespace std;
using namespace YAML;

struct VoltageProtocol {
    string name;
    int shortcutindex;
    int mode;
    double vhold;
    bool vholdref;
    int sweeps;
    int currentrange; //Not too sure on this one
    int voltagerange;
    int samplingrate;

//    Maybe add volageUnit instead of voltageRange as string
//    string voltageUnit;
//  vector<Control> controls;
    vector<Phase> phases;
    vector<Cursor> cursors;

};

namespace YAML {
template<>
struct convert<VoltageProtocol>{
    static Node encode(const VoltageProtocol& rhs) {
        Node node;

        node["name"] = rhs.name;
        node["shortcutindex"] = rhs.shortcutindex;
        node["operation_mode"] = rhs.mode;
        node["vhold"] = rhs.vhold;
        node["vholdref"] = rhs.vholdref;
        node["sweeps"] = rhs.sweeps;
        node["currentrange"] = rhs.currentrange;
        node["phases"] = rhs.phases;
        node["cursors"] = rhs.cursors;

        Node key;
        key[VOLTAGE_PROTOCOL] = node;
        return key;
    }

    static bool decode(const Node& n, VoltageProtocol& rhs) {
        if(!n.IsMap() || !n[VOLTAGE_PROTOCOL]) {
            return false;
        }
        Node node = n[VOLTAGE_PROTOCOL];

        rhs.name = node["name"].as<string>();
        rhs.shortcutindex = node["shortcutindex"].as<int>();
        rhs.mode = node["operation_mode"].as<int>();
        rhs.vhold = node["vhold"].as<double>();
        rhs.vholdref = node["vholdref"].as<bool>();
        rhs.sweeps = node["sweeps"].as<int>();
        rhs.currentrange = node["currentrange"].as<int>();
        rhs.phases = node["phases"].as<vector<Phase>>();
        rhs.cursors = node["cursors"].as<vector<Cursor>>();
        return true;
    }
};
}
#endif // VOLTAGE_PROTOCOL_H
