#include "controller.h"

GraspFSM::GraspFSM(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: lipm_walking::Controller(rm, dt, config)
{

  mc_rtc::log::success("GraspFSM init done ");
}

void GraspFSM::reset(const mc_control::ControllerResetData & reset_data)
{
  lipm_walking::Controller::reset(reset_data);
}


