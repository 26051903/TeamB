#pragma once
#include "Base/Base.h"

class UI : public Base {
private:
	CFont* m_font;
	CImage m_img_orenge;
	CImage m_img_fruit;

public:
	UI();
	void Draw() override;
};