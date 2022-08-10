#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define FSMSampleController_DLLIMPORT __declspec(dllimport)
#  define FSMSampleController_DLLEXPORT __declspec(dllexport)
#  define FSMSampleController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define FSMSampleController_DLLIMPORT __attribute__((visibility("default")))
#    define FSMSampleController_DLLEXPORT __attribute__((visibility("default")))
#    define FSMSampleController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define FSMSampleController_DLLIMPORT
#    define FSMSampleController_DLLEXPORT
#    define FSMSampleController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef FSMSampleController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define FSMSampleController_DLLAPI
#  define FSMSampleController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef FSMSampleController_EXPORTS
#    define FSMSampleController_DLLAPI FSMSampleController_DLLEXPORT
#  else
#    define FSMSampleController_DLLAPI FSMSampleController_DLLIMPORT
#  endif // FSMSampleController_EXPORTS
#  define FSMSampleController_LOCAL FSMSampleController_DLLLOCAL
#endif // FSMSampleController_STATIC