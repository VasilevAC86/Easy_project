#pragma once

#ifndef Deck_HPP
#define Deck_HPP

#include<vector>

class Deck {
public:
	Deck();

	void Shufle();
	void PutTop(Card card);
	void PutBotton(Card card);

	Card& Top();
	Card& Botton();

	Card& operator()(int i);
	const Card& operator[](int i)const;

	int Count()const;
private:
	std::vector<Card> cards;
};

#endif Deck_HPP