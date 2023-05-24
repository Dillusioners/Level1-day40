import random

# List of possible words for the game
words = ["lambo", "ferrari", "santa", "nunu", "elderberry", "fig", "sorsheposto", "honeydew", "chutfruit", "lebu"]

# Choose a random word from the list
word = random.choice(words)

# Convert the word to a list of letters
word_letters = list(word)

# Create a list to store correctly guessed letters
correct_guesses = []

# Create a list to store incorrectly guessed letters
incorrect_guesses = []

# Set the maximum number of allowed incorrect guesses
max_guesses = 6

# Loop until the game is won or lost
while len(incorrect_guesses) < max_guesses and set(word_letters) != set(correct_guesses):

    # Display the current state of the word
    print(" ".join([letter if letter in correct_guesses else "_" for letter in word_letters]))

    # Display the incorrect guesses
    print(f"Incorrect guesses: {' '.join(incorrect_guesses)}")

    # Get a guess from the user
    guess = input("Guess a letter: ").lower()

    # Check if the guess is a single letter
    if len(guess) != 1:
        print("Please enter only one letter.")
        continue

    # Check if the guess has already been made
    if guess in correct_guesses or guess in incorrect_guesses:
        print("You already guessed that letter.")
        continue

    # Check if the guess is in the word
    if guess in word_letters:
        correct_guesses.append(guess)
    else:
        incorrect_guesses.append(guess)

# Display the final state of the word
print(" ".join([letter if letter in correct_guesses else "_" for letter in word_letters]))

# Determine if the game was won or lost
if set(word_letters) == set(correct_guesses):
    print("Congratulations, you won!")
else:
    print(f"Sorry, you lost. The word was {word}.")