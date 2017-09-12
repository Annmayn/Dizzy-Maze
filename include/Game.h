#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "StackVector.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <sstream>


class Game
{
    public:
        Game();
        void showTime(int);
        std::string createMaze(int width,bool isPlay=true);
        void move(int direction);
        virtual ~Game();
        std::string NtoS(int);
        int displayCount=0;  //for transition effect to occur only once

    protected:
        int score;
        std::string scoreString;
        sf::Music wonMusic, lostMusic;
        sf::Text winMessage,lostMessage,timeText;
        sf::Font font;
        sf::RectangleShape textbox, timer;
        sf::Texture playerTexture,allTexture;
        sf::Sprite playerSprite,wallSprite,startSprite,solutionSprite,endSprite;

        sf::View view;

        sf::Clock clock;
        sf::Time timeLimit=sf::seconds(30+6);
        sf::Time timeElapsed;
        sf::Time timeRemaining=timeLimit;

        bool visited[1000][1000];

        const int RIGHT=0;
        const int LEFT=1;
        const int DOWN=2;
        const int UP=3;

        bool moveUp=false, moveDown=false, moveLeft=false, moveRight=false;

        int x, y, posx, posy, direction, remaining;
        int cnt=0;
        int gameWidth=0;
        std::stack<StackVector> path ,temp, solution;
        bool showSolution=false;

};

#endif // GAME_H
