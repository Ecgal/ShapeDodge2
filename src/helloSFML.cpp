//Created by Evan and Alexia

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
    sf::Vector2<float> squareDestination;
    sf::Vector2<float> intermediatePosition;
    float speed;
    bool moving;
    
public:
    Shapes(int x, int y){
        squarePosition = sf::Vector2f(x, y);
        speed = .0002f;
//        playerShape.setOrigin(300,300);
        squareShape.setPosition (squarePosition);
        squareShape.setSize(sf::Vector2<float>(10,10));
        squareShape.setFillColor(sf::Color::Yellow);
    
        
    }
    
    void move(int x, int y){
        if (!moving){
            squareDestination = sf::Vector2f(x, y);
            moving = true;
        }
       
        if (!reachedDestination(squareDestination.x, squareDestination.y)){
            intermediatePosition.x = squarePosition.x + (squareDestination.x - squarePosition.x) * speed;
            intermediatePosition.y = squarePosition.y + (squareDestination.y - squarePosition.y) * speed;
            std::cout << intermediatePosition.x << ", " << intermediatePosition.y << std::endl;
            squareShape.setPosition(intermediatePosition);
            squarePosition = intermediatePosition;
        } else {
            moving = false;
            std::cout << "Made it to " << squareDestination.x << ", " << squareDestination.y << std::endl;
        }
    }
        
 
               
    bool reachedDestination(float x, float y){
        return (abs(squarePosition.x - x) < 100 && abs(squarePosition.y - y) < 100);
        }
    
    //implement lerp while loop function (takes a position and give it a target location
    // give it a speed & within a given time, split the
    
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
    Shapes shape1(2, 6);
    Shapes shape2(45, 79);
    Shapes shape3(900, 981);
    Shapes shape4(750, 699);
    
    
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
            if(player1.playerShape.getPosition().y + (player1.playerShape.getGlobalBounds().height * 2) > windowHeight)
                player1.playerShape.setPosition(player1.playerShape.getPosition().x, windowHeight - (player1.playerShape.getGlobalBounds().height * 2));
            
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
        
        shape1.move(rand() % 1000, rand() % 1000);
        shape2.move(rand() % 1000, rand() % 1000);
        shape3.move(rand() % 1000, rand() % 1000);
        shape4.move(rand() % 1000, rand() % 1000);
        
        window.clear();//clear canvas
        
        player1.draw(window);
        shape1.draw(window);
        shape2.draw(window);
        shape3.draw(window);
        shape4.draw(window); //put into a vector and iterate through

        
        window.display();//diplay canvas
        
        
        
        ///processEvent ()
        ///Update()
        ///Render()
        
        
        
        
        
        
    }
    
    return 0;
}
