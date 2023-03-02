#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <string>

class Node : public InstanceCounter
{
private:
    NodeKind _kind;

public:
    virtual ~Node() = default;

    virtual std::string print() const = 0;
    NodeKind            kind() const { return _kind; }

protected:
    Node(NodeKind kind)
        : _kind { kind }
    {}
};
