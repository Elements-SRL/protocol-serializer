#ifndef FREQUENCYCTRL_H
#define FREQUENCYCTRL_H
#include "yaml.h"
using namespace std;

struct FrequencyCtrl {
    string name;
    unsigned int id;
    double value;
};

namespace YAML {
template<>
struct convert<FrequencyCtrl>{
    static Node encode(const FrequencyCtrl& rhs) {
        Node node;
        node["name"] = rhs.name;
        node["id"] = rhs.id;
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
        rhs.name = value["name"].as<string>();
        rhs.id = value["id"].as<unsigned int>();
        rhs.value = value["value"].as<double>();
        return true;
    }
};
}
#endif // FREQUENCYCTRL_H
