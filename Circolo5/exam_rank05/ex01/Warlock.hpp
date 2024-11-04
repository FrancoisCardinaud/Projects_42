#include <string>
#include <vector>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);

    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& spellName);
    void launchSpell(const std::string& spellName, const ATarget& target);

private:
    Warlock(const Warlock&) = delete;
    Warlock& operator=(const Warlock&) = delete;

    std::string name;
    std::string title;
    std::vector<ASpell*> spells;
};
