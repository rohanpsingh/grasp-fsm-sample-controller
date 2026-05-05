cmake_minimum_required(VERSION 3.1)

set(CXX_DISABLE_WERROR 1)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME GraspFSM)
set(PROJECT_DESCRIPTION "GraspFSM")
set(PROJECT_URL "")

project(${PROJECT_NAME} CXX)

# Check if the project is built inside mc_rtc
if(NOT TARGET mc_rtc::mc_control)
  find_package(mc_rtc REQUIRED)
endif()
# Pin BWC to a known-good minimum. Bump when validated against a newer release.
find_package(baseline_walking_controller 0.1.0 REQUIRED)

add_subdirectory(src)

set(AROBASE "@")

configure_file(etc/GraspFSM.in.yaml "${CMAKE_CURRENT_BINARY_DIR}/etc/GraspFSM.yaml" @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/etc/GraspFSM.yaml"
        DESTINATION "${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/etc")

configure_file(etc/mc_rtc.in.yaml "${CMAKE_CURRENT_BINARY_DIR}/etc/mc_rtc.yaml" @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/etc/mc_rtc.yaml"
        DESTINATION "${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/etc")

configure_file(etc/mc_mujoco.in.yaml "${CMAKE_CURRENT_BINARY_DIR}/etc/mc_mujoco.yaml" @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/etc/mc_mujoco.yaml"
        DESTINATION "${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/etc")

