#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <windows.h>

#define MAX_JOGADORES 5
#define TAM_NOME 30
#define MAX_ESTAGIOS 4
#define MAX_PERGUNTAS_POR_ESTAGIO 5

struct Jogador {
    char nome[TAM_NOME];
    int pts;
};

struct Pergunta {
    char pergunta[300];
    char alternativas[4][300];
    char respostaCorreta;
};

bool compararJogadores(const Jogador &a, const Jogador &b) {
    return a.pts > b.pts;
}

void exibirArquivoPorLinhas(const char *nomeArquivo, int linhaInicio, int linhaFim) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cout << "Erro ao abrir o arquivo " << nomeArquivo << "!\n";
        return;
    }
    std::string linha;
    int linhaAtual = 0;
    while (std::getline(arquivo, linha)) {
        if (linhaAtual >= linhaInicio && linhaAtual < linhaFim) {
            std::cout << linha << std::endl;
        }
        linhaAtual++;
    }
}

void dobrar(int &num) {
    num *= 2;
}

void exibirRanking(const std::vector<Jogador> &jogadores) {
    std::cout << "\nRanking Atual:\n";
    for (size_t i = 0; i < MAX_JOGADORES; i++) {
        if (i < jogadores.size()) {
            std::cout << i + 1 << " - " << jogadores[i].nome << ": " << jogadores[i].pts << " Pontos\n";
        } else {
            std::cout << i + 1 << " - [Vazio]\n";
        }
    }
    std::cout << "\n";
}

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int carregarPerguntas(Pergunta perguntas[], const char *nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cout << "Erro ao abrir o arquivo " << nomeArquivo << "\n";
        return 0;
    }
    int i = 0;
    while (arquivo.getline(perguntas[i].pergunta, sizeof(perguntas[i].pergunta))) {
        removerNovaLinha(perguntas[i].pergunta);

        for (int j = 0; j < 4; j++) {
            arquivo.getline(perguntas[i].alternativas[j], sizeof(perguntas[i].alternativas[j]));
            removerNovaLinha(perguntas[i].alternativas[j]);
        }

        arquivo >> perguntas[i].respostaCorreta;
        arquivo.ignore();
        i++;
    }
    return i;
}

void fazerPergunta(const Pergunta &pergunta, int &vidas, int &pts, int pontosPorAcerto) {
    char resposta;
    bool respostaValida = false;

    while (!respostaValida) {
     
        system("cls");
        std::cout << "\nPergunta: " << pergunta.pergunta << "\n";
        for (int i = 0; i < 4; i++) {
            std::cout << static_cast<char>('a' + i) << ") " << pergunta.alternativas[i] << "\n";
        }
        std::cout << "\nAlternativa: ";
        resposta = getch();
        std::cout << resposta << "\n";

        if (resposta >= 'a' && resposta <= 'd') {
            respostaValida = true;
            if (resposta == pergunta.respostaCorreta) {
                pts += pontosPorAcerto;
                std::cout << "Boa, Acertou!\n" << pontosPorAcerto << " Pts\n";
            } else {
                std::cout << "Errou! Perdeu uma vida!\nVidas restantes: " << --vidas << "\n";
            }
            Sleep(1000);
        } else {
            std::cout << "Caractere incorreto! Tente novamente.\n";
        }
    }
}

 void jogar(std::vector<Jogador> &jogadores, Pergunta perguntas[], int num_perguntas) {
    exibirArquivoPorLinhas("inicio.txt", 0, 5);
    std::cout << "\n";
    Sleep(1000);

    int pontosPorEstagio[MAX_ESTAGIOS] = {100, 200, 300, 400};

    for (int stg = 0; stg < MAX_ESTAGIOS; stg++) {
        bool ZeroVidas = false;
        do {
            system("cls");
            std::cout << "\n--- Estagio " << stg + 1 << " ---\n"; 
            Sleep(1000);

            int vidas = 3;
            int pts = 0;

            for (int i = 0; i < MAX_PERGUNTAS_POR_ESTAGIO && vidas > 0; i++) {
                fazerPergunta(perguntas[stg * MAX_PERGUNTAS_POR_ESTAGIO + i], vidas, pts, pontosPorEstagio[stg]);
            }

            if (vidas == 3) {
                dobrar(pts);
                std::cout << "\nPerfect! Acertou todas! Pontos Dobrados: " << pts << "\n";
                ZeroVidas = false;  
                Sleep(1500);
            } else if (vidas > 0) {
                std::cout << "\nEstagio " << stg + 1 << " Completo!\nPontos: " << pts << " Vidas restantes: " << vidas << "\n";
                ZeroVidas = false;  
                Sleep(1500);
            } else {
                std::cout << "\nGame Over\nTente novamente!\n\n";
                ZeroVidas = true; 
                Sleep(1500);
            }

            jogadores[0].pts += pts;
        } while (ZeroVidas);  
    }
    system("cls");
    std::cout << "Total de pontos acumulados: " << jogadores[0].pts << "\n";
    if (jogadores[0].pts > 0) {
        std::cout << "Digite seu nome: ";
        std::cin >> jogadores[0].nome;
    }

    std::sort(jogadores.begin(), jogadores.end(), compararJogadores);

    system("cls");
    exibirRanking(jogadores);
    std::cout << "\nObrigado por jogar!\n\n";
    system("pause");
    system("cls");
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::vector<Jogador> jogadores(MAX_JOGADORES);
    Jogador &jogador = jogadores[0];
    jogador.pts = 0;
    char escolha;
    Pergunta perguntas[MAX_ESTAGIOS * MAX_PERGUNTAS_POR_ESTAGIO];
    int num_perguntas = carregarPerguntas(perguntas, "perguntas.txt");

    do {
        std::cout << " Renaissance Lords\n";
        std::cout << "1 - Jogar\n";
        std::cout << "2 - Ver Ranking\n";
        std::cout << "3 - Informações sobre o jogo\n";
        std::cout << "4 - Sair\n";
        escolha = getch();
        std::cout << "\n";

        switch (escolha) {
            case '1':
                jogar(jogadores, perguntas, num_perguntas);
                break;
            case '2':
                system("cls");
                exibirRanking(jogadores);
                system("pause");
                system("cls");
                break;
            case '3':
                system("cls");
                exibirArquivoPorLinhas("inicio.txt", 5, 11);
                std::cout << "\n";
                system("pause");
                system("cls");
                break;
            case '4':
                std::cout << "Saindo do jogo.\n";
                break;
            default:
                std::cout << "Tente novamente.\n\n";
                Sleep(1000);
                system("cls");
                break;
        }
    } while (escolha != '4');

    return 0;
}

