#ifndef REPSEQSCALED_H
#define REPSEQSCALED_H
#include "yaml.h"
using namespace std;

struct RepSeqScaled {
    double vholdleak;
    unsigned int vholdleakctrl;
    int scalefactor;
    unsigned int scalefactorctrl;
    int repnum;
    unsigned int repnumctrl;
    int itemnum;
    unsigned int itemnumctrl;
    double restvoltage;
    unsigned int restvoltagectrl;
    double resttime;
    unsigned int resttimectrl;
    bool preceding;
    bool reversed;
    bool alternating;
};

namespace YAML {
template<>
struct convert<RepSeqScaled>{
    static Node encode(const RepSeqScaled& rhs) {
        Node node;
        node["vholdleak"] = rhs.vholdleak;
        node["vholdleakctrl"] = rhs.vholdleakctrl;
        node["scalefactor"] = rhs.scalefactor;
        node["scalefactorctrl"] = rhs.scalefactorctrl;
        node["repnum"] = rhs.repnum;
        node["repnumctrl"] = rhs.repnumctrl;
        node["itemnum"] = rhs.itemnum;
        node["itemnumctrl"] = rhs.itemnumctrl;
        node["restvoltage"] = rhs.restvoltage;
        node["restvoltagectrl"] = rhs.restvoltagectrl;
        node["resttime"] = rhs.resttime;
        node["resttimectrl"] = rhs.resttimectrl;
        node["preceding"] = rhs.preceding;
        node["reversed"] = rhs.reversed;
        node["alternating"] = rhs.alternating;
        Node key;
        key["repseqscaled"] = node;
        return key;
    }

    static bool decode(const Node& node, RepSeqScaled& rhs) {
        if(!node.IsMap() || !node["repseqscaled"]) {
            return false;
        }
        Node value = node["repseqscaled"];

        rhs.vholdleak = value["vholdleak"].as<double>();
        rhs.vholdleakctrl = value["vholdleakctrl"].as<unsigned int>();
        rhs.scalefactor = value["scalefactor"].as<int>();
        rhs.scalefactorctrl = value["scalefactorctrl"].as<unsigned int>();
        rhs.repnum = value["repnum"].as<int>();
        rhs.repnumctrl = value["repnumctrl"].as<unsigned int>();
        rhs.itemnum = value["itemnum"].as<int>();
        rhs.itemnumctrl = value["itemnumctrl"].as<unsigned int>();
        rhs.restvoltage = value["restvoltage"].as<double>();
        rhs.restvoltagectrl = value["restvoltagectrl"].as<unsigned int>();
        rhs.resttime = value["resttime"].as<double>();
        rhs.resttimectrl = value["resttimectrl"].as<unsigned int>();
        rhs.preceding = value["preceding"].as<bool>();
        rhs.reversed = value["reversed"].as<bool>();
        rhs.alternating = value["alternating"].as<bool>();
        return true;
    }
};
}
#endif // REPSEQSCALED_H
