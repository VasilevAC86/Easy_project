#pragma once

#ifndef GAME_DESK_HPP
#define GAME_DESK_HPP

#include<vector>

#include "Deck.hpp" // Колода
#include"Player.hpp" // Игрок
#include"Card.hpp" // Карты

// Интерфейс внешнего пользователя (просмотрщика стола)
// Принцип разделения интерфейсов при написании кода программы
// Игроки не смогут получить доступ к запретной информации
class iViewerDesk{
public:
	virtual int CurrentDeck()const = 0; // Текущее состояние стола
	// Показывать игроков согласно позициям
	virtual const Player& PlayerN(int position)const = 0;
	// Метод для раоты со слотами
	virtual int CurrentSlots()const = 0;
	// Возвращаем карту из слота
	virtual Card SlotN(int position)const = 0;
};

// Этот класс надо будет отправлять в графический интерфейс для отрисовки
class GameDesk:public iViewerDesk {
public: 
	// Метод для получения себе колоды
	void SetStartDeck(Deck deck);
	Deck GetTopCard();
	Deck GetBottonCard();
	
	// Перемещение карты в сброс
	void DraftCard(Card played);
	// Можно сделать метод для отправки набора карт в сброс

	// Разместить на себе игрока
	void NewPlayer(Player obj);
	// Удалить игрока
	void KickPlayer(int position); 
	// Метод доступа к игрокам
	Player& PlayerN(int position);
	const iViewPlayer& PlayerN(int position)const;
	// Геттер текущего кол-ва игроков
	int CurrentPlayers()const;
	// Получение доступа к верхней карте колоды
	Deck GetTopCard();
	// Получение доступа к нижней карте колоды
	Deck GetBottomCard();

	// Счётчик оставшихся карт в колоде
	int CurrentDeck()const;
	
	// Методы оперирования слотами 
	// Метод полного доступа
	void PlaceSlotN(Card card, bool visible, int position);
	// Положить карту на стол
	void PlaceSlot(Card card, bool visible); // Что за карта и в каком режиме
	// Возвращаем карту из слота
	Card SlotN(int position)const;
	// Геттер кол-ва карт на столе
	int CurrentSlots()const;
	// Метод для уборки карт со стола (методы сброса карт в отбой будут определять правила с посмщь. этого метода)
	Card FreeSlot(int position);

	const iViewerDesk& CurrentEnvirement()const;
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
