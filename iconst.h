#ifndef ICONST_H
#define ICONST_H
#include "yaml.h"
using namespace std;

struct IConst {
    double v0;
    unsigned int v0ctrl;
    double t0;
    unsigned int t0ctrl;
    bool visible;
};

namespace YAML {
template<>
struct convert<IConst>{
    static Node encode(const IConst& rhs) {
        Node node;
        node["i0"] = rhs.v0;
        node["i0ctrl"] = rhs.v0ctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["iconst"] = node;
        return key;
    }

    static bool decode(const Node& node, IConst& rhs) {
        if(!node.IsMap() || !node["iconst"]) {
            return false;
        }
        Node value = node["iconst"];
        rhs.v0 = value["i0"].as<double>();
        rhs.v0ctrl = value["i0ctrl"].as<unsigned int>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<unsigned int>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // ICONST_H
