#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <ctime>
using namespace std;

int main() {
	time_t now = time(nullptr);

	setlocale(LC_ALL, "Portuguese");
	setlocale(LC_TIME, "pt_BR.UTF-8");

	int escolha = 0,  dificuldade  = 1;

	// Letras ainda tão quebrando o codigo todo
	while (escolha != 4) { // serve pra que todas as escolhas voltem pro menu

		system("cls");// pra deixar o jogo mais clean

		cout << "===================SENHA==================="  << endl;
		cout << "escolha uma opção :" << endl;
		cout << "1 - Jogar" << endl;
		cout << "2 - Dificuldade" << endl;
		cout << "3 - Sobre" << endl;
		cout << "4 - FIM" << endl;
		cin >> escolha;

		if(cin.fail()) { // resetar a variavel se o rese escrever algo
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Digite apenas numeros! ( de 1 a 4 ).\n";
			continue;
		}

		switch (escolha)
		{
		case 1:  // Tem Que começar a arrumar a parte do jogo
			cout << "aaa";
			break;

		case 2:// O codigo também ta motrando qual a dificuldade atual do jogador
			system("cls");
			cout << "=============DIFICULDADE==========="<<  endl;
			cout << "Por favor escolha a dificuldade que quer desafiar:  " << endl;
			if (dificuldade == 1) {
				cout << "  Dificuldade atual: fácil"<<  endl;
			} else if (dificuldade == 2) {
				cout << "  Dificuldade atual: médio"<<  endl;
			} else {
				cout << "  Dificuldade atual: difícil"<<  endl;
			}
			cout << "1 - Fácil" << endl;
			cout << "2 - médio" << endl;
			cout << "3 - Difícil" << endl;
			cin >> dificuldade;
			if(cin.fail()) {

				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Digite apenas numeros!\n";

				system("pause");
				break;
			}

			while(dificuldade < 1 || dificuldade > 3) {

				cout << "Escolha apenas entre 1 e 3: ";
				cin >> dificuldade;

				if(cin.fail()) {

					cin.clear();
					cin.ignore(1000, '\n');

					cout << "Digite apenas numeros!\n";

					break;
				}
			}

			break;

		case 3: // Coloquem o nome completo de voces aqui
			system("cls");
			cout << "==============SOBRE================" << endl;
			cout << "Equipe de Desenvolvimento==========" << endl;
			cout << "- João Gabriel M. T. dos Santos" << endl;
			cout << "- Thiago" << endl;
			cout << "- Juliano" << endl;
			cout << "- Yasmin" << endl;
			cout << "dia e data atuais :" << endl;

			//Tem que converter a data de ingles para protgues ele pega direto do sistema
			cout << "Data atual: " << ctime(&now);

			cout << "===Professor e Disciplina=========="<< endl;
			cout << "Professor: Alex Rese" << endl;
			cout << "Disciplina : Algoritmo e Programação" << endl;
			system("pause");
			break;


		case 4: // Finaliza o código
			return 0;

		default:
			cout << "Digite uma escolha válida" << endl;
			break;

		}
	}
	return 0;

}