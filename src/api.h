#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define GraspFSM_DLLIMPORT __declspec(dllimport)
#  define GraspFSM_DLLEXPORT __declspec(dllexport)
#  define GraspFSM_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define GraspFSM_DLLIMPORT __attribute__((visibility("default")))
#    define GraspFSM_DLLEXPORT __attribute__((visibility("default")))
#    define GraspFSM_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define GraspFSM_DLLIMPORT
#    define GraspFSM_DLLEXPORT
#    define GraspFSM_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef GraspFSM_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define GraspFSM_DLLAPI
#  define GraspFSM_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef GraspFSM_EXPORTS
#    define GraspFSM_DLLAPI GraspFSM_DLLEXPORT
#  else
#    define GraspFSM_DLLAPI GraspFSM_DLLIMPORT
#  endif // GraspFSM_EXPORTS
#  define GraspFSM_LOCAL GraspFSM_DLLLOCAL
#endif // GraspFSM_STATIC