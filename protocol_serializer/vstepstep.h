#ifndef VSTEPSTEP_H
#define VSTEPSTEP_H
#include "yaml.h"
using namespace std;

struct VStepStep {
    double v0;
    double v0ctrl;
    double vstepctrl;
    double t0;
    double t0ctrl;
    double tstep;
    bool visible;
};

namespace YAML {
template<>
struct convert<VStepStep>{
    static Node encode(const VStepStep& rhs) {
        Node node;
        node["v0"] = rhs.v0;
        node["v0ctrl"] = rhs.v0ctrl;
        node["vstepctrl"] = rhs.vstepctrl;
        node["t0"] = rhs.t0;
        node["tstep"] = rhs.tstep;
        node["t0ctrl"] = rhs.t0ctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["vstepstep"] = node;
        return key;
    }

    static bool decode(const Node& node, VStepStep& rhs) {
        if(!node.IsMap() || !node["vstepstep"]) {
            return false;
        }
        Node value = node["vstepstep"];
        rhs.v0 = value["v0"].as<double>();
        rhs.v0ctrl = value["v0ctrl"].as<double>();
        rhs.vstepctrl = value["vstepctrl"].as<double>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<double>();
        rhs.tstep = value["tstep"].as<double>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VSTEPSTEP_H
