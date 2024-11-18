#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball* Fireball::clone() const
{
	return (new Fireball());
}