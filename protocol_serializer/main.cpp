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
    VConst vc = {0,0,100,0,true};
    VConst vc2 = {10,10,1000,10,false};
    VRamp vr = {0,0,100,0,100,0,true};
    VStepStep vstepstep = {100,0,0,0,100,0,true};
    VSin vsin = {0,0,100,0,10,0,true};

//    Cursor c = {90, 0, LocationType::from_start, 90.4, RepetitionType::all, 1, SweepType::all, 1, TriggerType::none, 1 };
    Cursor c = {90, 0, 90.4, 1, 1, 1 };
    Cursor c2 = {30, 30, 390.4, 31, 31, 31 };
    VoltageProtocol vp = {{vc,vc2,vr,vstepstep,vsin}, {c, c2}};
    YAML::Node node;
    node = vp;

//    std::ofstream fout("C:\\Users\\lucar\\p.yaml");
//    fout << node;

    YAML::Node node_taken_from_file = YAML::LoadFile("C:\\Users\\lucar\\p.yaml");
    VoltageProtocol vp_from_file = node_taken_from_file.as<VoltageProtocol>();
    cout << vp_from_file.cursors[1].itemidx << endl;
    return 0;
}
