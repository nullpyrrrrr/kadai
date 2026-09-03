//**************************************************************
//シーンクラス
//**************************************************************
#pragma once

#include <list>
#include "game_object.h"

#define LAYER_NUM	3


class Scene {
protected:
	std::list<GameObject*> m_GameObject[LAYER_NUM];		// 0:背景　1:キャラクター等表示物　2:UI

public:
	virtual HRESULT Init(void) { return S_OK; };

	virtual void Uninit(void) 
	{
		for (int i = 0; i < LAYER_NUM; i++) {

			for (GameObject* gameObject : m_GameObject[i])
			{
				gameObject->Uninit();
				delete gameObject;
			}

			m_GameObject[i].clear();//空の入れ物だけが残っている状態になるものを消す
		}
	};

	virtual void Update(void) 
	{
		for (int i = 0; i < LAYER_NUM; i++) {

			for (GameObject* gameObject : m_GameObject[i])
			{
				gameObject->Update();
			}

			//remove_if  ループ処理してこの中でtrueのやつを消せる
			m_GameObject[i].remove_if([](GameObject* object) {return object->Destroy(); });
		}
	};

	virtual void Draw(void) 
	{
		for (int i = 0; i < LAYER_NUM; i++) {

			for (GameObject* gameObject : m_GameObject[i])
			{
				gameObject->Draw();

			}
		}
	};

	template<typename T>//テンプレート関数 バグの原因になるので多用は避ける
	T* AddGameObject(int Layer)
	{

		T* gameObject = new T();
		m_GameObject[Layer].push_back(gameObject);
		gameObject->Init();

		return gameObject;

	}
};