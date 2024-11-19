#include "Warlock.hpp"

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
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
	SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string SpellName)
{
	SpellBook.forgetSpell(SpellName);
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (SpellBook.createSpell(SpellName))
		SpellBook.createSpell(SpellName)->launch(target);
}
