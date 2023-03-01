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
//    string name;
//    double initial_value;
//    string unit;
//    bool forward_euler;
//    int shortcutindex;
//    operation_mode mode;
//    double vhold;
//    bool vholdref;
//    int sweeps;
//    int currentrange; //Not too sure on this one
//    int voltagerange;
//    string voltageUnit;
//    int samplingrate;
//    int controls;
    vector<Phase> phases;
    vector<Cursor> cursors;
};

namespace YAML {
template<>
struct convert<VoltageProtocol>{
    static Node encode(const VoltageProtocol& rhs) {
        Node node;
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
//        rhs.v0= node["symbol"].as<double>();
//        rhs.v0ctrl= node["name"].as<double>();
//        rhs.vfinal = node["initial_value"].as<double>();
//        rhs.vfinalctrl = node["unit"].as<double>();
//        rhs.t0 = node["forward_euler"].as<double>();
//        rhs.t0ctrl = node["symbol"].as<double>();
//        rhs.visible = node["name"].as<bool>();
        rhs.phases = node["phases"].as<vector<Phase>>();
        rhs.cursors = node["cursors"].as<vector<Cursor>>();
        return true;
    }
};
}
#endif // VOLTAGE_PROTOCOL_H
