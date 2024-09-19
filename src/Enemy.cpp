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


void Enemy::eraseEnemy(std::vector<Enemy>& enemyVec, int enemyToErase){
    if( enemyToErase >= 0 && enemyToErase <enemyVec.size()){
        enemyVec.erase(enemyVec.begin() + enemyToErase);
        
        
    }
}

void Enemy::collisionAction (std::vector<Enemy>& enemyVec,  Player& player1){
    for (int i = 0; i < enemyVec.size(); ++i) {
        if(enemyVec[i].enemyShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
            player1.lives = player1.lives - 1;
            player1.reduceLife();
            if(player1.lives > 0){
                
                enemyVec[i].eraseEnemy(enemyVec, i);
                
                int randomXCoordinate = rand() % 1000;
                int randomYCoordinate = rand() % 1000;
                
                Enemy newEnemy (randomXCoordinate, randomYCoordinate);
                enemyVec.push_back(newEnemy);
                std::cout<<"Player Lives: "<<player1.lives<<std::endl;
            }else{
                std::cout<<"GAME OVER"<<std::endl;
            }
                
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

