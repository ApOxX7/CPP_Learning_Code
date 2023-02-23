#pragma once
#include <string>
#include <Card.hpp>

enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind
};

std::string to_symbol(const Attribute type)
{
    switch (type)
    {
    case Attribute::Dark:
        return u8"闇";

    case Attribute::Divine:
        return u8"神";

    case Attribute::Earth:
        return u8"地";
    case Attribute::Fire:
        return u8"炎";
    case Attribute::Light:
        return u8"光";

    case Attribute::Water:
        return u8"水";

    case Attribute::Wind:
        return u8"風";
    }

    return "";
}

class Monster : public Card
{
private:
    const std::string _fonction;
    const Attribute _type;
    const unsigned int _atk;
    const unsigned int _def;

public:
    Monster(const std::string &id, const std::string &name, Attribute type, const std::string &fonction, unsigned int atk, unsigned int def)
        : Card{id, CardType::Monster}, _fonction{fonction}, _type{type}, _atk{atk}, _def{def}
    {
        set_name(name);
    }

    unsigned int get_def() const
    {
        return _def;
    }

    Attribute get_attribute() const
    {
        return _type;
    }

    unsigned int get_atk() const
    {
        return _atk;
    }

    std::string get_symbol() const
    {
        return to_symbol(_type);
    }
    std::string get_description() const
    {
        return "[" + _fonction + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
    }
};
