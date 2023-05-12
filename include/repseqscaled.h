#ifndef REPSEQSCALED_H
#define REPSEQSCALED_H

#include "yaml.h"

namespace YAML {
typedef struct RepSeqScaled {
    double vholdleak;
    std::string vholdleakctrl;
    int scalefactor;
    std::string scalefactorctrl;
    int repnum;
    std::string repnumctrl;
    int itemnum;
    std::string itemnumctrl;
    double reststimulus;
    std::string reststimulusctrl;
    double resttime;
    std::string resttimectrl;
    bool preceding;
    bool reversed;
    bool alternating;
} RepSeqScaled_t;

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
        node["reststimulus"] = rhs.reststimulus;
        node["reststimulusctrl"] = rhs.reststimulusctrl;
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
        rhs.vholdleakctrl = value["vholdleakctrl"].as<std::string>();
        rhs.scalefactor = value["scalefactor"].as<int>();
        rhs.scalefactorctrl = value["scalefactorctrl"].as<std::string>();
        rhs.repnum = value["repnum"].as<int>();
        rhs.repnumctrl = value["repnumctrl"].as<std::string>();
        rhs.itemnum = value["itemnum"].as<int>();
        rhs.itemnumctrl = value["itemnumctrl"].as<std::string>();
        rhs.reststimulus = value["reststimulus"].as<double>();
        rhs.reststimulusctrl = value["reststimulusctrl"].as<std::string>();
        rhs.resttime = value["resttime"].as<double>();
        rhs.resttimectrl = value["resttimectrl"].as<std::string>();
        rhs.preceding = value["preceding"].as<bool>();
        rhs.reversed = value["reversed"].as<bool>();
        rhs.alternating = value["alternating"].as<bool>();
        return true;
    }
};
}
#endif // REPSEQSCALED_H
