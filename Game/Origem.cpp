#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu_Principal.h"
using namespace std;
using namespace sf;



int main() {
    RenderWindow window(VideoMode(800, 600), "Renaissance Lords", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);
    Image icon;
    if (!icon.loadFromFile("Assets/image/icon.png")) {
        cerr << "Erro ao carregar icon!" << endl;
    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    int opc_select = 0;
    int sair_opc = 0;
    bool tela_saida = false;
    bool creditos = false;
    bool como_jogar = false;

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (tela_saida) {
                    switch (event.key.code) {
                    case Keyboard::Left:
                        sair_opc = (sair_opc - 1 + CONFIRM_MAX_OPC) % CONFIRM_MAX_OPC; break;
                    case Keyboard::Right:
                        sair_opc = (sair_opc + 1) % CONFIRM_MAX_OPC; break;
                    case Keyboard::Enter:
                        if (sair_opc == CONFIRM_MAX_OPC - 2) {
                            window.close();
                        }
                        else {
                            tela_saida = false;
                        }
                        break;
                        
                    }
                } else {
                    switch (event.key.code) {
                    case Keyboard::Up:
                        opc_select = (opc_select - 1 + MENU_MAX_OPC) % MENU_MAX_OPC;
                        break;
                    case Keyboard::Down:
                        opc_select = (opc_select + 1) % MENU_MAX_OPC;
                        break;
                    case Keyboard::Enter:
                       
                        if (opc_select == MENU_MAX_OPC - 1) {
                            tela_saida = true;
                        }
                        else if (opc_select == MENU_MAX_OPC - 2) {
                            creditos = true;
                        }
                        break;
                    case Keyboard::Escape:
                        if (creditos) {
                            creditos = false;
                            
                        }
                        else {
                            tela_saida = true;
                        }
                        
                        break;
                    }
                    
                }
            }
        }
        
        if (tela_saida) {
            confirma_saida(window, sair_opc);
        }
        else {
            window.clear();
            if (creditos) {
              
                creditos_menu(window, opc_select);
            }
            else {
               
                menu_inicial(window, opc_select);
            }
        }
        window.display();
    }
    
    return 0;
}