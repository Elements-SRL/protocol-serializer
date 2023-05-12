#ifndef NATURALNUMCTRL_H
#define NATURALNUMCTRL_H

#include "yaml.h"

namespace YAML {
typedef struct NaturalNumCtrl {
    std::string name;
    int value;
} NaturalNumCtrl_t;

template<>
struct convert<NaturalNumCtrl>{
    static Node encode(const NaturalNumCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["value"] = rhs.value;
        Node key;
        key["naturalnumctrl"] = node;
        return key;
    }

    static bool decode(const Node& node, NaturalNumCtrl& rhs) {
        if(!node.IsMap() || !node["naturalnumctrl"]) {
            return false;
        }
        Node value = node["naturalnumctrl"];
        rhs.name = value["name"].as<std::string>();
        rhs.value = value["value"].as<int>();
        return true;
    }
};
}
#endif // NATURALNUMCTRL_H
