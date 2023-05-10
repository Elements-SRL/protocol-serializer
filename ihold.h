#ifndef IHOLD_H
#define IHOLD_H
#include "yaml.h"
using namespace std;

struct IHold {
    double t0;
    unsigned int t0ctrl;
    bool visible;
};

namespace YAML {
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
        rhs.t0ctrl = value["t0ctrl"].as<unsigned int>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // IHOLD_H
