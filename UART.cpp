#include "UART.hpp"

// Simulates sending one byte at a time and buffered.

void UART::sendByte(uint8_t byte) {
    wire.push(byte);
}
uint8_t UART::getByte() {
    return wire.pop();
}