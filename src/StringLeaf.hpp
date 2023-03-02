#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class StringLeaf : public Leaf
{
private:
    std::string _str;

public:
    StringLeaf(std::string str)
        : Leaf(NodeKind::STRING)
        , _str { str }
    {}
    std::string                        data();
    std::string                        print() const override;
    NodeKind                           kind() const;
    static std::unique_ptr<StringLeaf> make_ptr(std::string str);
};
