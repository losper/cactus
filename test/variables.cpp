#include "../../../3rd/eigen/Eigen/Dense"
#include <gtest/gtest.h>
#include <vector>


TEST(layer, fully) {
    using namespace Eigen;
    Eigen::MatrixXf m(4, 4);
    m << 1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16;
    std::cout << "Block in the middle" << std::endl;
    
    auto z = m.block(1, 1, 2, 2);
    std::cout << z.array() << std::endl;
    Eigen::Array<int, 12, RowMajor> tmp;
    tmp << 1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12;
    auto tmpz = tmp.block(0, 0, 11, 1);
    std::cout << tmpz << std::endl;
}