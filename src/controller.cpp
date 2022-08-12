#include "controller.h"

FSMSampleController::FSMSampleController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: lipm_walking::Controller(rm, dt, config)
{

  mc_rtc::log::success("FSMSampleController init done ");
}

void FSMSampleController::reset(const mc_control::ControllerResetData & reset_data)
{
  lipm_walking::Controller::reset(reset_data);
}


