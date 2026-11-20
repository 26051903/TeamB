#include "Title.h" 
#include "Game/Game.h"

Title::Title() : Base(eType_Scene) {
	m_img = COPY_RESOURCE("Title", CImage);
	m_cnt = 0;

	float btn_w = 500.0f;
	float btn_h = 130.0f;

	float left = (SCREEN_WIDTH - btn_w) / 2.0f;
	float top = (SCREEN_HEIGHT / 2.0f) +255.0f;
	m_start_rect = CRect(left, top, left + btn_w, top + btn_h);
}

void Title::Update() {
	if (m_cnt++ > 2 && PUSH(CInput::eMouseL)) {
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(GL::hWnd, &pt);
		CVector2D mouse_pos((float)pt.x, (float)pt.y);

		if (CCollision::CollisionRectPoint(m_start_rect, mouse_pos)) {
			Base::KillAll();
			new Game();
		}
	}
}

void Title::Draw() {
	m_img.SetSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	m_img.Draw();
}