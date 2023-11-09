#include "include/hyperbernate.h"

#include <filesystem>
#include <fstream>
#include <string>

using namespace Hyperbernate;

bool Hyperbernate::hasSuspendToDiskSupport() {
  std::filesystem::path acpi_sleep_path{Hyperbernate::ARCH_MEM_SLEEP_CONFIG_PATH};
  bool acpi_settings_exist = std::filesystem::exists(acpi_sleep_path);
  return acpi_settings_exist;
}

std::string Hyperbernate::toggleSuspendToDisk() {
  bool hasHibernateOn = isHyperbernateEnabled();
  std::string sleepMode = get_file_contents(Hyperbernate::ACPI_MODE_PATH);
  if (!hasHibernateOn) {
    // open the ACPI sleep mode file in append mode
    std::ofstream fileOUt(ACPI_MODE_PATH, std::ios::app);
    fileOUt << "deep" << std::endl;
    fileOUt.close();
    return sleepMode;
  } else {
    // open the ACPI sleep mode file in append mode
    std::ofstream fileOUt(ACPI_MODE_PATH, std::ios::app);
    fileOUt << "sleep" << std::endl;
    fileOUt.close();
    return sleepMode;  // toggle
  }
}

bool Hyperbernate::isHyperbernateEnabled() {
  ACPISleepMode mode = getACPIsleepMode();
  switch (mode) {
    case 0:
      return false;
    case 1:
      return true;
    default:
      break;
  }
}

LidStatus Hyperbernate::getLidStatus() {
  std::string laptopLidState = get_file_contents(Hyperbernate::LAPTOP_LID_STATE_PATH);
  if (laptopLidState == "state:      open")
    return Hyperbernate::LidStatus::OPEN;
  else
    return Hyperbernate::LidStatus::CLOSED;
}

ACPISleepMode Hyperbernate::getACPIsleepMode() {
  std::string ACPIMode = get_file_contents(Hyperbernate::ACPI_MODE_PATH);
  if (ACPIMode == "[s2idle] deep")
    return Hyperbernate::ACPISleepMode::SLEEP;  // ['s2idle'] enabled in this case
  else if (ACPIMode == "[deep] s2idle")
    return Hyperbernate::ACPISleepMode::DEEP;  // ['deep'] enabled in this case
}

// From Gist: https://gist.github.com/arrieta/97438876b9db784beffb0de8d27f1dc9
std::string Hyperbernate::get_file_contents(std::string path) {
  std::ifstream fp(path, std::ios::in | std::ios::binary);
  return {std::istreambuf_iterator<char>{fp}, std::istreambuf_iterator<char>{}};
}
