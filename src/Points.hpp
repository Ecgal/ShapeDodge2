//
//  Points.hpp
//  testSFML
//
//  Created by Evan Gallagher on 9/18/24.
//

#ifndef Points_hpp
#define Points_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <string>

//points
class Points{
public:
    sf::RectangleShape pointsShape;
    sf::Vector2<float> pointsPosition;
    sf::Vector2<float> pointsDestination;
    sf::Vector2<float> intermediatePosition;
    float speed;
    bool moving;
    bool collision;
    float collisionDestationX;
    float collisionDestationY;
    
public:
    Points(int x, int y){
        pointsPosition = sf::Vector2f(x, y);
        speed = .0002f;
        pointsShape.setPosition (pointsPosition);
        pointsShape.setSize(sf::Vector2<float>(10,10));
        pointsShape.setFillColor(sf::Color::Yellow);
        collisionDestationX=1100;
        collisionDestationY =500;
    }
    
    void moveOutOfTheScreen () {
        if (!moving){
            pointsDestination = sf::Vector2f(collisionDestationX, collisionDestationY);
            moving = true;
        }
        if (!reachedDestination(pointsDestination.x, pointsDestination.y)){
            intermediatePosition.x = pointsPosition.x + (pointsDestination.x - pointsPosition.x) * speed;
            intermediatePosition.y = pointsPosition.y + (pointsDestination.y - pointsPosition.y) * speed;
            pointsShape.setPosition(intermediatePosition);
            pointsPosition = intermediatePosition;
        } else {
            moving = false;
        }
    }
    
    void move(int x, int y){
        if(!collision){
            if (!moving){
                pointsDestination = sf::Vector2f(x, y);
                moving = true;
            }
            if (!reachedDestination(pointsDestination.x, pointsDestination.y)){
                intermediatePosition.x = pointsPosition.x + (pointsDestination.x - pointsPosition.x) * speed;
                intermediatePosition.y = pointsPosition.y + (pointsDestination.y - pointsPosition.y) * speed;
                pointsShape.setPosition(intermediatePosition);
                pointsPosition = intermediatePosition;
            } else {
                moving = false;
            }
        } else {
//            moveOutOfTheScreen();
        }
    }
    
    bool reachedDestination(float x, float y){
        return (abs(pointsPosition.x - x) < 100 && abs(pointsPosition.y - y) < 100);
    }
    
    void draw ( sf::RenderWindow &window ){
        window.draw(pointsShape);
    }
};








#endif /* Points_hpp */
