#include <iostream>
#include <fstream>

#include "protocols.h"

#include <assert.h>

using namespace std;
using namespace YAML;

int main()
{
//    Struct built normally
    VoltageCtrl c {"v1", 1, 100};
    NaturalNumCtrl c2 {"n1", 2, 5};

    VConst vc = {0,0,100,0,true};
    VConst vc2 = {10,0,1000,0,false};
    VRamp vr = {0,0,100,0,100,0,true};
    VStepTStep vstepstep = {100,0,0,0,100,0,100,0,true};
    VSin vsin = {0,0,100,0,10,0,true};

    RepSeqWithSteps rsws = {2,0,2,0,3.3,0,10,0};

    Cursor cr = {110.0, 1, CursorLocationFromStart, 10.0, CursorRepetitionAll, 1, CursorSweepAll, 1, CursorTriggerNone, 1};
    Cursor cr1 = {60.0, 0, CursorLocationToEnd, 40.0, CursorRepetitionOne, 0, CursorSweepLast, 4, CursorTriggerRising, 1};

    Analysis a = {NoiseReport, {1, 2}};

    VoltageProtocol vp = {"p1",1, GapFree, 0, true, 1, "10 nA", "None", "None",{c, c2}, {vc,vc2,vr,vstepstep,vsin, rsws}, {cr, cr1}, {a}};
    VoltageProtocol vp1 = {"p2",1, Episodic, 0, true, 5, "10 nA", "None", "None",{c, c2}, {vc,vc2,vr,vsin, rsws}, {cr1}, {}};
    Protocols ps;
    ps.voltageprotocols = {vp, vp1};
    YAML::Node node;
    node = ps;

    std::ofstream fout("p.yaml");
    fout << node;
    fout.close();

//    Read yaml file
    YAML::Node node_taken_from_file = YAML::LoadFile("p.yaml");
    Protocols ps_from_file = node_taken_from_file.as<Protocols>();

    cout << ps_from_file.voltageprotocols[1].operationmode << endl;

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
