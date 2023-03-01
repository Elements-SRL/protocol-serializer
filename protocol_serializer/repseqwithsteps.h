#ifndef REPSEQWITHSTEPS_H
#define REPSEQWITHSTEPS_H
#include <string>
#include <iostream>
#include "yaml.h"
using namespace std;

struct RepSeqWithSteps {
    int repnum;
    int repnumctrl;
    int itemnum;
    int itemnumctrl;
    double restvoltage;
    double resttime;
    int resttimectrl;
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
        rhs.repnumctrl = value["repnumctrl"].as<int>();
        rhs.itemnum = value["itemnum"].as<int>();
        rhs.itemnumctrl = value["itemnumctrl"].as<int>();
        rhs.restvoltage = value["restvoltage"].as<double>();
        rhs.resttime = value["resttime"].as<double>();
        rhs.resttimectrl = value["resttimectrl"].as<int>();
        return true;
    }
};
}
#endif // REPSEQWITHSTEPS_H
