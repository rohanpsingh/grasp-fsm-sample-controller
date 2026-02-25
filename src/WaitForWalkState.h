#pragma once

#include <BaselineWalkingController/State.h>

/** \brief FSM state that waits until the footstep queue is empty. */
struct WaitForWalkState : BWC::State
{
  void start(mc_control::fsm::Controller & ctl) override;
  bool run(mc_control::fsm::Controller & ctl) override;
  void teardown(mc_control::fsm::Controller & ctl) override;
};
