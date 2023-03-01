#ifndef PHASE_H
#define PHASE_H
#include <variant>
#include <iostream>
#include <cursor.h>
#include "vramp.h"
#include "vconst.h"
#include "vstepstep.h"
#include "vsin.h"
#include "yaml.h"
#include "repseqwithsteps.h"
//REMEMBER TO ADD THE IMPLEMENTED PROTOCOL HERE
typedef variant<VConst, VRamp, VStepStep, VSin, RepSeqWithSteps> Phase;


namespace YAML {
template<>
struct convert<Phase>{
    static Node encode(const Phase& rhs) {
        Node node;
        switch (rhs.index()) {
            case 0:
                node = get<VConst>(rhs);
            break;
            case 1:
                node = get<VRamp>(rhs);
            break;
            case 2:
                node = get<VStepStep>(rhs);
            break;
            case 3:
                node = get<VSin>(rhs);
            break;
            case 4:
                node = get<RepSeqWithSteps>(rhs);
            break;
        }
        return node;
    }

    static bool decode(const Node& node, Phase& rhs) {
        if(!node.IsMap()) {
            return false;
        }
        if (node["vconst"]){
            rhs.emplace<VConst>(node.as<VConst>());
        }
        else if (node["vramp"]){
            rhs.emplace<VRamp>(node.as<VRamp>());
        }
        else if (node["vstepstep"]){
            rhs.emplace<VStepStep>(node.as<VStepStep>());
        }
        else if (node["vsin"]){
            rhs.emplace<VSin>(node.as<VSin>());
        }
        else if (node["repseqwithsteps"]){
            rhs.emplace<RepSeqWithSteps>(node.as<RepSeqWithSteps>());
        }
        return true;
    }
};
}

#endif // PHASE_H
