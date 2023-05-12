#ifndef VOLTAGECTRL_H
#define VOLTAGECTRL_H

#include "yaml.h"

namespace YAML {
typedef struct VoltageCtrl {
    std::string name;
    double value;
} VoltageCtrl_t;

template<>
struct convert<VoltageCtrl>{
    static Node encode(const VoltageCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
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
        rhs.name = value["name"].as<std::string>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // VOLTAGECTRL_H
