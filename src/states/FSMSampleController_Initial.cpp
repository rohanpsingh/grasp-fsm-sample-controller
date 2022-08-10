#include "FSMSampleController_Initial.h"

#include "../FSMSampleController.h"

void FSMSampleController_Initial::configure(const mc_rtc::Configuration & config)
{
}

void FSMSampleController_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<FSMSampleController &>(ctl_);
}

bool FSMSampleController_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<FSMSampleController &>(ctl_);
  output("OK");
  return true;
}

void FSMSampleController_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<FSMSampleController &>(ctl_);
}

EXPORT_SINGLE_STATE("FSMSampleController_Initial", FSMSampleController_Initial)
