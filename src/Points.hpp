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
#include <ctime>
#include <cstdlib>
#include "Player.hpp"
#include "Points.hpp"
#include "CreateGame.hpp"

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
    
    void moveOutOfTheScreen ();
    
    void move(int x, int y);
    
    bool reachedDestination(float x, float y);
    
    void pointsCreator( std::vector<Points>& pointsVec);
    
    void moveDirection(std::vector<Points>& pointsVec);
    
    void erasePoint(std::vector<Points>& pointsVec, int pointToErase);
    
    void collisionAction (std::vector<Points>& pointsVec,  Player& player1);
    
    void drawPoints (std::vector<Points>& pointsVec,  sf::RenderWindow &window );
    
    void draw ( sf::RenderWindow &window );

};







#endif /* Points_hpp */
