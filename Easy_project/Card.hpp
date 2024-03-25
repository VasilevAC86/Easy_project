#pragma once

#ifndef Card_HPP
#define Card_HPP

class Card {
public:
	enum class Ranks { // Набор целочисленных констант
		Two,
		Tree,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace
	};
	enum class Suits {
		Hearts,
		Diamonds,
		Clubs,
		Spades
	};
	Card();
	Card(Suits suit, Ranks rank);
	
	// Карты менять нельзя
	Ranks Rank()const;
	Suits Suit()const;
private:
	Ranks rank_; // Номинал
	Suits suit_; // Масть
};

#endif // !Card_HPP