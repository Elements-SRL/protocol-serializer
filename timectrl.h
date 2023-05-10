#ifndef TIMECTRL_H
#define TIMECTRL_H
#include "yaml.h"
using namespace std;

struct TimeCtrl {
    string name;
    unsigned int id;
    double value;
};

namespace YAML {
template<>
struct convert<TimeCtrl>{
    static Node encode(const TimeCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["id"] = rhs.id;
        node["value"] = rhs.value;
        Node key;
        key["timectrl"] = node;
        return key;
    }

    static bool decode(const Node& node, TimeCtrl& rhs) {
        if(!node.IsMap() || !node["timectrl"]) {
            return false;
        }
        Node value = node["timectrl"];
        rhs.name = value["name"].as<string>();
        rhs.id = value["id"].as<unsigned int>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // TIMECTRL_H
