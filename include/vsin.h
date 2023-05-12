#ifndef VSIN_H
#define VSIN_H

#include "yaml.h"

namespace YAML {
typedef struct VSin {
    double v0;
    std::string v0ctrl;
    double vamp;
    std::string vampctrl;
    double freq;
    std::string freqctrl;
    bool visible;
} VSin_t;

template<>
struct convert<VSin>{
    static Node encode(const VSin& rhs) {
        Node node;
        node["v0"] = rhs.v0;
        node["v0ctrl"] = rhs.v0ctrl;
        node["vamp"] = rhs.vamp;
        node["vampctrl"] = rhs.vampctrl;
        node["freq"] = rhs.freq;
        node["freqctrl"] = rhs.freqctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["vsin"] = node;
        return key;
    }

    static bool decode(const Node& node, VSin& rhs) {
        if(!node.IsMap() || !node["vsin"]) {
            return false;
        }
        Node value = node["vsin"];
        rhs.v0 = value["v0"].as<double>();
        rhs.v0ctrl = value["v0ctrl"].as<std::string>();
        rhs.vamp = value["vamp"].as<double>();
        rhs.vampctrl = value["vampctrl"].as<std::string>();
        rhs.freq = value["freq"].as<double>();
        rhs.freqctrl = value["freqctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // ISIN_H
