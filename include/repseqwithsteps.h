#ifndef REPSEQWITHSTEPS_H
#define REPSEQWITHSTEPS_H

#include "yaml.h"

namespace YAML {
typedef struct RepSeqWithSteps {
    int repnum;
    std::string repnumctrl;
    int itemnum;
    std::string itemnumctrl;
    double reststimulus;
    std::string reststimulusctrl;
    double resttime;
    std::string resttimectrl;
} RepSeqWithSteps_t;

template<>
struct convert<RepSeqWithSteps>{
    static Node encode(const RepSeqWithSteps& rhs) {
        Node node;
        node["repnum"] = rhs.repnum;
        node["repnumctrl"] = rhs.repnumctrl;
        node["itemnum"] = rhs.itemnum;
        node["itemnumctrl"] = rhs.itemnumctrl;
        node["reststimulus"] = rhs.reststimulus;
        node["reststimulusctrl"] = rhs.reststimulusctrl;
        node["resttime"] = rhs.resttime;
        node["resttimectrl"] = rhs.resttimectrl;
        Node key;
        key["repseqwithsteps"] = node;
        return key;
    }

    static bool decode(const Node& node, RepSeqWithSteps& rhs) {
        if(!node.IsMap() || !node["repseqwithsteps"]) {
            return false;
        }
        Node value = node["repseqwithsteps"];

        rhs.repnum = value["repnum"].as<int>();
        rhs.repnumctrl = value["repnumctrl"].as<std::string>();
        rhs.itemnum = value["itemnum"].as<int>();
        rhs.itemnumctrl = value["itemnumctrl"].as<std::string>();
        rhs.reststimulus = value["reststimulus"].as<double>();
        rhs.reststimulusctrl = value["reststimulusctrl"].as<std::string>();
        rhs.resttime = value["resttime"].as<double>();
        rhs.resttimectrl = value["resttimectrl"].as<std::string>();
        return true;
    }
};
}
#endif // REPSEQWITHSTEPS_H
