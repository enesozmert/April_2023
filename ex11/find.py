import requests

# Ask the user for the name of a Pokemon
name = input("Enter the name of a Pokemon: ")

# Make a request to the PokeAPI
response = requests.get(f"https://pokeapi.co/api/v2/pokemon/{name.lower()}")

# Check if the request was successful
if response.status_code == 200:
    # Get the Pokemon's abilities from the response
    abilities = [ability['ability']['name'] for ability in response.json()['abilities']]

    # Print the Pokemon's name and abilities
    print(f"Name: {name.title()}")
    print("Abilities:")
    for ability in abilities:
        print(f"- {ability.title()}")
else:
    # Print an error message if the request failed
    print("Error: Pokemon not found.")