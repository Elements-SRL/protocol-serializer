#include <iostream>
#include "vconst.h"
#include "vramp.h"
#include "vstepstep.h"
#include "cursor.h"
#include "vsin.h"
#include "voltage_protocol.h"
#include<fstream>


using namespace std;

int main()
{
//    Struct built normally
    VConst vc = {0,0,100,0,true};
    VConst vc2 = {10,10,1000,10,false};
    VRamp vr = {0,0,100,0,100,0,true};
    VStepStep vstepstep = {100,0,0,0,100,0,true};
    VSin vsin = {0,0,100,0,10,0,true};

//    Cursor c = {90, 0, LocationType::from_start, 90.4, RepetitionType::all, 1, SweepType::all, 1, TriggerType::none, 1 };
    Cursor c = {90, 0, 90.4, 1, 1, 1 };
    Cursor c2 = {30, 30, 390.4, 31, 31, 31 };
    VoltageProtocol vp = {"p1",1, 0, 1, true, 5, 50,50,35,{vc,vc2,vr,vstepstep,vsin}, {c, c2}};
    YAML::Node node;
    node = vp;

//     Decomment these lines if you want to save to disk
//     WARNING: changes will be saved only at the end of the execution,
//     so comment the last lines or they will try to import an empty file

    std::ofstream fout("p.yaml");
    fout << node;
    fout.close();

//    Read yaml file and the node can be used as a VoltageProtocol
    YAML::Node node_taken_from_file = YAML::LoadFile("p.yaml");
    VoltageProtocol vp_from_file = node_taken_from_file.as<VoltageProtocol>();
    cout << vp_from_file.name << endl;
    return 0;
}
