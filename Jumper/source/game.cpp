#include "../header/game.hpp"
#include <iostream>

Game::Game() {
    platforms.resize(10);
    sf::Texture t;
    t.loadFromFile("../include/platform.png");
    for (size_t i = 0; i < platforms.size(); ++i) {
        platforms[i].setTexture(t);
    }
    for (size_t i = 0; i < platforms.size(); ++i) {
        setRandomPlatform(platforms[i]);
    }
    t.loadFromFile("../include/ball_default.png");
    ball.setTexture(t);
    ball.setObjectPosition(sf::Vector2f(225.f, 300.f));
}

void Game::setRandomPlatform(Object& platform) {
    float x = rand() % 420;
    float y = rand() % 590;
    platform.setObjectPosition(sf::Vector2f(x, y));
}

void Game::moveSide(int speed) {
    sf::Vector2f pos = ball.getObjectPosition();
    if (pos.x < 0) {
        pos.x = 500;
    } else if (pos.x > 500) {
        pos.x = 0;
    }
    ball.setObjectPosition(sf::Vector2f(pos.x + speed, pos.y));
}

bool Game::gameProcess() {
    sf::Vector2f ball_pos = ball.getObjectPosition();
    static float dy = 0;
    dy += 0.2;
    ball_pos.y += dy;
    std::cout << ball_pos.y << std::endl;
    if (ball_pos.y > 600) {
        return false;
    }
    ball.setObjectPosition(ball_pos);
    for (size_t i = 0; i < 10; ++i) {
        sf::Vector2f platform_pos = platforms[i].getObjectPosition();
        if (ball_pos.x > platform_pos.x && ball_pos.x < platform_pos.x + 80 && ball_pos.y > platform_pos.y - 20 && ball_pos.y < platform_pos.y) {
            dy = -5;
        }
    }
    if (ball_pos.y < 500) {
        for (size_t i = 0; i < 10; ++i) {
            ball_pos.y = 500;
            sf::Vector2f platform_pos = platforms[i].getObjectPosition();
            platform_pos.y -= dy;
            if (platform_pos.y > 600) {
                float x = rand() % 500;
                platform_pos.x = x;
                platform_pos.y = 0;
            }
            platforms[i].setObjectPosition(platform_pos);
        }
    }
    return true;
}

void Game::drawGame(sf::RenderWindow& window) {
    for (auto platform : platforms) {
        platform.drawObject(window);
    }
    ball.drawObject(window);
}