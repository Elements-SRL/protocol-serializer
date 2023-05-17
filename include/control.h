#ifndef CONTROL_H
#define CONTROL_H

#include <variant>

#include "voltagectrl.h"
#include "currentctrl.h"
#include "timectrl.h"
#include "frequencyctrl.h"
#include "naturalnumctrl.h"
#include "yaml.h"

namespace YAML {
typedef std::variant<VoltageCtrl, CurrentCtrl, TimeCtrl, FrequencyCtrl, NaturalNumCtrl> Control_t;

typedef enum CtrlIdxs {VoltageCtrlIdx, CurrentCtrlIdx, TimeCtrlIdx, FrequencyCtrlIdx, NaturalNumCtrlIdx} CtrlIdxs_t;

template<>
struct convert<Control_t>{
    static Node encode(const Control_t& rhs) {
        Node node;
        switch (rhs.index()) {
        case VoltageCtrlIdx:
            node = std::get<VoltageCtrl>(rhs);
            break;
        case CurrentCtrlIdx:
            node = std::get<CurrentCtrl>(rhs);
            break;
        case TimeCtrlIdx:
            node = std::get<TimeCtrl>(rhs);
            break;
        case FrequencyCtrlIdx:
            node = std::get<FrequencyCtrl>(rhs);
            break;
        case NaturalNumCtrlIdx:
            node = std::get<NaturalNumCtrl>(rhs);
            break;
        }
        return node;
    }

    static bool decode(const Node& node, Control_t& rhs) {
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
