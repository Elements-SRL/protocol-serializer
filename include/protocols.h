#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include "yaml.h"
#include "voltageprotocol.h"
#include "currentprotocol.h"

namespace YAML {
typedef struct Protocols {
    std::vector<VoltageProtocol_t> voltageprotocols;
    std::vector<CurrentProtocol_t> currentprotocols;

//    void addProtocol(VoltageProtocol_t newProtocol);
//    void addProtocol(CurrentProtocol_t newProtocol);
//    void replaceProtocol(VoltageProtocol_t newProtocol);
//    void replaceProtocol(CurrentProtocol_t newProtocol);
    std::vector <std::string> getVoltageProtocolsNames();
    std::vector <std::string> getCurrentProtocolsNames();
} Protocols_t;

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
        rhs.voltageprotocols = node["voltageprotocols"].as<std::vector<VoltageProtocol>>();
        rhs.currentprotocols = node["currentprotocols"].as<std::vector<CurrentProtocol>>();
        return true;
    }
};
}
#endif // PROTOCOLS_H
