#pragma once

#ifndef GAME_DESK_HPP
#define GAME_DESK_HPP

#include<vector>

#include "Deck.hpp" // Колода
#include"Player.hpp" // Игрок
#include"Card.hpp" // Карты

// Этот класс надо будет отправлять в графический интерфейс для отрисовки
class GameDesk {
public: 
	// Метод для получения себе колоды
	void SetStartDeck(Deck deck);
	// Перемещение карты в сброс
	void DraftCard(Card played);
	// Можно сделать метод для отправки набора карт в сброс

	// Разместить на себе игрока
	void NewPlayer(Player obj);
	// Удалить игрока
	void KickPlayer(int position); 
	// Метод доступа к игрокам
	Player& PlayerN(int position);
	// Геттер текущего кол-ва игроков
	int CurrentPlayers()const;
	// Получение доступа к верхней карте колоды
	Deck GetTopCard();
	// Получение доступа к нижней карте колоды
	Deck GetBottomCard();

	// Счётчик оставшихся карт в колоде
	int CurrentDeck();
	
	// Методы оперирования слотами 
	// Метод полного доступа
	void PlaceSlotN(Card card, bool visible, int position);
	// Положить карту на стол
	void PlaceSlot(Card card, bool visible); // Что за карта и в каком режиме
	// Возвращаем карту 
	Card SlotN(int position);
	// Геттер слотов
	int CurrentSlots()const;
	// Опустошаем слот
	Card FreeSlot(int position);
private:
	// Поля для разыгранных, неразыгранных карт, карты на игровом столе
	Deck newCards_; // место для хранения неразыгранных карт
	Deck oldCards_; // место для хранения уже разыгранных карт (которые уже не будут учавствовать в игре)
	std::vector<Player> player_; // Вестор игроков в игре
	/// Класс карт, которые на столе
	class CardSlot { 
	public:

		// Нет прайвата, т.к. доступность к классу будет только из нужных классов
		Card current; // Карта, хранимая в слотев текущий момент
		bool visible_; // Открыта или закрыта
	};

	std::vector<CardSlot> deskGards_; // Сколько слотов под карты на столе могут быть (наприме, 0 элемент - это слот под козырь)
	// Спрашиваем у игры, во что играйм, то и берём из deskGards_
};

#endif // !GAME_DESK_HPP
