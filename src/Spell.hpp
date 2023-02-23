#pragma once
#include <string>
#include <Card.hpp>

enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

std::string to_string(const SpellType type)
{
    switch (type)
    {
    case SpellType::Normal:
        return "Normal";

    case SpellType::Equip:
        return "Equip";

    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    }

    return "";
}

class Spell : public Card
{
private:
    const SpellType _type;

public:
    Spell(const std::string &id, const std::string &name, SpellType type)
        : Card{id, CardType::Spell}, _type{type}
    {
        set_name(name);
    }

    SpellType get_spell_type() const
    {
        return _type;
    }

    std::string get_symbol() const
    {
        return u8"魔";
    }
};
