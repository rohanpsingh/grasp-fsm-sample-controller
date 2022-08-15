#pragma once

#include <mc_control/mc_controller.h>
#include <lipm_walking/Controller.h>

#include "api.h"

struct GraspFSM_DLLAPI GraspFSM : public lipm_walking::Controller
{
    GraspFSM(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);
    void reset(const mc_control::ControllerResetData & reset_data) override;
private:
    mc_rtc::Configuration config_;
};
