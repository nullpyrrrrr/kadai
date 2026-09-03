//**************************************************************
//–â‘èŠÇ—ƒNƒ‰ƒX
//**************************************************************
#pragma once
#include <string>
#include <vector>

class QuestionManager
{
private:
	std::vector<std::string> m_Questions;

public:
	bool Load(const char* fileName);
	std::string GetRandomQuestion();
};