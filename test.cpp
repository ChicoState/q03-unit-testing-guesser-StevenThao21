#include "Guesser.h"
#include <string>
#include <algorithm> // for std::min

using std::string;

Guesser::Guesser(string secret)
{
    // Truncate secret to 32 characters if longer
    m_secret = secret.substr(0, 32);
    m_guessesRemaining = 3; // Start with 3 guesses
    m_locked = false;       // Initially, the secret is not locked
}

unsigned int Guesser::distance(string guess)
{
    int distance = 0;
    size_t len_secret = m_secret.size();
    size_t len_guess = guess.size();
    size_t min_len = std::min(len_secret, len_guess);

    // Calculate the distance for the length of the shorter string
    for (size_t i = 0; i < min_len; i++)
    {
        if (m_secret[i] != guess[i])
            distance++;
    }

    // Add remaining characters from the longer string
    distance += abs(static_cast<int>(len_secret) - static_cast<int>(len_guess));

    return distance;
}

bool Guesser::match(string guess)
{
    if (m_locked || m_guessesRemaining == 0)
        return false; // Return false if locked or no guesses left

    // Calculate distance to check for brute force attempt
    if (distance(guess) > 2)
    {
        m_locked = true; // Lock if the guess is wildly incorrect
        return false;
    }

    if (m_secret == guess)
    {
        m_guessesRemaining = 3; // Reset guesses on a correct guess
        return true;
    }
    else
    {
        m_guessesRemaining--; // Decrease remaining guesses
        return false;
    }
}

unsigned int Guesser::remaining()
{
    return m_guessesRemaining;
}
