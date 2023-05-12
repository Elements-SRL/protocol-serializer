#ifndef CURSOR_H
#define CURSOR_H

#include "yaml.h"
#include "global_defines.h"

namespace YAML {
typedef struct Cursor {
    double xvalue;
    int itemidx;
    YAML::CursorLocationType locationtype;
    double locationdelay;
    YAML::CursorRepetitionType repetitiontype;
    int repetitionidx;
    YAML::CursorSweepType sweeptype;
    int sweepidx;
    YAML::CursorTriggerType triggertype;
    int triggeridx;
} Cursor_t;

template<>
struct convert<Cursor>{
    static Node encode(const Cursor& rhs) {
        Node node;
        node["xvalue"] = rhs.xvalue;
        node["itemidx"] = rhs.itemidx;
        node["locationtype"] = cursorLocationStrings[rhs.locationtype];
        node["locationdelay"] = rhs.locationdelay;
        node["repetitiontype"] = cursorRepetitionStrings[rhs.repetitiontype];
        node["repetitionidx"] = rhs.repetitionidx;
        node["sweeptype"] = cursorSweepStrings[rhs.sweeptype];
        node["sweepidx"] = rhs.sweepidx;
        node["triggertype"] = cursorTriggerStrings[rhs.triggertype];
        node["triggeridx"] = rhs.triggeridx;
        return node;
    }

    static bool decode(const Node& n, Cursor& rhs) {
        if(n.size() != 10) {
            return false;
        }
        Node node = n;
        rhs.xvalue =  node["xvalue"].as<double>();
        rhs.itemidx = node["itemidx"].as<int>();
        rhs.locationtype = (CursorLocationType)(std::find(cursorLocationStrings.begin(), cursorLocationStrings.end(), node["locationtype"].as<std::string>())-cursorLocationStrings.begin());
        rhs.locationdelay = node["locationdelay"].as<double>();
        rhs.repetitiontype = (CursorRepetitionType)(std::find(cursorRepetitionStrings.begin(), cursorRepetitionStrings.end(), node["repetitiontype"].as<std::string>())-cursorRepetitionStrings.begin());
        rhs.repetitionidx = node["repetitionidx"].as<int>();
        rhs.sweeptype = (CursorSweepType)(std::find(cursorSweepStrings.begin(), cursorSweepStrings.end(), node["sweeptype"].as<std::string>())-cursorSweepStrings.begin());
        rhs.sweepidx = node["sweepidx"].as<int>();
        rhs.triggertype = (CursorTriggerType)(std::find(cursorTriggerStrings.begin(), cursorTriggerStrings.end(), node["triggertype"].as<std::string>())-cursorTriggerStrings.begin());
        rhs.triggeridx = node["triggeridx"].as<int>();
        return true;
    }
};
}
#endif // CURSOR_H
