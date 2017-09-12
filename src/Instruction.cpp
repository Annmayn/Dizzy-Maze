#include "Instruction.h"

Instruction::Instruction()
{
    font.loadFromFile("LCALLIG.ttf");
    //ctor
}

Instruction::~Instruction()
{
    //dtor
}

void Instruction::showInstruction(){
    sf::RenderWindow insWindow(sf::VideoMode(640,600),"Instruction Window");
    insWindow.setFramerateLimit(60);

    sf::Image icon;
    icon.loadFromFile("icon.png");
    insWindow.setIcon(32,32,icon.getPixelsPtr());

    instruction.setFont(font);
    instruction.setCharacterSize(20);
    instruction.setPosition(100,100);
    instruction.setString("\
INSTRUCTION:\n\n\t\
\tThis game does what the name suggests; it generates maze.\n\
If you want to generate a maze of a size of your choosing,\n\
generate mode is the mode you should head to; but if you want\n\
to play the mini-game we provided alongside the generator, you \n\
may want to head to game mode. From here on out, every instance\n\
of game shall be called an event.\n\t\
\tDuring the start of every event, you will have six seconds to view\n\
the entire maze and search for the possible path that leads you to \n\
the finish. After six seconds, the camera will transition to such \n\
a state where you’ll not be able to view the entire maze and you will \n\
have to rely on your memory power to find the path.\n\n\
i)Play mode:\n\t\
\tThis is where you compete and try to achieve the best time possible or\n\
complete the maze in time depending upon the situation that presents\n\
itself. You are not allowed to view the solution of the path in this mode\n\
of game play. It consists three modes: easy, medium and hard. \n\
The difference - easy has smaller maze; medium has a slightly larger\n\
and harder has the largest of them all.  You will have 1 minute to \n\
complete the level in play mode.\n\n\
ii) Generate mode:\n\t\
\tThis is where you just generate mazes as per your need. Here, you are\n\
free to use any tool to check the maze for completeness. Press F1 to \n\
toggle solution while in game. Also, there is no limit in how much time \n\
you take to complete the maze; the stage is all yours. \n\n\
CONTROLS:\n\
W - Up\n\
S - Down\n\
A - Left\n\
D - Right\n\
F1 - view solution   (only in generate mode)\n\
Arrow up - move camera upwards(only in generate mode)\n\
Arrow down - move camera downwards (only in genererate mode) \n\
Arrow Left - move the camera towards left(only in generate mode) \n\
Arrow right - move the camera towards right (only in generate mode) \n\
Q - zoom out    (only in generate mode)\n\
E - zoom in (only in generate mode)\n\
Esc - quit to main menu\n\n\n\
*PRESS ESC TO RETURN TO THE MAIN MENU AT ANY MOMENT*\
");

    view.setCenter(640/2+150,100);
    view.setSize(640,600);
    view.zoom(1.5);

    while (insWindow.isOpen()){
        sf::Event event;
        while (insWindow.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                insWindow.close();
            }
            if (event.type==sf::Event::KeyPressed){
                if (event.key.code==sf::Keyboard::Down or event.key.code==sf::Keyboard::S)
                    view.move(0,10);
                if (event.key.code==sf::Keyboard::Up or event.key.code==sf::Keyboard::W)
                    view.move(0,-10);
                if (event.key.code==sf::Keyboard::Escape)
                    insWindow.close();
            }
        }
        insWindow.setView(view);
        insWindow.clear();
        insWindow.draw(instruction);
        insWindow.display();

    }
}
