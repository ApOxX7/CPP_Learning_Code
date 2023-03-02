#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
private:
    int _i;

public:
    IntLeaf(int i)
        : Leaf(NodeKind::INT)
        , _i { i }
    {}

    int                             data();
    std::string                     print() const override;
    NodeKind                        kind() const;
    static std::unique_ptr<IntLeaf> make_ptr(int i);
};
