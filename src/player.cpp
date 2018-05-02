#include <SFML/Graphics.hpp>
#include <iostream>

#define SAFE 1
#define UNSAFE 0

//using namespace std; //Standard
using namespace sf;  //SFML

class GameObject {
private:
    int x, y;
    int pos;
    int length, const height;
    int velocity;
    char m;

public:
    void jwalkerMove(int x, int y, char m) {
        //Move using ASWD and HJKL
        switch(m) {
            case 'a' : //Move left
            case 'h' :
                x = x - 1;
                break;
            case 's' : //Move down
            case 'j' :
                y = y - 1;
                break;
            case 'w' : //Move up
            case 'k':
                y = y + 1;
                break;
            case 'd' : //Move right
            case 'l' :
                x = x + 1;
                break;

            default:
                break;


        }
    }
};

class Jwalker {
private:
    int lives;
    int score;

public:
    void jwalkerMove();
};

int main() {
    GameObject object;
    Jwalker jwalker;

    sf::Window window;

    sf::Event::KeyEvent event;

    //While there are pending events...
    while (window.pollEvent(event))
    {
        //Check the type of the event...
        switch (event.key)
        {
                //Window closed
            case sf::Event::Closed:
                window.close();
                break;

                //Key pressed
            case sf::Event::KeyPressed:
                ...
                break;

                //We don't process other types of events
            default:
                break;
        }
    }
}
