#ifndef IHOLD_H
#define IHOLD_H

#include "yaml.h"

namespace YAML {
typedef struct IHold {
    double t0;
    std::string t0ctrl;
    bool visible;
} IHold_t;

template<>
struct convert<IHold>{
    static Node encode(const IHold& rhs) {
        Node node;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["ihold"] = node;
        return key;
    }

    static bool decode(const Node& node, IHold& rhs) {
        if(!node.IsMap() || !node["ihold"]) {
            return false;
        }
        Node value = node["ihold"];
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // IHOLD_H
