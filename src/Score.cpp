#include "Score.h"

Score::Score(){
    icon.loadFromFile("icon.png");
    font.loadFromFile("LCALLIG.ttf");

}

Score::~Score()
{
    //dtor
}

void Score::showScore(){
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreText.setFont(font);

    scoreTitle.setFont(font);
    scoreTitle.setCharacterSize(30);
    scoreTitle.setPosition(100,0);
    scoreTitle.setString("SCORES:");
    scoreTitle.setFillColor(sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(640,480),"ScoreBoard");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.setIcon(32,32,icon.getPixelsPtr());


    view.setCenter(640/2,240);
    view.setSize(640,600);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                window.close();
            }
            if (event.type==sf::Event::KeyPressed){
                if (event.key.code==sf::Keyboard::Escape)
                    window.close();
                if (event.key.code==sf::Keyboard::Up){
                    view.move(0,-10);
                }
                if (event.key.code==sf::Keyboard::Down){
                    view.move(0,10);
                }
            }
        }
        window.clear();
        window.setView(view);
        j=1;
        window.draw(scoreTitle);
        score.open("score/score.txt",std::ios::in);
        while (std::getline(score,fileContent)){
            scoreText.setString(fileContent);
            scoreText.setPosition(0,j*50);
            window.draw(scoreText);
            j+=1;
        }
        score.close();

        window.display();

    }
}
