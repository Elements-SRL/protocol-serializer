#ifndef PROT_SER_GLOBAL_DEFINES_H
#define PROT_SER_GLOBAL_DEFINES_H

#include <string>
#include <vector>
#include <yaml.h>

namespace YAML {
typedef enum OperationMode {
    GapFree,
    Episodic,
    OperationModesNum
} OperationMode_t;

typedef enum CursorLocationType {
    CursorLocationFromStart,
    CursorLocationToEnd,
    CursorLocationsNum
} CursorLocationType_t;

typedef enum CursorRepetitionType {
    CursorRepetitionAll,
    CursorRepetitionLast,
    CursorRepetitionOne,
    CursorRepetitionsNum
} CursorRepetitionType_t;

typedef enum CursorSweepType {
    CursorSweepAll,
    CursorSweepLast,
    CursorSweepOne,
    CursorSweepsNum
} CursorSweepType_t;

typedef enum CursorTriggerType {
    CursorTriggerNone,
    CursorTriggerRising,
    CursorTriggerFalling,
    CursorTriggersNum
} CursorTriggerType_t;

typedef enum AnalysisType {
    ResistanceEstimation,
    PipetteCapacitanceEstimation,
    MembraneEstimation,
    AnalysisNum
} AnalysisType_t;

static std::vector <std::string> operationModeStrings = {"Gap Free", "Episodic"};
static std::vector <std::string> cursorLocationStrings = {"from start", "to end"};
static std::vector <std::string> cursorRepetitionStrings = {"all", "last", "one"};
static std::vector <std::string> cursorSweepStrings = {"all", "last", "one"};
static std::vector <std::string> cursorTriggerStrings = {"none", "rising", "falling"};
static std::vector <std::string> analysisStrings = {"resistance estimation", "pipette capacitance estimation", "membrane estimation"};
}

#endif // PROT_SER_GLOBAL_DEFINES_H
