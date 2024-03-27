#pragma once

#ifndef RULES_HPP
#define RULES_HPP

#include<string>
#include<vector>

#include"Player.hpp" // Правила должны уметь работать с игроками
#include"Card.hpp"
#include"Deck.hpp"
#include"GameDesk.hpp" // Игровой стол
#include"Action.hpp"

/// Класс правил (абстрактный, чтобы реализовывать в наследниках новые правила)
class Rules {
public:
	// Виртуальный метод для возврата колоды
	virtual Deck StartDeck() = 0;
	// Правила должны уметь выполнять первоначальную установку на игровом поле (например, разложить карты)
	virtual void InitialDesk(GameDesk& obj) = 0;
	// Метод, который будет возвращать перечень действий в игре
	virtual std::vector<std::string> Action() = 0;

private:
	int minPlayers_;
	int maxPlayers_;
	std::string name_; // Название игры
	int activePlayer; // Поле активного игрока сейчас (для выдачи правил)
};

#endif // !RULES_HPP

