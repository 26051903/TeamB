#include "Field.h"

Field::Field() : Base(eType_Field) {
    m_img = COPY_RESOURCE("BackGround", CImage);
    m_foreground = COPY_RESOURCE("ground", CImage);

    m_img.SetSize(1920, 1080);
    m_foreground.SetSize(1920, 185);

    m_ground_y = 920;
}

void Field::Draw() {
    m_img.Draw();
    m_foreground.SetPos(0, m_ground_y);
    m_foreground.Draw();
}
