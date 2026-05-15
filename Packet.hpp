#pragma once
#include <cstdint>
#pragma pack(push, 1)

// Exact layout for UART and removes padding.

struct PacketHeader {
    uint8_t header;
    uint8_t type;
    uint8_t length;
};

#pragma pack(pop)

uint16_t bigEndian(uint16_t value) {
    return (value >> 8) | (value << 8);
};