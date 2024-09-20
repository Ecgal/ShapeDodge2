//
//  createGame.hpp
//  testSFML
//
//  Created by Evan Gallagher on 9/18/24.
//

#ifndef createGame_hpp
#define createGame_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Points.hpp"
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <string>

class Game {
private:
    float windowHeight = 1000;
    float windowWidth = 1000;
    sf::RenderWindow window;
    Player player1;
    
public:
    Game ():window(sf::VideoMode(windowHeight, windowWidth),"my first SFML game"), player1(windowHeight,windowWidth){
        player1.setWindowDimessions(1000,1000);
    }
    
    sf::RenderWindow& getWindow(){
        return window;
    }
    
    Player& getPlayer() {
        return player1;
    }
    
    void run(){}
    
};

#endif /* createGame_hpp */
