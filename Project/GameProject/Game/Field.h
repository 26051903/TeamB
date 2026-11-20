#pragma once 
#include "Base/Base.h" 
class Field : public Base 
{ 
private:
	CImage m_img; // 背景画像（1枚） 
	CImage m_foreground;
	//地面の高さ
	float m_ground_y;
public: Field(); // コンストラクタ 
	  void Draw(); // 描画処理 
	  //地面の高さを取得
	  float GetGroundY() {
		  return m_ground_y;
	  }
};