#ifndef CACTUS_EIGEN3_HPP
#define CACTUS_EIGEN3_HPP

#include "common.hpp"
#include "operator.hpp"
namespace cactus {
    template<typename T,typename S>
    std::ostream & operator<<(std::ostream & os, tensor<T,S>& stu)
    {
        os << stu.value();
        return os;
    }
    
    //template<typename Tx,typename Ty>
    //tensor<Ty> tensor_cast(tensor<Tx> in) {
    //    using namespace Eigen;
    //    tensor<Ty> val;
    //    /*if (std::is_same<Tx, Ty>()) {
    //    }
    //    else {
    //    }*/
    //    val.reshape(in.shape());
    //    Map<Array<Tx, Dynamic, RowMajor>>
    //        x(in.data(), in.size());
    //    Map<Array<Ty, Dynamic, RowMajor>>
    //        y(val.data(), val.size());
    //    y = x.cast<Ty>();
    //    
    //    return val;
    //}

}
#endif