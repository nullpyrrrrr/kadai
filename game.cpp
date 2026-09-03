//**************************************************************
//ゲームシーンクラス
//**************************************************************
#include "game.h"


//==============================================================
//初期化処理
//==============================================================
HRESULT Game::Init()
{
	m_Timer = AddGameObject<Timer>(2);
	m_Timer->SetTime(30.0f);

	m_QuestionManager = new QuestionManager();
	m_QuestionManager->Load((char*)"data/TEXT/question.txt");

	m_InputTyping = new InputTyping();
	m_TextSprite = AddGameObject<TextSprite>(2);
	m_TextSprite->SetQuestionText(m_QuestionManager->GetRandomQuestion());

	return S_OK;
}

//==============================================================
//終了処理
//==============================================================
void Game::Uninit()
{
	Scene::Uninit();

	delete m_InputTyping;
	delete m_QuestionManager;
}

//==============================================================
//更新処理
//==============================================================
void Game::Update()
{
	Scene::Update();

	// 入力 - 正誤判定
	m_InputTyping->Update();
	if (m_InputTyping->IsInput())
	{
		int judge = m_TextSprite->Judge(m_InputTyping->GetKey());

		switch (judge)
		{
		// ミス
		case 0:
			m_Timer->DecTime(0.5f);
			break;
		// 1文字正解
		case 1:
			m_Timer->IncTime(0.5f);
			break;
		// 全て打ち切った
		case 2:
			m_TextSprite->ResetText();
			m_TextSprite->SetQuestionText(m_QuestionManager->GetRandomQuestion());
			m_Timer->SetTime(30.0f);
			break;
		default:
			break;
		}
	}

}
