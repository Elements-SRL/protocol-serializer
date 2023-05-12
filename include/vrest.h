#ifndef VREST_H
#define VREST_H

#include "yaml.h"

namespace YAML {
typedef struct VRest {
    double v0;
    std::string v0ctrl;
    double t0;
    std::string t0ctrl;
    bool visible;
} VRest_t;

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
        rhs.v0ctrl = value["v0ctrl"].as<std::string>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VREST_H
