#include "Player.h"
#include "Fruit.h"
#include "GameDate.h"

Player::Player(const CVector2D& pos) :Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);	//画像リソースを複製
	m_img.SetSize(128, 128);					//表示サイズ
	m_img.SetCenter(64, 128);					//足元を基準点に設定
	m_rect = CRect(-64, -128, 64, 0);
	m_pos = pos;								//出現座標を設定
	m_flip = false;
	m_next_order = 1;
}

void Player::Update() {
	const float move_speed = 4.0f;				//移動速度

	Fruit* target = nullptr;
	for (Base* b : Base::FindObjects(eType_Item)) {
		if (Fruit* f = dynamic_cast<Fruit*>(b)) {
			if (f->IsGround() && f->GetOrder() == m_next_order) {
				target = f;
				break;
			}
		}
	}
	if (target) {
		if (target->m_pos.x < m_pos.x - 16) {
			m_pos.x -= move_speed;
			m_flip = true;
		}
		else if (target->m_pos.x > m_pos.x + 16) {
			m_pos.x += move_speed;
			m_flip = false;
		}
	}
}

void Player::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));			//スクロールを考慮した位置に設定
	m_img.SetFlipH(m_flip);						//向き反転
	m_img.Draw();								//描画
}

void Player::Collision(Base* b) {
	switch (b->GetType()) {
	case eType_Item:
		if(Fruit* f = dynamic_cast<Fruit*>(b)) {
			if (f->IsGround() && f->GetOrder() == m_next_order && Base::CollisionRect(this, b)) {
				f->SetKill();
				m_next_order++;
				GameDate::s_score += 100;	//ポイントの加点
			}
		}
		break;
	}
}