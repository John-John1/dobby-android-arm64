// Minimal stubs for Android ARM64 build
#include "../common_bridge_handler.h"
#include <string.h>

#if defined(__aarch64__)

// Stub trampoline code - just a RET instruction
static uint8_t dummy_trampoline[] = { 0xc0, 0x03, 0x5f, 0xd6 };
extern "C" uint8_t *closure_trampoline_asm = dummy_trampoline;
extern "C" uint8_t *closure_trampoline_asm_end = dummy_trampoline + sizeof(dummy_trampoline);

// Stub init function
extern "C" void closure_bridge_init() {
    // No-op for Android build without ASM
}

#endif
