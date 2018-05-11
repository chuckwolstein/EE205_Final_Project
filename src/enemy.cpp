#include "../include/enemy.hpp"

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
    //update x pos of enemy by adding the speed
    pos.x += speed;
    setPosition(pos.x, pos.y);
    //redraw enemy once they have moved completely off screen
    if (getPosition().x > GAME_WIDTH)
    {
      setPosition(0 - getSize().x, getPosition().y);
    }
  }
  else if (!direction_right){
    //update x pos of enemy by subtracting the speed
    pos.x -= speed;
    setPosition(pos.x,pos.y);
    //redraw enemy once they have moved completely off screen
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
  int min_speed = 1;
  int range = 5;
  int rand_speed = min_speed + (rand() % range);
  /*for a lane with direction right, create enemies randomly spaced apart,
  and add them the vector for the lane, each lane will have static speed
  and direction*/
  if (current_direction_right){
    int Xpos = 90;
      for(int i = 0; i < num_enemies; ++i){
      int range2 = 150;
      int rand_x = 250 + (rand() % range2);
      Xpos -= rand_x;
      Enemy enemy(Xpos,Ypos);
      enemies.push_back(enemy);
      enemies[i].set_speed(rand_speed);
      enemies[i].set_direction(current_direction_right);
    }
  }
  else if (!current_direction_right){
    int Xpos = GAME_WIDTH - 70;
      for(int i = 0; i < num_enemies; ++i){
        int range2 = 150;
        int rand_x = 250 + (rand() % range2);
        Xpos += rand_x;
        Enemy enemy(Xpos,Ypos);
        enemies.push_back(enemy);
        enemies[i].set_speed(rand_speed);
        enemies[i].set_direction(current_direction_right);
      }
  }
}

void Enemy_Lane::refresh(){
  for(int i = 0; i<enemies.size(); ++i){
    enemies[i].MoveEnemy();
  }
}
void Enemy_Lane::drawlanes(sf::RenderWindow &window){
  for(int i = 0; i <NUM_ENEMIES; ++i){
    window.draw(this->enemies[i]);
  }
}
