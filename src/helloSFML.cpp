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
    bool collision;
    int collisionDestationX;
    int collisionDestationY;
    
public:
    Shapes(int x, int y){
        squarePosition = sf::Vector2f(x, y);
        speed = .0002f;
        squareShape.setPosition (squarePosition);
        squareShape.setSize(sf::Vector2<float>(10,10));
        squareShape.setFillColor(sf::Color::Yellow);
        collisionDestationX=1100;
        collisionDestationY =500;
    }
    
    void moveOutOfTheScreen () {
        if (!moving){
            squareDestination = sf::Vector2f(collisionDestationX, collisionDestationY);
            moving = true;
        }
        if (!reachedDestination(squareDestination.x, squareDestination.y)){
            intermediatePosition.x = squarePosition.x + (squareDestination.x - squarePosition.x) * speed;
            intermediatePosition.y = squarePosition.y + (squareDestination.y - squarePosition.y) * speed;
            squareShape.setPosition(intermediatePosition);
            squarePosition = intermediatePosition;
        } else {
            moving = false;
        }
    }
    
    void move(int x, int y){
        if(!collision){
            if (!moving){
                squareDestination = sf::Vector2f(x, y);
                moving = true;
            }
            if (!reachedDestination(squareDestination.x, squareDestination.y)){
                intermediatePosition.x = squarePosition.x + (squareDestination.x - squarePosition.x) * speed;
                intermediatePosition.y = squarePosition.y + (squareDestination.y - squarePosition.y) * speed;
                squareShape.setPosition(intermediatePosition);
                squarePosition = intermediatePosition;
            } else {
                moving = false;
            }
        } else {
            moveOutOfTheScreen();
        }
    }
    
    bool reachedDestination(float x, float y){
        return (abs(squarePosition.x - x) < 100 && abs(squarePosition.y - y) < 100);
    }
    
    void draw ( sf::RenderWindow &window ){
        window.draw(squareShape);
    }
};

class Triangle{
public:
    sf::CircleShape triangleShape;
    sf::Vector2<float> squarePosition;
    sf::Vector2<float> squareDestination;
    sf::Vector2<float> intermediatePosition;
    float speed;
    bool moving;
    bool collision;
    int collisionDestationX;
    int collisionDestationY;
    
public:
    Triangle(int x, int y){
        squarePosition = sf::Vector2f(x, y);
        speed = .0002f;
        triangleShape.setPosition (squarePosition);
        triangleShape.setRadius(40);
        triangleShape.setPointCount(3);
        triangleShape.setFillColor(sf::Color::Red);
        collisionDestationX=1100;
        collisionDestationY =500;
    }
    
    void moveOutOfTheScreen () {
        if (!moving){
            squareDestination = sf::Vector2f(collisionDestationX, collisionDestationY);
            moving = true;
        }
        if (!reachedDestination(squareDestination.x, squareDestination.y)){
            intermediatePosition.x = squarePosition.x + (squareDestination.x - squarePosition.x) * speed;
            intermediatePosition.y = squarePosition.y + (squareDestination.y - squarePosition.y) * speed;
            triangleShape.setPosition(intermediatePosition);
            squarePosition = intermediatePosition;
        } else {
            moving = false;
        }
    }
    
    void move(int x, int y){
        if(!collision){
            if (!moving){
                squareDestination = sf::Vector2f(x, y);
                moving = true;
            }
            if (!reachedDestination(squareDestination.x, squareDestination.y)){
                intermediatePosition.x = squarePosition.x + (squareDestination.x - squarePosition.x) * speed;
                intermediatePosition.y = squarePosition.y + (squareDestination.y - squarePosition.y) * speed;
                triangleShape.setPosition(intermediatePosition);
                squarePosition = intermediatePosition;
            } else {
                moving = false;
            }
        }
    }
    
    bool reachedDestination(float x, float y){
        return (abs(squarePosition.x - x) < 100 && abs(squarePosition.y - y) < 100);
    }
    //implement lerp while loop function (takes a position and give it a target location
    // give it a speed & within a given time, split the
    void draw ( sf::RenderWindow &window ){
        window.draw(triangleShape);
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
    //  Game game;
    //  game.run();
    float windowHeight = 1000;
    float windowWidth = 1000;
    sf::RenderWindow window (sf::VideoMode(windowHeight, windowWidth),"my first SFML game");
    
    Player player1
    
    Shapes shape1(2, 6);
    Shapes shape2(45, 79);
    Shapes shape3(900, 981);
    Shapes shape4(750, 699);
    
    Triangle triangle1 (60,90);
    Triangle triangle2 (600,900);
    Triangle triangle3 (50,900);
    Triangle triangle4 (6,9);
    
    while (window.isOpen()){
        float playerSpeed = 200.0f;
        sf::Event event;
        while( window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
            //Up Arrow
        if (event.key.code == sf::keyboard::Up ){
            std::cout<<"up key"<<std::endl;
            player1.playerShape.move(0.f ,-0.1);
            if(player1.playerShape.getPosition().y < 0.f)
                player1.playerShape.setPosition(player1.playerShape.getPosition().x, 0.f);
            
            //Down Arrow
        }else if (event.key.code == sf::keyboard::Down ){
            player1.playerShape.move(0.f ,0.1);
            if(player1.playerShape.getPosition().y + (player1.playerShape.getGlobalBounds().height * 2) > windowHeight)
                player1.playerShape.setPosition(player1.playerShape.getPosition().x, windowHeight - (player1.playerShape.getGlobalBounds().height * 2));
            
            //Left Arrow
        }else if (event.key.code == sf::keyboard::Left ){
            player1.playerShape.move(-0.1, 0.f);
            if(player1.playerShape.getPosition().x < 0.f)
                player1.playerShape.setPosition(0.f, player1.playerShape.getPosition().y);
            
            //Right Arrow
        }else if (event.key.code == sf::keyboard::Right){
            player1.playerShape.move( 0.1, 0.0f);
            if(player1.playerShape.getPosition().x + player1.playerShape.getGlobalBounds().width > windowWidth)
                player1.playerShape.setPosition(windowWidth - player1.playerShape.getGlobalBounds().width, player1.playerShape.getPosition().y);
        }
        
        shape1.move(rand() % 1000, rand() % 1000);
        shape2.move(rand() % 1000, rand() % 1000);
        shape3.move(rand() % 1000, rand() % 1000);
        shape4.move(rand() % 1000, rand() % 1000);
        
        triangle1.move(rand() % 1000, rand() % 1000);
        triangle2.move(rand() % 1000, rand() % 1000);
        triangle3.move(rand() % 1000, rand() % 1000);
        triangle4.move(rand() % 1000, rand() % 1000);
        
        if (shape1.squareShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
            //      shape1.intermediatePosition (rand() % 1000, rand() % 1000);
            shape1.squareShape.move(rand() % 1000, rand() % 1000); /*- (int)shape1.squareShape.getGlobalBounds().width), 0)*/
            shape1.collision =true;
        }
        
        if (triangle1.triangleShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
            //      shape1.intermediatePosition (rand() % 1000, rand() % 1000);
            triangle1.triangleShape.move(rand() % 1000, rand() % 1000); /*- (int)shape1.squareShape.getGlobalBounds().width), 0)*/
            triangle1.collision =true;
        }
        
        window.clear();//clear canvas
        
        player1.draw(window);
        
        shape1.draw(window);
        shape2.draw(window);
        shape3.draw(window);
        shape4.draw(window); //put into a vector and iterate through
        
        triangle1.draw(window);
        triangle2.draw(window);
        triangle3.draw(window);
        triangle4.draw(window);
        window.display();//diplay canvas
        ///processEvent ()
        ///Update()
        ///Render()
        //
    }
    return 0;
};
