#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

constexpr auto MENU_MAX_OPC = 4;
constexpr auto CONFIRM_MAX_OPC = 2;


void menu_inicial(RenderWindow& window_menu,int opc_select) {
	Font fonte_menu;
	Text opc_menu[4];
	Texture background_tmenu;
	Sprite background_smenu;
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

void confirma_saida(RenderWindow& window_menu, int sair_opc) {
	Font fonte_confirm;
	Text opc_confirm[2];
	Text titulo_confirm;
	Texture tconfirm_tela;
	Sprite sconfirm_tela;
	Texture tconfirm_select;
	Sprite sconfirm_select;
	Color confirm_color_opc(255,255,255);


	if (!tconfirm_tela.loadFromFile("Assets/image/provisorio.png")) {
		cerr << "Erro ao carregar tela de confirmação!" << endl;
	}
	sconfirm_tela.setTexture(tconfirm_tela);
	sconfirm_tela.setPosition(225, 225);
	window_menu.draw(sconfirm_tela);

	if (!fonte_confirm.loadFromFile("Assets/fonts/GothicPixels.ttf")) {
		cerr << "Erro ao carregar fonte!" << endl;
	}

	titulo_confirm.setFont(fonte_confirm);
	titulo_confirm.setString("Voce tem certeza?");
	titulo_confirm.setFillColor(confirm_color_opc);
	titulo_confirm.setCharacterSize(32);
	titulo_confirm.setPosition(250, 245);
	window_menu.draw(titulo_confirm);
	
	for (int i = 0; i < CONFIRM_MAX_OPC; i++) {
		opc_confirm[i].setFont(fonte_confirm);
		opc_confirm[i].setFillColor(confirm_color_opc);
		opc_confirm[i].setCharacterSize(36);
		opc_confirm[i].setPosition(300 + (i * 125), 300.0);
		switch (i) {
		case 0: opc_confirm[i].setString("Sim"); break;
		case 1: opc_confirm[i].setString("Nao"); break;
		}
		window_menu.draw(opc_confirm[i]);
		
	}
	if (!tconfirm_select.loadFromFile("Assets/image/livro.png")) {
		cerr << "Erro ao carregar indicador do menu!" << endl;
	}
	
	sconfirm_select.setTexture(tconfirm_select);
	sconfirm_select.setScale(0.09f, 0.09f);

	if (sair_opc >= 0 && sair_opc < CONFIRM_MAX_OPC) {
		sconfirm_select.setPosition(250 + (sair_opc * 125), 300); // Posição ao lado da opção
		window_menu.draw(sconfirm_select);
	}

}

void creditos_menu(RenderWindow& window_menu) {


}

