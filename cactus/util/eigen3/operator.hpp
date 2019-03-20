
#ifndef CACTUS_EIGEN3_COND_HPP
#define CACTUS_EIGEN3_COND_HPP
#include "common.hpp"
//#include "four_operations.hpp"
//#include "pow.hpp"
//#include "func.hpp"

namespace cactus {
    /*REG_OP(int, NoneGradOp, > );
    REG_OP(int, NoneGradOp, < );
    REG_OP(int, NoneGradOp, >=);
    REG_OP(int, NoneGradOp, <=);
    REG_OP(int, NoneGradOp, != );
    REG_OP(int, NoneGradOp, == );
    REG_OP(REG_RET_TYPE, AddGradOp, +);
    REG_OP(REG_RET_TYPE, SubGradOp, -);
    REG_OP(REG_RET_TYPE, MulGradOp, *);
    REG_OP(REG_RET_TYPE, DivGradOp, /);*/
    /*REG_FUNC_OP(LogGradOp, log);
    REG_FUNC_OP(AbsGradOp, abs);
    REG_FUNC_OP(SqrtGradOp, sqrt);
    REG_FUNC_OP(NoneGradOp, log10);
    REG_FUNC_OP(NoneGradOp, exp);
    REG_FUNC_OP(NoneGradOp, sin);
    REG_FUNC_OP(NoneGradOp, cos);
    REG_FUNC_OP(NoneGradOp, tan);
    REG_FUNC_OP(NoneGradOp, asin);
    REG_FUNC_OP(NoneGradOp, acos);
    REG_FUNC_OP(NoneGradOp, atan);
    REG_FUNC_OP(NoneGradOp, sinh);
    REG_FUNC_OP(NoneGradOp, cosh);
    REG_FUNC_OP(NoneGradOp, tanh);
    REG_FUNC_OP(NoneGradOp, arg);
    REG_FUNC_OP(NoneGradOp, floor);
    REG_FUNC_OP(NoneGradOp, ceil);
    REG_FUNC_OP(NoneGradOp, round);
    REG_FUNC_OP(NoneGradOp, isfinite);
    REG_FUNC_OP(NoneGradOp, isinf);
    REG_FUNC_OP(NoneGradOp, isnan);*/
   
    template<
        typename LV,
        typename LVlayout,
        typename RV,
        typename RVlayout>
        decltype(auto) operator * (tensor<LV, LVlayout>& lv, tensor<RV, RVlayout>& rv) {

        Tensor<typename std::result_of<S<LV, RV>()>::type> tmp;
        auto lvsh = lv.shape(), rvsh = rv.shape();
        if (std::equal(lvsh.begin(), lvsh.end(), rvsh.begin())) {
            tmp.reshape(lvsh);
            tmp.value() = lv.value()*rv.value();
        }
        return tmp;
    }
    template<
        typename LV,
        typename LVlayout,
        typename RV>
        decltype(auto) operator *(tensor<LV, LVlayout>& lv, RV rv) {
        Tensor<typename std::result_of<S<LV, RV>()>::type> tmp(lv.shape());
        Xscalar<RV> val = rv;
        tmp.value() = lv.value()*val.value();
        return tmp;
    }
    template<
        typename LV,
        typename RV,
        typename RVlayout>
        decltype(auto) operator *(LV lv, tensor<RV, RVlayout>& rv) {
        Tensor<typename std::result_of<S<LV, RV>()>::type> tmp(rv.shape());
        Xscalar<LV> val = lv;
        tmp.value() = val.value()*rv.value();
        return tmp;
    }
    template<
        typename LV,
        typename LVlayout,
        typename RV,
        typename RVlayout>
        decltype(auto) operator > (tensor<LV, LVlayout>& lv, tensor<RV, RVlayout>& rv) {

        Tensor<bool> tmp;
        auto lvsh = lv.shape(), rvsh = rv.shape();
        if (std::equal(lvsh.begin(), lvsh.end(), rvsh.begin())) {
            tmp.reshape(lvsh);
            
            tmp.value().array()=lv.value().array()>rv.value().array();
        }
        return tmp;
    }
}
#endif