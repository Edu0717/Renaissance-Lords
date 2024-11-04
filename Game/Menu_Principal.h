#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

constexpr auto MENU_MAX_OPC = 4;

void menu_inicial(RenderWindow& window_menu,int opc_select) {
	Font fonte_menu;
	Text opc_menu[4];
	Texture background_tmenu;
	Sprite background_smenu;
	Image icon;
	Color cor_opc(22, 8, 2);
	Texture tmenu_select;
	Sprite smenu_select;
	
	if (!background_tmenu.loadFromFile("Assets/image/background.png")) {
		cerr << "Erro ao carregar fonte!" << endl;
	}
	background_smenu.setTexture(background_tmenu);

	if (!tmenu_select.loadFromFile("Assets/image/livro.png")) {
		cerr << "Erro ao carregar indicador do menu!" << endl;
	}
	int i = 0;
	smenu_select.setTexture(tmenu_select);
	smenu_select.setScale(0.1f, 0.1f);
	

	if (!fonte_menu.loadFromFile("Assets/fonts/GothicPixels.ttf")) {
		cerr << "Erro ao carregar fonte!" << endl;
	}
	window_menu.draw(background_smenu);
	

	if (opc_select >= 0 && opc_select < MENU_MAX_OPC) {
		smenu_select.setPosition(15, 236 + (opc_select * 70)); // Posição ao lado da opção
		window_menu.draw(smenu_select);
	}
	for (int i = 0; i < MENU_MAX_OPC; ++i) {
		opc_menu[i].setFont(fonte_menu);
		opc_menu[i].setFillColor(cor_opc);
		opc_menu[i].setCharacterSize(45);
		opc_menu[i].setPosition(72, 230 + (i * 70));
		
		switch (i) {
		case 0: opc_menu[i].setString("Jogar"); break;
		case 1: opc_menu[i].setString("Como Jogar"); break;
		case 2: opc_menu[i].setString("Creditos"); break;
		case 3: opc_menu[i].setString("Sair"); break;
		}
		window_menu.draw(opc_menu[i]);
	}
}

