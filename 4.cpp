#include <iostream>
#include <vector>
using namespace std;
class Card
{
public:
	enum class Card_value
	{
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack = 10,
		Queen = 10,
		King = 10,
	};
	enum class Suit
	{
		Spades,
		Hearts,
		Diamonds,
		Clubs
	};
	Card(Card_value v, Suit s, bool p) : c_value(v), c_suit(s), card_position(p) {}
	void Flip()
	{
		card_position = !(card_position);
	}
	int GetValue() const
	{
		int value{};
		value = (int)c_value;
		return value;
	}

private:
	Card_value c_value;
	Suit c_suit;
	bool card_position{};
};

class Hand
{
public:
	virtual ~Hand()
	{
		Clear();
	}
	void Add(Card* pCard)
	{
		h_Cards.push_back(pCard);
	}
	void Clear()
	{
		vector<Card*>::iterator iter = h_Cards.begin();
		for (iter = h_Cards.begin(); iter != h_Cards.end(); ++iter)
		{
			delete* iter;
			*iter = 0;
		}
		h_Cards.clear();
	}
	int GetTotal() const
	{
		if (h_Cards.empty())
		{
			return 0;
		}
		if (h_Cards[0]->GetValue() == 0)
		{
			return 0;
		}
		int total = 0;
		vector<Card*>::const_iterator iter;
		for (iter = h_Cards.begin(); iter != h_Cards.end(); ++iter)
		{
			total += (*iter)->GetValue();
		}
		bool containsAce = false;
		for (iter = h_Cards.begin(); iter != h_Cards.end(); ++iter)
		{
			if ((*iter)->GetValue() == (int)Card::Card_value::Ace)
			{
				containsAce = true;
			}
		}
		if (containsAce && total <= 11)
		{
			total += 10;
		}
		return total;
	}

protected:
	vector<Card*> h_Cards;
};

class GenericPlayer : public Hand
{
public:
	GenericPlayer(const string& name) : g_Name(name) {}
	virtual ~GenericPlayer() {}
	virtual bool IsHitting() const = 0;
	bool IsBusted() const
	{
		return (GetTotal() > 21);
	}
	void Bust() const
	{
		cout << g_Name << "Перебор" << endl;
	}

protected:
	string g_Name;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	return 0;
}