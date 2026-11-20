#include "Fruit.h"
#include "Field.h"

Fruit::Fruit(const char* name, const CVector2D& pos, int order) : Base(eType_Item) {
	m_img = COPY_RESOURCE(name, CImage);
	m_img.SetSize(64, 64); // 表示サイズ 
	m_img.SetCenter(32, 32); // 中心点 
	m_rect = CRect(-32, -32, 32, 32);

	m_rope_img = COPY_RESOURCE("Rope", CImage);
	m_rope_img.SetCenter(0, 0);
	m_pos = pos; // 座標を設定
	m_is_falling = false;
	m_is_ground = false;
	m_order = order;
}


void Fruit::Update() {
	if (m_is_falling) {
		m_vec.y += GRAVITY;
		m_pos += m_vec;
	}
	else {
		if (PUSH(CInput::eMouseL)) {
			POINT pt; GetCursorPos(&pt); // モニター全体の座標取得
			ScreenToClient(GL::hWnd, &pt); // ウィンドウ内の座標に変換

			CVector2D mouse_pos((float)pt.x, (float)pt.y);

			float rope_lenth = 200.0f;
			float top_y = m_pos.y - rope_lenth;
			if (mouse_pos.x >= m_pos.x - 20 && mouse_pos.x <= m_pos.x + 20 && mouse_pos.y >= top_y && mouse_pos.y <= m_pos.y)
			{
				CutRope();
			}
		}
	}
}



void Fruit::Draw()
{
	if (!m_is_falling) {
		float rope_width = 50.0f; // ★紐の太さ（例: 8から16に増やして太くする） 
		float rope_length = 200.0f; // ★紐の長さ（例: 200px など好みの長さに設定）
		// Fruitの位置から指定した長さ(rope\_length)分だけ上の座標を計算 
		CVector2D rope_pos = CVector2D(m_pos.x - (rope_width / 2), m_pos.y - rope_length);
		m_rope_img.SetPos(GetScreenPos(rope_pos));
		m_rope_img.SetSize(rope_width, rope_length);
		m_rope_img.Draw();
	}
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Fruit::Collision(Base* b) {
	// 地面（Field）と接触した場合 
	if (b->GetType() == eType_Field) {
		if (Field* f = dynamic_cast<Field*>(b)) {
			if (m_pos.y + 32 > f->GetGroundY()) {
				m_pos.y = f->GetGroundY()- 32;
				m_vec.y = 0;
				m_is_ground = true;
			}
		}
	}
}