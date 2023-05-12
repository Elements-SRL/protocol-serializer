#ifndef VSTEPTSTEP_H
#define VSTEPTSTEP_H

#include "yaml.h"

namespace YAML {
typedef struct VStepTStep {
    double v0;
    std::string v0ctrl;
    double vstep;
    std::string vstepctrl;
    double t0;
    std::string t0ctrl;
    double tstep;
    std::string tstepctrl;
    bool visible;
} VStepTStep_t;

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
        rhs.v0ctrl = value["v0ctrl"].as<std::string>();
        rhs.vstep = value["vstep"].as<double>();
        rhs.vstepctrl = value["vstepctrl"].as<std::string>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<std::string>();
        rhs.tstep = value["tstep"].as<double>();
        rhs.tstepctrl = value["tstepctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // VSTEPSTEP_H
