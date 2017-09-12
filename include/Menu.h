#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>

#include "Game.h"
#include "Instruction.h"
#include "Score.h"

class Menu
{
    public:
        Menu();
        void showMenu();
        void askName();
        void askName(int);
        virtual ~Menu();
        std::string playerName;

    protected:
        Game *gameptr;
        std::string strSizeOfMaze, scoreString;
        int sizeOfMaze=11;

        sf::Font font;
        sf::Music menuMusic;
        sf::SoundBuffer selectBuffer, clickBuffer;
        sf::Sound selectSound, clickSound;
        std::ofstream writeFile;
        std::ifstream readFile;

        sf::Image icon;

        sf::Vector2i pos;
        sf::Font titleFont;
        sf::Text Title, lastScoreText, askNameText, playerNameText, playText, exitText;
        sf::Text generateText, instructionText, easyText, mediumText, hardText, scoreText;
        sf::RectangleShape questionBox, answerBox;

        Instruction *insptr;
        Score *scrptr;

        bool quit=false, showPlayOptions=false;
        int mazeSize;

};

#endif // MENU_H
