//
//  Enemy.hpp
//  testSFML
//
//  Created by Evan Gallagher on 9/18/24.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <string>
#include "Player.hpp"
#include "Points.hpp"
#include "createGame.cpp"


class Enemy{
public:
    sf::CircleShape enemyShape;
    sf::Vector2<float> enemyPosition;
    sf::Vector2<float> enemyDestination;
    sf::Vector2<float> intermediatePosition;
    
    float speed;
    bool moving;
    bool collision;
    int collisionDestationX;
    int collisionDestationY;
    
    Enemy(int x, int y){
        enemyPosition = sf::Vector2f(x, y);
        enemyDestination = sf::Vector2f(x, y);
        speed = .0002f;
        enemyShape.setPosition (enemyPosition);
        enemyShape.setRadius(40);
        enemyShape.setPointCount(3);
        enemyShape.setFillColor(sf::Color::Red);
        collisionDestationX = 500;
        collisionDestationY = 500;
    }
    
    void moveOutOfTheScreen ();
    
    void move(int x, int y);
    
    bool reachedDestination(float x, float y);
    
    void enemyCreator( std::vector<Enemy>& enemyVec);
    
    void moveDirection(std::vector<Enemy>& enemyVec);
    
    void eraseEnemy(std::vector<Enemy>& enemyVec, int enemyToErase);
    
    void collisionAction (std::vector<Enemy>& enemyVec, Player& player1);
    
    void drawEnemy (std::vector<Enemy>& enemyVec,  sf::RenderWindow &window );
   
    void draw ( sf::RenderWindow &window );
    
};
























#endif /* Enemy_hpp */





















