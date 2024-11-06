#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
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
	Texture ttitulo;
	Sprite stitulo;
	
	if (!ttitulo.loadFromFile("Assets/image/titulo.png")) {
		cerr << "Erro ao carregar fonte!" << endl;
	}
	stitulo.setTexture(ttitulo);
	stitulo.setScale(0.35f, 0.35f);
	stitulo.setPosition(30.0f, 75.0f);

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
	window_menu.draw(stitulo);

	if (opc_select >= 0 && opc_select < MENU_MAX_OPC) {
		smenu_select.setPosition(15.0f, 236.0f + (opc_select * 70.0f)); // Posição ao lado da opção
		window_menu.draw(smenu_select);
	}
	

	for (int i = 0; i < MENU_MAX_OPC; ++i) {
		opc_menu[i].setFont(fonte_menu);
		opc_menu[i].setFillColor(cor_opc);
		opc_menu[i].setCharacterSize(45);
		opc_menu[i].setPosition(70.0f, 230.0f + (i * 70.0f));
		
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
	sconfirm_tela.setPosition(225.0f, 225.0f);
	window_menu.draw(sconfirm_tela);

	if (!fonte_confirm.loadFromFile("Assets/fonts/GothicPixels.ttf")) {
		cerr << "Erro ao carregar fonte!" << endl;
	}

	titulo_confirm.setFont(fonte_confirm);
	titulo_confirm.setString("Voce tem certeza?");
	titulo_confirm.setFillColor(confirm_color_opc);
	titulo_confirm.setCharacterSize(32);
	titulo_confirm.setPosition(250.0f, 245.0f);
	window_menu.draw(titulo_confirm);
	
	for (int i = 0; i < CONFIRM_MAX_OPC; i++) {
		opc_confirm[i].setFont(fonte_confirm);
		opc_confirm[i].setFillColor(confirm_color_opc);
		opc_confirm[i].setCharacterSize(36);
		opc_confirm[i].setPosition(300.0f + (i * 125.0f), 300.0f);
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
		sconfirm_select.setPosition(250.0f + (sair_opc * 125.0f), 300.0f); // Posição ao lado da opção
		window_menu.draw(sconfirm_select);
	}

}

void creditos_menu(RenderWindow& window_menu, int opc_credit_select) {
	 Texture tbackground_creditos;
	 Sprite sbackground_creditos;
	 Texture ttitulo;
	 Sprite stitulo;
	 Font font;
	 Text text_creditos;
	 Texture tlogoUnifan;
	 Sprite slogoUnifan;

	if (!font.loadFromFile("Assets/fonts/Ancient Modern Tales.otf")) {
		cerr << "Erro ao carregar fonte!" << endl;
	}

	if (!tbackground_creditos.loadFromFile("Assets/image/background.png")) {
		cerr << "Erro ao carregar fundo!" << endl;
	}
	sbackground_creditos.setTexture(tbackground_creditos);

	if (!ttitulo.loadFromFile("Assets/image/titulo.png")) {
		cerr << "Erro ao carregar título!" << endl;
	}
	if (!tlogoUnifan.loadFromFile("Assets/image/unifan_logo.png")) {
		cerr << "Erro ao carregar título!" << endl;
	}
	stitulo.setTexture(ttitulo);
	stitulo.setScale(0.35f, 0.35f);
	stitulo.setPosition(30.0f, 75.0f);

	slogoUnifan.setTexture(tlogoUnifan);
	slogoUnifan.setPosition(150.0f, 460.0f);
	slogoUnifan.setScale(0.2f, 0.2f);

	vector<string> list_creditos = {
		"---------EQUIPE---------",
		"Victor Gomes - Desenvolvedor",
		"Mateus Nobre - Roteirista",
		"Italo Oliveira- Gerente de projeto",
		"Pedro Henrique O.- Artista",
		"Eduardo santos - Game Designer",
		"------ORIENTADOR-------",
		"Gean Trabuco Lima - Orientador",
	};

	text_creditos.setFont(font);
	text_creditos.setFillColor(Color::Black);
	float posY = 215.0f;

	window_menu.draw(sbackground_creditos);
	window_menu.draw(stitulo);
	

	for (const auto& linha : list_creditos) {
		text_creditos.setString(linha);
		text_creditos.setPosition(67.0f, posY);
		posY += 30.0f;
		window_menu.draw(text_creditos);
	}
	window_menu.draw(slogoUnifan);
}

void como_jogar(RenderWindow& window_menu, int opc_credit_select) {

}

	

