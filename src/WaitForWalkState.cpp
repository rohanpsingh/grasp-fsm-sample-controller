#include "WaitForWalkState.h"

#include <BaselineWalkingController/BaselineWalkingController.h>
#include <BaselineWalkingController/FootManager.h>

void WaitForWalkState::start(mc_control::fsm::Controller & _ctl)
{
  State::start(_ctl);
  output("OK");
}

bool WaitForWalkState::run(mc_control::fsm::Controller &)
{
  return ctl().footManager_->footstepQueue().empty();
}

void WaitForWalkState::teardown(mc_control::fsm::Controller &) {}

EXPORT_SINGLE_STATE("WaitForWalk", WaitForWalkState)
