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
        system("color 07");
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
			system("cls");
			if (dificuldade == 1) {
				int num1, num2, num3, tentativas = 1, res1 = 0, res2 = 0, res3= 0;
				int certos = 0;
				int errados = 0;
				bool resposta = false;
				srand(time(0));

				do {
					num1  = rand()%6 + 1;
					num2  = rand()%6 + 1;
					num3  = rand()%6 + 1;
				} while (num1 == num2 or num1 == num3 or num2 == num3);
				//cout << num1 << num2 << num3;
				while (tentativas <= 8 && resposta == false) {
					cout <<"============ DIFICULDADE FÁCIL ===================" << endl;
                    cout << "Tentativa " << tentativas << " de 8" << endl;
                    cout << "Seu último chute foi: " << res1 << res2 << res3 << endl;
					cout << "Digite 3 numeros de 1 a 6: " << endl;
					cout << "Primeiro numero:  " << endl;
					cin  >> res1;
					if(cin.fail()) {

						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Digite apenas numeros!\n";

						continue;
					}
					cout << "Segundo numero:  " << endl;
					cin  >> res2;
					if(cin.fail()) {

						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Digite apenas numeros!\n";

						continue;
					}
					cout << "Terceiro numero:  " << endl;
					cin  >> res3;
					if(cin.fail()) {

						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Digite apenas numeros!\n";

						continue;
					}

					while (
					    res1 < 1 || res1 > 6 ||
					    res2 < 1 || res2 > 6 ||
					    res3 < 1 || res3 > 6
					) {

						cout << "Numeros invalidos!" << endl;
						cout << "Digite 3 numeros de 1 a 6: " << endl;
						cout << "Primeiro numero:  " << endl;
						cin  >> res1;
						if(cin.fail()) {

							cin.clear();
							cin.ignore(1000, '\n');

							cout << "Digite apenas numeros!\n";

							continue;
						}
						cout << "Segundo numero:  " << endl;
						cin  >> res2;
						if(cin.fail()) {

							cin.clear();
							cin.ignore(1000, '\n');

							cout << "Digite apenas numeros!\n";

							continue;
						}
						cout << "Terceiro numero:  " << endl;
						cin  >> res3;
						if(cin.fail()) {

							cin.clear();
							cin.ignore(1000, '\n');

							cout << "Digite apenas numeros!\n";

							continue;
						}
						cout << "\n=========== RESULTADO ===========" << endl;
					}
					
					if (res1 == num1) {
                        cout << "\033[32m";
						cout << "[✓] Primeiro numero correto na posicao correta" << endl;
                        cout << "\033[0m";
                    } else if (res1 == num2 || res1 == num3) {
                        cout << "\033[33m";
						cout << "[~] Primeiro numero correto mas esta na posicao errada" << endl;
                        cout << "\033[0m";
                    } else {
                        cout << "\033[31m";
						cout << "[X] Primeiro numero incorreto" << endl;
                        cout << "\033[0m";
					}
					
					if (res2 == num2) {
                        cout << "\033[32m";
						cout << "[✓] Segundo numero correto na posicao correta" << endl;
					    cout << "\033[0m";
                    } else if (res2 == num1 || res2 == num3) {
                        cout << "\033[33m";
						cout << "[~] Segundo numero existe mas esta na posicao errada" << endl;
                        cout << "\033[0m";
                    } else {
                        cout << "\033[31m";
						cout << "[X] Segundo numero incorreto" << endl;
                        cout << "\033[0m";
                    }
					
					if (res3 == num3) {
                        cout << "\033[32m";
						cout << "[✓] Terceiro numero correto na posicao correta" << endl;
                        cout << "\033[0m";
                    } else if (res3 == num1 || res3 == num2) {
                        cout << "\033[33m";
						cout << "[~] Terceiro numero existe mas esta na posicao errada" << endl;
                        cout << "\033[0m";
                    } else {
                        cout << "\033[31m";
						cout << "[X] Terceiro numero incorreto" << endl;
                        cout << "\033[0m";
                    }
					
					tentativas++;
					
					if (res1 == num1 && res2 == num2 && res3 == num3) {
                        system("color 0A");
						cout << "Parabéns você conseguiu!!" << endl;
						resposta =  true;
						system("pause");
						break;
					}


				}
				if (tentativas == 8 and resposta ==  false) {
                    system("color 0C");
					cout << "Você não conseguiu adivinhar. Que pena!" << endl;
					system("pause");
					break;
				}
			}

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