#ifndef INFREPSEQ_H
#define INFREPSEQ_H

#include "yaml.h"

namespace YAML {
typedef struct InfRepSeq {
    int itemnum;
    std::string itemnumctrl;
    double reststimulus;
    std::string reststimulusctrl;
    double resttime;
    std::string resttimectrl;
} InfRepSeq_t;

template<>
struct convert<InfRepSeq>{
    static Node encode(const InfRepSeq& rhs) {
        Node node;
        node["itemnum"] = rhs.itemnum;
        node["itemnumctrl"] = rhs.itemnumctrl;
        node["reststimulus"] = rhs.reststimulus;
        node["reststimulusctrl"] = rhs.reststimulusctrl;
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
        rhs.itemnumctrl = value["itemnumctrl"].as<std::string>();
        rhs.reststimulus = value["reststimulus"].as<double>();
        rhs.reststimulusctrl = value["reststimulusctrl"].as<std::string>();
        rhs.resttime = value["resttime"].as<double>();
        rhs.resttimectrl = value["resttimectrl"].as<std::string>();
        return true;
    }
};
}
#endif // INFREPSEQ_H
