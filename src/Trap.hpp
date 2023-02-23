#pragma once
#include <string>
#include <Card.hpp>

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

std::string to_string(const TrapType type)
{
    switch (type)
    {
    case TrapType::Normal:
        return "Normal";

    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    }

    return "";
}

class Trap : public Card
{
private:
    const TrapType _type;

public:
    Trap(const std::string &id, const std::string &name, TrapType type)
        : Card{id, CardType::Trap}, _type{type}
    {
        set_name(name);
    }

    TrapType get_trap_type() const
    {
        return _type;
    }

    std::string get_symbol() const
    {
        return u8"罠";
    }
};
