#include "Game.h"

Game::Game(){
    wonMusic.openFromFile("sound/gameWon.ogg");
    lostMusic.openFromFile("sound/gameOver.wav");

    font.loadFromFile("LCALLIG.ttf");
    allTexture.loadFromFile("layer.png");
    playerTexture.loadFromFile("car.png");

    textbox.setFillColor(sf::Color(0,0,0) );

    winMessage.setString("CONGRATULATIONS YOU DID IT!!!");
    winMessage.setFont(font);
    winMessage.setCharacterSize(20);
    winMessage.setPosition(-100,0);
    winMessage.setFillColor(sf::Color::Red);

    lostMessage.setString("Sorry, time's up!!!");
    lostMessage.setFont(font);
    lostMessage.setCharacterSize(20);
    lostMessage.setFillColor(sf::Color::Red);
}

Game::~Game()
{
    //dtor
}

std::string Game::NtoS(int number){
    std::ostringstream ss;
    ss<<number;
    return ss.str();
}

void Game::showTime(int remaining){
    std::string timeRemaining;
    std::string minute,second;

    timer.setPosition(view.getCenter()-sf::Vector2f(400-view.getSize().x/2,view.getSize().y/2));
    timer.setFillColor(sf::Color::Green);
    timer.setSize(sf::Vector2f(250,30));


    timeText.setFont(font);
    timeText.setCharacterSize(18);
    timeText.setPosition(view.getCenter()-sf::Vector2f(397-view.getSize().x/2,view.getSize().y/2-2));
    timeText.setFillColor(sf::Color::Red);

    minute = NtoS(int(remaining/60));
    second = NtoS(remaining%60);

    if(int(remaining/60)<10)
        minute='0'+minute;
    if(remaining%60<10)
        second='0'+second;
    timeRemaining = "Time Remaining:   " + minute + ":" + second;
    timeText.setString(timeRemaining);

}

void Game::move(int direction){
//    view.setCenter(playerSprite.getPosition());
    int Xmin = playerSprite.getPosition().x /50 - 2;
    if (Xmin<0)
        Xmin=0;
    int Xmax = playerSprite.getPosition().x /50 + 2;
    if (Xmax>gameWidth)
        Xmax = gameWidth;
    int Ymin = playerSprite.getPosition().y /50 - 1;
    if (Ymin<0)
        Ymin=0;
    int Ymax = playerSprite.getPosition().y /50 + 2;
    if (Ymax>gameWidth)
        Ymax = gameWidth;
    if(direction == UP){
        playerSprite.move(0,-5);
        view.move(0,-5);
        playerSprite.setRotation(270);
        for (int i=Xmin; i<Xmax; ++i){
            for (int j=Ymin; j<Ymax; ++j){
                if (visited[i][j]==false){
                    wallSprite.setPosition(i*50,j*50);
                    if(playerSprite.getGlobalBounds().intersects(wallSprite.getGlobalBounds())){
                        playerSprite.move(0,5);
                        view.move(0,5);
                        return;
                    }
                }
            }
        }
    }
      if(direction == DOWN){
        playerSprite.move(0,5);
        view.move(0,5);
        playerSprite.setRotation(90);
        for (int i=Xmin; i<Xmax; ++i){
            for (int j=Ymin; j<Ymax; ++j){
                if (visited[i][j]==false){
                    wallSprite.setPosition(i*50,j*50);
                    if(playerSprite.getGlobalBounds().intersects(wallSprite.getGlobalBounds())){
                        playerSprite.move(0,-5);
                        view.move(0,-5);
                        return;
                    }
                }
            }
        }
    }
      if(direction == RIGHT){
        playerSprite.move(5,0);
        view.move(5,0);
        playerSprite.setRotation(0);
        for (int i=Xmin; i<Xmax; ++i){
            for (int j=Ymin; j<Ymax; ++j){
                if (visited[i][j]==false){
                    wallSprite.setPosition(i*50,j*50);
                    if(playerSprite.getGlobalBounds().intersects(wallSprite.getGlobalBounds())){
                        playerSprite.move(-5,0);
                        view.move(-5,0);
                        return;
                    }
                }
            }
        }
    }
      if(direction == LEFT){
        playerSprite.move(-5,0);
        view.move(-5,0);
        playerSprite.setRotation(180);
        for (int i=Xmin; i<Xmax; ++i){
            for (int j=Ymin; j<Ymax; ++j){
                if (visited[i][j]==false){
                    wallSprite.setPosition(i*50,j*50);
                    if(playerSprite.getGlobalBounds().intersects(wallSprite.getGlobalBounds())){
                        playerSprite.move(5,0);
                        view.move(5,0);
                    }
                }
            }
        }
    }
}

std::string Game::createMaze(int width,bool isPlay){
    sf::RenderWindow window(sf::VideoMode(1920,1080),"Dizzy Maze",sf::Style::Fullscreen);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);                                   //set the frame rate to 60
    window.setVerticalSyncEnabled(true);

    playerSprite.setPosition((width-3)*50 +15,(width-3)*50 +15);
    playerSprite.setTexture(playerTexture);
    playerSprite.setOrigin(15,15);          //texture size is 30*30

    wallSprite.setTexture(allTexture);
    wallSprite.setTextureRect(sf::IntRect(150,0,50,50));

    sf::Sprite solutionSprite(allTexture);
    solutionSprite.setTextureRect(sf::IntRect(0,0,50,50));
    solutionSprite.setColor(sf::Color(255,255,255) );
    solutionSprite.setOrigin(25,25);        //texture size is 50*50

    sf::Sprite startSprite(allTexture);
    startSprite.setTextureRect(sf::IntRect(50,0,50,50));
    startSprite.setPosition((width-3)*50,(width-3)*50);

    sf::Sprite endSprite(allTexture);
    endSprite.setTextureRect(sf::IntRect(100,0,50,50));
    endSprite.setPosition(2*50,2*50);

    textbox.setPosition(width/2,width/2);
    textbox.setSize(sf::Vector2f(width/3,width/3));

    gameWidth = width;
    remaining=timeLimit.asSeconds()-6;

    sf::Image icon;                              //
    icon.loadFromFile("icon.png");              // Set the icon of the window
    window.setIcon(32,32,icon.getPixelsPtr()); //


    view.setCenter(width/2*50, width/2*50);
    view.setSize(width*50+400,width*50);

    for(x=0;x<width;x++){
        for(y=0;y<width;y++){
            visited[x][y]=false;
        }
    }
    for(x=0;x<width-2;x++){
        visited[x][0]=true;
        visited[x][width-1]=true;
        visited[0][x]=true;
        visited[width-1][x]=true;
    }
    x=2;
    y=2;
    int score=0;
    visited[2][2]=true;
    srand(time(NULL));
    bool quit = false;
    while(!quit){
        direction = rand()%4;
        if(visited[x+2][y] && visited[x-2][y] && visited[x][y+2] && visited[x][y-2]){
            x=path.top().getx();
            y=path.top().gety();
            path.pop();
        }
        else{
            path.push(StackVector(x,y));
        }
        if (x==width-3 and y==width-3){
            solution = path;
            path.pop();
            x=path.top().getx();
            y=path.top().gety();
        }
        if(path.empty()){
            quit = true;
        }
        if(direction==RIGHT && !visited[x+2][y]){
            visited[x+2][y]=true;
            visited[x+1][y]=true;
            x+=2;
        }
        if(direction==LEFT && !visited[x-2][y]){
            visited[x-2][y]=true;
            visited[x-1][y]=true;
            x-=2;
        }
        if(direction==DOWN && !visited[x][y+2]){
            visited[x][y+2]=true;
            visited[x][y+1]=true;
            y+=2;
        }
        if(direction==UP && !visited[x][y-2]){
            visited[x][y-2]=true;
            visited[x][y-1]=true;
            y-=2;
        }

    }
    for(x=0;x<width-2;x++){
        visited[x][0]=false;
        visited[x][1]=false;
        visited[x][width-2]=false;
        visited[x][width-1]=false;
        visited[0][x]=false;
        visited[1][x]=false;
        visited[width-2][x]=false;
        visited[width-1][x]=false;
    }
    clock.restart();
    quit=false;
    while (!quit){
        sf::Vector2f playerPosition=playerSprite.getPosition();
        if (displayCount>0){
            timeElapsed=clock.getElapsedTime();
            timeRemaining=timeLimit-timeElapsed;
            remaining=timeRemaining.asSeconds();
        }

        sf::Event event;
        if (window.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                quit=true;
//                window.close();
            }
            if (event.type==sf::Event::KeyPressed){     //Handle all key presses

                if (event.key.code==sf::Keyboard::Up && !isPlay){
                    view.move(0,-10);                     //moves camera upwards
                }
                if (event.key.code==sf::Keyboard::Down && !isPlay){
                    view.move(0,10);                        //moves camera downwards
                }
                 if (event.key.code==sf::Keyboard::Right && !isPlay){
                    view.move(10,0);                     //move camera towards right
                }
                if (event.key.code==sf::Keyboard::Left && !isPlay){
                    view.move(-10,0);                        //move camera towards left
                }
                 if (event.key.code==sf::Keyboard::Space && !isPlay){
                    view.setCenter(playerSprite.getPosition());
                    view.setSize(600,400);
                }
                if (event.key.code==sf::Keyboard::Q && !isPlay){
                    view.zoom(1.1);                        //zoom out
                }
                if (event.key.code==sf::Keyboard::E && !isPlay){
                    view.zoom(0.9);                        //zoom in
                }
                if (event.key.code==sf::Keyboard::F1 && !isPlay){
                    if (showSolution==false)
                        showSolution=true;
                    else
                        showSolution=false;
                }

                if (event.key.code==sf::Keyboard::Escape){
                    quit=true;
                }

                if (event.key.code==sf::Keyboard::W){
                   moveUp=true;
                   moveDown=false;
                   moveLeft=false;
                   moveRight=false;
                }
                else if (event.key.code==sf::Keyboard::S){
                    moveUp=false;
                   moveDown=true;
                   moveLeft=false;
                   moveRight=false;
                }
                else if (event.key.code==sf::Keyboard::A){
                   moveUp=false;
                   moveDown=false;
                   moveLeft=true;
                   moveRight=false;
                }
                else if (event.key.code==sf::Keyboard::D){
                   moveUp=false;
                   moveDown=false;
                   moveLeft=false;
                   moveRight=true;
                }

            }
        }
        if (moveUp)
            move(UP);
        if (moveDown)
            move(DOWN);
        if (moveLeft)
            move(LEFT);
        if (moveRight)
            move(RIGHT);
        if (remaining<1 && isPlay) {
             //lost the game
            showTime(remaining);
            window.draw(timer);
            window.draw(timeText);
            lostMusic.play();
            textbox.setPosition(view.getCenter().x-300, view.getCenter().y-100);
            textbox.setSize(sf::Vector2f(1280,150));
            window.draw(textbox);
            lostMessage.setPosition(view.getCenter().x-100, view.getCenter().y);
            window.draw(lostMessage);
            window.display();
            sf::sleep(sf::milliseconds(2000));
            quit=true;
        }
        else if ( (playerPosition.x > 2*50 and playerPosition.x < 3*50 ) and ( playerPosition.y > 2*50 and playerPosition.y < 3*50 ) ) {
             //completed the game
            wonMusic.play();
            textbox.setPosition(-300,-100);
            textbox.setSize(sf::Vector2f(1280,150) );

            view.setCenter(playerPosition);
            view.setSize(600,400);
            window.setView(view);

            window.draw(textbox);
            window.draw(winMessage);
            window.display();
            sf::sleep(sf::milliseconds(2000));
            score = remaining*gameWidth;
            quit=true;

        }

        window.clear(sf::Color::White);
        window.setView(view);

        temp = solution;
        if(showSolution){
            while(!temp.empty()){
                x=temp.top().getx();
                y=temp.top().gety();
                solutionSprite.setPosition(x*50+25,y*50+25);
                window.draw(solutionSprite);
                temp.pop();
                if(!temp.empty()){
                    x-=(x-temp.top().getx())/2;
                    y-=(y-temp.top().gety())/2;
                    posx=temp.top().getx();
                    posy=temp.top().gety();
                    if (posx-x < 0)
                        solutionSprite.setRotation(180);
                    else if (posx-x > 0)
                        solutionSprite.setRotation(0);
                    else if (posy-y < 0)
                        solutionSprite.setRotation(270);
                    else if (posy-y > 0)
                        solutionSprite.setRotation(90);
                    solutionSprite.setPosition(x*50+25,y*50+25);
                    window.draw(solutionSprite);
                }
            }
        }
        int Xmin = (view.getCenter().x - view.getSize().x/2)/50 - 1;
        if (Xmin<0)
            Xmin=0;
        int Xmax = (view.getCenter().x + view.getSize().x/2)/50 + 2;
        if (Xmax>width)
            Xmax = width;
        int Ymin = (view.getCenter().y - view.getSize().y/2)/50 - 1;
        if (Ymin<0)
            Ymin=0;
        int Ymax = (view.getCenter().y + view.getSize().y/2)/50 + 2;
        if (Ymax>width)
            Ymax = width;
        for (int i=Xmin; i<Xmax; ++i){
            for (int j=Ymin; j<Ymax; ++j){
                if (visited[i][j]==false){
                    wallSprite.setPosition(i*50,j*50);
                    window.draw(wallSprite);
                }
            }
        }
        showTime(remaining);
        window.draw(startSprite);
        window.draw(endSprite);
        if(isPlay){
            window.draw(timer);
            window.draw(timeText);
        }
        window.draw(playerSprite);

        window.display();

        while (displayCount++<1){
            sf::sleep(sf::milliseconds(6000));           //                                     //
            view.setCenter((width-3)*50,(width-3)*50);  // This creates the transition effect  //
            view.setSize(600,400);                     //                                     //
        }
    }

    return NtoS(score);
}
