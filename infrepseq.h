#ifndef INFREPSEQ_H
#define INFREPSEQ_H
#include "yaml.h"
using namespace std;

struct InfRepSeq {
    int itemnum;
    unsigned int itemnumctrl;
    double restvoltage;
    unsigned int restvoltagectrl;
    double resttime;
    unsigned int resttimectrl;
};

namespace YAML {
template<>
struct convert<InfRepSeq>{
    static Node encode(const InfRepSeq& rhs) {
        Node node;
        node["itemnum"] = rhs.itemnum;
        node["itemnumctrl"] = rhs.itemnumctrl;
        node["restvoltage"] = rhs.restvoltage;
        node["restvoltagectrl"] = rhs.restvoltagectrl;
        node["resttime"] = rhs.resttime;
        node["resttimectrl"] = rhs.resttimectrl;
        Node key;
        key["infrepseq"] = node;
        return key;
    }

    static bool decode(const Node& node, InfRepSeq& rhs) {
        if(!node.IsMap() || !node["infrepseq"]) {
            return false;
        }
        Node value = node["infrepseq"];

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
#endif // INFREPSEQ_H
