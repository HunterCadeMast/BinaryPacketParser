#include "CRC.hpp";

// Checksum detects errors like dropped bits, flipped bits, or corruption and recomputes.

uint8_t computeCheckSum(const std::vector<uint8_t>& bytes) {
    uint8_t sum = 0;
    for (uint8_t byte : bytes) {
        sum += byte;
    }
    return sum;
};