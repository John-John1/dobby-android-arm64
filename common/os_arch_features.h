#pragma once
#include <sys/mman.h>
#include <unistd.h>

// Forward declarations for Android build
class OSMemory {
public:
    static int PageSize() { return sysconf(_SC_PAGESIZE); }
    static void *Allocate(size_t size, int access);
    static bool SetPermission(void *address, size_t size, int permission);
    static bool Free(void *address, size_t size);
};

enum MemoryPermission { kNoAccess = 0, kRead = 1, kWrite = 2, kExecute = 4, kReadWrite = 3, kReadExecute = 5, kReadWriteExecute = 7 };
static const int kReadExecute = 5;

#include <sys/types.h>
#include <stddef.h>
#include "pac_kit.h"

#include "PlatformUnifiedInterface/platform.h"

#if defined(__arm64e__) && __has_feature(ptrauth_calls)
#include <ptrauth.h>
#endif

namespace features {

template <typename T> inline T arm_thumb_fix_addr(T &addr) {
#if defined(__arm__) || defined(__aarch64__)
  addr = (T)((uintptr_t)addr & ~1);
#endif
  return addr;
}

namespace apple {
template <typename T> inline T arm64e_pac_strip(T &addr) {
  return pac_strip(addr);
}

template <typename T> inline T arm64e_pac_sign(T &addr) {
  return pac_sign(addr);
}

template <typename T> inline T arm64e_pac_strip_and_sign(T &addr) {
  return pac_strip_and_sign(addr);
}
} // namespace apple

namespace android {
inline void make_memory_readable(void *address, size_t size) {
#if defined(ANDROID)
  auto page = (void *)ALIGN_FLOOR(address, OSMemory::PageSize());
  if (!OSMemory::SetPermission(page, OSMemory::PageSize(), kReadExecute)) {
    return;
  }
#endif
}
} // namespace android
} // namespace features