//
// Created by nicho on 11/27/2023.
//
#include <SFML/Graphics.hpp>
using namespace std;

//this class is to display the champion
class Icon {
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Icon(sf::Vector2f _position);
    sf::Vector2f getPosition();
    void draw();
    void setChampionImage(string champion);

};

