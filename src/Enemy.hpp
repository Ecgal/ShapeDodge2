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
    
public:
    Enemy(int x, int y){
        enemyPosition = sf::Vector2f(x, y);
        speed = .0002f;
        enemyShape.setPosition (enemyPosition);
        enemyShape.setRadius(40);
        enemyShape.setPointCount(3);
        enemyShape.setFillColor(sf::Color::Red);
        collisionDestationX = 500;
        collisionDestationY = 500;
    }
    
    
    
    void moveOutOfTheScreen () {
        if (!moving){
            enemyDestination = sf::Vector2f(collisionDestationX, collisionDestationY);
            moving = true;
        }
        if (!reachedDestination(enemyDestination.x, enemyDestination.y)){
            intermediatePosition.x = enemyPosition.x + (enemyDestination.x - enemyPosition.x) * speed;
            intermediatePosition.y = enemyPosition.y + (enemyDestination.y - enemyPosition.y) * speed;
            enemyShape.setPosition(intermediatePosition);
            enemyPosition = intermediatePosition;
        } else {
            moving = false;
        }
    }
    
    void move(int x, int y){
        if(!collision){
            if (!moving){
                enemyDestination = sf::Vector2f(x, y);
                moving = true;
            }
            if (!reachedDestination(enemyDestination.x, enemyDestination.y)){
                intermediatePosition.x = enemyPosition.x + (enemyDestination.x - enemyPosition.x) * speed;
                intermediatePosition.y = enemyPosition.y + (enemyDestination.y - enemyPosition.y) * speed;
                enemyShape.setPosition(intermediatePosition);
                enemyPosition = intermediatePosition;
            } else {
                moving = false;
            }
        }else{
            moveOutOfTheScreen();
        }
    }
    
    bool reachedDestination(float x, float y){
        return (abs(enemyPosition.x - x) < 100 && abs(enemyPosition.y - y) < 100);
    }
    
    void draw ( sf::RenderWindow &window ){
        window.draw(enemyShape);
    }
};
























#endif /* Enemy_hpp */
