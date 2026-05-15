#include <iostream>
#include <thread>
#include "UART.hpp"
#include "Packet.cpp"
#include "CRC.hpp"

void sender(UART& uart) {
    auto packet = serializePacket(1, "HELLO");
    packet.push_back(computeCheckSum(packet));
    for (uint8_t byte : packet) {
        uart.sendByte(byte);
        std::cout << "TX: " << std::hex << (int)byte << std::endl;
    }
}
void getter(UART& uart) {
    while(true) {
        uint8_t byte = uart.getByte();
        std::cout << "RX: " << std::hex << (int)byte << std::endl;
    }
}