//**************************************************************
//文字表示・正誤判定クラス
//**************************************************************
#include "main.h"
#include "camera.h"
#include "collision.h"
#include "texture.h"
#include "sprite.h"
#include "text_sprite.h"


//==============================================================
//初期化処理
//==============================================================
HRESULT TextSprite::Init(void)
{
	//テクスチャ読み込み
	m_Texture = LoadTexture((char*)"data/TEXTURE/text.png");

	return S_OK;
}

//==============================================================
//終了処理
//==============================================================
void TextSprite::Uninit(void)
{

}

//==============================================================
//更新処理
//==============================================================
void TextSprite::Update(void)
{

}

//==============================================================
//描画処理
//==============================================================
void TextSprite::Draw(void)
{
	//ベース座標を受け取る
	D3DXVECTOR2 size = D3DXVECTOR2(50.0f, 50.0f);
	D3DXVECTOR2 basePos((SCREEN_WIDTH / 2) - (size.x * m_QuestionText.size() / 2), 100.0f);

	const int COLUMN = 8;
	const int ROW = 9;

	const std::string fontTable =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789"
		"!?.,-";

	for (int i = 0; i < m_QuestionText.size(); i++) {
		char c = m_QuestionText[i];
		size_t index = fontTable.find(c);

		if (index == std::string::npos)
		{
			continue;
		}

		int x = index % COLUMN;
		int y = index / COLUMN;

		D3DXVECTOR2 pos(basePos.x + size.x * i, basePos.y);
		D3DXVECTOR2 uv((float)x / COLUMN, (float)y / ROW);
		D3DXVECTOR2 uvSize(1.0f / COLUMN, 1.0f / ROW);
		D3DXCOLOR color = i < m_Text.size() ? m_Color : m_BaseColor;

		DrawSpriteColor(m_Texture, pos, size, uv, uvSize, color);
	}
}


int TextSprite::Judge(char Key) 
{
	if (Key == m_QuestionText[m_Text.size()]) {

		AddText(Key);

		if (m_QuestionText == m_Text) {
			return 2;
		}

		return 1;
	}

	return 0;
}