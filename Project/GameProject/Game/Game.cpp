#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "fruit.h"
#include "UI.h"
#include "GameDate.h"

Game::Game() :Base(eType_Scene) {
	GameDate::s_score = 0;
	GameDate::s_got_orenge = false;
	GameDate::s_got_fruit = false;
	new Field();
	new Player(CVector2D(300, 920));
	new Fruit("fruit", CVector2D(1600, 500), 1);
	new Fruit("orenge", CVector2D(900, 400), 2);
	new UI();
}

void Game::Update() {

}