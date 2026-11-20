#pragma once 
#include "Base/Base.h" 

class Fruit :public Base {
private:
	CImage m_img;
	CImage m_rope_img;
	bool m_is_falling;	//—Ž‰º’†‚©‚Ç‚¤‚©
	bool m_is_ground;	//’n–Ê‚É’…’n‚µ‚½‚©‚Ç‚¤‚©
	int m_order;

public:
	  Fruit(const char* name,const CVector2D& pos, int order);
	  void Update() override;
	  void Draw() override;
	  void Collision(Base* b) override;

	  void CutRope() {
		  m_is_falling = true;
	  }
	  bool IsGround() const {
		  return m_is_ground;
	  }
	  int GetOrder() const {
		  return m_order;
	  }
};