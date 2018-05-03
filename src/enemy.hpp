#ifndef enemy_hpp
#define enemy_hpp
// your code
#include <SFML/Graphics.hpp>
#define GAME_HEIGHT 500
#define GAME_WIDTH 800
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

#endif
