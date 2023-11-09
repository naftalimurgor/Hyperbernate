#pragma once
#include <string>

namespace Hyperbernate {
  /**
   * https://wiki.archlinux.org/title/Power_management/Suspend_and_hibernate
   * Standard path for mem_sleep settings supported by ACPI
   */
  const std::string ARCH_MEM_SLEEP_CONFIG_PATH = "/sys/power/mem_sleep";
  const std::string ACPI_MODE_PATH = "/sys/power/mem_sleep";
  /**
   * ACPI laptop lid to monitor state | closed or Open
   */
  const std::string LAPTOP_LID_STATE_PATH = "/proc/acpi/button/lid/LID/state";

  /**
   * Enum for monitoring Lid status, CLOSED = 1, OPEN = 0
   */
  enum LidStatus { CLOSED, OPEN };
  /**
   * Enum for monitoring ACPI Kernel value, normally set permanently by Kernel
   * parameter:mem_sleep_default=deep
   */
  enum ACPISleepMode { SLEEP, DEEP };  // Sleep = "Suspend to RAM", DEEP = "suspend to disk"

  bool hasSuspendToDiskSupport();

  std::string toggleSuspendToDisk();

  // @todo: Check if hardware supports S3 sleep by default
  std::string toggleSuspendToDiskOFF();
  bool isHyperbernateEnabled();
  LidStatus getLidStatus();
  std::string get_file_contents(std::string path);
  ACPISleepMode getACPIsleepMode();

}  // namespace Hyperbernate
