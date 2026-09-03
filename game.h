//**************************************************************
//ゲームシーンクラス
//**************************************************************
#pragma once
#include "scene.h"
#include "timer.h"
#include "question_manager.h"
#include "input_typing.h"
#include "text_sprite.h"


class Game : public Scene
{
private:
	Timer* m_Timer;
	QuestionManager* m_QuestionManager;
	InputTyping* m_InputTyping;
	TextSprite* m_TextSprite;

public:
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
};