#ifndef ISIN_H
#define ISIN_H

#include "yaml.h"

namespace YAML {
typedef struct ISin {
    double i0;
    std::string i0ctrl;
    double iamp;
    std::string iampctrl;
    double freq;
    std::string freqctrl;
    bool visible;
} ISin_t;

template<>
struct convert<ISin>{
    static Node encode(const ISin& rhs) {
        Node node;
        node["i0"] = rhs.i0;
        node["i0ctrl"] = rhs.i0ctrl;
        node["iamp"] = rhs.iamp;
        node["iampctrl"] = rhs.iampctrl;
        node["freq"] = rhs.freq;
        node["freqctrl"] = rhs.freqctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["isin"] = node;
        return key;
    }

    static bool decode(const Node& node, ISin& rhs) {
        if(!node.IsMap() || !node["isin"]) {
            return false;
        }
        Node value = node["isin"];
        rhs.i0 = value["i0"].as<double>();
        rhs.i0ctrl = value["i0ctrl"].as<std::string>();
        rhs.iamp = value["iamp"].as<double>();
        rhs.iampctrl = value["iampctrl"].as<std::string>();
        rhs.freq = value["freq"].as<double>();
        rhs.freqctrl = value["freqctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // ISIN_H
