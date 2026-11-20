#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "fruit.h"
#include "UI.h"
#include "GameDate.h"

Game::Game() :Base(eType_Scene) {
	new Field();
	new Player(CVector2D(300, 920));
	new Fruit("fruit", CVector2D(1600, 500), 2);
	new Fruit("orenge", CVector2D(900, 400), 1);
	new UI();
}

void Game::Update() {

}