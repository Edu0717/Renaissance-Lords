#include <SFML/Graphics.hpp>

void creditos_simples(sf::RenderWindow& janela, const sf::Font& fonte) {
    sf::Text texto("Obrigado!", fonte, 30);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(200, janela.getSize().y);  // Começa na parte inferior da janela

    while (janela.isOpen()) {
        sf::Event evento;
        while (janela.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                janela.close();
        }

        // Move o texto para cima por um valor fixo
        texto.move(0, -1.0f);  // Mover para cima a cada iteração

        janela.clear();
        janela.draw(texto);
        janela.display();

        // Para quando o texto sair da tela
        if (texto.getPosition().y + texto.getGlobalBounds().height < 0) {
            break;
        }
    }
}