#ifndef TIMECTRL_H
#define TIMECTRL_H

#include "yaml.h"

namespace YAML {
typedef struct TimeCtrl {
    std::string name;
    double value;
} TimeCtrl_t;

template<>
struct convert<TimeCtrl>{
    static Node encode(const TimeCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
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
        rhs.name = value["name"].as<std::string>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // TIMECTRL_H
