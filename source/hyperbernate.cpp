#include <hyperbernate/hyperbernate.h>

#include <filesystem>
#include <string>

using namespace Hyperbernate;

bool Hyperbernate::hasSuspendToDiskSupport()
{
  std::filesystem::path acpi_sleep_path{Hyperbernate::ARCH_MEM_SLEEP_PATH};
  std::filesystem::exists(acpi_sleep_path) ? true : false;
}

std::string Hyperbernate::toggleSuspendToDisk() 
{
  // write to disk
  // alter the mem_sleep file
  // listen for lid close events > 5 minutes
  // toggle hibernate
  std::filesystem::path acpi_sleep_path{Hyperbernate::ARCH_MEM_SLEEP_PATH};
}