#pragma once

#ifndef FOOL_HPP
#define FOOL_HPP

#include"Rules.hpp"

class Fool :public Rules {
public:
	void PlayMove(const GameDesk& obj) override {
		auto &current = obj.PlayerN(this->activePlayer);
		Action act = current.Action(const iViewerDesk & obj, this.Actions());
		if (this->IsPossible(act, obj)) {
			// делаем действие
		}
	}
};

#endif // !FOOL_HPP
