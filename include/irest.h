#ifndef IREST_H
#define IREST_H

#include "yaml.h"

namespace YAML {
typedef struct IRest {
    double i0;
    std::string i0ctrl;
    double t0;
    std::string t0ctrl;
    bool visible;
} IRest_t;

template<>
struct convert<IRest>{
    static Node encode(const IRest& rhs) {
        Node node;
        node["i0"] = rhs.i0;
        node["i0ctrl"] = rhs.i0ctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["irest"] = node;
        return key;
    }

    static bool decode(const Node& node, IRest& rhs) {
        if(!node.IsMap() || !node["vrest"]) {
            return false;
        }
        Node value = node["irest"];
        rhs.i0 = value["i0"].as<double>();
        rhs.i0ctrl = value["i0ctrl"].as<std::string>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // IREST_H
