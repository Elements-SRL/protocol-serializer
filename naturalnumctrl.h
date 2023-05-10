#ifndef NATURALNUMCTRL_H
#define NATURALNUMCTRL_H
#include "yaml.h"
using namespace std;
struct NaturalNumCtrl {
    string name;
    unsigned int id;
    int value;
};

namespace YAML {
template<>
struct convert<NaturalNumCtrl>{
    static Node encode(const NaturalNumCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["id"] = rhs.id;
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
        rhs.name = value["name"].as<string>();
        rhs.id = value["id"].as<unsigned int>();
        rhs.value = value["value"].as<int>();
        return true;
    }
};
}
#endif // NATURALNUMCTRL_H
