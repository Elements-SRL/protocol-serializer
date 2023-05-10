#ifndef ITEPTSTEP_H
#define ISTEPTSTEP_H
#include "yaml.h"
using namespace std;

struct IStepTStep {
    double i0;
    unsigned int i0ctrl;
    double istep;
    unsigned int istepctrl;
    double t0;
    unsigned int t0ctrl;
    double tstep;
    unsigned int tstepctrl;
    bool visible;
};

namespace YAML {
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
        rhs.i0ctrl = value["i0ctrl"].as<unsigned int>();
        rhs.istep = value["istep"].as<double>();
        rhs.istepctrl = value["istepctrl"].as<unsigned int>();
        rhs.t0 = value["t0"].as<double>();
        rhs.t0ctrl = value["t0ctrl"].as<unsigned int>();
        rhs.tstep = value["tstep"].as<double>();
        rhs.tstepctrl = value["tstepctrl"].as<unsigned int>();
        rhs.visible = value["visible"].as<bool>();
        return true;
    }
};
}
#endif // ISTEPSTEP_H
