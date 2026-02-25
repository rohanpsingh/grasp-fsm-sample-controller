#pragma once

#include <mc_control/mc_controller.h>
#include <BaselineWalkingController/BaselineWalkingController.h>

#include "api.h"

struct GraspFSM_DLLAPI GraspFSM : public BWC::BaselineWalkingController
{
    GraspFSM(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);
    void reset(const mc_control::ControllerResetData & reset_data) override;

private:
    /** \brief Merge robot-specific state overrides from robots/<name>/states into top-level states.
     *
     *  FSM states are parsed by mc_control::fsm::Controller before BWC merges
     *  robot-specific config, so we pre-merge here to allow per-robot frame
     *  names and target positions in the grasp states.
     */
    static mc_rtc::Configuration prepareConfig(mc_rbdyn::RobotModulePtr rm,
                                               const mc_rtc::Configuration & config);

    mc_rtc::Configuration config_;
};
