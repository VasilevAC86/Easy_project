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
	// Конструктор для указания стартовой позиции при создании правил игры
	Rules(std::string name, int minPlayers, int maxPlayers)
		:minPlayers_(minPlayers),
		maxPlayers_(maxPlayers),
		name_(name),
		activePlayer(0) {}
	// Виртуальный метод для возврата колоды
	virtual Deck StartDeck() = 0;
	// Правила должны уметь выполнять первоначальную установку на игровом поле (например, разложить карты)
	virtual void InitialDesk(GameDesk& obj) = 0;
	// Метод, который будет возвращать перечень действий в игре
	virtual std::vector<std::string> Action() = 0;
	// Методы доступа, методы, которые будут обеспечивать работу правил в части доьалвнеия новго игрока
	int MinPlayers()const;
	int MaxPlayers()const;
	std::string Name()const;

	// Базова проверка работы правил (текущее кол-во игроков за столом)
	bool CanStart(const GameDesk& obj);
	// Допустимо ли добалять нового игрока?
	bool CanAddPlayer(const GameDesk& obj);
	// Как сделать игровой ход, правила не знают, они знают, что такой метод должен быть
	virtual void PlayMove(const GameDesk& obj) = 0;
	virtual bool IsPossible(Action act, const GameDesk& obj);
protected:
	int minPlayers_; // Минимальное кол-во игроков для игры
	int maxPlayers_; // Максимальное кол-во игроков для игры
	std::string name_; // Название игры
	int activePlayer; // Поле активного игрока сейчас (для выдачи правил)
};

#endif // !RULES_HPP

