#ifndef _NFLIB_BASE_H
#define _NFLIB_BASE_H

#include <stddef.h>
#include <stdbool.h>

#define _LAYER(layer, name) 1

#if _LAYER(0, "macro") /////////////////////////////////////////////////////////

#define __WINDOWS_10__ 1
#define __LPC177X_8X__ 0

#if __WINDOWS_10__ /////////////////////////////////////////////////////////////

#include <stdio.h>
#include <Windows.h>
#define GET_TICK_COUNT() (u32)GetTickCount64()
#pragma warning(disable:4996)

#elif __LPC177X_8X__ ///////////////////////////////////////////////////////////

#include "base/time.h"
#define GET_TICK_COUNT() get_tick()

#endif // __WINDOWS_10__
#endif // _LAYER(0, "macro")

static const char* g_assertName = "none";
inline Assert(bool isTrue, const char* name);

#if _LAYER(0, "typedef") ///////////////////////////////////////////////////////

typedef bool        Bit;
typedef char*       Str;
typedef const char* CStr;

#if __WINDOWS_10__

typedef char      i8;
typedef short     i16;
typedef int       i32;
typedef long long i64;

#endif

typedef unsigned char      u8 , Byte;
typedef unsigned short     u16, Word;
typedef unsigned int       u32, DWord;
typedef unsigned long long u64, QWord;

typedef struct {
    Byte byte[1];
} u8x1;

typedef union {
    Word word[1];
    Byte byte[2];
} ByteWord, u8x2;

typedef union {
    DWord dWord[1];
    Word word[2];
    Byte byte[4];
} ByteDWord, u8x4;

typedef union {
    QWord qWord[1];
    DWord dWord[2];
    Word word[4];
    Byte byte[8];
} ByteQWord, u8x8;
#endif // _LAYER(0, "typedef")

#if _LAYER(0, "function") //////////////////////////////////////////////////////

Bit GetBit(Byte byte, Byte i);
void SetBit(Byte* byte, Byte i, Bit data);
void EndianReverse(Byte byte[], size_t size);
void ASC2BCD(u8* bcd, const u8* asc, u16 bcdSize); // ASCII to BCD

#endif // _LAYER(0, "function")

#endif // _NFLIB_BASE_H
