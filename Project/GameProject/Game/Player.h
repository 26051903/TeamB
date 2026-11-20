#pragma once
#include "Base/Base.h"

class Player : public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_next_order;
	int m_last_fruit;


public:
	Player(const CVector2D& pos);
	void Update() override;
	void Draw() override;
	void Collision(Base* b)override;	//“–‚½‚è”»’è

	int GetNextOrder() const {
		return m_next_order;
	}
};
