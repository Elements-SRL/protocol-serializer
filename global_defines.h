#ifndef GLOBAL_DEFINES_H
#define GLOBAL_DEFINES_H

#include <string>
#include <vector>
#include <yaml.h>

using namespace std;

namespace YAML {
enum OperationMode {
    GapFree,
    Episodic,
    OperationModesNum
};

enum CursorLocationType {
    CursorLocationFromStart,
    CursorLocationToEnd,
    CursorLocationsNum
};

enum CursorRepetitionType {
    CursorRepetitionAll,
    CursorRepetitionLast,
    CursorRepetitionOne,
    CursorRepetitionsNum
};

enum CursorSweepType {
    CursorSweepAll,
    CursorSweepLast,
    CursorSweepOne,
    CursorSweepsNum
};

enum CursorTriggerType {
    CursorTriggerNone,
    CursorTriggerRising,
    CursorTriggerFalling,
    CursorTriggersNum
};

enum AnalysisType {
    NoiseReport,
    Histogram,
    Spectrum,
    MembraneTest,
    IVGraph,
    ResistanceEstimation,
    APThreshold,
    APStatistics,
    AnalysisNum
};

static vector <string> operationModeStrings = {"Gap Free", "Episodic"};
static vector <string> cursorLocationStrings = {"from start", "to end"};
static vector <string> cursorRepetitionStrings = {"all", "last", "one"};
static vector <string> cursorSweepStrings = {"all", "last", "one"};
static vector <string> cursorTriggerStrings = {"none", "rising", "falling"};
static vector <string> analysisStrings = {"noisereport", "histogram", "spectrum", "membranetest", "ivgraph", "resistanceestimation", "apthreshold", "apstatistics"};
}

#endif // GLOBAL_DEFINES_H
