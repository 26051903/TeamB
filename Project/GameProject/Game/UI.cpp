#include "UI.h" 
#include "GameDate.h"

UI::UI() : Base(eType_UI) {
	m_font = GET_RESOURCE("ScoreFont", CFont);
}
void UI::Draw() {
	m_font->Draw(15, 80, 1, 1, 1, "%04d", GameDate::s_score);
}