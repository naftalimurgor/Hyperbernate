#pragma once
#include <string>

namespace Hyperbernate {
    /**
     Standard path for 
    */
    const std::string ARCH_MEM_SLEEP_PATH = "/sys/power/mem_sleep";
    bool hasSuspendToDiskSupport();
    std::string toggleSuspendToDisk();
    bool hyperbernateEnabled();

}  // namespace Hyperbernate
