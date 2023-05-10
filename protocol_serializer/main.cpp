#include <iostream>
#include "vconst.h"
#include "vramp.h"
#include "vsteptstep.h"
#include "vsin.h"
#include "voltageprotocol.h"
#include "protocols.h"
#include "repseqwithsteps.h"
#include<fstream>

#include <assert.h>

using namespace std;

int main()
{
//    Struct built normally
    VConst vc = {0,0,100,0,true};
    VConst vc2 = {10,0,1000,0,false};
    VRamp vr = {0,0,100,0,100,0,true};
    VStepTStep vstepstep = {100,0,0,0,100,0,100,0,true};
    VSin vsin = {0,0,100,0,10,0,true};
    RepSeqWithSteps rsws = {2,0,2,0,3.3,0,10,0};
    VoltageCtrl c {"v1", 1, 100};
    NaturalNumCtrl c2 {"n1", 2, 5};
    VoltageProtocol vp = {"p1",1, 1, 0, true, 5, "10 nA", "None", "None",{c, c2}, {vc,vc2,vr,vstepstep,vsin, rsws}};
    VoltageProtocol vp1 = {"p2",1, 1, 0, true, 5, "10 nA", "None", "None",{c, c2}, {vc,vc2,vr,vsin, rsws}};
    Protocols ps;
    ps.voltageprotocols = {vp, vp1};
    YAML::Node node;
    node = ps;

    std::ofstream fout("p.yaml");
    fout << node;
    fout.close();

//    Read yaml file and the node can be used as a VoltageProtocol
    YAML::Node node_taken_from_file = YAML::LoadFile("p.yaml");
    Protocols ps_from_file = node_taken_from_file.as<Protocols>();

    for(variant v: ps_from_file.voltageprotocols[0].phases){
        switch (v.index()) {
        case 1: {
            VConst p = get<VConst>(v);
            cout << p.t0 << endl;
            break;
        }
        default:
            cout << "da implementare" << endl;
            break;
        }
    }
    return 0;
}
