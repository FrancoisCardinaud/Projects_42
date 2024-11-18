#pragma once
#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    public:
        virtual ~ASpell();
        ASpell(const std::string& name, const std::string& effects);

        const std::string& getName() const;
        const std::string& getEffects() const;
        void launch(const ATarget& target) const;
        virtual ASpell* clone() const = 0;

    private:
        std::string name;
        std::string effects;

};