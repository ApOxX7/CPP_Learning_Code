#pragma once
#include <memory>
#include <string>
class Trainer;
// A creature that is cute and can fight other ones.
class Pokemon
{
private:
    std::string _name;
    int _id = 0;
    static inline int idIncr = 0;
    const Trainer *_trainer = nullptr;

public:
    Pokemon(const std::string &name)
        : _name{name}, _id{idIncr++}
    {
    }

    Pokemon(const Pokemon &poke)
        : _name{poke._name}, _id{poke.idIncr++}
    {
    }

    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            _name = other._name;
        }

        return *this;
    }

    std::string name() const
    {
        return _name;
    }
    int id() const
    {
        return _id;
    }

    const Trainer *trainer() const
    {
        return _trainer;
    }

    void set_trainer(const Trainer &trainer)
    {
        _trainer = &trainer;
    }
};

using PokemonPtr = std::unique_ptr<Pokemon>;