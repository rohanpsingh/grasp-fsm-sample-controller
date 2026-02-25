set(controller_SRC
  controller.cpp
)

set(controller_HDR
  controller.h
)

add_library(${PROJECT_NAME} SHARED ${controller_SRC} ${controller_HDR})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DGraspFSM_EXPORTS")
target_link_libraries(${PROJECT_NAME} PUBLIC baseline_walking_controller::BaselineWalkingController)
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION "${MC_RTC_LIBDIR}"
  LIBRARY DESTINATION "${MC_RTC_LIBDIR}"
  RUNTIME DESTINATION bin)

add_controller(${PROJECT_NAME}_controller lib.cpp "")
target_link_libraries(${PROJECT_NAME}_controller PUBLIC ${PROJECT_NAME})

add_fsm_state(WaitForWalkState WaitForWalkState.cpp WaitForWalkState.h)
target_link_libraries(WaitForWalkState PUBLIC baseline_walking_controller::BaselineWalkingController)
