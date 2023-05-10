#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include "yaml.h"
#include "voltageprotocol.h"
#include "currentprotocol.h"

using namespace std;

struct Protocols {
    vector<VoltageProtocol> voltageprotocols;
    vector<CurrentProtocol> currentprotocols;
};

namespace YAML {
template<>
struct convert<Protocols>{
    static Node encode(const Protocols& rhs) {
        Node node;
        node["voltageprotocols"] = rhs.voltageprotocols;
        node["currentprotocols"] = rhs.currentprotocols;

        Node key;
        key["protocols"] = node;
        return key;
    }

    static bool decode(const Node& n, Protocols& rhs) {
        if(!n.IsMap() || !n["protocols"]) {
            return false;
        }
        Node node = n["protocols"];
        rhs.voltageprotocols = node["voltageprotocols"].as<vector<VoltageProtocol>>();
        rhs.currentprotocols = node["currentprotocols"].as<vector<CurrentProtocol>>();
        return true;
    }
};
}
#endif // PROTOCOLS_H
