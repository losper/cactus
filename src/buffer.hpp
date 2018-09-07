
/*
Copyright(C) 2018 liuwenjun.All rights reserved.
*/

#ifndef SRC_BUFFER_HPP_
#define SRC_BUFFER_HPP_

#include <cstdlib>
#include <cassert>
#include <stdint.h>

namespace cactus {

class Buffer {
 public:
    Buffer():buf_(0) {
    }
    explicit Buffer(uint32_t size):buf_(0) {
        resize(size);
    }
    ~Buffer() {
        if (buf_) {
            std::free(buf_);
        }
    }

 public:
    uint32_t size() {
        return size_;
    }
    int resize(uint32_t size) {
        if (buf_) {
            buf_ = std::realloc(buf_, size);
        } else {
            buf_ = std::malloc(size);
        }
        size_ = size;
        assert(buf_ != NULL);
        return 0;
    }
    void* data() const {
        return buf_;
    }
 private:
    void* buf_;
    uint32_t size_;
};
}  // namespace cactus

#endif  // SRC_BUFFER_HPP_
