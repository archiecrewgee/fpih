#include "stdint.h"
#include "stddef.h"

#define fpih_bit_width(n) (sizeof(n.v) * 8)
#define fpih_sbit(n) (n.v & ((size_t) 1 << (fpih_bit_width(n) - 1)))

typedef struct {
    uint32_t v;
    uint8_t  whole_bits;
} ufpt32_t;

typedef ufpt32_t fpt32_t;

static inline ufpt32_t fpih_ufpt32_lshift(ufpt32_t n, size_t shift) {
    n.v <<= shift;
    return n; 
}

static inline ufpt32_t fpih_ufpt32_rshift(ufpt32_t n, size_t shift) {
    n.v >>= shift;
    return n; 
}

static inline fpt32_t fpih_fpt32_lshift(fpt32_t n, size_t shift) {
    uint32_t sign = fpih_sbit(n);
    n.v <<= shift;
    n.v |= sign;
    return n; 
}

static inline fpt32_t fpih_fpt32_rshift(fpt32_t n, size_t shift) {
    int32_t sign = fpih_sbit(n);
    n.v >>= shift;
    if (sign) n.v = (int32_t) n.v + sign;
    return n; 
}
