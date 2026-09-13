/* RFC 1321 MD5 under mbedtls-style names (md5.c) */
#ifndef PANEL_DISPLAY_MD5_H_
#define PANEL_DISPLAY_MD5_H_

#include <stdint.h>
#include <stddef.h>

typedef struct {
	uint32_t count[2];        /* 0x00 number of bits, modulo 2^64 (lsb first) */
	uint32_t state[4];        /* 0x08 state (ABCD) */
	unsigned char buffer[64]; /* 0x18 input buffer */
} mbedtls_md5_context;

void mbedtls_md5_starts(mbedtls_md5_context *context);
void mbedtls_internal_md5_process(uint32_t state[4], const unsigned char block[64]);
void mbedtls_md5_update(mbedtls_md5_context *context, const unsigned char *input,
			unsigned int inputLen);
void mbedtls_md5_finish(mbedtls_md5_context *context, unsigned char digest[16]);
int mbedtls_md5(const unsigned char *input, size_t ilen, unsigned char output[16]);

#endif
