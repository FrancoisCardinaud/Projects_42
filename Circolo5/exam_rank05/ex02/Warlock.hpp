#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"


class Warlock {
public:
    ~Warlock();
    Warlock(const std::string& name, const std::string& title);

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);
    void introduce() const;

	void learnSpell(ASpell* spell);
	void forgetSpell(const std::string SpellName);
	void launchSpell(const std::string SpellName, ATarget const & target);

private:
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);

    std::string name;
    std::string title;
    SpellBook SpellBook;
};
