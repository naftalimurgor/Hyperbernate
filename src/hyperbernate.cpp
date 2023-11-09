#include "include/hyperbernate.h"

#include <filesystem>
#include <fstream>
#include <string>

using namespace Hyperbernate;

bool Hyperbernate::hasSuspendToDiskSupport() {
  std::filesystem::path acpi_sleep_path{Hyperbernate::ARCH_MEM_SLEEP_PATH};
  std::filesystem::exists(acpi_sleep_path) ? true : false;
}

std::string Hyperbernate::toggleSuspendToDiskON() {
  std::filesystem::path acpi_sleep_path{Hyperbernate::ARCH_MEM_SLEEP_PATH};
}

bool Hyperbernate::hyperbernateEnabled() {
  ACPISleepMode mode = Hyperbernate::getACPIsleepMode();
  switch (mode) {
    case 0:
      return false;
    case 1:
      return true;
    default:
      break;
  }
}

LidStatus getLidStatus() {
  std::string laptopLidState = Hyperbernate::get_file_contents(Hyperbernate::LAPTOP_LID_STATE_PATH);
  laptopLidState == "state:      open" ? Hyperbernate::LidStatus::OPEN
                                       : Hyperbernate::LidStatus::CLOSED;
}

ACPISleepMode getACPIsleepMode() {
  std::string ACPIMode = Hyperbernate::get_file_contents(Hyperbernate::ARCH_MEM_SLEEP_PATH);
  if (ACPIMode == "[s2idle] deep") {
    return Hyperbernate::ACPISleepMode::SLEEP;  // ['s2idle'] enabled in this case
  } else if (ACPIMode == "[deep] s2idle") {
    return Hyperbernate::ACPISleepMode::DEEP;  // ['deep'] enabled in this case
  }
}

// From Gist: https://gist.github.com/arrieta/97438876b9db784beffb0de8d27f1dc9
std::string get_file_contents(std::string path) {
  std::ifstream fp(path, std::ios::in | std::ios::binary);
  return {std::istreambuf_iterator<char>{fp}, std::istreambuf_iterator<char>{}};
}
