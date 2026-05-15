#include "Packet.hpp";
#include <vector>;
#include <string>;

std::vector<uint8_t> serializePacket(uint8_t type, const std::string& data) {
    std::vector<uint8_t> bytes;
    PacketHeader hdr;
    hdr.header = 0xAA;
    hdr.type = type;
    hdr.length = bigEndian(data.size());
    uint8_t* hdrPtr = reinterpret_cast<uint8_t*>(&hdr);
    bytes.insert(bytes.end(), hdrPtr, hdrPtr + sizeof(PacketHeader));
    bytes.insert(bytes.end(), data.begin(), data.end());
    return bytes;
};