#ifndef VOLTAGECTRL_H
#define VOLTAGECTRL_H
#include "yaml.h"
using namespace std;

struct VoltageCtrl {
    string name;
    unsigned int id;
    double value;
};

namespace YAML {
template<>
struct convert<VoltageCtrl>{
    static Node encode(const VoltageCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["id"] = rhs.id;
        node["value"] = rhs.value;
        Node key;
        key["voltagectrl"] = node;
        return key;
    }

    static bool decode(const Node& node, VoltageCtrl& rhs) {
        if(!node.IsMap() || !node["voltagectrl"]) {
            return false;
        }
        Node value = node["voltagectrl"];
        rhs.name = value["name"].as<string>();
        rhs.id = value["id"].as<unsigned int>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // VOLTAGECTRL_H
