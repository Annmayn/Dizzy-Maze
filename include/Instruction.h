#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Instruction
{
    public:
        Instruction();
        virtual ~Instruction();
        void showInstruction();

    protected:
        sf::Text instruction;
        sf::Font font;
        sf::View view;
};

#endif // INSTRUCTION_H
