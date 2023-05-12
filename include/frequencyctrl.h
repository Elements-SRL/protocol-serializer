#ifndef FREQUENCYCTRL_H
#define FREQUENCYCTRL_H

#include "yaml.h"

namespace YAML {
typedef struct FrequencyCtrl {
    std::string name;
    double value;
} FrequencyCtrl_t;

template<>
struct convert<FrequencyCtrl>{
    static Node encode(const FrequencyCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["value"] = rhs.value;
        Node key;
        key["frequencyctrl"] = node;
        return key;
    }

    static bool decode(const Node& node, FrequencyCtrl& rhs) {
        if(!node.IsMap() || !node["frequencyctrl"]) {
            return false;
        }
        Node value = node["frequencyctrl"];
        rhs.name = value["name"].as<std::string>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // FREQUENCYCTRL_H
