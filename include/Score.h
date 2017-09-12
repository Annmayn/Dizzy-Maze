#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

class Score
{
    public:
        Score();
        void showScore();
        virtual ~Score();

    protected:
        int j;
        sf::Image icon;
        sf::Font font;
        sf::Text scoreText,scoreTitle;
        sf::View view;
        std::string fileContent;
        std::ifstream score;
};

#endif // SCORE_H
