#include "Warlock.hpp"

Warlock::~Warlock() 
{
	std::cout << name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = SpellBook.begin(); it != SpellBook.end(); ++it)
	{
		delete it->second;
	}
	SpellBook.clear();
}

Warlock::Warlock(const std::string& name, const std::string title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

const std::string& Warlock::getName() const
{
	return this->name;
}

const std::string& Warlock::getTitle() const
{
	return this->title;
}

void Warlock::setTitle(const std::string& newTitle)
{
	this->title = newTitle;
}

void Warlock::introduce() const 
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		if (SpellBook.find(spell->getName()) == SpellBook.end())
			SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string SpellName)
{
	if (SpellBook.find(SpellName) != SpellBook.end()) {
		delete SpellBook[SpellName];	
		SpellBook.erase(SpellBook.find(SpellName));
	}
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (SpellBook.find(SpellName) != SpellBook.end())
		SpellBook[SpellName]->launch(target);
}
