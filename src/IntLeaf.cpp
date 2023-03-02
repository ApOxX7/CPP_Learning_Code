#include "IntLeaf.hpp"

#include <memory>
#include <string>

std::string IntLeaf::print() const
{
    return std::to_string(_i);
}

int IntLeaf::data()
{
    return _i;
}

NodeKind IntLeaf::kind() const
{
    return NodeKind::INT;
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int i)
{
    return std::make_unique<IntLeaf>(i);
}