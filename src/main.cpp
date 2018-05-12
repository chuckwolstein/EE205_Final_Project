#include "../include/enemy.hpp"
#include "../include/Macros-and-libs.hpp"

int main() {

  // Seed the RNG once, at the start of the program
     srand( time( NULL ) );

  //open file to display best time
  std::ifstream myfile;
  myfile.open ("./src/time.txt");
  std::string line;
  getline(myfile,line);

  //load font and set up text to display time
  sf::Text timeText;
  sf::Font font;
  if (!font.loadFromFile("./fonts/Sansation-Regular.ttf"))
        {
            std::cout<<"Unable to load font"<<std::endl;
        }

  timeText.setFont(font);
  timeText.setPosition((GAME_WIDTH)/4,0);
  timeText.setCharacterSize(34);
/*These next 2 lines are for SFML v2.4.0 or later
  timeText.setOutlineColor(sf::Color::Red);
  timeText.setFillColor(sf::Color::Red); */
/*But Chuck has v 2.3.2, so this next line is for his */
  timeText.setColor(sf::Color::Red);
  std::string yourT = "Your Time:";
  sf::Text timeText2;
  timeText2.setFont(font);
  timeText2.setPosition((GAME_WIDTH/4+GAME_WIDTH/4),0);
  timeText2.setCharacterSize(34);
/*These next 2 lines are for SFML v2.4.0 or later
  timeText2.setOutlineColor(sf::Color::Red);
  timeText2.setFillColor(sf::Color::Red); */
/*But Chuck has v 2.3.2, so this next line is for his */
  timeText2.setColor(sf::Color::Red);
  std::string best = "Best Time: ";
  best+=line;
  timeText2.setString(best);
  sf::Clock clock; // start clock
  sf::Time elapsed1; // set object
  int intSecondsCounted;
  std::stringstream ss;
  std::string to_save;
  float t1, t2;

  const int NUM_LANES = GAME_HEIGHT / CELL_HEIGHT;
	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Traffic Dodger!!!");
	window.setVerticalSyncEnabled(true);

  /*  This code is for a version of SFML that is more advanced than what Chuck has

  sf::Music hardcoremusic;
          if(!hardcoremusic.openFromFile("./media/Take.ogg"))
                  return -1;
          hardcoremusic.play();
          hardcoremusic.setLoop(1);
*/
/*
          //for the music soundtrack
          sf::SoundBuffer buffer;
          if(!buffer.loadFromFile("./media/Take.ogg"))
                  return 0;
          sf::Sound sound;
          sound.setBuffer(buffer);
          sound.play();
          sound.setLoop(1);
          */

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

  //declare a texture to use in our background
  sf::Texture background;
  //check to ensure background texture loads correctly
  if(!background.loadFromFile("media/Road.PNG")) {
    std::cout << "Failed to load background" << std::endl;
    system("pause");
  }

  //declare a sprite for the background and set its texture
  sf::Sprite backgroundSprite;
  backgroundSprite.setTexture(background);

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
    //draw the background backgroundSprite
    window.draw(backgroundSprite);

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
    timeText.setString(yourT);
    to_save = ss.str().c_str();
    window.draw(timeText);
    window.draw(timeText2);
  	window.display();
  	}
End:
    //check if current playtime is higher than best time
    t1 = std::stof(line);
    t2 = std::stof(to_save);
    if(myfile.is_open()){
      if(t2>t1){
        myfile.close();
        std::ofstream myfile2 ("src/time.txt");
        myfile2 << ss.str().c_str();
        myfile2.close();
      }
      myfile.close();
    }
	return EXIT_SUCCESS;
}
