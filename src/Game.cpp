#include <cstdlib>
#include "Game.hpp"
#include "Display/Display.hpp"
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "Display/draw.hpp"
#include "Utils/Timer.hpp"
#include "Utils/common.hpp"
#include "Character/Player.hpp"
#include "Parser/ResourceParser.hpp"

const std::string Game::GAME_TITLE = "Open RPG Creator Engine";
const std::string Game::SETTINGS_FILE = "settings/settings.xml";
Game* Game::INSTANCE;

Game::Game() {
	map = 0;
	player = 0;
	isRunning = true;
	xmlParser = ResourceParser::getParser();
	display = Display::getInstance();
}

void Game::run() {
	GameData* gameData = xmlParser->parseGame(Game::SETTINGS_FILE);
	map = new Map(gameData->getMap());
	player = gameData->getPlayer();
	display->setMap(map);
	while (isRunning) {
		timer.start();
		handleKeyboard();
		//renderFrame();
		display->renderFrame(player);
		handleTimer();
	}
}

void Game::handleTimer() {
	if (timer.get_ticks() < 1000 / FRAMES_PER_SECONDS) {
		SDL_Delay((1000 / FRAMES_PER_SECONDS) - timer.get_ticks());
	}
}

void Game::setPlayerInStandingPosition() {
	player->stand();
}

void Game::handleKeyboard() {
	handleEvents();
	handleArrows();
}

void Game::handleEvents() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
		}
	}
}

void Game::handleArrows() {
	keystates = SDL_GetKeyState(0);
	if (keystates[SDLK_UP]) {
		movePlayer(UP, keystates[SDLK_LSHIFT]);
	} else if (keystates[SDLK_DOWN]) {
		movePlayer(DOWN, keystates[SDLK_LSHIFT]);
	} else if (keystates[SDLK_RIGHT]) {
		movePlayer(RIGHT, keystates[SDLK_LSHIFT]);
	} else if (keystates[SDLK_LEFT]) {
		movePlayer(LEFT, keystates[SDLK_LSHIFT]);
	} else {
		setPlayerInStandingPosition();
	}
}

void Game::movePlayer(Direction dir, bool isRunning) {

	if (map->checkCollision(player, dir, isRunning)) {
		player->rotate(dir);
	} else {
		player->move(dir, isRunning);
	}
}

bool Game::isSet() {
	return ((map != 0) && (player != 0));
}

Game& Game::getInstance() {
	if (INSTANCE == 0) {
		INSTANCE = new Game();
	}
	return *INSTANCE;
}
