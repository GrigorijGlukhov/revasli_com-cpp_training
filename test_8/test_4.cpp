#include <iostream>
#include <array>
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
#include <ctime>

class Card
{
public:
  enum CardSuit
  {
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
  };
  enum CardRank
  {
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
  };
  //Card() { m_rank = CardRank::RANK_2; m_suit = CardSuit::SUIT_CLUB; }
  Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS) : m_rank(rank), m_suit(suit) {}
private:
  CardRank m_rank;
  CardSuit m_suit;
public:
  //void printCard(const Card &card) const
  void printCard() const
  {
    switch (m_rank)
    {
      case RANK_2:		std::cout << '2'; break;
      case RANK_3:		std::cout << '3'; break;
      case RANK_4:		std::cout << '4'; break;
      case RANK_5:		std::cout << '5'; break;
      case RANK_6:		std::cout << '6'; break;
      case RANK_7:		std::cout << '7'; break;
      case RANK_8:		std::cout << '8'; break;
      case RANK_9:		std::cout << '9'; break;
      case RANK_10:		std::cout << 'T'; break;
      case RANK_JACK:		std::cout << 'J'; break;
      case RANK_QUEEN:	std::cout << 'Q'; break;
      case RANK_KING:		std::cout << 'K'; break;
      case RANK_ACE:		std::cout << 'A'; break;
    }
   
    switch (m_suit)
    {
      case SUIT_CLUB:		std::cout << 'C'; break;
      case SUIT_DIAMOND:	std::cout << 'D'; break;
      case SUIT_HEART:	std::cout << 'H'; break;
      case SUIT_SPADE:	std::cout << 'S'; break;
    }
  }
 
  //int getCardValue(const Card &card) const
  int getCardValue() const
  {
    switch (m_rank)
    {
    case RANK_2:		return 2;
    case RANK_3:		return 3;
    case RANK_4:		return 4;
    case RANK_5:		return 5;
    case RANK_6:		return 6;
    case RANK_7:		return 7;
    case RANK_8:		return 8;
    case RANK_9:		return 9;
    case RANK_10:		return 10;
    case RANK_JACK:		return 10;
    case RANK_QUEEN:	return 10;
    case RANK_KING:		return 10;
    case RANK_ACE:		return 11;
    }
    
    return 0;
  }
 
};


class Deck
{
  static const int cardsCount = 52;
  std::array<Card, cardsCount> m_deck;
  int m_cardIndex;
public:
  Deck() { m_cardIndex = 0; init(); } // ctor

  void printDeck()
  {
    for (const auto & card : m_deck)
    {
      card.printCard();
      std::cout << ' ';
    }
    std::cout << '\n';
  }

  void shuffleDeck()
  {
    // Перебираем каждую карту в колоде
    for ( auto & card : m_deck )
    {
      // Выбираем любую случайную карту
      int swapIndex = getRandomNumber(0, m_deck.size()-1);
      // Меняем местами с нашей текущей картой
      swapCard(card, m_deck[swapIndex]);
    }
    m_cardIndex = 0;
  }

  Card & dealCard()
  {
    // print card rank and suit when dealt
    m_deck.at(m_cardIndex).printCard();
    return m_deck.at(m_cardIndex++);
  }

private:
  void init() 
  {
    // fill deck with cards
    int card = 0;
    for( int suit = 0; suit < Card::CardSuit::MAX_SUITS; ++suit )
      for( int rank = 0; rank < Card::CardRank::MAX_RANKS; ++rank )
      {
        m_deck.at(card) = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
        ++card;
      }
  }
  
  // Генерируем случайное число между min и max (включительно).
  // Предполагается, что srand() уже был вызван
  int getRandomNumber(int min, int max) const
  {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
    // Равномерно распределяем вычисление значения из нашего диапазона
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }

  static void swapCard(Card &a, Card &b)
  {
    Card temp = a;
    a = b;
    b = temp;
  }
};

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');
	
	return choice;
}

bool playBlackjack(Deck deck)
{
  // dealer's and player's scores
	int playerTotal = 0;
	int dealerTotal = 0;
 
	// Дилер получает одну карту
  std::cout << "Dealer take card: ";
	Card & card = deck.dealCard(); // get current card
  std::cout << '\n';
	dealerTotal += card.getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << " scores.\n";
 
	// Игрок получает две карты
  std::cout << "Player two cards: card ";
	card = deck.dealCard(); 
  std::cout << " and card ";
	playerTotal += card.getCardValue();
	card = deck.dealCard(); 
  std::cout << '\n';
	playerTotal += card.getCardValue();

 
	// Игрок начинает
	while (1)
	{
		std::cout << "You have: " << playerTotal << " scores.\n";
		char choice = getPlayerChoice();
		if (choice == 's')
			break;
 
    std::cout << "You ";
	  card = deck.dealCard(); 
    std::cout << " card.\n";
		playerTotal += card.getCardValue();
		
		// Смотрим, не проиграл ли игрок
		if (playerTotal > 21)
			return false;
	}
 
	// Если игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
	while (dealerTotal < 17)
	{
    std::cout << "Dealer ";
    card = deck.dealCard(); 
    std::cout << " card.\n";
		dealerTotal += card.getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << "scores.\n";
	}
 
	// Если у дилера больше 21, то он проиграл, а игрок выиграл
	if (dealerTotal > 21)
		return true;
 
	return (playerTotal > dealerTotal);
}
 
int main()
{
  srand(static_cast<unsigned int>(time(0)));

//  Card myCard(Card::CardRank::RANK_JACK, Card::CardSuit::SUIT_CLUB);
//  myCard.printCard();
//  std::cout << myCard.getCardValue() << '\n';

  Deck deck;
  //deck.printDeck();
  deck.shuffleDeck();
  //deck.printDeck();
  //std::cout << "Card value: " << deck.dealCard().getCardValue() << '\n';

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

  return 0;
}


