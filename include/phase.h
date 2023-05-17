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

namespace YAML {
typedef std::variant<VHold, VConst, VStepTStep, VRest, VRamp, VSin,
IHold, IConst, IStepTStep, IRest, IRamp, ISin,
RepSeq, RepSeqWithSteps, InfRepSeq, RepSeqScaled> Phase_t;

typedef enum PhaseIdxs {VHoldIdx, VConstIdx, VStepTStepIdx, VRestIdx, VRampIdx, VSinIdx,
                        IHoldIdx, IConstIdx, IStepTStepIdx, IRestIdx, IRampIdx, ISinIdx,
                        RepSeqIdx, RepSeqWithStepsIdx, InfRepSeqIdx, RepSeqScaledIdx} PhaseIdxs_t;

template<>
struct convert<Phase_t>{
    static Node encode(const Phase_t& rhs) {
        Node node;
        switch (rhs.index()) {
        case VHoldIdx:
            node = std::get<VHold>(rhs);
            break;
        case VConstIdx:
            node = std::get<VConst>(rhs);
            break;
        case VStepTStepIdx:
            node = std::get<VStepTStep>(rhs);
            break;
        case VRestIdx:
            node = std::get<VRest>(rhs);
            break;
        case VRampIdx:
            node = std::get<VRamp>(rhs);
            break;
        case VSinIdx:
            node = std::get<VSin>(rhs);
            break;
        case IHoldIdx:
            node = std::get<IHold>(rhs);
            break;
        case IConstIdx:
            node = std::get<IConst>(rhs);
            break;
        case IStepTStepIdx:
            node = std::get<IStepTStep>(rhs);
            break;
        case IRestIdx:
            node = std::get<IRest>(rhs);
            break;
        case IRampIdx:
            node = std::get<IRamp>(rhs);
            break;
        case ISinIdx:
            node = std::get<ISin>(rhs);
            break;
        case RepSeqIdx:
            node = std::get<RepSeq>(rhs);
            break;
        case RepSeqWithStepsIdx:
            node = std::get<RepSeqWithSteps>(rhs);
            break;
        case InfRepSeqIdx:
            node = std::get<InfRepSeq>(rhs);
            break;
        case RepSeqScaledIdx:
            node = std::get<RepSeqScaled>(rhs);
            break;
        }
        return node;
    }

    static bool decode(const Node& node, Phase_t& rhs) {
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
