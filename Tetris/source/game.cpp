#include "../header/game.hpp"

Game::Game() {
    texture.loadFromFile("../include/background.png");
    background.setTexture(texture);
    background.setPosition(0, 0);
    setRandomFigure();
}

void Game::setRandomFigure() {

}

void Game::drawGame(sf::RenderWindow& window) {
    window.draw(background);
}