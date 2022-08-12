#pragma once

#include <mc_control/mc_controller.h>
#include <lipm_walking/Controller.h>

#include "api.h"

struct FSMSampleController_DLLAPI FSMSampleController : public lipm_walking::Controller
{
    FSMSampleController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);
    void reset(const mc_control::ControllerResetData & reset_data) override;
private:
    mc_rtc::Configuration config_;
};
