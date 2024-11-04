#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
    for (ASpell* spell : spells)
        delete spell;
}

const std::string& Warlock::getName() const { return name; }
const std::string& Warlock::getTitle() const { return title; }
void Warlock::setTitle(const std::string& newTitle) { title = newTitle; }

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell) {
        for (ASpell* s : spells)
            if (s->getName() == spell->getName())
                return;
        spells.push_back(spell->clone());
    }
}

void Warlock::forgetSpell(const std::string& spellName) {
    for (auto it = spells.begin(); it != spells.end(); ++it) {
        if ((*it)->getName() == spellName) {
            delete *it;
            spells.erase(it);
            return;
        }
    }
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target) {
    for (ASpell* spell : spells) {
        if (spell->getName() == spellName) {
            spell->launch(target);
            return;
        }
    }
}
