#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSJumpFlip :public IPState {
public:
	PSJumpFlip(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Player;
	Animation* m_Animation;

	float m_currentTime;

};