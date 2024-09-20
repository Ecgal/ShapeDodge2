//Created by Evan and Alexia

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <string>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Points.hpp"
//#include "CreateGame.hpp"

int main(int argc, const char * argv[]) {
    Game game;
    
    game.run();
    
    sf::Clock clock;
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();
    
    Enemy enemy(1,10);
    std::vector<Enemy> enemies;
    enemy.enemyCreator(enemies);
    
    Points points(788,900);
    std::vector<Points> point;
    points.pointsCreator(point);
    
    while (game.getWindow().isOpen()){
        float playerSpeed = 200.0f;
        sf::Event event;
        while(game.getWindow().pollEvent(event)){
            if(event.type==sf::Event::Closed){
                game.getWindow().close();
            }
        }
        
        if (game.getPlayer().lives == 0){
            game.getWindow().clear();
            game.getWindow().display();
            continue;
        }
        
        game.getPlayer().move(event);
        
        enemy.moveDirection(enemies);
        enemy.collisionAction(enemies,  game.getPlayer());
        
        points.moveDirection(point);
        points.collisionAction(point,  game.getPlayer());
        
        game.getWindow().clear();
        
        enemy.drawEnemy(enemies, game.getWindow());
        points.drawPoints(point, game.getWindow());
        game.getPlayer().draw(game.getWindow());
        
        game.getWindow().display();
    }
    
    return 0;
}
