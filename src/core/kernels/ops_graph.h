#include "../framework/node.hpp"

namespace cactus {
class InitVariable : public Operation {
  public:
    InitVariable(std::vector<Node *>);
    void compute();
};
} // namespace cactus