#ifndef ITEPTSTEP_H
#define ISTEPTSTEP_H

#include "yaml.h"

namespace YAML {
typedef struct IStepTStep {
    double i0;
    std::string i0ctrl;
    double istep;
    std::string istepctrl;
    double t0;
    std::string t0ctrl;
    double tstep;
    std::string tstepctrl;
    bool visible;
} IStepTStep_t;

template<>
struct convert<IStepTStep>{
    static Node encode(const IStepTStep& rhs) {
        Node node;
        node["i0"] = rhs.i0;
        node["i0ctrl"] = rhs.i0ctrl;
        node["istep"] = rhs.istep;
        node["istepctrl"] = rhs.istepctrl;
        node["t0"] = rhs.t0;
        node["t0ctrl"] = rhs.t0ctrl;
        node["tstep"] = rhs.tstep;
        node["tstepctrl"] = rhs.tstepctrl;
        node["visible"] = rhs.visible;
        Node key;
        key["isteptstep"] = node;
        return key;
    }

    static bool decode(const Node& node, IStepTStep& rhs) {
        if(!node.IsMap() || !node["isteptstep"]) {
            return false;
        }
        Node value = node["isteptstep"];
        rhs.i0 = value["i0"].as<double>();
        rhs.i0ctrl = value["i0ctrl"].as<std::string>();
        rhs.istep = value["istep"].as<double>();
        rhs.istepctrl = value["istepctrl"].as<std::string>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<std::string>();
        rhs.tstep = value["tstep"].as<double>();
        rhs.tstepctrl = value["tstepctrl"].as<std::string>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // ISTEPSTEP_H
