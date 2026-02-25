#include "controller.h"

mc_rtc::Configuration GraspFSM::prepareConfig(mc_rbdyn::RobotModulePtr rm,
                                              const mc_rtc::Configuration & config)
{
  mc_rtc::Configuration cfg(config);
  const std::string & robotName = rm->name;
  if(cfg.has("robots") && cfg("robots").has(robotName) && cfg("robots")(robotName).has("states"))
  {
    mc_rtc::log::info("[GraspFSM] Merging robot-specific state overrides for {}", robotName);
    cfg("states").load(cfg("robots")(robotName)("states"));
  }
  return cfg;
}

GraspFSM::GraspFSM(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: BWC::BaselineWalkingController(rm, dt, prepareConfig(rm, config))
{
  mc_rtc::log::success("GraspFSM init done ");
}

void GraspFSM::reset(const mc_control::ControllerResetData & reset_data)
{
  BWC::BaselineWalkingController::reset(reset_data);
}
