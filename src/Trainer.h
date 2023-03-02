#include <vector>
#include "PC.h"
#include "Pokeball.h"

class Trainer
{
public:
    Trainer(const std::string &name, PC &pc) : name_(name), _pc(pc)
    {
        for (int i = 0; i < 6; i++)
        {
            _pokeballs.push_back(Pokeball{});
        }
    }

    std::string name() const
    {
        return name_;
    }

    PC &pc()
    {
        return _pc;
    }

    const std::vector<Pokeball> &pokeballs() const
    {
        return _pokeballs;
    }

    void capture(PokemonPtr pokemon)
    {
        pokemon->set_trainer(*this);
        for (int i = 0; i < 6; i++)
        {
            if (_pokeballs[i].empty())
            {
                _pokeballs[i].store(std::move(pokemon));

                return;
            }
        }
        _pc.transfer(std::move(pokemon));
    }

    void store_in_pc(size_t index)
    {
        _pc.transfer(_pokeballs[index].steal());
    }

    void fetch_from_pc(const std::string &name)
    {
        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                auto pokemon = _pc.steal(*this, name);
                if (pokemon != nullptr)
                {
                    pokeball.store(std::move(pokemon));
                }

                return;
            }
        }
    }

private:
    std::string name_;
    PC &_pc;
    std::vector<Pokeball> _pokeballs;
};
