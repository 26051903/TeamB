#include "UI.h" 
#include "GameDate.h"
#include "Player.h"

UI::UI() : Base(eType_UI) {
	m_font = GET_RESOURCE("ScoreFont", CFont);
	m_img_orenge = COPY_RESOURCE("orenge", CImage);
	m_img_orenge.SetSize(80, 80);

	m_img_fruit = COPY_RESOURCE("fruit", CImage);
	m_img_fruit.SetSize(96, 96);
}
void UI::Draw() {
	m_font->Draw(15, 80, 1, 1, 1, "%04d", GameDate::s_score);
	int next_order = 1;
	if (Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player))) {
		next_order = p->GetNextOrder();
	}
	float start_x = SCREEN_WIDTH - 170.0f;

	if (GameDate::s_got_fruit) {
		m_img_fruit.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	}
	else {
		m_img_fruit.SetColor(0.3f, 0.3f, 0.3f, 1.0f);
	}
	m_img_fruit.SetPos(start_x, 2.0f);
	m_img_fruit.Draw();

	if (GameDate::s_got_orenge) {
		m_img_orenge.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	}
	else {
		m_img_orenge.SetColor(0.3f, 0.3f, 0.3f, 1.0f);
	}
	m_img_orenge.SetPos(start_x + 75.0f, 9.0f);
	m_img_orenge.Draw();

}