#include <SFML/Graphics.hpp>

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
