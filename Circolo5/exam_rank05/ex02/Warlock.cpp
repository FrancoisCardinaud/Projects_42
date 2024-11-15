#include "Warlock.hpp"

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
}

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

const std::string& Warlock::getName() const { 
    return name;
}

const std::string& Warlock::getTitle() const { 
    return title;
}

void Warlock::setTitle(const std::string& newTitle) { 
    title = newTitle;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string SpellName)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end()) {
		delete _SpellBook[SpellName];	
		_SpellBook.erase(_SpellBook.find(SpellName));
	}
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook[SpellName]->launch(target);
}
