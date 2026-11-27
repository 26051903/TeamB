#pragma once
#include "Base/Base.h"

class UI : public Base {
private:
	CFont* m_font;
	CImage m_img_orenge;
	CImage m_img_fruit;
	CImage m_img_clear;
	CImage m_img_Score;

public:
	UI();
	void Update() override;
	void Draw() override;
};