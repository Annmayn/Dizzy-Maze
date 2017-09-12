#include "Menu.h"

Menu::Menu(){
    icon.loadFromFile("icon.png");

    menuMusic.openFromFile("sound/menu.ogg");
    menuMusic.setVolume(30);
    menuMusic.setLoop(true);

    selectBuffer.loadFromFile("sound/menuSelect.wav");
    clickBuffer.loadFromFile("sound/menuClick.ogg");
    selectSound.setBuffer(selectBuffer);
    clickSound.setBuffer(clickBuffer);

    font.loadFromFile("LCALLIG.ttf");
    askNameText.setFont(font);
    titleFont.loadFromFile("28 Days Later.ttf");

    Title.setFont(titleFont);
    Title.setString("DIZZY MAZE");
    Title.setCharacterSize(90);
    Title.setFillColor(sf::Color::Red);
    Title.setPosition(sf::Vector2f(100,75));

    askNameText.setFont(font);
    askNameText.setCharacterSize(20);
    askNameText.setPosition(sf::Vector2f(100,100));

    playerNameText.setFont(font);
    playerNameText.setCharacterSize(25);
    playerNameText.setFillColor(sf::Color::Black);
    playerNameText.setPosition(100,200);

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Green);
    scoreText.setString("Scores");
    scoreText.setPosition(sf::Vector2f(100,300));

    playText.setFont(font);
    playText.setCharacterSize(30);
    playText.setFillColor(sf::Color::Green);
    playText.setString("Play");
    playText.setPosition(sf::Vector2f(100,200));

    exitText.setFont(font);
    exitText.setCharacterSize(30);
    exitText.setFillColor(sf::Color::Green);
    exitText.setString("Exit");
    exitText.setPosition(sf::Vector2f(100,400));

    generateText.setFont(font);
    generateText.setCharacterSize(30);
    generateText.setFillColor(sf::Color::Green);
    generateText.setString("Generate");
    generateText.setPosition(sf::Vector2f(100,250));

    instructionText.setFont(font);
    instructionText.setCharacterSize(30);
    instructionText.setFillColor(sf::Color::Green);
    instructionText.setString("Instruction");
    instructionText.setPosition(sf::Vector2f(100,350));

    easyText.setFont(font);
    easyText.setCharacterSize(25);
    easyText.setFillColor(sf::Color::Magenta);
    easyText.setString("Easy");
    easyText.setPosition(sf::Vector2f(300,200));

    mediumText.setFont(font);
    mediumText.setCharacterSize(25);
    mediumText.setFillColor(sf::Color::Magenta);
    mediumText.setString("Medium");
    mediumText.setPosition(sf::Vector2f(300,250));

    hardText.setFont(font);
    hardText.setCharacterSize(25);
    hardText.setFillColor(sf::Color::Magenta);
    hardText.setString("Hard");
    hardText.setPosition(sf::Vector2f(300,300));

    lastScoreText.setFont(font);
    lastScoreText.setStyle(sf::Text::Bold);
    lastScoreText.setCharacterSize(15);
    lastScoreText.setFillColor(sf::Color::Black);
    lastScoreText.setPosition(0,50);

    questionBox.setFillColor(sf::Color::Black);
    questionBox.setPosition(0,100);
    questionBox.setSize(sf::Vector2f(640,40));

    answerBox.setFillColor(sf::Color::White);
    answerBox.setPosition(0,200);
    answerBox.setSize(sf::Vector2f(640,40));
}

Menu::~Menu()
{
}

void Menu::showMenu(){
    sf::RenderWindow window(sf::VideoMode(600,480),"MENU WINDOW");
    window.setFramerateLimit(60);

    window.setIcon(32,32,icon.getPixelsPtr());      //set the icon of the application
    window.clear(sf::Color::White);
    menuMusic.play();
    while (!quit){

        std::string lastScore;
        readFile.open("score/lastScore.txt");
        std::getline(readFile,lastScore);               //read the last score from file
        readFile.close();
        lastScoreText.setString("LAST SCORE:\t\t"+lastScore);      //append the last score here

        sf::Event event;
        pos = sf::Mouse::getPosition(window);
        if (window.pollEvent(event)){

            if (pos.x>100 and pos.x<200 and pos.y>300 and pos.y<(300+30) ){
                scoreText.setFillColor(sf::Color::Red);
                selectSound.play();
            }
            if (pos.x>100 and pos.x<170 and pos.y>150 and pos.y<(200+30) ){
                playText.setFillColor(sf::Color::Red);
                selectSound.play();
            }
            if (pos.x>100 and pos.x<170 and pos.y>400 and pos.y<(400+30)){
                exitText.setFillColor(sf::Color::Red);
                selectSound.play();
            }

            if (pos.x>100 and pos.x<250 and pos.y>250 and pos.y<(250+30) ){
                generateText.setFillColor(sf::Color::Red);
                selectSound.play();
            }

            if (pos.x>100 and pos.x<280 and pos.y>350 and pos.y<(350+30) ){
                instructionText.setFillColor(sf::Color::Red);
                selectSound.play();
            }

            if (pos.x>300 and pos.x<370 and pos.y>200 and pos.y< (200+25)){
                easyText.setFillColor(sf::Color::Blue);
                selectSound.play();
            }

            if (pos.x>300 and pos.x<370 and pos.y>250 and pos.y< (250+25)){
                mediumText.setFillColor(sf::Color::Blue);
                selectSound.play();
            }

            if (pos.x>300 and pos.x<370 and pos.y>300 and pos.y< (300+25)){
                hardText.setFillColor(sf::Color::Blue);
                selectSound.play();
            }


            if (pos.x < 100 or pos.x > 200 or pos.y < 300 or pos.y > (300+30))
                scoreText.setFillColor(sf::Color::Green);
            if (pos.x < 100 or pos.x > 170 or pos.y < 150 or pos.y > (200+30) )
                playText.setFillColor(sf::Color::Green);
            if (pos.x < 100 or pos.x > 170 or pos.y < 400 or pos.y > (400+30) )
                exitText.setFillColor(sf::Color::Green);
            if (pos.x < 100 or pos.x > 250 or pos.y < 250 or pos.y > (250+30) )
                generateText.setFillColor(sf::Color::Green);
            if (pos.x < 100 or pos.x > 280 or pos.y < 350 or pos.y > (350+30))
                instructionText.setFillColor(sf::Color::Green);
            if (pos.x<300 or pos.x>370 or pos.y<200 or pos.y >(200+25))
                easyText.setFillColor(sf::Color::Magenta);
            if (pos.x<300 or pos.x>370 or pos.y<250 or pos.y>(250+25))
                mediumText.setFillColor(sf::Color::Magenta);
            if (pos.x<300 or pos.x>370 or pos.y<300 or pos.y>(300+25))
                hardText.setFillColor(sf::Color::Magenta);

            if (event.type==sf::Event::Closed){
                quit=true;
            }
            if (event.type==sf::Event::MouseButtonReleased){
                if (event.mouseButton.button==sf::Mouse::Left){
                    if (pos.x>100 and pos.x<170 and pos.y>200 and pos.y<(200+30) ){     //play
                        clickSound.play();
                        playText.setFillColor(sf::Color::Black);
                        showPlayOptions=true;
                    }
                    else if (pos.x>100 and pos.x<250 and pos.y>250 and pos.y<(250+30)){     //generate
                        gameptr=new Game();
                        clickSound.play();
                        window.setVisible(false);
                        askName(mazeSize);
                        gameptr->createMaze(sizeOfMaze,false);            //Size of the maze goes here, the other to (not) show solution
                        showPlayOptions=false;
                        window.setVisible(true);
                        delete gameptr;
                    }
                    else if (pos.x>100 and pos.x<170 and pos.y>300 and pos.y<(300+30)){     //score
                        clickSound.play();
                        scoreText.setFillColor(sf::Color::Black);
                        window.setVisible(false);
                        scrptr=new Score();
                        scrptr->showScore();
                        delete scrptr;
                        window.setVisible(true);
                    }
                    else if (pos.x>100 and pos.x<170 and pos.y>400 and pos.y<(400+30)){     //quit
                        clickSound.play();
                        quit=true;
                        showPlayOptions=false;
                    }
                    else if (pos.x>100 and pos.x<300 and pos.y>350 and pos.y<(350+30)){     //instruction
                        insptr=new Instruction();
                        clickSound.play();
                        showPlayOptions=false;
                        window.setVisible(false);
                        insptr->showInstruction();
                        delete insptr;
                        window.setVisible(true);
                    }
                    else if (pos.x>300 and pos.x<370 and pos.y>200 and pos.y< (200+25)){        //easy level
                        gameptr=new Game();
                        clickSound.play();
                        window.setVisible(false);
                        askName();
                        writeFile.open("score/score.txt",std::ios::app);
                        writeFile<<playerName<<"\t-\t";
                        writeFile.close();
                        scoreString=gameptr->createMaze(21);
                        writeFile.open("score/score.txt",std::ios::app);
                        writeFile<<scoreString<<"\n";
                        writeFile.close();
                        writeFile.open("score/lastScore.txt",std::ios::out);
                        writeFile<<playerName<<"\t-\t"<<scoreString<<"\n";
                        writeFile.close();
                        showPlayOptions=false;
                        window.setVisible(true);
                        delete gameptr;
                    }
                    else if (pos.x>300 and pos.x<370 and pos.y>250 and pos.y< (250+25)){        //medium level
                        gameptr=new Game();
                        clickSound.play();
                        window.setVisible(false);
                        askName();
                        writeFile.open("score/score.txt",std::ios::app);
                        writeFile<<playerName<<"\t-\t";
                        writeFile.close();
                        scoreString=gameptr->createMaze(25);
                        writeFile.open("score/score.txt",std::ios::app);
                        writeFile<<scoreString<<"\n";
                        writeFile.close();
                        writeFile.open("score/lastScore.txt",std::ios::out);
                        writeFile<<playerName<<"\t-\t"<<scoreString<<"\n";
                        writeFile.close();
                        showPlayOptions=false;
                        window.setVisible(true);
                        delete gameptr;
                    }
                    else if (pos.x>300 and pos.x<370 and pos.y>300 and pos.y< (300+25)){        //hard level
                        gameptr=new Game();
                        clickSound.play();
                        window.setVisible(false);
                        askName();
                        writeFile.open("score/score.txt",std::ios::app);
                        writeFile<<playerName<<"\t-\t";
                        writeFile.close();
                        scoreString=gameptr->createMaze(29);
                        writeFile.open("score/score.txt",std::ios::app);
                        writeFile<<scoreString<<"\n";
                        writeFile.close();
                        writeFile.open("score/lastScore.txt",std::ios::out);
                        writeFile<<playerName<<"\t-\t"<<scoreString<<"\n";
                        writeFile.close();
                        showPlayOptions=false;
                        window.setVisible(true);
                        delete gameptr;
                    }
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(Title);
        window.draw(lastScoreText);
        window.draw(scoreText);
        window.draw(playText);
        window.draw(exitText);
        window.draw(generateText);
        window.draw(instructionText);

        if (showPlayOptions){
            window.draw(easyText);
            window.draw(mediumText);
            window.draw(hardText);
        }
        window.display();

    }
}

void Menu::askName(){
    sf::RenderWindow nameAskWindow(sf::VideoMode(640,480),"Name Window");
    nameAskWindow.setFramerateLimit(60);

    nameAskWindow.setIcon(32,32,icon.getPixelsPtr());

    askNameText.setString("Before we begin, please enter your name:");
    bool quit=false;
    while (!quit){
        sf::Event event;
        while (nameAskWindow.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                quit=true;
            }
            if (event.type==sf::Event::KeyPressed){
                if (event.key.code==sf::Keyboard::Return){
                    //done entering name
                    if (!playerName.empty())
                        quit=true;
                }

            }
            if (event.type==sf::Event::TextEntered){
                if ( (event.text.unicode>64 and event.text.unicode<91) or (event.text.unicode>96 and event.text.unicode<123) or event.text.unicode==32){
                    playerName+=char(event.text.unicode);
                }
                else if (event.text.unicode==8){
                    if (!playerName.empty())
                        playerName.pop_back();
                }
            }
        }
        nameAskWindow.clear(sf::Color::Yellow);
        nameAskWindow.draw(questionBox);
        nameAskWindow.draw(askNameText);
        nameAskWindow.draw(answerBox);

        playerNameText.setString(playerName);
        nameAskWindow.draw(playerNameText);

        nameAskWindow.display();
    }
}

void Menu::askName(int){
    sf::RenderWindow sizeAskWindow(sf::VideoMode(640,480),"Maze Size Window");
    sizeAskWindow.setFramerateLimit(60);

    sizeAskWindow.setIcon(32,32,icon.getPixelsPtr());
    askNameText.setString("Before we begin, please enter the size of maze:");
    bool quit=false;
    while (!quit){
        sf::Event event;
        while (sizeAskWindow.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                quit=true;
            }
            if (event.type==sf::Event::KeyPressed){
                if (event.key.code==sf::Keyboard::Return){
                    //done entering size of maze
                    if (!strSizeOfMaze.empty()){
                        sizeOfMaze=std::atoi(strSizeOfMaze.c_str());
                        if (sizeOfMaze%2==0)
                            ++sizeOfMaze;
                        if (sizeOfMaze<11)
                            sizeOfMaze=11;      //make sure maze is not too small
                        else if (sizeOfMaze>999)
                            sizeOfMaze=999;      //make sure maze is not too big
                        quit=true;
                    }
                }

            }
            if (event.type==sf::Event::TextEntered){
                if (event.text.unicode==8){
                    if (!strSizeOfMaze.empty())
                        strSizeOfMaze.pop_back();
                }
                else if (event.text.unicode!=13)
                    strSizeOfMaze+=char(event.text.unicode);
            }
        }
        sizeAskWindow.clear(sf::Color::Yellow);
        sizeAskWindow.draw(questionBox);
        sizeAskWindow.draw(askNameText);
        sizeAskWindow.draw(answerBox);

        playerNameText.setString(strSizeOfMaze);
        sizeAskWindow.draw(playerNameText);

        sizeAskWindow.display();
    }
}
