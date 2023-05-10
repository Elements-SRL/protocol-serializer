#ifndef REPSEQWITHSTEPS_H
#define REPSEQWITHSTEPS_H
#include "yaml.h"
using namespace std;

struct RepSeqWithSteps {
    int repnum;
    unsigned int repnumctrl;
    int itemnum;
    unsigned int itemnumctrl;
    double restvoltage;
    unsigned int restvoltagectrl;
    double resttime;
    unsigned int resttimectrl;
};

namespace YAML {
template<>
struct convert<RepSeqWithSteps>{
    static Node encode(const RepSeqWithSteps& rhs) {
        Node node;
        node["repnum"] = rhs.repnum;
        node["repnumctrl"] = rhs.repnumctrl;
        node["itemnum"] = rhs.itemnum;
        node["itemnumctrl"] = rhs.itemnumctrl;
        node["restvoltage"] = rhs.restvoltage;
        node["restvoltagectrl"] = rhs.restvoltagectrl;
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
        rhs.repnumctrl = value["repnumctrl"].as<unsigned int>();
        rhs.itemnum = value["itemnum"].as<int>();
        rhs.itemnumctrl = value["itemnumctrl"].as<unsigned int>();
        rhs.restvoltage = value["restvoltage"].as<double>();
        rhs.restvoltagectrl = value["restvoltagectrl"].as<unsigned int>();
        rhs.resttime = value["resttime"].as<double>();
        rhs.resttimectrl = value["resttimectrl"].as<unsigned int>();
        return true;
    }
};
}
#endif // REPSEQWITHSTEPS_H
