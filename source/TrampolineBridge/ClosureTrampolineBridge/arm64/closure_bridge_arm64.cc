// Stub implementations for Android ARM64 build
// ASM closure bridge removed due to ADRP relocation issues
#include "../common_bridge_handler.h"
#include <string.h>

// Stub: closure_bridge_init
void closure_bridge_init() {
    // No-op for Android build
}

// Stub: closure_trampoline_asm - dummy code block
static uint8_t dummy_trampoline_code[] = { 0xc0, 0x03, 0x5f, 0xd6 }; // RET
uint8_t *closure_trampoline_asm = dummy_trampoline_code;
uint8_t *closure_trampoline_asm_end = dummy_trampoline_code + sizeof(dummy_trampoline_code);
