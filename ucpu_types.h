#ifndef UCPU_TYPES_H
#define UCPU_TYPES_H

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef int8_t i8;
typedef uint8_t u8;
typedef uint16_t u16;

#define LOG(msg) printf("[LOG %s] %s", __FUNCTION__, msg)
#define LEN(a) (sizeof(a) / sizeof(a[0]))

#define UCPU_USTACK_MAX_SIZE 256

typedef struct uStack_t {
	i8 top;
	u8 elements[UCPU_USTACK_MAX_SIZE];
} uStack;

extern uStack* ustack_new();
extern void ustack_push(uStack* stack, u8 element);
extern u8 ustack_pop(uStack* stack);
extern bool ustack_empty(uStack* stack);
extern bool ustack_full(uStack* stack);

typedef struct uMem_t {
	u8* data;
	u16 size;
} uMem;

extern uMem* umem_new(u16 size);
extern void umem_free(uMem* mem);

extern u8 umem_read(uMem* mem, u16 addr);
extern void umem_write(uMem* mem, u16 addr, u8 v);

extern u16 umem_read16(uMem* mem, u16 addr);
extern void umem_write16(uMem* mem, u16 addr, u16 v);

#endif // UCPU_TYPES_H