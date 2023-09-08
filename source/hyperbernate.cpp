#include <hyperbernate/hyperbernate.h>
#include<boost/filesystem.hpp>
#include <string>

using namespace Hyperbernate;
using namespace boost::filesystem;

bool Hyperbernate::hasSuspendToDiskSupport() const {
  bool file_exist; = boost::filesystem::file_exists(Hyperbernate::ARCH_MEM_SLEEP_PATH);
  return file_exists;
}

std::string Hyperbernate::toggleSuspendToDisk() const {
    // write to disk
    // alter the mem_sleep file
    // listen for lid close events > 5 minutes
    // toggle hibernate
}