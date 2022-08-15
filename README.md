# grasp-fsm-sample-controller

![Screenshot from 2022-08-15 02-33-07](https://user-images.githubusercontent.com/16384313/184548325-4557783a-e26f-443c-88fe-304b90aa7ca4.png)
---

### Notes

Assumes `longtable` and `box` objects are placed in the mujoco scene as follows: 


```
objects:
  box:
    name: "box"
    init_pos:
      translation: [3.1, 0, 0.9]
      rotation: [0, 0, 0]
  longtable:
    name: "longtable"
    init_pos:
      translation: [3.5, 0, 0.8]
      rotation: [3.14, 0, 0]
```
There is no need to add these objects to `mc-rtc`.  
You may need to apply the following patch to LIPM-Walking to set the desired target:
```
diff --git a/include/lipm_walking/PlanInterpolator.h b/include/lipm_walking/PlanInterpolator.h
index 8db8c9f..b8f6012 100644
--- a/include/lipm_walking/PlanInterpolator.h
+++ b/include/lipm_walking/PlanInterpolator.h
@@ -342,7 +342,7 @@ private:
   SE2d lastBackwardTarget_ = {-0.5, 0., 0.}; /**< Last target for a custom_backward plan */
   SE2d lastForwardTarget_ = {0.5, 0., 0.}; /**< Last target for a custom_forward plan */
   SE2d lastLateralTarget_ = {0.0, 0.3, 0.}; /**< Last target for a custom_lateral plan */
-  SE2d targetPose_ = {0.5, 0., 0.}; /**< Target SE2 transform in the horizontal plane */
+  SE2d targetPose_ = {2.5, 0., 0.}; /**< Target SE2 transform in the horizontal plane */
   bool startWithRightFootstep_ = true;
   double desiredStepAngle_ = 10. * M_PI / 180.; // [rad]
   double desiredStepLength_ = 0.2; // [m]

```

### Build and Install

```sh
$ git clone --recursive git@github.com:rohanpsingh/grasp-fsm-sample-controller.git
$ cd mc_mujoco
$ mkdir build && cd build
$ cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
$ make install
```

### Launch
Edit `mc-rtc` config file:
```yaml
MainRobot: HRP5P
Enabled: GraspFSM
Timestep: 0.002
```

```sh
$ mc_mujoco
```

All states and transitions should occur automatically.


