#include "ObjectNode.hpp"

std::string ObjectNode::print() const
{
    return "{}";
}

NodeKind ObjectNode::kind() const
{
    return NodeKind::OBJECT;
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr()
{
    auto tmp     = std::make_unique<ObjectNode>();
    tmp->_object = std::move(_object);
    return tmp;
}