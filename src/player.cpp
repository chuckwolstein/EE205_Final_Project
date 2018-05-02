#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#define SAFE 1
#define UNSAFE 0

//using namespace std; //Standard
using namespace sf;  //SFML

class GameObject {
private:
    int x, y;
    int pos;
    int length;
    int height;
    int velocity;
    char m;

public:
    void jwalkerMove(int x, int y, char m) {

        /* -------------------Start of old code we may want to keep
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
                --------------------end of old code we may want to keep*/
                m+=1;

        }
};

class Jwalker {
private:
    int x, y;
    int length;
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
        switch (event.type)
        {
                //Window closed
            case sf::Event::Closed:
                window.close();
                break;

                //Key pressed
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                  //Quit
                }
                else if (event.key.code == sf::Keyboard::Space) {
                  //Pause and Unpause
                }
                else if (event.key.code == sf::Keyboard::Left) {
                  //Move Left
                }
                else if (event.key.code == sf::Keyboard::Right) {
                  //Move Right
                }
                else if (event.key.code == sf::Keyboard::Up) {
                  //Move Up
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    //Move down
                }
    }
                break;


                //We don't process other types of events
            default:
                break;
        }
    }
}
