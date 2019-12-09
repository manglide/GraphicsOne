#include <SFML/Graphics.hpp>

// Create the main window
sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow app(vm, "Hello Game SFML !!!", sf::Style::Default);

sf::Texture skyTexture;
sf::Sprite skySprite;

sf::Texture bgTexture;
sf::Sprite bgSprite;

sf::Texture heroTexture;
sf::Sprite heroSprite;

sf::Vector2f playerPosition;

bool playerMoving = false;

int init() {

    if (!skyTexture.loadFromFile("sky.png"))
        return EXIT_FAILURE;
    skySprite.setTexture(skyTexture);

    if (!bgTexture.loadFromFile("bg.png"))
        return EXIT_FAILURE;
    bgSprite.setTexture(bgTexture);

    /*
    if (!heroTexture.loadFromFile("hero.png"))
        return EXIT_FAILURE;
    heroSprite.setTexture(heroTexture);

    heroSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
    heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);
    */
    // Load a sprite to display
    // sf::Texture texture;
    // if (!texture.loadFromFile("knowledge.png"))
        // return EXIT_FAILURE;
    // sf::Sprite sprite(texture);
}

void draw() {
    app.draw(skySprite);
    app.draw(bgSprite);
    // app.draw(heroSprite);
}

void updateInput() {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            /*
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Right) {
                    playerMoving = true;
                }
            }
            if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Right) {
                    playerMoving = false;
                }
            }
            */
            // Close window : exit
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                app.close();
        }
}

void update(float dt) {
    // if(playerMoving) {
    //    heroSprite.move(50.0f * dt, 0);
    // }
}

int main()
{
    sf::Clock clock;
    app.setFramerateLimit(60);
    init();
	// Start the game loop
    while (app.isOpen())
    {
        // Handle Events
        updateInput();
        sf::Time dt = clock.restart();
        update(dt.asSeconds());
        // Clear screen
        app.clear(sf::Color::Red);
        // Draw the sprite
        draw();
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
