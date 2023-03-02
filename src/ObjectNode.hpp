#pragma once
#include "Leaf.hpp"

#include <string>

class ObjectNode : public Node
{
private:
    std::string _object;

public:
    ObjectNode()
        : Node(NodeKind::OBJECT)
    {}

    std::string                        print() const override;
    NodeKind                           kind() const;
    static std::unique_ptr<ObjectNode> make_ptr();
};