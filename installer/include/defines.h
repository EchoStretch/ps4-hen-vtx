#ifndef __DEFINES_H__
#define __DEFINES_H__
#pragma once

#define VERSION "2.1.4"

//#define DEBUG_SOCKET

#define LOG_IP   "192.168.1.3\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define LOG_PORT 9023

struct payload_info {
	uint8_t* buffer;
	size_t size;
};

struct payload_header {
	uint64_t signature;
	size_t entrypoint_offset;
};

struct install_payload_args {
	void* syscall_handler;
	struct payload_info* payload_info;
};

#define X86_CR0_WP (1 << 16)

static inline __attribute__((always_inline)) void disable_interrupts(void) {
	__asm__ volatile("cli");
}

static inline __attribute__((always_inline)) void enable_interrupts(void) {
	__asm__ volatile("sti");
}

static inline __attribute__((always_inline)) uint64_t read_flags(void) {
	uint64_t flags;
	__asm__ volatile("pushf; pop %0;" : "=r" (flags));
	return flags;
}

static inline __attribute__((always_inline)) uint64_t intr_disable(void) {
	uint64_t flags = read_flags();
	disable_interrupts();
	return flags;
}

static inline __attribute__((always_inline)) void intr_restore(uint64_t flags) {
	__asm__ volatile("push %0; popf;" : : "rm" (flags) : "memory");
}

#endif
