#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu_Principal.h"
using namespace std;
using namespace sf;

/*void tela_inicial() {
    RenderWindow window(VideoMode(800, 600), "Renaissance Lords", Style::Close | Style::Titlebar);
    Image icon;

    if (!icon.loadFromFile("D:/dujsc/icon.png")) {
        cerr << "Erro ao carregar icon!" << endl;
    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Texture background;

    if (!background.loadFromFile("D:/dujsc/background.png")) {
        cerr << "Erro ao carregar a imagem de background!" << endl;

    }
    Font fonte;

    if (!fonte.loadFromFile("C:/Users/dujsc/AppData/Local/Microsoft/Windows/Fonts/GothicPixels.ttf")) {
        cerr << "Erro ao carregar fonte!" << endl;
    }

    Text titulo("Renaissance Lords", fonte);
    titulo.setCharacterSize(30);
    titulo.setStyle(titulo.Regular);
    titulo.setFillColor(Color::Blue);
    Sprite backgroundSprite;
    backgroundSprite.setTexture(background);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(titulo);
        window.display();
    }
}*/

int main() {
    RenderWindow window(VideoMode(800, 600), "Renaissance Lords", Style::Close | Style::Titlebar);
    int opc_select = 0;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    opc_select = (opc_select - 1 + MENU_MAX_OPC) % MENU_MAX_OPC;
                }
                if (event.key.code == Keyboard::Down) {
                    opc_select = (opc_select + 1) % MENU_MAX_OPC;
                }
            }
        }
        
        window.clear();
        menu_inicial(window,opc_select);
        window.display(); 
        
    }
    
    return 0;
}