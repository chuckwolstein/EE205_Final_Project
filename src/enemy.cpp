//#include <SFML/Graphics.hpp>
//#include <RectangleShape.hpp>
#include "enemy.hpp"
#define GAME_HEIGHT 500
#define GAME_WIDTH 800
#define CELL_HEIGHT 50
#define CELL_WIDTH 50
#include <iostream>

Enemy::Enemy(){
  setPosition(0,0);
  setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
  speed = 2;
  direction_right = true;
}

Enemy::Enemy(int pos_x, int pos_y){
  setPosition(pos_x, pos_y);
  setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
  setFillColor(sf::Color::White);
  speed = 2;
  direction_right = true;
}

void Enemy::MoveEnemy(){
  sf::Vector2f pos = getPosition();
  if (direction_right){
    pos.x += speed;
    setPosition(pos.x, pos.y);
    if (getPosition().x > GAME_WIDTH)
    {
      setPosition(0 - getSize().x, getPosition().y);
    }
  }
  else if (!direction_right){
    pos.x -= speed;
    setPosition(pos.x,pos.y);
    if (getPosition().x < -50){
      setPosition(GAME_WIDTH + getSize().x, getPosition().y);
    }
  }
}

void Enemy::set_speed(int s){
  speed = s;
}

void Enemy::set_direction(bool d){
  direction_right = d;
}
bool Enemy::get_direction(void){
  return this->direction_right;
}

Enemy::~Enemy(){
}

void Enemy_Lane::set_direct(bool direction){
    current_direction_right = direction;
}

Enemy_Lane::Enemy_Lane(){
  num_enemies = 0;
  current_direction_right = true;
}

Enemy_Lane::Enemy_Lane(int Ypos, int num_enemies, bool direction){
  //generate random speed for lane
  current_direction_right = direction;
  std::cout <<current_direction_right <<std::endl;
  int min_speed = 1;
  int range = 2;
  int rand_speed = min_speed + (rand() % range);
  if (current_direction_right){
    int Xpos = 100;
      for(int i = 0; i < num_enemies; ++i){
      int range2 = 150;
      int rand_x = 250 + (rand() % range2);
      Xpos -= rand_x;
      Enemy enemy(Xpos,Ypos);
      enemies.push_back(enemy);
      enemies[i].set_speed(rand_speed);
      enemies[i].set_direction(current_direction_right);
sf::Vector2f position = enemies[i].getPosition();
int x = position.x;
int y = position.y;
std::cout<< i<<" " <<x<<' '<<y<<std::endl;
    }
  }
  else if (!current_direction_right){
    int Xpos = GAME_WIDTH;
      for(int i = 0; i < num_enemies; ++i){
        int range2 = 150;
        int rand_x = 250 + (rand() % range2);
        Xpos += rand_x;
        Enemy enemy(Xpos,Ypos);
        enemies.push_back(enemy);
        enemies[i].set_speed(rand_speed);
        enemies[i].set_direction(current_direction_right);
sf::Vector2f position = enemies[i].getPosition();
int x = position.x;
int y = position.y;
std::cout<< i<<" " <<x<<' '<<y<<std::endl;
      }
  }
//  setSize(sf::Vector2f(GAME_WIDTH, CELL_HEIGHT));
//  setFillColor(sf::Color::Red);
}

void Enemy_Lane::refresh(){
  for(int i = 0; i<enemies.size(); ++i){
    enemies[i].MoveEnemy();
  }
}
