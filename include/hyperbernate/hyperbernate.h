#pragma once
#include <string>

namespace Hyperbernate {
  /**
   * Standard path for mem_sleep settings supported by ACPI

  */
  const std::string ARCH_MEM_SLEEP_PATH = "/sys/power/mem_sleep";
  const std::string LAPTOP_LID_STATE_PATH = "/proc/acpi/button/lid/LID/state";
  enum LidStatus { CLOSED, OPEN };

  bool hasSuspendToDiskSupport();

  std::string toggleSuspendToDisk();

  bool hyperbernateEnabled();
  LidStatus getLidStatus();

}  // namespace Hyperbernate
