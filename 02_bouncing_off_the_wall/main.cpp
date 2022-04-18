#include <SFML/Graphics.hpp>
#include <cstdlib>

int main() {
	int windowWidth = 540;
	int windowHeight = 600;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
			"Bouncing Off the Wall");

	// textures of the sprite
	sf::Texture texture_dog;
	texture_dog.loadFromFile("asset/img/dog.png");
	sf::Texture texture_gorilla;
	texture_gorilla.loadFromFile("asset/img/gorilla.png");
	sf::Texture texture_tiger;
		texture_tiger.loadFromFile("asset/img/tiger.png");
	sf::Texture textures[] = { texture_dog, texture_gorilla, texture_tiger };
	int textureCounter = 0;
	int texturesLength = sizeof(textures) / sizeof(sf::Texture);


	// set a texture to a sprite and set the origin of the sprite
	sf::Sprite sprite(texture_dog);
	sf::Vector2u size = texture_dog.getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);


	/*
	// set a random position to sprite
	srand(int(time(0)));
	unsigned int randomNumber = rand() % (windowWidth - size.x / 2)
			+ size.x / 2;
	sprite.setPosition(randomNumber, size.y / 2);
	*/


	// speed and direction of the moving sprite
	// positive value means go left or down, negative value means go right or up
	sf::Vector2f increment(0.1f, 0.1f);

	// background colors
	sf::Color white = sf::Color(255, 255, 255);
	sf::Color yellow = sf::Color(255, 248, 10);
	sf::Color cryon = sf::Color(43, 224, 253);
	sf::Color green = sf::Color(0, 255, 0);
	sf::Color rose = sf::Color(254, 26, 225);
	sf::Color red = sf::Color(254, 32, 31);
	sf::Color blue = sf::Color(21, 21, 255);
	sf::Color backgroundColors[] = { white, yellow, cryon, green, rose, red,
			blue };
	int colorCounter = 0;
	const int colorsLength = sizeof(backgroundColors) / sizeof(sf::Color);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// if the sprite hit any corner, which means the directions of x and y both changed,
		// xChanged and yChanged mark the change of directions.
		bool xChanged = false;
		bool yChanged = false;

		bool isHitBoundary = false;

		int spriteTextureSizeX = sprite.getTexture()->getSize().x;
		int spriteTextureSizeY = sprite.getTexture()->getSize().y;

		if ((sprite.getPosition().x + (spriteTextureSizeX / 2)
				> window.getSize().x && increment.x > 0)
				|| (sprite.getPosition().x - (spriteTextureSizeX / 2) < 0
						&& increment.x < 0)) {
			increment.x = -increment.x;
			xChanged = true;
			isHitBoundary = true;
		}
		if ((sprite.getPosition().y + (spriteTextureSizeY / 2)
				> window.getSize().y && increment.y > 0)
				|| (sprite.getPosition().y - (spriteTextureSizeY / 2) < 0
						&& increment.y < 0)) {
			increment.y = -increment.y;
			yChanged = true;
			isHitBoundary = true;
		}
		if (xChanged && yChanged) {
			textureCounter++;
			if (textureCounter == texturesLength) {
				textureCounter = 0;
			}
			// change image(texture) of the sprite when sprite hit the corner
			sprite.setTexture(textures[textureCounter]);
			sprite.setOrigin(textures[textureCounter].getSize().x / 2,
					textures[textureCounter].getSize().y / 2);
		}
		sprite.setPosition(sprite.getPosition() + increment);

		// change background color
		if (isHitBoundary) {
			colorCounter++;
			if (colorCounter == colorsLength) {
				colorCounter = 0;
			}
		}

		window.clear(backgroundColors[colorCounter]);

		window.draw(sprite);
		window.display();
	}
	return 0;
}
