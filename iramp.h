#ifndef IRAMP_H
#define IRAMP_H
#include "yaml.h"
using namespace std;

struct IRamp {
    double i0;
    unsigned int i0ctrl;
    double ifinal;
    unsigned int ifinalctrl;
    double t0;
    unsigned int t0ctrl;
    bool visible;
};

namespace YAML {
template<>
struct convert<IRamp>{
    static Node encode(const IRamp& rhs) {
        Node node;
        node["i0"] = rhs.i0;
        node["i0ctrl"] = rhs.i0ctrl;
        node["ifinal"] = rhs.ifinal;
        node["ifinalctrl"] = rhs.ifinalctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["iramp"] = node;
        return key;

    }

    static bool decode(const Node& n, IRamp& rhs) {
        if(!n.IsMap() || !n["iramp"]) {
            return false;
        }
        Node node = n["iramp"];
        rhs.i0 = node["i0"].as<double>();
        rhs.i0ctrl = node["i0ctrl"].as<unsigned int>();
        rhs.ifinal = node["ifinal"].as<double>();
        rhs.ifinalctrl = node["ifinalctrl"].as<unsigned int>();
        rhs.t0 = node["t0"].as<double>();
        rhs.t0ctrl = node["t0ctrl"].as<unsigned int>();
        rhs.visible = node["visible"].as<bool>();
        return true;
    }
};
}
#endif // IRAMP_H
