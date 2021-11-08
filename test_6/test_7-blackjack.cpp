
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // time()

enum class CardSuit {
  TREFU,
  BUBNU,
  CHERVU,
  PIKI,
  MAX_SUITS
};

enum class CardRank {
  DVOIKA,
  TROIKA,
  CHETVERKA,
  PATIORKA,
  SHESTERKA,
  SEMERKA,
  VOSMERKA,
  DEVYATKA,
  DESYATKA,
  VALET,
  DAMA,
  KOROL,
  TUZ,
  MAX_RANKS
};

// calc deck size
const int deckSize = static_cast<int>(CardSuit::MAX_SUITS)*static_cast<int>(CardRank::MAX_RANKS);

struct Card {
  CardSuit suit;
  CardRank rank;
};

void printCard( const Card & card ) {
  switch ( card.rank ) {
    case CardRank::DVOIKA     : std::cout << "2";  break;
    case CardRank::TROIKA     : std::cout << "3";  break;
    case CardRank::CHETVERKA  : std::cout << "4";  break;
    case CardRank::PATIORKA   : std::cout << "5";  break;
    case CardRank::SHESTERKA  : std::cout << "6";  break;
    case CardRank::SEMERKA    : std::cout << "7";  break;
    case CardRank::VOSMERKA   : std::cout << "8";  break;
    case CardRank::DEVYATKA   : std::cout << "9";  break;
    case CardRank::DESYATKA   : std::cout << "10"; break;
    case CardRank::VALET      : std::cout << "V";  break;
    case CardRank::DAMA       : std::cout << "D";  break;
    case CardRank::KOROL      : std::cout << "K";  break;
    case CardRank::TUZ        : std::cout << "T";  break;
  }
  switch ( card.suit ) {
    case CardSuit::TREFU  : std::cout << "TR"; break;
    case CardSuit::BUBNU  : std::cout << "B"; break;
    case CardSuit::CHERVU : std::cout << "CH"; break;
    case CardSuit::PIKI   : std::cout << "P"; break;
  }
}

// Initialize deck with cards
void initDeck( std::array<Card, deckSize> & deck ) {
  int card = 0;
  for ( int suit = 0; suit < static_cast<int>(CardSuit::MAX_SUITS); ++suit ) {
    for ( int rank = 0; rank < static_cast<int>(CardRank::MAX_RANKS); ++rank ) {
      deck.at(card).suit = static_cast<CardSuit>(suit);
      deck.at(card).rank = static_cast<CardRank>(rank);
      ++card;
    }
  }
}

// print whole deck
void printDeck(const std::array<Card, deckSize> & deck) {
  for ( const auto & card : deck ) {
    printCard(card);
    std::cout << ' ';
  }
  std::cout << '\n';
}

// swap two cards
void swapTwoCards( Card & cardA, Card & cardB ) {
  Card temp = cardA;
  cardA = cardB;
  cardB = temp;
}

// custom random number generator
int getRandomNumber( int min, int max ) {
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// shuffle whole Cards deck
void shuffleDeck( std::array<Card, deckSize> & deck ) {
  int index = 0;
  for ( Card & card : deck ) {
    swapTwoCards(deck[index], deck[getRandomNumber(0, deck.size())]);
    //deck[index]
    ++index;
  }
}

// get (int) value of card
int getCardValue( const Card card ) {
  int result;
  switch ( static_cast<int>(card.rank) ) {
    default:
    case 0  : result = 2; break;
    case 1  : result = 3; break;
    case 2  : result = 4; break;
    case 3  : result = 5; break;
    case 4  : result = 6; break;
    case 5  : result = 7; break;
    case 6  : result = 8; break;
    case 7  : result = 9; break;
    case 8  : result = 10; break;
    case 9  : result = 10; break;
    case 10 : result = 10; break;
    case 11 : result = 10; break;
    case 12 : result = 11; break;
  }
  return result;
}

bool playBlackJack( std::array<Card, deckSize> & deck ) {
  Card * cardPtr = &deck.at(0); // get first card in deck
  int playerScore = 0, dealerScore = 0, round = 1;
  do { // main loop while players getting cards
    std::cout << "\n---Round " << round << '\n';
    dealerScore += getCardValue(*cardPtr++);
    std::cout << "Dealer gets card for : " << dealerScore << '\n';
    if ( playerScore == 0 ) { // first round
      playerScore = getCardValue(*cardPtr++) + getCardValue(*cardPtr++);
      std::cout << "Player gets two cards for : " << playerScore << '\n';
    }
    char choose;
    do { // ask player for answer letter
      std::cout << "Player's turn. What you want to do: (h)it or (s)tand? ";
      std::cin >> choose;
      std::cin.ignore(32767, '\n');
      if ( std::cin.fail() or choose != 's' and choose != 'h' ) {
        std::cout << "Wrong answer! Try again - s or h.\n";
      }
      std::cin.clear();
    } while ( std::cin.fail() or choose != 's' and choose != 'h' );
    std::cout << "\nYou choose : " << choose << '\n';
    if ( choose == 'h' ) {
      playerScore += getCardValue(*cardPtr++);
      std::cout << "Player gets another card and his score is " << playerScore << '\n';
    } else {
      std::cout << "Player still have " << playerScore << " scores and Dealer's score is " << dealerScore << '\n';
    }
    ++round;
  } while ( playerScore < 21 and dealerScore < 21 );

  if ( playerScore == 21 and dealerScore != 21 ) { // player wins
    std::cout << "\n--------Player wins with 21 score!\n";
    return true;
  } else if ( dealerScore > 21 ) {
    std::cout << "\n--------Player wins with dealer's loose!\n";
  } else if ( playerScore == 21 and dealerScore == 21 ) {
    std::cout << "\n--------Player and dealer have equal 21 scores!\n";
    return false;
  } else {
    std::cout << "\n--------Player loose!\n";
    return false;
  }
}


//------------------------------------------------------------------
// Main
//------------------------------------------------------------------
int main() {

  srand( static_cast<unsigned int>(time(0)) );

  // create deck of cards (array)
  std::array <Card, deckSize> deck;
  // init deck with cards
  initDeck(deck);
  // print whole deck
  printDeck(deck);

  std::cout << '\n';

  // shuffle deck
  shuffleDeck(deck);

  // print whole shuffled deck
  printDeck(deck);

  std::cout << '\n';

  // print all cards value
  for ( int i = 0; i < 52; ++i )
    std::cout << getCardValue(deck[i]) << ' ';

	playBlackJack(deck);

  return EXIT_SUCCESS;
}

