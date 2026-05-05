# grasp-fsm-sample-controller

<div align="center">
      <a href="https://youtu.be/7GmmAW5C20o">
     <img src="assets/demo.gif"
      alt="Demo video"
      style="width:100%;">
      </a>
</div>


### Notes

This controller was previously built on top of [LIPM-Walking](https://github.com/jrl-umi3218/lipm_walking_controller) and has since been ported to use [BaselineWalkingController](https://github.com/isri-aist/BaselineWalkingController) for footstep planning and walking.

The scene assumes a `longtable` object and a `tallbox` (a box of `size="0.02 0.06 0.15"` and `noslip_iterations="3"`); both are shipped in `etc/mc_mujoco.in.yaml` and installed for you (see Launch).

### Tested with

| Dependency | Commit |
|---|---|
| [BaselineWalkingController](https://github.com/isri-aist/BaselineWalkingController) | [`9cba7e2`](https://github.com/isri-aist/BaselineWalkingController/commit/9cba7e2fcc95b990774599f405471b86cc0f9e07) |
| [CentroidalControlCollection](https://github.com/isri-aist/CentroidalControlCollection) | [`a874f6a`](https://github.com/isri-aist/CentroidalControlCollection/commit/a874f6a09e4f1431509c166fb622af25781fe396) |
| [ForceControlCollection](https://github.com/isri-aist/ForceControlCollection) | [`55de511`](https://github.com/isri-aist/ForceControlCollection/commit/55de5119347987e9e3bc76783aec439748202cf5) |
| [TrajectoryCollection](https://github.com/isri-aist/TrajectoryCollection) | [`3f18e7a`](https://github.com/isri-aist/TrajectoryCollection/commit/3f18e7a8748e40dbccdd28b0b3ec98353a33f58d) |
| [QpSolverCollection](https://github.com/isri-aist/QpSolverCollection) | [`42cb586`](https://github.com/isri-aist/QpSolverCollection/commit/42cb58674e692bea0bf64c7ab7a4a80137023aee) |
| [NMPC](https://github.com/isri-aist/NMPC) | [`d88792c`](https://github.com/isri-aist/NMPC/commit/d88792ccb1a77e78bca7572ba2afd35b0418cd71) |

### Build and Install

```sh
$ git clone --recursive git@github.com:rohanpsingh/grasp-fsm-sample-controller.git
$ cd grasp-fsm-sample-controller
$ mkdir build && cd build
$ cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
$ make install
```

### Launch

Copy the shipped configs into your mc_rtc user config dir (one-time setup):

```sh
$ mkdir -p ~/.config/mc_rtc/mc_mujoco
$ cp <install-prefix>/lib/mc_controller/etc/mc_rtc.yaml    ~/.config/mc_rtc/mc_rtc.yaml
$ cp <install-prefix>/lib/mc_controller/etc/mc_mujoco.yaml ~/.config/mc_rtc/mc_mujoco/mc_mujoco.yaml
```

Then fire up `mc-mujoco` (or any other interface):

```sh
$ mc_mujoco
```

All states and transitions should occur automatically.
