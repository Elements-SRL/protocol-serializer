#ifndef CONTROL_H
#define CONTROL_H

#include <variant>

#include "voltagectrl.h"
#include "currentctrl.h"
#include "timectrl.h"
#include "frequencyctrl.h"
#include "naturalnumctrl.h"
#include "yaml.h"

typedef variant<VoltageCtrl, CurrentCtrl, TimeCtrl, FrequencyCtrl, NaturalNumCtrl> Control;

namespace YAML {
template<>
struct convert<Control>{
    static Node encode(const Control& rhs) {
        Node node;
        switch (rhs.index()) {
        case 0:
            node = get<VoltageCtrl>(rhs);
            break;
        case 1:
            node = get<CurrentCtrl>(rhs);
            break;
        case 2:
            node = get<TimeCtrl>(rhs);
            break;
        case 3:
            node = get<FrequencyCtrl>(rhs);
            break;
        case 4:
            node = get<NaturalNumCtrl>(rhs);
            break;
        }
        return node;
    }

    static bool decode(const Node& node, Control& rhs) {
        if(!node.IsMap()) {
            return false;
        }
        if (node["voltagectrl"]){
            rhs.emplace<VoltageCtrl>(node.as<VoltageCtrl>());

        } else if (node["currentctrl"]){
            rhs.emplace<CurrentCtrl>(node.as<CurrentCtrl>());

        } else if (node["timectrl"]){
            rhs.emplace<TimeCtrl>(node.as<TimeCtrl>());

        } else if (node["frequencyctrl"]){
            rhs.emplace<FrequencyCtrl>(node.as<FrequencyCtrl>());

        } else if (node["naturalnumctrl"]){
            rhs.emplace<NaturalNumCtrl>(node.as<NaturalNumCtrl>());
        }
        return true;
    }
};
}

#endif // CONTROL_H
