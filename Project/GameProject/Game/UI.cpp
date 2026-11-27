#include "UI.h" 
#include "GameDate.h"
#include "Player.h"
#include "Game.h"

UI::UI() : Base(eType_UI) {
	m_font = GET_RESOURCE("ScoreFont", CFont);
	m_img_orenge = COPY_RESOURCE("orenge", CImage);
	m_img_orenge.SetSize(80, 80);

	m_img_fruit = COPY_RESOURCE("fruit", CImage);
	m_img_fruit.SetSize(96, 96);

	m_img_clear = COPY_RESOURCE("clear", CImage);
	m_img_clear.SetSize(1000, 650);
	m_img_Score = COPY_RESOURCE("Score", CImage);
}

void UI::Update() {
	
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

	if (GameDate::s_got_fruit && GameDate::s_got_orenge) {
		float center_x = (SCREEN_WIDTH - 1000.0f) / 2.0f;
		float center_y = (SCREEN_HEIGHT - 650.0f) / 2.0f;

		m_img_clear.SetPos(center_x, center_y);
		m_img_clear.Draw();

		int score = GameDate::s_score;
		float src_w = 160.0f; 
		float src_h = 160.0f;
		float draw_w = 160.0f; 
		float draw_h = 160.0f;
		float num_start_x = center_x + 700.0f;
		float num_draw_y = center_y + 260.0f;
		for (int i = 0; i < 4; i++) {
			int digit = score % 10;
			m_img_Score.SetRect(src_w * digit, 0, src_w * digit + src_w, src_h);
			m_img_Score.SetSize(draw_w, draw_h);
			m_img_Score.SetPos(num_start_x - (draw_w * i), num_draw_y);
			m_img_Score.Draw();
			score /= 10;



		}
		
	}
	if (GameDate::s_got_fruit && GameDate::s_got_orenge) {
		float center_x = (SCREEN_WIDTH - 1000.0f) / 2.0f;
		float center_y = (SCREEN_HEIGHT - 650.0f) / 2.0f;

		CVector2D mouse_pos = CInput::GetMousePoint();

		float btn_retry_left = center_x + 195.0f;
		float btn_retry_right = center_x + 495.0f;
		float btn_retry_top = center_y + 490.0f;
		float btn_retry_bottom = center_y + 600.0f;
		Utility::DrawQuad(
			CVector2D(btn_retry_left, btn_retry_top),
			CVector2D(
				btn_retry_right - btn_retry_left,
				btn_retry_bottom - btn_retry_top
			),
			CVector4D(1, 0, 0, 0.5f));
		bool is_retry_clicked = PUSH(CInput::eMouseL) &&
			(mouse_pos.x >= btn_retry_left && mouse_pos.x <= btn_retry_right) &&
			(mouse_pos.y >= btn_retry_top && mouse_pos.y <= btn_retry_bottom);
		if (is_retry_clicked) {
			Base::KillAll();
			new Game();
		}
	}
}