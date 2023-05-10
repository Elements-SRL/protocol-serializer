#ifndef ISIN_H
#define ISIN_H

#include "yaml.h"

using namespace std;

struct ISin {
    double i0;
    unsigned int i0ctrl;
    double iamp;
    unsigned int iampctrl;
    double freq;
    unsigned int freqctrl;
    bool visible;
};

namespace YAML {
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
        rhs.i0ctrl = value["i0ctrl"].as<unsigned int>();
        rhs.iamp = value["iamp"].as<double>();
        rhs.iampctrl = value["iampctrl"].as<unsigned int>();
        rhs.freq = value["freq"].as<double>();
        rhs.freqctrl = value["freqctrl"].as<unsigned int>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // ISIN_H
