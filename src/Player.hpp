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
    int score;

public:
    Player(){
        score = 0;
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


//class Player{
//public:
//    sf::RectangleShape playerShape;
//    sf::Vector2<float> playerPosition;
//    std::vector<sf::RectangleShape> playerLives;
//    float speed;
//    int _gameBoardHeight, _gameBoardWidth;
//    
//public:
//    Player(int gameBoardHeight, int gameBoardWidth){
//        playerPosition = sf::Vector2f(300,300);
//        speed = 5.0f;
//        _gameBoardWidth = gameBoardWidth;
//        _gameBoardHeight = gameBoardHeight;
//        playerShape.setPosition (playerPosition);
//        playerShape.setSize(sf::Vector2<float>(50,50));
//        playerShape.setFillColor(sf::Color::Transparent);
//        playerShape.setOutlineColor(sf::Color::Green);
//        playerShape.setOutlineThickness(5);
//        for (int i = 0; i < 5; i++){
//            sf::RectangleShape lifeShape;
//            lifeShape.setSize(sf::Vector2<float>(10, 10));
//            lifeShape.setFillColor(sf::Color::Magenta);
//            lifeShape.setPosition(playerPosition.x + 50, playerPosition.y + i * 10);
//            playerLives.push_back(lifeShape);
//            std::cout << "You created a new triangle!" << std::endl;
//        }
//        
//    }
//    void draw ( sf::RenderWindow &window ){
//        window.draw(playerShape);
//        for (int i = 0; i < 5; i++){
//            window.draw(playerLives[i]);
//        }
//    }
//    
//    void move (sf::Event event){
//        //Up Arrow
//        if (event.key.code == sf::Keyboard::Up ){
//            std::cout<<"up key"<<std::endl;
//            playerShape.move(0.f ,-0.1);
//            for (int i = 0; i < 5; i++){
//                playerLives[i].move(0.f, -0.1);
//            }
//            if(playerShape.getPosition().y < 0.f){
//                playerShape.move(0.f, 0.1);
//                for (int i = 0; i < 5; i++){
//                    playerLives[i].move(0.f, 0.1);
//                }
//            }
//            
//            //Down Arrow
//        } else if (event.key.code == sf::Keyboard::Down ){
//            playerShape.move(0.f ,0.1);
//            for (int i = 0; i < 5; i++){
//                playerLives[i].move(0.f, 0.1);
//            }
//            if(playerShape.getPosition().y + (playerShape.getGlobalBounds().height * 2) > _gameBoardHeight){
//                playerShape.move(0.f, -0.1);
//                for (int i = 0; i < 5; i++){
//                    playerLives[i].move(0.f, -0.1);
//                }
//            }
//            //Left Arrow
//        } else if (event.key.code == sf::Keyboard::Left ){
//            playerShape.move(-0.1, 0.f);
//            for (int i = 0; i < 5; i++){
//                playerLives[i].move(-0.1, 0.f);
//            }
//            if(playerShape.getPosition().x < 0.f){
//                playerShape.move(0.1, 0.0f);
//                for (int i = 0; i < 5; i++){
//                    playerLives[i].move(0.1, 0.0f);
//                }
//            }
//            
//            //Right Arrow
//        } else if (event.key.code == sf::Keyboard::Right){
//            playerShape.move( 0.1, 0.0f);
//            for (int i = 0; i < 5; i++){
//                playerLives[i].move(0.1, 0.0f);
//            }
//            if(playerShape.getPosition().x + playerShape.getGlobalBounds().width > _gameBoardWidth){
//                playerShape.move(-0.1, 0.0f);
//                for (int i = 0; i < 5; i++){
//                    playerLives[i].move(-0.1, 0.0f);
//                }
//            }
//        }
//    }
//    
//};
//














#endif /* Player_hpp */
