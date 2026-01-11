#include "stdint.h"
#include "stddef.h"

#define FPIH_DEVELOPMENT

#define fpih_bit_width(n) (sizeof(n.v) * 8)
#define fpih_sbit(n) (n.v & ((size_t) 1 << (fpih_bit_width(n) - 1)))

#define FPIH_32_ONES        (UINT32_MAX)

typedef struct {
    uint32_t v;
    uint8_t  whole_bits;
} ufpt32_t;

typedef ufpt32_t fpt32_t;

/**
 * @brief performs a logical left shift on a 32-bit value
 * 
 * @param n value to left shift
 * @param shift left shit (must be positive)
 * @return uint32_t `n << shift`
 */
static inline uint32_t fpih_32_logical_lshift(uint32_t n, size_t shift) {
    n <<= shift;
    return n; 
}

/**
 * @brief performs a logical right shift on a 32-bit value
 * 
 * @param n value to right shift
 * @param shift right shit (must be positive)
 * @return uint32_t `n >> shift`
 */
static inline uint32_t fpih_32_logical_rshift(uint32_t n, size_t shift) {
    n >>= shift;
    return n; 
}

/**
 * @brief performs an arithmetic left shift on an unsigned 32-bit fpt value
 * 
 * @param n value to left shift
 * @param shift left shit (must be positive)
 * @return ufpt32_t left shifted unsigned fpt value 
 */
static inline fpt32_t fpih_ufpt32_arithmetic_lshift(ufpt32_t n, size_t shift) {
    n.v = fpih_32_logical_lshift(n.v, shift);
    return n;
}

/**
 * @brief performs an arithmetic right shift on an unsigned 32-bit fpt value
 * 
 * @param n value to right shift
 * @param shift right shit (must be positive)
 * @return ufpt32_t right shifted unsigned fpt value 
 */
static inline fpt32_t fpih_ufpt32_arithmetic_rshift(ufpt32_t n, size_t shift) {
    n.v = fpih_32_logical_rshift(n.v, shift);
    return n;
}

/**
 * @brief performs an arithmetic left shift on a signed 32-bit fpt value
 * @note the sign bit is preserved on overflow condition; i.e. overflow occurs at `shift > 31 - msb_index(n)`
 * 
 * @param n value to left shift
 * @param shift left shit (must be positive)
 * @return fpt32_t left shifted unsigned fpt value 
 */
static inline fpt32_t fpih_fpt32_lshift(fpt32_t n, size_t shift) {
    uint32_t sign = fpih_sbit(n);
    n.v = fpih_32_logical_lshift(n.v, shift);
    n.v |= sign;
    return n; 
}

/**
 * @brief performs an arithmetic right shift on a signed 32-bit fpt value
 * 
 * @param n value to right shift
 * @param shift right shit (must be positive)
 * @return fpt32_t right shifted signed fpt value 
 */
static inline fpt32_t fpih_fpt32_rshift(fpt32_t n, size_t shift) {
    int32_t sign = fpih_sbit(n);
    n.v = fpih_32_logical_rshift(n.v, shift);
    if (sign) n.v |= fpih_32_logical_lshift(FPIH_32_ONES, fpih_bit_width(n) - shift);
    return n; 
}
