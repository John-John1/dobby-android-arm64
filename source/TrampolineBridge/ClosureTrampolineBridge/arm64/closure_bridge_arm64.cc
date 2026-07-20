// Minimal stubs for Android ARM64 build
// ASM closure bridge removed due to ADRP relocation issues with NDK
#include "../common_bridge_handler.h"

#if defined(__aarch64__)

// Stub closure_trampoline_asm - just return a small dummy code block
static uint8_t dummy_trampoline[] = { 0xc0, 0x03, 0x5f, 0xd6 }; // RET
extern "C" uint8_t *closure_trampoline_asm = dummy_trampoline;
extern "C" uint8_t *closure_trampoline_asm_end = dummy_trampoline + sizeof(dummy_trampoline);

#endif
