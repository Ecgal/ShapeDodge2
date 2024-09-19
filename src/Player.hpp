//
//  Player.hpp
//  testSFML
//
//  Created by Evan Gallagher on 9/18/24.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <string>

class Player{
public:
    sf::RectangleShape playerShape;
    sf::Vector2<float> playerPosition;
    float speed;
    
public:
    Player(){
        playerPosition = sf::Vector2f(300,300);
        speed = 5.0f;
        playerShape.setPosition (playerPosition);
        playerShape.setSize(sf::Vector2<float>(50,50));
        playerShape.setFillColor(sf::Color::Transparent);
        playerShape.setOutlineColor(sf::Color::Green);
        playerShape.setOutlineThickness(5);
    }
    void draw ( sf::RenderWindow &window ){
        window.draw(playerShape);
    }
};















#endif /* Player_hpp */
