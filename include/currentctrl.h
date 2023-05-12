#ifndef CURRENTCTRL_H
#define CURRENTCTRL_H

#include "yaml.h"

namespace YAML {
typedef struct CurrentCtrl {
    std::string name;
    double value;
} CurrentCtrl_t;

template<>
struct convert<CurrentCtrl>{
    static Node encode(const CurrentCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["value"] = rhs.value;
        Node key;
        key["currentctrl"] = node;
        return key;
    }

    static bool decode(const Node& node, CurrentCtrl& rhs) {
        if(!node.IsMap() || !node["currentctrl"]) {
            return false;
        }
        Node value = node["currentctrl"];
        rhs.name = value["name"].as<std::string>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // CURRENTCTRL_H
