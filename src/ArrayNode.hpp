#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class ArrayNode : public Node
{
private:
    std::string _array;
    int         _count;

public:
    ArrayNode()
        : Node(NodeKind::ARRAY)
    {}

    std::string                       print() const override;
    NodeKind                          kind() const;
    static std::unique_ptr<ArrayNode> make_ptr();
    int                               child_count() const;
};