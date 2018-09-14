/*
Copyright(C) 2018 liuwenjun.All rights reserved.
*/

#ifndef SRC_OPARETOR_HPP_
#define SRC_OPARETOR_HPP_

namespace cactus {

class OpKernel {
public:
    virtual void input(std::vector<Tensor>) = 0;
    virtual void compute() = 0;
};
}

#endif  // SRC_OPARETOR_HPP_