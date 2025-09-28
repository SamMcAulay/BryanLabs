#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

// Global arrays that hold all the 13 Ranks and 4 suits available in a deck
std::string Ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
std::string Suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

// Create a new struct to represent each card
struct card {
    // Suit of the card
    std::string suit;
    // Rank of the card
    std::string rank;
};

// Function to create and shuffle a standard 52-card deck
std::vector<card> shuffleDeck() {
    /*
    - Decks have 52 cards
    - 13 cards for each rank
    - 4 suits
    */
    int n_suits = 4;


    std::vector<card> deck; // Initialise empty vector to hold cards

    // Add cards to deck
    for (size_t s = 0; s < n_suits; s++) {
        int n_rank = 13;

        for (size_t r = 0; r < n_rank; r++) {
            // Create a new card
            card newCard;
            // Assign a rank to the new card from the global Ranks array
            newCard.rank = Ranks[r];
            // Assign a suit to the new card from the global Suits array
            newCard.suit = Suits[s];
            // Push the new card to the deck vector
            deck.push_back(newCard);
        }
    }

    // Using a time-based seed to shuffle:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // Seed will change each time the app runs
    std::ranges::shuffle(deck, std::default_random_engine(seed)); // Shuffle cards in deck

    return deck;
}

// Function to deal a single card from the top of the deck
card dealCard(std::vector<card>& deck) {
    // Access the value of the last card in the vector, while declaring hit
    card hit = deck.back();

    // Remove the last card from the deck
    deck.pop_back();

    return hit;
}

// Function to print all the cards in a given deck or hand
void printDeck(const std::vector<card>& deck) {
    // Ranged loop to print each card
    for (const auto& c : deck) {
        std::cout << c.rank << " of " << c.suit << std::endl;
    }
}

int main() {
    char guess;

    // New deck with all cards, created and shuffled
    std::vector<card> deck = shuffleDeck();

    std::vector<card> playerHand; // Player's hand (empty vector)

    while (true) {
        std::cout << "\n\nPress 'h' to get a card or 's' to stop: ";
        // Take input using cin
        std::cin >> guess;

        if (guess == 'h') {
            // Check if the deck is empty
            if (deck.empty()) {
                std::cout << "No more cards in the deck.\n";
                break;
            }

            card newCard = dealCard(deck); // Get a card from the deck

            // Add the new card to the player's hand
            playerHand.push_back(newCard);

            std::cout << "Cards you have: \n";
            printDeck(playerHand);

        } else if (guess == 's') {
            std::cout << "You chose to stop. Final hand:\n";
            printDeck(playerHand);
            break;
        } else {
            std::cout << "Invalid input. Please press 'h' or 's'.\n";
        }
    }
    return 0;
}
