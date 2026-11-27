#include "Field.h"

Field::Field(int stage_no) : Base(eType_Field) {
    if (stage_no == 1) {
        m_img = COPY_RESOURCE("BackGround", CImage);
        m_foreground = COPY_RESOURCE("ground", CImage);
        m_ground_y = 920;
    }
    else if (stage_no == 2) {
        m_img = CPOY_RESOURCE("BackGaroud2"CImage);
        m_foreground = COPY_RESOUCE("ground2", CImage);
        m_ground_y = 920.0f;
    }
    m_img.SetSize(1920, 1080);
    m_foreground.SetSize(1920, 185);

}

void Field::Draw() {
    m_img.Draw();
    m_foreground.SetPos(0, m_ground_y);
    m_foreground.Draw();
}
