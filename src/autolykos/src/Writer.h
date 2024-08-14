#ifndef WRITER_H
#define WRITER_H

#include "includes.h"

class Writer {
public:
    std::vector<uint8_t> buffer;

    void put(uint8_t value);
    void putBytes(const std::vector<uint8_t>& bytes);
    void putBytes(const uint8_t* bytes, size_t length);
    void putULong(uint64_t value);
    void putUInt(uint32_t value);
    void putUByte(uint8_t value);

    std::vector<uint8_t> result() const;
};

#endif // WRITER_H

