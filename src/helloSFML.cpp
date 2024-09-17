//Created by Evan and Alexia

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>

class Player{
public:
    sf::RectangleShape playerShape;
    sf::Vector2<float> playerPosition;
    float speed;
    
public:
    Player(){
        playerPosition = sf::Vector2f(300,300);
        speed = 5.0f;
//        playerShape.setOrigin(300,300);
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


class Shapes{
public:
    sf::RectangleShape squareShape;
    sf::Vector2<float> squarePosition;
    float speed;
    
public:
    Shapes(){
        squarePosition = sf::Vector2f(300,300);
        speed = 5.0f;
//        playerShape.setOrigin(300,300);
        squareShape.setPosition (squarePosition);
        squareShape.setSize(sf::Vector2<float>(10,10));
        squareShape.setFillColor(sf::Color::Yellow);
    
        
    }
    

    
    void draw ( sf::RenderWindow &window ){
        window.draw(squareShape);
    }
    
 
    
    
};



//sf::Clock clock;
//sf::Time deltaTime = clock.restart();
//float dt = deltaTime.asSeconds();

int main(int argc, const char * argv[]) {
   
  
    sf::Clock clock;
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();
        
    
//all he wants in main for final
//    Game game;
//    game.run();
    
    float windowHeight = 1000;
    float windowWidth = 1000;
    sf::RenderWindow window (sf::VideoMode(windowHeight, windowWidth),"my first SFML game");
    
    
    Player player1;
    Shapes shape1;
    
    while (window.isOpen()){
        float playerSpeed = 200.0f;
        
        sf::Event event;
    
        while( window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
        }
            
          
    }
        if (event.key.code == sf::Keyboard::Up ){
                std::cout<<"up key"<<std::endl;
            player1.playerShape.move(0.f  ,-0.1);
            if(player1.playerShape.getPosition().y < 0.f)
                player1.playerShape.setPosition(player1.playerShape.getPosition().x, 0.f);
            
            //Down Arrow
            }else if (event.key.code == sf::Keyboard::Down ){
                player1.playerShape.move(0.f ,0.1);
                if(player1.playerShape.getPosition().y + player1.playerShape.getGlobalBounds().height > windowHeight)
                    player1.playerShape.setPosition(windowHeight - player1.playerShape.getGlobalBounds().height, player1.playerShape.getPosition().x);
                
            //Left Arrow
            }else if (event.key.code == sf::Keyboard::Left ){
                player1.playerShape.move(-0.1, 0.f);
                if(player1.playerShape.getPosition().x < 0.f)
                    player1.playerShape.setPosition(0.f, player1.playerShape.getPosition().y);
                
            //Right Arrow
            }else if (event.key.code == sf::Keyboard::Right){
                player1.playerShape.move( 0.1, 0.0f);
                if(player1.playerShape.getPosition().x + player1.playerShape.getGlobalBounds().width > windowWidth)
                    player1.playerShape.setPosition(windowWidth - player1.playerShape.getGlobalBounds().width, player1.playerShape.getPosition().y);
            }
            
    
            window.clear();//clear canvas
            
            player1.draw(window);
        shape1.draw(window);
        
            window.display();//diplay canvas
            
            
            
            ///processEvent ()
            ///Update()
            ///Render()
            
            
            
         
            
        
    }
    
        return 0;
//
}
