//**************************************************************
//問題管理クラス
//**************************************************************
#include "question_manager.h"

#include <fstream>
#include <cstdlib>

//==============================================================
//読み込み
//==============================================================
bool QuestionManager::Load(const char* fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		return false;
	}

	std::string line;

	while (std::getline(file, line))
	{
		// 空行は登録しない
		if (!line.empty())
		{
			m_Questions.push_back(line);
		}
	}

	file.close();

	return !m_Questions.empty();
}

//==============================================================
//ランダムに問題を返す
//==============================================================
std::string QuestionManager::GetRandomQuestion()
{
	if (m_Questions.empty())
	{
		return "";
	}

	int index = rand() % m_Questions.size();

	return m_Questions[index];
}