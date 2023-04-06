<?php

// Array of valid choices
$choices = array('rock', 'paper', 'scissors');

// Prompt the user for input
echo "Choose rock, paper, or scissors: ";
$user_choice = strtolower(trim(fgets(STDIN)));

// Validate the user's choice
if (!in_array($user_choice, $choices)) {
    echo "Invalid choice. Please choose rock, paper, or scissors.\n";
    exit;
}

// Generate a random choice for the computer
$computer_choice = $choices[rand(0, 2)];

// Determine the winner
if ($user_choice == $computer_choice) {
    echo "It's a tie!\n";
} elseif (($user_choice == 'rock' && $computer_choice == 'scissors') || 
          ($user_choice == 'paper' && $computer_choice == 'rock') ||
          ($user_choice == 'scissors' && $computer_choice == 'paper')) {
    echo "Congratulations! You won! The computer chose rock.";
} else {
    echo "Sorry, you lost. The computer chose scissors.";
}