#ifndef VCONST_H
#define VCONST_H

#include "yaml.h"

using namespace std;

struct VConst {
    double v0;
    unsigned int v0ctrl;
    double t0;
    unsigned int t0ctrl;
    bool visible;
};

namespace YAML {
template<>
struct convert<VConst>{
    static Node encode(const VConst& rhs) {
        Node node;
        node["v0"] = rhs.v0;
        node["v0ctrl"] = rhs.v0ctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["vconst"] = node;
        return key;
    }

    static bool decode(const Node& node, VConst& rhs) {
        if(!node.IsMap() || !node["vconst"]) {
            return false;
        }
        Node value = node["vconst"];
        rhs.v0 = value["v0"].as<double>();
        rhs.v0ctrl = value["v0ctrl"].as<unsigned int>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<unsigned int>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VCONST_H
