#include "../include/enemy.hpp"
#include "../include/Macros-and-libs.hpp"

int main() {

  // Seed the RNG once, at the start of the program
     srand( time( NULL ) );

  //open file to display best time
  std::ifstream myfile;
  myfile.open ("../src/time.txt");
  std::string line;
  getline(myfile,line);

  //load font and set up text to display time
  sf::Text text;
  sf::Font font;
  if (!font.loadFromFile("../src/Sansation-Regular.ttf"))
        {
            //Nothing goes here...?
        }
  text.setFont(font);
  text.setPosition((GAME_WIDTH)/4,0);
  text.setCharacterSize(34);
  text.setColor(sf::Color::Red);
  //text.setFillColor(sf::Color::Red);
  std::string yourT = "Your Time:";
  sf::Text text2;
  text2.setFont(font);
  text2.setPosition((GAME_WIDTH/4+GAME_WIDTH/4),0);
  text2.setCharacterSize(34);
  text2.setColor(sf::Color::Red);
  //text2.setFillColor(sf::Color::Red);
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
	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), ""
    "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTraffic Dodger!!!");
	window.setVerticalSyncEnabled(true);
	sf::RectangleShape hero;

	hero.setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
	hero.setFillColor(sf::Color::Yellow);
	hero.setPosition(sf::Vector2f(hero.getPosition().x + (GAME_WIDTH/2), window.getSize().y - hero.getSize().y));
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
							hero.move(0, -50);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
							hero.move(0, 50);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
							hero.move(-50, 0);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
							hero.move(50, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
							window.close();
              goto End;
			}

		}
//set walker bounds
		sf::Vector2f position = hero.getPosition();
		position.y = std::max(position.y, windowBounds.top+CELL_HEIGHT);
		position.y = std::min(position.y, windowBounds.top + windowBounds.height - hero.getSize().y);
		position.x = std::max(position.x, windowBounds.left);
		position.x = std::min(position.x, windowBounds.left + windowBounds.width - hero.getSize().x);
		hero.setPosition(position);

//detect collisions
    for(int i = 0; i < NUM_LANES; ++i){
      Enemy_Lane check;
      for(int i2 = 0; i2 < NUM_ENEMIES; ++i2){
        check = Lanes[i];
        if((hero.getGlobalBounds().intersects(check.enemies[i2].getGlobalBounds()))){
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
  	window.draw(hero);
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
