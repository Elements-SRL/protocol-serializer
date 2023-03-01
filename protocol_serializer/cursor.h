#ifndef CURSOR_H
#define CURSOR_H
#include <string>
#include "yaml.h"
#include <iostream>
using namespace std;

enum class LocationType {
    from_start
};

enum class SweepType{
    all
};

enum class TriggerType{
    none
};

enum class RepetitionType {
    all
};

struct Cursor {
    int xvalue;
    int itemidx;
//    LocationType locationtype;
    double locationdelay;
//    RepetitionType repetitiontype;
    int repetitionidx;
//    SweepType sweeptype;
    int sweepidx;
//    TriggerType triggertype;
    int triggeridx;
};

namespace YAML {
template<>
struct convert<Cursor>{
    static Node encode(const Cursor& rhs) {
        Node node;
        node["xvalue"] = rhs.xvalue;
        node["itemidx"] = rhs.itemidx;
//        node["locationtype"] = rhs.locationtype;
        node["locationdelay"] = rhs.locationdelay;
//        node["repetitiontype"] = rhs.repetitiontype;
        node["repetitionidx"] = rhs.repetitionidx;
//        node["sweeptype"] = rhs.sweeptype;
        node["sweepidx"] = rhs.sweepidx;
//        node["triggertype"] = rhs.triggertype;
        node["triggeridx"] = rhs.triggeridx;
        return node;
    }

    static bool decode(const Node& n, Cursor& rhs) {
        if(n.size() != 6) {
            return false;
        }
        Node node = n;
        rhs.xvalue =  node["xvalue"].as<int>();
        rhs.itemidx = node["itemidx"].as<int>();
//        rhs.locationtype = node["locationtype"].as<LocationType>();
        rhs.locationdelay = node["locationdelay"].as<double>();
//        rhs.repetitiontype = node["locationdelay"].as<RepetitionType>();
        rhs.repetitionidx = node["repetitionidx"].as<int>();
//        rhs.sweeptype = node["sweeptype"].as<SweepType>();
        rhs.sweepidx = node["sweepidx"].as<int>();
//        rhs.triggertype = node["triggertype"].as<TriggerType>();
        rhs.triggeridx = node["triggeridx"].as<int>();
        return true;
    }
};
}
#endif // CURSOR_H
