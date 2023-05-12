#ifndef VHOLD_H
#define VHOLD_H

#include "yaml.h"

namespace YAML {
typedef struct VHold {
    double t0;
    std::string t0ctrl;
    bool visible;
} VHold_t;

template<>
struct convert<VHold>{
    static Node encode(const VHold& rhs) {
        Node node;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["vhold"] = node;
        return key;
    }

    static bool decode(const Node& node, VHold& rhs) {
        if(!node.IsMap() || !node["vhold"]) {
            return false;
        }
        Node value = node["vhold"];
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VHOLD_H
