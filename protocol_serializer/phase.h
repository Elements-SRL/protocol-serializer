#ifndef PHASE_H
#define PHASE_H

#include <variant>

#include "vhold.h"
#include "vconst.h"
#include "vsteptstep.h"
#include "vrest.h"
#include "vramp.h"
#include "vsin.h"
#include "ihold.h"
#include "iconst.h"
#include "isteptstep.h"
#include "irest.h"
#include "iramp.h"
#include "isin.h"
#include "repseq.h"
#include "repseqwithsteps.h"
#include "infrepseq.h"
#include "repseqscaled.h"
#include "yaml.h"

typedef variant<VHold, VConst, VStepTStep, VRest, VRamp, VSin,
IHold, IConst, IStepTStep, IRest, IRamp, ISin,
RepSeq, RepSeqWithSteps, InfRepSeq, RepSeqScaled> Phase;

namespace YAML {
template<>
struct convert<Phase>{
    static Node encode(const Phase& rhs) {
        Node node;
        switch (rhs.index()) {
        case 0:
            node = get<VHold>(rhs);
            break;
        case 1:
            node = get<VConst>(rhs);
            break;
        case 2:
            node = get<VStepTStep>(rhs);
            break;
        case 3:
            node = get<VRest>(rhs);
            break;
        case 4:
            node = get<VRamp>(rhs);
            break;
        case 5:
            node = get<VSin>(rhs);
            break;
        case 6:
            node = get<IHold>(rhs);
            break;
        case 7:
            node = get<IConst>(rhs);
            break;
        case 8:
            node = get<IStepTStep>(rhs);
            break;
        case 9:
            node = get<IRest>(rhs);
            break;
        case 10:
            node = get<IRamp>(rhs);
            break;
        case 11:
            node = get<ISin>(rhs);
            break;
        case 12:
            node = get<RepSeq>(rhs);
            break;
        case 13:
            node = get<RepSeqWithSteps>(rhs);
            break;
        case 14:
            node = get<InfRepSeq>(rhs);
            break;
        case 15:
            node = get<RepSeqScaled>(rhs);
            break;
        }
        return node;
    }

    static bool decode(const Node& node, Phase& rhs) {
        if(!node.IsMap()) {
            return false;
        }
        if (node["vhold"]){
            rhs.emplace<VHold>(node.as<VHold>());

        } else if (node["vconst"]){
            rhs.emplace<VConst>(node.as<VConst>());

        } else if (node["vsteptstep"]){
            rhs.emplace<VStepTStep>(node.as<VStepTStep>());

        } else if (node["vrest"]){
            rhs.emplace<VRest>(node.as<VRest>());

        } else if (node["vramp"]){
            rhs.emplace<VRamp>(node.as<VRamp>());

        } else if (node["vsin"]){
            rhs.emplace<VSin>(node.as<VSin>());

        } else if (node["ihold"]){
            rhs.emplace<IHold>(node.as<IHold>());

        } else if (node["iconst"]){
            rhs.emplace<IConst>(node.as<IConst>());

        } else if (node["isteptstep"]){
            rhs.emplace<IStepTStep>(node.as<IStepTStep>());

        } else if (node["irest"]){
            rhs.emplace<IRest>(node.as<IRest>());

        } else if (node["iramp"]){
            rhs.emplace<IRamp>(node.as<IRamp>());

        } else if (node["isin"]){
            rhs.emplace<ISin>(node.as<ISin>());

        } else if (node["repseq"]){
            rhs.emplace<RepSeq>(node.as<RepSeq>());

        } else if (node["repseqwithsteps"]){
            rhs.emplace<RepSeqWithSteps>(node.as<RepSeqWithSteps>());

        } else if (node["infrepseq"]){
            rhs.emplace<InfRepSeq>(node.as<InfRepSeq>());

        } else if (node["repseqscaled"]){
            rhs.emplace<RepSeqScaled>(node.as<RepSeqScaled>());
        }
        return true;
    }
};
}
#endif // PHASE_H
