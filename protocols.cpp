#include "protocols.h"

namespace YAML {
void Protocols::addProtocol(VoltageProtocol_t newProtocol) {
    voltageprotocols.push_back(newProtocol);
}

void Protocols::addProtocol(CurrentProtocol_t newProtocol) {
    currentprotocols.push_back(newProtocol);
}

void Protocols::replaceProtocol(VoltageProtocol_t newProtocol) {
    bool replaced = false;
    for (unsigned int idx = 0; idx < voltageprotocols.size(); idx++) {
        if (voltageprotocols[idx].name == newProtocol.name) {
            voltageprotocols[idx] = newProtocol;
            replaced = true;
        }
    }

    if (!replaced) {
        addProtocol(newProtocol);
    }
}

void Protocols::replaceProtocol(CurrentProtocol_t newProtocol) {
    bool replaced = false;
    for (unsigned int idx = 0; idx < currentprotocols.size(); idx++) {
        if (currentprotocols[idx].name == newProtocol.name) {
            currentprotocols[idx] = newProtocol;
            replaced = true;
        }
    }

    if (!replaced) {
        addProtocol(newProtocol);
    }
}

std::vector <std::string> Protocols::getVoltageProtocolsNames() {
    std::vector <std::string> names;
    for (unsigned int idx = 0; idx < voltageprotocols.size(); idx++) {
        names.push_back(voltageprotocols[idx].name);
    }
    return names;
}

std::vector <std::string> Protocols::getCurrentProtocolsNames() {
    std::vector <std::string> names;
    for (unsigned int idx = 0; idx < currentprotocols.size(); idx++) {
        names.push_back(currentprotocols[idx].name);
    }
    return names;
}
}
