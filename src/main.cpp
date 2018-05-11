#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define GAME_HEIGHT 700
#define GAME_WIDTH 1200
#define NUM_ENEMIES 4
#define CELL_HEIGHT 50
#define CELL_WIDTH 50

//enemy class for game
class Enemy : public sf::RectangleShape {
  public:
    int speed;
    bool direction_right;
    void set_speed(int s);
    void set_direction(bool d);
    bool get_direction(void);
    Enemy();
    Enemy(int pos_x, int pos_y);
    virtual void MoveEnemy();
    ~Enemy();
};
//class to hold a vector of enemies to be drawn to screen
class Enemy_Lane : public Enemy {
  public:
    bool current_direction_right;
    void set_direct(bool direction);
    std::vector<Enemy> enemies;
    Enemy_Lane();
    Enemy_Lane(int Ypos, int num_enemies, bool direction);
    void refresh(); //moves the enemies in a given lane
    void drawlanes(sf::RenderWindow &window);
  private:
    int num_enemies;
};

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
  int min_speed = 2;
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

int main()
{
  //open file to display best time
  std::ifstream myfile;
  myfile.open ("time.txt");
  std::string line;
  getline(myfile,line);

  //load font and set up text to display time
  sf::Text text;
  sf::Font font;
  font.loadFromFile("sansation.ttf");
  text.setFont(font);
  text.setPosition((GAME_WIDTH)/4,0);
  text.setCharacterSize(34);
  text.setOutlineColor(sf::Color::Red);
  text.setFillColor(sf::Color::Red);
  std::string yourT = "Your Time:";
  sf::Text text2;
  text2.setFont(font);
  text2.setPosition((GAME_WIDTH/4+GAME_WIDTH/4),0);
  text2.setCharacterSize(34);
  text2.setOutlineColor(sf::Color::Red);
  text2.setFillColor(sf::Color::Red);
  std::string best = "Best Time: ";
  best+=line;
  text2.setString(best);
  sf::Clock clock; // start clock
  sf::Time elapsed1; // set object
  int intSecondsCounted;
  std::stringstream ss;
  std::string to_save;
  float t1, t2;

  const int NUM_LANES = GAME_HEIGHT / CELL_HEIGHT;
	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Traffic Dodger!!!");
	window.setVerticalSyncEnabled(true);
	sf::RectangleShape jwalker;

	jwalker.setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
	jwalker.setFillColor(sf::Color::Yellow);
	jwalker.setPosition(sf::Vector2f(jwalker.getPosition().x + (GAME_WIDTH/2), window.getSize().y - jwalker.getSize().y));
	sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window.getDefaultView().getSize());
  int px = CELL_HEIGHT;
  Enemy_Lane Lanes[NUM_LANES];
  for(int i = 0; i<NUM_LANES;++i){
    Lanes[i] = Enemy_Lane(px,NUM_ENEMIES,rand()%2);
    px+=50;
  }
  //restart clock
  clock.restart();
	while (window.isOpen()){
    //reset string yourT
    yourT = "Your Time:";
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
              goto End;
			}

		}
//set walker bounds
		sf::Vector2f position = jwalker.getPosition();
		position.y = std::max(position.y, windowBounds.top+CELL_HEIGHT);
		position.y = std::min(position.y, windowBounds.top + windowBounds.height - jwalker.getSize().y);
		position.x = std::max(position.x, windowBounds.left);
		position.x = std::min(position.x, windowBounds.left + windowBounds.width - jwalker.getSize().x);
		jwalker.setPosition(position);

//detect collisions
    for(int i = 0; i < NUM_LANES; ++i){
      Enemy_Lane check;
      for(int i2 = 0; i2 < NUM_ENEMIES; ++i2){
        check = Lanes[i];
        if((jwalker.getGlobalBounds().intersects(check.enemies[i2].getGlobalBounds()))){
          window.close();
          goto End;
        }
      }
    }
    window.clear();

		// draw SFML content
    for(int i = 0; i<NUM_LANES;++i){
      Lanes[i].refresh();
    }
    for(int i = 0; i<NUM_LANES;++i){
      Lanes[i].drawlanes(window);
    }
  	window.draw(jwalker);
  //draw clock and best time
    elapsed1 = clock.getElapsedTime();
    ss.str(std::string()); //clear the string
    ss << elapsed1.asSeconds();
    yourT+=ss.str().c_str();
    text.setString(yourT);
    to_save = ss.str().c_str();
    window.draw(text);
    window.draw(text2);
  	window.display();
  	}
End:
    //check if current playtime is higher than best time
    t1 = std::stof(line);
    t2 = std::stof(to_save);
    if(myfile.is_open()){
      if(t2>t1){
        myfile.close();
        std::ofstream myfile2 ("time.txt");
        myfile2 << ss.str().c_str();
        myfile2.close();
      }
      myfile.close();
    }
	return EXIT_SUCCESS;
}
