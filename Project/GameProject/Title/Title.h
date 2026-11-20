#pragma once
#include "Base/Base.h"

class Title : public Base {
private:
	CImage m_img;
	CRect m_start_rect;
	int m_cnt;

public:
	Title();
	void Update() override;
	void Draw() override;
};