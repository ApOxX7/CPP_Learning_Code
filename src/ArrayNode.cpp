#include "ArrayNode.hpp"

#include <memory>
#include <string>

std::string ArrayNode::print() const
{
    return "[]";
}

NodeKind ArrayNode::kind() const
{
    return NodeKind::ARRAY;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr()
{
    auto tmp    = std::make_unique<ArrayNode>();
    tmp->_array = std::move(_array);
    return tmp;
}

int ArrayNode::child_count() const
{
    return _count;
}