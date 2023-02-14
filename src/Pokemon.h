#pragma once
#include <memory>
#include <string>

// A creature that is cute and can fight other ones.
class Pokemon
{
private:
    std::string _name;
    int _id;
    static inline int idIncr;

public:
    Pokemon(const std::string &name)
        : _name{name}

    {
        _id = idIncr++;
    }

    Pokemon(const Pokemon &poke)
        : _name{poke.name()}

    {
        _id = idIncr++;
    }

    std::string name() const
    {
        return _name;
    }
    int id() const
    {
        return _id;
    }
};