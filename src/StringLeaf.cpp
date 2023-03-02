#include "StringLeaf.hpp"

#include <memory>
#include <string>

std::string StringLeaf::print() const
{
    return "\"" + _str + "\"";
}

std::string StringLeaf::data()
{
    return _str;
}

NodeKind StringLeaf::kind() const
{
    return NodeKind::STRING;
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(std::string str)
{
    return std::make_unique<StringLeaf>(std::move(str));
}
