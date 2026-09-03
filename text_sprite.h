//**************************************************************
//文字表示・正誤判定クラス
//**************************************************************
#pragma once
#include "game_object.h"
#include <string>
#include <iostream>

class TextSprite : public GameObject {
private:
	int m_Texture = 0;
	D3DXCOLOR m_BaseColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	D3DXCOLOR m_Color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);

	std::string m_QuestionText;
	std::string m_Text;

public:
	HRESULT Init(void) override;
	void	Uninit(void) override;
	void	Update(void) override;
	void	Draw(void) override;

	int		Judge(char Key);

	void	SetColor(D3DXCOLOR Color) { m_Color = Color; }
	std::string GetText() { return m_Text; }
	void	SetQuestionText(std::string Text) { m_QuestionText = Text; }
	void	AddText(char Text) { m_Text += Text; }
	void	ResetText() { m_Text.clear(); m_QuestionText.clear(); }
};