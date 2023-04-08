#include "ParallelBackground.h"

void ParallexBackground::Init()
{
	Layer* layer;
	std::string path = "Background layers/";
	//Layer 2
	layer = new Layer();
	layer->Init(path+"Background",120);
	m_Background.push_back(layer);
	// trang chi them cho background thi them o day :))


}

void ParallexBackground::Update(float deltaTime)
{
	for (auto layer : m_Background) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	for (auto layer : m_Background) {
		layer->Render(window);
	}
}
