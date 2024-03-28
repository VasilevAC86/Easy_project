#pragma once

#ifndef GAME_HPP
#define GAME_HPP

// Максимально простой интерфейс для взаимодействия с игрой

#include<string>
#include<vector>

#include"Rules.hpp" // Класс должен знать, что такое правила
#include"Player.hpp"
#include"GameDesk.hpp"

class Game {
	// Нужно предоставить пользователю инф-ю о том, с чем он работает
public:
	// Возврат типов игроков
	std::vector<std::string> PlayerType(); 
	// Возврат перечень игр, с которыми она работает
	std::vector<std::string> GameType();	
	// Метод, который, исходя из правил, будет реализовывать стол
	void Init();
	// Метод добовления нового игрока за столом (не позволяет добавлять игроков с одинаковыми именами)
	void Add(std::string playerType, std::string name);
	// Метод добавления новой игры из существующегно списка доступных игр
	void Set(std::string GameType);
	// Метод сообщения инф-ии об игроках за столом (пары типы и имена игроков)	
	std::vector<std::pair<std::string, std::string>>CurrentPlayers();
	// Замена игрока
	void ChangeName(std::string newName, int position);
	// Метод для работы с правилами (выполянять внутри себя кое-кае вещи)
	void Play();
	// Метод для сообщения внешнему пользователю, что происходит за столом
	const GameDesk& CurrentEnvirement()const;
private:
	GameDesk desk_;
	Rules* rules_; // через указатель, т.к. класс Rules абстрактный
};

#endif // !GAME_HPP
