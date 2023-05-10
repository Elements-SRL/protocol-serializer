#ifndef VREST_H
#define VREST_H
#include "yaml.h"
using namespace std;

struct VRest {
    double v0;
    unsigned int v0ctrl;
    double t0;
    unsigned int t0ctrl;
    bool visible;
};

namespace YAML {
template<>
struct convert<VRest>{
    static Node encode(const VRest& rhs) {
        Node node;
        node["v0"] = rhs.v0;
        node["v0ctrl"] = rhs.v0ctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["vrest"] = node;
        return key;
    }

    static bool decode(const Node& node, VRest& rhs) {
        if(!node.IsMap() || !node["vrest"]) {
            return false;
        }
        Node value = node["vrest"];
        rhs.v0 = value["v0"].as<double>();
        rhs.v0ctrl = value["v0ctrl"].as<unsigned int>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<unsigned int>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VREST_H
