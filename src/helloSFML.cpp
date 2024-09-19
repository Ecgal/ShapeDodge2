






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
#include "createGame.hpp"

//#include

//class Player{
//public:
//    sf::RectangleShape playerShape;
//    sf::Vector2<float> playerPosition;
//    float speed;
//
//public:
//    Player(){
//        playerPosition = sf::Vector2f(300,300);
//        speed = 5.0f;
//        playerShape.setPosition (playerPosition);
//        playerShape.setSize(sf::Vector2<float>(50,50));
//        playerShape.setFillColor(sf::Color::Transparent);
//        playerShape.setOutlineColor(sf::Color::Green);
//        playerShape.setOutlineThickness(5);
//    }
//    void draw ( sf::RenderWindow &window ){
//        window.draw(playerShape);
//    }
//};
////points
//class Points{
//public:
//    sf::RectangleShape pointsShape;
//    sf::Vector2<float> pointsPosition;
//    sf::Vector2<float> pointsDestination;
//    sf::Vector2<float> intermediatePosition;
//    float speed;
//    bool moving;
//    bool collision;
//    float collisionDestationX;
//    float collisionDestationY;
//
//public:
//    Points(int x, int y){
//        pointsPosition = sf::Vector2f(x, y);
//        speed = .0002f;
//        pointsShape.setPosition (pointsPosition);
//        pointsShape.setSize(sf::Vector2<float>(10,10));
//        pointsShape.setFillColor(sf::Color::Yellow);
//        collisionDestationX=1100;
//        collisionDestationY =500;
//    }
//
//    void moveOutOfTheScreen () {
//        if (!moving){
//            pointsDestination = sf::Vector2f(collisionDestationX, collisionDestationY);
//            moving = true;
//        }
//        if (!reachedDestination(pointsDestination.x, pointsDestination.y)){
//            intermediatePosition.x = pointsPosition.x + (pointsDestination.x - pointsPosition.x) * speed;
//            intermediatePosition.y = pointsPosition.y + (pointsDestination.y - pointsPosition.y) * speed;
//            pointsShape.setPosition(intermediatePosition);
//            pointsPosition = intermediatePosition;
//        } else {
//            moving = false;
//        }
//    }
//
//    void move(int x, int y){
//        if(!collision){
//            if (!moving){
//                pointsDestination = sf::Vector2f(x, y);
//                moving = true;
//            }
//            if (!reachedDestination(pointsDestination.x, pointsDestination.y)){
//                intermediatePosition.x = pointsPosition.x + (pointsDestination.x - pointsPosition.x) * speed;
//                intermediatePosition.y = pointsPosition.y + (pointsDestination.y - pointsPosition.y) * speed;
//                pointsShape.setPosition(intermediatePosition);
//                pointsPosition = intermediatePosition;
//            } else {
//                moving = false;
//            }
//        } else {
////            moveOutOfTheScreen();
//        }
//    }
//
//    bool reachedDestination(float x, float y){
//        return (abs(pointsPosition.x - x) < 100 && abs(pointsPosition.y - y) < 100);
//    }
//
//    void draw ( sf::RenderWindow &window ){
//        window.draw(pointsShape);
//    }
//};
//enemy

//class Enemy{
//public:
//    sf::CircleShape enemyShape;
//    sf::Vector2<float> enemyPosition;
//    sf::Vector2<float> enemyDestination;
//    sf::Vector2<float> intermediatePosition;
//
//
//    float speed;
//    bool moving;
//    bool collision;
//    int collisionDestationX;
//    int collisionDestationY;
//
//public:
//    Enemy(int x, int y){
//        enemyPosition = sf::Vector2f(x, y);
//        speed = .0002f;
//        enemyShape.setPosition (enemyPosition);
//        enemyShape.setRadius(40);
//        enemyShape.setPointCount(3);
//        enemyShape.setFillColor(sf::Color::Red);
//        collisionDestationX = 500;
//        collisionDestationY = 500;
//    }
//
//
//
//    void moveOutOfTheScreen () {
//        if (!moving){
//            enemyDestination = sf::Vector2f(collisionDestationX, collisionDestationY);
//            moving = true;
//        }
//        if (!reachedDestination(enemyDestination.x, enemyDestination.y)){
//            intermediatePosition.x = enemyPosition.x + (enemyDestination.x - enemyPosition.x) * speed;
//            intermediatePosition.y = enemyPosition.y + (enemyDestination.y - enemyPosition.y) * speed;
//            enemyShape.setPosition(intermediatePosition);
//            enemyPosition = intermediatePosition;
//        } else {
//            moving = false;
//        }
//    }
//
//    void move(int x, int y){
//        if(!collision){
//            if (!moving){
//                enemyDestination = sf::Vector2f(x, y);
//                moving = true;
//            }
//            if (!reachedDestination(enemyDestination.x, enemyDestination.y)){
//                intermediatePosition.x = enemyPosition.x + (enemyDestination.x - enemyPosition.x) * speed;
//                intermediatePosition.y = enemyPosition.y + (enemyDestination.y - enemyPosition.y) * speed;
//                enemyShape.setPosition(intermediatePosition);
//                enemyPosition = intermediatePosition;
//            } else {
//                moving = false;
//            }
//        }else{
//            moveOutOfTheScreen();
//        }
//    }
//
//    bool reachedDestination(float x, float y){
//        return (abs(enemyPosition.x - x) < 100 && abs(enemyPosition.y - y) < 100);
//    }
//
//    void draw ( sf::RenderWindow &window ){
//        window.draw(enemyShape);
//    }
//};


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
    
    Player player1;
    
    Points shape1(2, 6);
    Points shape2(45, 79);
    Points shape3(900, 981);
    Points shape4(750, 699);
    
    Enemy enemy(1,10);
    std::vector<Enemy> enemies;
   enemy.enemyCreator(enemies);
 
    Points points(788,900);
    std::vector<Points> point;
   points.pointsCreator(point);

   
//    std::vector<Enemy> enemyCreator;
//
//    for (int i = 0; i < 10; i++){
//        int randomXCoordinate = rand() % 1000;
//        int randomYCoordinate = rand() % 1000;
//        Enemy enemy (randomXCoordinate, randomYCoordinate);
//        enemyCreator.push_back(enemy);
//        std::cout << "You created a new triangle!" << std::endl;
//    }
    
//    Triangle triangle1 (60,90);
//    Triangle triangle2 (600,900);
//    Triangle triangle3 (50,900);
//    Triangle triangle4 (6,9);
    
    while (window.isOpen()){
        float playerSpeed = 200.0f;
        sf::Event event;
        while( window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
            //Up Arrow
        if (event.key.code == sf::Keyboard::Up ){
            player1.playerShape.move(0.f ,-0.1);
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
        
        
        
        
        enemy.moveDirection(enemies);
        enemy.collisionAction(enemies, player1);
        
        points.moveDirection(point);
        points.collisionAction(point, player1);
        
        
        
//        for (Enemy& t: enemyCreator){
//            t.move(rand() % 1000, rand() % 1000);
//        }
//
//        for (Enemy& t : enemyCreator){
//            if (t.enemyShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
//                t.enemyShape.setPosition(0, 0);
//                t.move(rand() % 1000, rand() % 1000);
//                std::cout<<"inside move"<< std::endl;
//            }
//        }
////
//        shape1.move(rand() % 1000, rand() % 1000);
//        shape2.move(rand() % 1000, rand() % 1000);
//        shape3.move(rand() % 1000, rand() % 1000);
//        shape4.move(rand() % 1000, rand() % 1000);
//
//        triangleCreator[0].move(rand() % 1000, rand() % 1000);
//        triangle2.move(rand() % 1000, rand() % 1000);
//        triangle3.move(rand() % 1000, rand() % 1000);
//        triangle4.move(rand() % 1000, rand() % 1000);
//
//        if (shape1.squareShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
//            shape1.squareShape.move(rand() % 1000, rand() % 1000);
//            shape1.collision =true;
//        }
//
//        if (triangle1.triangleShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
//            triangle1.triangleShape.move(rand() % 1000, rand() % 1000);
//            triangle1.collision =true;
//        }
//        if (triangle2.triangleShape.getGlobalBounds().intersects(player1.playerShape.getGlobalBounds())) {
//            triangle2.triangleShape.move(rand() % 1000, rand() % 1000);
//            triangle2.collision =true;
//        }
        
        window.clear();//clear canvas
        enemy.drawEnemy(enemies, window);
        points.drawPoints(point, window);
        player1.draw(window);
        
//        shape1.draw(window);
//        shape2.draw(window);
//        shape3.draw(window);
//        shape4.draw(window); //put into a vector and iterate through
        
//        for (Enemy t: enemyCreator){
//            t.draw(window);
////            t.move(rand() % 1000, rand() % 1000);
//        }
//        triangle1.draw(window);
//        triangle2.draw(window);
//        triangle3.draw(window);
//        triangle4.draw(window);
        window.display();//diplay canvas
        ///processEvent ()
        ///Update()
        ///Render()
        //
    }
    return 0;
};
