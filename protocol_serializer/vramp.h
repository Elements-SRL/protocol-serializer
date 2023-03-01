#ifndef VRAMP_H
#define VRAMP_H
#include <string>
#include "yaml.h"
#include <iostream>
using namespace std;

struct VRamp {
    double v0;
    double v0ctrl;
    double vfinal;
    double vfinalctrl;
    double t0;
    double t0ctrl;
    bool visible;
};

namespace YAML {
template<>
struct convert<VRamp>{
    static Node encode(const VRamp& rhs) {
        Node node;
        node["v0"] = rhs.v0;
        node["v0ctrl"] = rhs.v0ctrl;
        node["vfinal"] = rhs.vfinal;
        node["vfinalctrl"] = rhs.vfinalctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["vramp"] = node;
        return key;

    }

    static bool decode(const Node& n, VRamp& rhs) {
        if(!n.IsMap() || !n["vramp"]) {
            return false;
        }
        Node node = n["vramp"];
        rhs.v0 = node["v0"].as<double>();
        rhs.v0ctrl = node["v0ctrl"].as<double>();
        rhs.vfinal = node["vfinal"].as<double>();
        rhs.vfinalctrl = node["vfinalctrl"].as<double>();
        rhs.t0 = node["t0"].as<double>();
        rhs.t0ctrl = node["t0ctrl"].as<double>();
        rhs.visible = node["visible"].as<bool>();
        return true;
    }
};
}
#endif // VRAMP_H
