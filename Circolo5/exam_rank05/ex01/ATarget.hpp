#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    public:
        virtual ~ATarget();
        ATarget(const std::string& type);

        const std::string& getType() const;

        void getHitBySpell(const ASpell& spell) const;
        virtual ATarget* clone() const = 0;

    private:
        std::string type;
};