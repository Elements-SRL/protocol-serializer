#ifndef VSTEPTSTEP_H
#define VSTEPTSTEP_H
#include "yaml.h"
using namespace std;

struct VStepTStep {
    double v0;
    unsigned int v0ctrl;
    double vstep;
    unsigned int vstepctrl;
    double t0;
    unsigned int t0ctrl;
    double tstep;
    unsigned int tstepctrl;
    bool visible;
};

namespace YAML {
template<>
struct convert<VStepTStep>{
    static Node encode(const VStepTStep& rhs) {
        Node node;
        node["v0"] = rhs.v0;
        node["v0ctrl"] = rhs.v0ctrl;
        node["vstep"] = rhs.vstep;
        node["vstepctrl"] = rhs.vstepctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["tstep"] = rhs.tstep;
        node["tstepctrl"] = rhs.tstepctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["vsteptstep"] = node;
        return key;
    }

    static bool decode(const Node& node, VStepTStep& rhs) {
        if(!node.IsMap() || !node["vsteptstep"]) {
            return false;
        }
        Node value = node["vsteptstep"];
        rhs.v0 = value["v0"].as<double>();
        rhs.v0ctrl = value["v0ctrl"].as<unsigned int>();
        rhs.vstep = value["vstep"].as<double>();
        rhs.vstepctrl = value["vstepctrl"].as<unsigned int>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<unsigned int>();
        rhs.tstep = value["tstep"].as<double>();
        rhs.tstepctrl = value["tstepctrl"].as<unsigned int>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VSTEPSTEP_H
