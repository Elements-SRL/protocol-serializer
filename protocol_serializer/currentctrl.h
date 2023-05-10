#ifndef CURRENTCTRL_H
#define CURRENTCTRL_H
#include "yaml.h"
using namespace std;

struct CurrentCtrl {
    string name;
    unsigned int id;
    double value;
};

namespace YAML {
template<>
struct convert<CurrentCtrl>{
    static Node encode(const CurrentCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["id"] = rhs.id;
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
        rhs.name = value["name"].as<string>();
        rhs.id = value["id"].as<unsigned int>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // CURRENTCTRL_H
