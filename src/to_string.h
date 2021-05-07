#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "keys.h"
#include "os_cx.h"
#include "types.h"
#include "ui.h"
#include "uint256.h"

size_t nano_avax_to_string(char *const dest, size_t const buff_size, uint64_t const nano_avax);
size_t wei_to_gwei_string(char *const dest, size_t const buff_size, uint64_t const wei);
size_t wei_to_gwei_string_256(char *const dest, size_t const buff_size, uint256_t const wei);
size_t wei_to_navax_string(char *const dest, size_t const buff_size, uint64_t const wei);
size_t wei_to_navax_string_256(char *const dest, size_t const buff_size, uint256_t const *const wei);

void bip32_path_to_string(char *const out, size_t const out_size, bip32_path_t const *const path);
size_t pkh_to_string(char *const out, size_t const out_size, char const *const hrp, size_t const hrp_size,
                     public_key_hash_t const *const payload);
size_t nodeid_to_string(char *const out, size_t const out_size, public_key_hash_t const *const payload);

// dest must be at least MAX_INT_DIGITS
size_t number_to_string(char *const dest, uint64_t number);

// These take their number parameter through a pointer and take a length
void nano_avax_to_string_indirect64(char *const dest, size_t const buff_size, uint64_t const *const number);
void number_to_string_indirect64(char *const dest, size_t const buff_size, uint64_t const *const number);
void number_to_string_indirect32(char *const dest, size_t const buff_size, uint32_t const *const number);

void delegation_fee_to_string(char *const dest, size_t const buff_size, uint32_t const *const delegation_fee);

// `src` may be unrelocated pointer to rodata.
void copy_string(char *const dest, size_t const buff_size, char const *const src);

// Encodes binary blob to hex string.
// `in` may be unrelocated pointer to rodata.
void bin_to_hex(char *const out, size_t const out_size, uint8_t const *const in, size_t const in_size);

// Encodes binary blob to hex string.
// `in` may be unrelocated pointer to rodata.
void bin_to_hex_lc(char *const out, size_t const out_size, uint8_t const *const in, size_t const in_size);

// Wrapper around `bin_to_hex` that works on `buffer_t`.
// `in` may be unrelocated pointer to rodata.
void buffer_to_hex(char *const out, size_t const out_size, buffer_t const *const in);

// Convert time to YYYY-MM-DD HH:MM:SS format
size_t time_to_string(char *const dest, size_t const buff_size, uint64_t const *const time);
