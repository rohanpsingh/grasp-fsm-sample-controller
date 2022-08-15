cmake_minimum_required(VERSION 3.1)

set(CXX_DISABLE_WERROR 1)
set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME GraspFSM)
set(PROJECT_DESCRIPTION "GraspFSM")
set(PROJECT_URL "")

project(${PROJECT_NAME} CXX)

# Check if the project is built inside mc_rtc
if(NOT TARGET mc_rtc::mc_control)
  find_package(mc_rtc REQUIRED)
endif()
find_package(lipm_walking_controller REQUIRED)

add_subdirectory(src)

set(AROBASE "@")
configure_file(etc/GraspFSM.in.yaml "${CMAKE_CURRENT_BINARY_DIR}/etc/GraspFSM.yaml")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/etc/GraspFSM.yaml" DESTINATION "${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/etc")

