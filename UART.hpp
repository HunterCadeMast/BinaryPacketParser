#pragma once
#include "ThreadQueue.hpp"

class UART {
    private:
        ThreadQueue<uint8_t> wire;
    public:
        void sendByte(uint8_t byte);
        uint8_t getByte();
};