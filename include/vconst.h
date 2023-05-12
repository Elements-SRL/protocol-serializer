#ifndef VCONST_H
#define VCONST_H

#include "yaml.h"

namespace YAML {
typedef struct VConst {
    double v0;
    std::string v0ctrl;
    double t0;
    std::string t0ctrl;
    bool visible;
} VConst_t;

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
        rhs.v0ctrl = value["v0ctrl"].as<std::string>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VCONST_H
