#pragma once
#include "ASpell.hpp"
#include <map>

class SpellBook
{
	public :
		~SpellBook();
		SpellBook();

		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);

	private :
		SpellBook(const SpellBook& other);
		SpellBook & operator=(const SpellBook& other);
		std::map < std::string, ASpell*> _SpellBook;
};