#ifndef VSIN_H
#define VSIN_H
#include <string>
#include <iostream>
#include "yaml.h"
using namespace std;

struct VSin {
    double v0;
    double v0ctrl;
    double vamp;
    double vampctrl;
    double freq;
    double freqctrl;
    bool visible;
};

//YAML::Node toNode(VConst& vc){
//    YAML::Node node;
//    node = vc;
//    return node;
//}

namespace YAML {
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
            cout << "ciccia" <<endl;
            return false;
        }
        Node value = node["vsin"];
        rhs.v0= value["v0"].as<double>();
        rhs.v0ctrl= value["v0ctrl"].as<double>();
        rhs.vamp = value["vamp"].as<double>();
        rhs.vampctrl = value["vampctrl"].as<double>();
        rhs.freq = value["freq"].as<double>();
        rhs.freqctrl = value["freqctrl"].as<double>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VSIN_H
