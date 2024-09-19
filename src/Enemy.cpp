//
//  Enemy.cpp
//  testSFML
//
//  Created by Evan Gallagher on 9/18/24.
//

#include "Enemy.hpp"

void Enemy::moveOutOfTheScreen () {
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

void Enemy::move(int x, int y){
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

bool Enemy::reachedDestination(float x, float y){
    return (abs(enemyPosition.x - x) < 100 && abs(enemyPosition.y - y) < 100);
}


void Enemy::enemyCreator( std::vector<Enemy>& enemyVec){
    for (int i = 0; i < 5; i++){
        
        int randomXCoordinate = rand() % 1000;
        int randomYCoordinate = rand() % 1000;
        Enemy enemy (randomXCoordinate, randomYCoordinate);
        enemy.enemyDestination = sf::Vector2f(rand() % 1000, rand() % 1000);
        enemyVec.push_back(enemy);
    }
}

void Enemy::moveDirection(std::vector<Enemy>& enemyVec) {
    for (Enemy& t: enemyVec){
        int randomX = rand() % 1000;
       int randomY = rand() % 1000;
        t.move(randomX, randomY);
    }
}

void Enemy::collisionAction (std::vector<Enemy>& enemyVec, const Player& player1){
    for (Enemy& t : enemyVec){
        if(t.enemyShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
            t.enemyShape.setPosition(0, 0);
            t.move(rand() % 1000, rand() % 1000);
        }
    }
}


void Enemy::drawEnemy (std::vector<Enemy>& enemyVec,  sf::RenderWindow &window ){
    for (Enemy t: enemyVec){
        t.draw(window);
        //            t.move(rand() % 1000, rand() % 1000);
    }
}


void Enemy::draw ( sf::RenderWindow &window ){
    window.draw(enemyShape);
}
