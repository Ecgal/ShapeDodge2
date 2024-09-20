
//  Points.cpp
//  testSFML
//
//  Created by Evan Gallagher on 9/18/24.
//

#include "Points.hpp"

void Points::moveOutOfTheScreen(){
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

void Points::move(int x, int y){
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
    }
}

bool Points::reachedDestination(float x, float y){
    return (abs(pointsPosition.x - x) < 100 && abs(pointsPosition.y - y) < 100);
}

void Points::pointsCreator(std::vector<Points>& pointsVec){
    for (int i = 0; i < 3; i++){
        int randomXCoordinate = rand() % 1000;
        int randomYCoordinate = rand() % 1000;
        Points points (randomXCoordinate, randomYCoordinate);
        points.pointsDestination = sf::Vector2f(rand() % 1000, rand() % 1000);
        pointsVec.push_back(points);
    }
}

void Points::moveDirection(std::vector<Points>& pointsVec){
    for (Points& t: pointsVec){
        int randomX = rand() % 1000;
        int randomY = rand() % 1000;
        t.move(randomX, randomY);
    }
}

void Points::erasePoint(std::vector<Points>& pointsVec, int pointToErase){
    if (pointToErase >= 0 && pointToErase < pointsVec.size()){
        pointsVec.erase(pointsVec.begin() + pointToErase);
    }
}

void Points::collisionAction(std::vector<Points>& pointsVec, Player& player1){
    for (int i = 0; i < pointsVec.size(); ++i){
        if (pointsVec[i].pointsShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())){
            pointsVec[i].erasePoint(pointsVec, i);
            player1.score++;
            int randomXCoordinate = rand() % 1000;
            int randomYCoordinate = rand() % 1000;
            Points newPoint(randomXCoordinate, randomYCoordinate);
            pointsVec.push_back(newPoint);
            std::cout << "Player score: " << player1.score << std::endl;
        }
    }
}

void Points::drawPoints(std::vector<Points>& pointsVec, sf::RenderWindow &window){
    for (Points t: pointsVec){
        t.draw(window);
    }
}

void Points::draw(sf::RenderWindow &window){
    window.draw(pointsShape);
}

