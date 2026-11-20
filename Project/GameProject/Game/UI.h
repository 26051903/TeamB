#pragma once
#include "Base/Base.h"

class UI : public Base {
private:
	CFont* m_font;

public:
	UI();
	void Draw() override;
};