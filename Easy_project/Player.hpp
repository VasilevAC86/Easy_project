#pragma once

#ifndef Player_HPP
#define Player_HPP

#include<string>
#include"GameDesk.hpp"
#include"Action.hpp"
#include"Controller.hpp"

// Для внешнего наблюдателя
class iViewPlayer {
public:
	virtual std::string GetName()const = 0;
	virtual int CurrentCards()const = 0;
private:
};

class Player:public iViewPlayer {
public:
	Player();
	
	Action Action(std::vector<Action> &Action, const iViewerDesk & env) {
		//return controller_->Action(actions, env);
	}

	//
	void SetName(std::string name);
	std::string GetName()const;

	void Taik(Card obj); // Карта в руке
	int CurrentCards()const; // Сколько карт в руке
private:
	Controller controller_;
	std::string name_;
	Deck hand_;	
};

#endif // !Player_HPP

