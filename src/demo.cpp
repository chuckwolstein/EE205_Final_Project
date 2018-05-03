#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#define SAFE 1
#define UNSAFE 0
#define NUM_LANES 6
#define NUM_ENEMIES 4
#define GAME_HEIGHT 1000
#define GAME_WIDTH 1800
#define CELL_HEIGHT 50
#define CELL_WIDTH 50


class Enemy : public sf::RectangleShape {
  public:
  //  sf::Sprite EnemySprite;
  //	sf::Texture EnemyTexture;
    int speed;
    bool direction_right;
    void set_speed(int s);
    void set_direction(bool d);
    bool get_direction(void);
    Enemy();
    Enemy(int pos_x, int pos_y);
    virtual void MoveEnemy();
    ~Enemy();
  //  bool collide(player &player);
};

class Enemy_Lane : public Enemy {
  public:
    bool current_direction_right;
    void set_direct(bool direction);
    std::vector<Enemy> enemies;
    Enemy_Lane();
    Enemy_Lane(int Ypos, int num_enemies, bool direction);
    void refresh();
  private:
    int num_enemies;
};

Enemy::Enemy(){
  setPosition(0,0);
  setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
  speed = 1;
  direction_right = true;
}

Enemy::Enemy(int pos_x, int pos_y){
  setPosition(pos_x, pos_y);
  setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
  setFillColor(sf::Color::White);
  speed = 1;
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
  int range = 5;
  int rand_speed = min_speed + (rand() % range);
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

int main()
{
	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Traffic Dodger!!!");
	window.setVerticalSyncEnabled(true);
	sf::RectangleShape jwalker;

	jwalker.setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
	jwalker.setFillColor(sf::Color::Yellow);
	jwalker.setPosition(sf::Vector2f(jwalker.getPosition().x, window.getSize().y - jwalker.getSize().y));
	sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window.getDefaultView().getSize());

	Enemy_Lane lane1(0, NUM_ENEMIES,rand()%2);
  Enemy_Lane lane2(50, NUM_ENEMIES,rand()%2);
  Enemy_Lane lane3(100, NUM_ENEMIES,rand()%2);
  Enemy_Lane lane4(150, NUM_ENEMIES,rand()%2);
  Enemy_Lane lane5(200, NUM_ENEMIES,rand()%2);
  Enemy_Lane lane6(250, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane7(300, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane8(350, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane9(400, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane10(450, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane11(500, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane12(550, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane13(600, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane14(650, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane15(700, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane16(750, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane17(800, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane18(850, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane19(900, NUM_ENEMIES,rand()%2);
	Enemy_Lane lane20(950, NUM_ENEMIES,false);






	while (window.isOpen())
	{

		// handle events
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
							jwalker.move(0, -50);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
							jwalker.move(0, 50);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
							jwalker.move(-50, 0);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
							jwalker.move(50, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
							window.close();
			}

		}
//set walker bounds
		sf::Vector2f position = jwalker.getPosition();
		position.y = std::max(position.y, windowBounds.top);
		position.y = std::min(position.y, windowBounds.top + windowBounds.height - jwalker.getSize().y);
		position.x = std::max(position.x, windowBounds.left);
		position.x = std::min(position.x, windowBounds.left + windowBounds.width - jwalker.getSize().x);
		jwalker.setPosition(position);

//detect collisions

for(int i = 0; i<lane1.enemies.size();++i){
	if ((jwalker.getGlobalBounds().intersects(lane1.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane2.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane3.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane4.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane5.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane6.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane7.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane8.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane9.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane10.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane11.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane12.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane13.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane14.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane15.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane16.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane17.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane18.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane19.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane20.enemies[i].getGlobalBounds()))){
		window.close();
		}
}
window.clear();

		// draw SFML content
lane1.refresh();
lane2.refresh();
lane3.refresh();
lane4.refresh();
lane5.refresh();
lane6.refresh();
		lane7.refresh();
		lane8.refresh();
		lane9.refresh();
		lane10.refresh();
		lane11.refresh();
		lane12.refresh();
		lane13.refresh();
		lane14.refresh();
		lane15.refresh();
		lane16.refresh();
		lane17.refresh();
		lane18.refresh();
		lane19.refresh();
		lane20.refresh();

		window.draw(jwalker);
		for(int i = 0; i<lane1.enemies.size();++i){
			window.draw(lane1.enemies[i]);
			window.draw(lane2.enemies[i]);
			window.draw(lane3.enemies[i]);
			window.draw(lane4.enemies[i]);
			window.draw(lane5.enemies[i]);
			window.draw(lane6.enemies[i]);
			window.draw(lane7.enemies[i]);
			window.draw(lane8.enemies[i]);
			window.draw(lane9.enemies[i]);
			window.draw(lane10.enemies[i]);
			window.draw(lane11.enemies[i]);
			window.draw(lane12.enemies[i]);
			window.draw(lane13.enemies[i]);
			window.draw(lane14.enemies[i]);
			window.draw(lane15.enemies[i]);
			window.draw(lane16.enemies[i]);
			window.draw(lane17.enemies[i]);
			window.draw(lane18.enemies[i]);
			window.draw(lane19.enemies[i]);
			window.draw(lane20.enemies[i]);
			}
		window.display();
	}

	return EXIT_SUCCESS;
}
