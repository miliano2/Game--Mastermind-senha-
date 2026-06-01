#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <ctime>
using namespace std;

int main() {
	time_t now = time(nullptr);
	system("chcp 65001 > nul");
	setlocale(LC_ALL, "pt_BR.UTF-8");

	int escolha = 0,  dificuldade  = 2;

	// Letras ainda tão quebrando o codigo todo
	while (escolha != 6) { // serve pra que todas as escolhas voltem pro menu

		system("clear");// pra deixar o jogo mais clean
		system("color 07");
		cout << "======================================" << endl;
		cout << "         MASTERMIND SENHA            " << endl;
		cout << "======================================" << endl;
		cout << "escolha uma opção :" << endl;
		cout << "1 - Jogar (modo single)" << endl;
		cout << "2 - Jogar (modo duplo)" << endl;
		cout << "3 - Dificuldade" << endl;
		cout << "4 - Sobre" << endl;
		cout << "5 - Automático" << endl;
		cout << "6 - FIM" << endl;
		cin >> escolha;

		if(cin.fail()) { // resetar a variavel se o rese escrever algo
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Digite apenas numeros! ( de 1 a 6 ).\n";
			continue;
		}

		switch (escolha)
		{
		case 1: { // Tem Que começar a arrumar a parte do jogo
			system("clear");
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
					    res3 < 1 || res3 > 6 ||
					    res1 == res2 ||
					    res1 == res3 ||
					    res2 == res3
					) {

						cout << "Numeros invalidos!" << endl;
						if (
						    res1 == res2 ||
						    res1 == res3 ||
						    res2 == res3) {
							cout<<"OS números não podem se repetir!"<< endl;
						}
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
						;
						break;
					}


				}
				if (tentativas == 8 and resposta ==  false) {
					system("color 0C");
					cout << "Você não conseguiu adivinhar. Que pena!" << endl;
					cout << "A senha era: " << num1 << num2 << num3 << endl;
					;
					break;
				}
			}
			else if (dificuldade == 2) {

				int num1, num2, num3, num4;
				int res1, res2, res3, res4;
				int tentativas = 1;

				bool resposta = false;

				do {

					num1 = rand()%8 + 1;
					num2 = rand()%8 + 1;
					num3 = rand()%8 + 1;
					num4 = rand()%8 + 1;

				} while (
				    num1 == num2 ||
				    num1 == num3 ||
				    num1 == num4 ||
				    num2 == num3 ||
				    num2 == num4 ||
				    num3 == num4
				);

				while (tentativas <= 10 && resposta == false) {


					cout << "========= DIFICULDADE MEDIA =========" << endl;
					cout << "Tentativa " << tentativas << " de 10" << endl;
					cout << "Seu último chute foi: " << res1 << res2 << res3 << res4 << endl;
					cout << "Digite 4 numeros de 1 a 8" << endl;

					cin >> res1 >> res2 >> res3 >> res4;

					if(cin.fail()) {

						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Digite apenas numeros!" << endl;

						;
						continue;
					}

					if (
					    res1 < 1 || res1 > 8 ||
					    res2 < 1 || res2 > 8 ||
					    res3 < 1 || res3 > 8 ||
					    res4 < 1 || res4 > 8
					) {

						cout << "Digite apenas numeros entre 1 e 8!" << endl;

						;
						continue;
					}
					if (res1 == num1) {

						cout << "\033[32m";
						cout << "[✓] Primeiro numero correto" << endl;
						cout << "\033[0m";
					} else if (
					    res1 == num2 ||
					    res1 == num3 ||
					    res1 == num4
					) {
						cout << "\033[33m";
						cout << "[~] Primeiro numero em posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Primeiro numero incorreto" << endl;
						cout << "\033[0m";
					}
					if (res2 == num2) {
						cout << "\033[32m";
						cout << "[✓] Segundo numero correto" << endl;
						cout << "\033[0m";
					} else if (
					    res2 == num1 ||
					    res2 == num3 ||
					    res2 == num4
					) {
						cout << "\033[33m";
						cout << "[~] Segundo numero em posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Segundo numero incorreto" << endl;
						cout << "\033[0m";
					}
					if (res3 == num3) {
						cout << "\033[32m";
						cout << "[✓] Terceiro numero correto" << endl;
						cout << "\033[0m";
					} else if (
					    res3 == num1 ||
					    res3 == num2 ||
					    res3 == num4
					) {
						cout << "\033[33m";
						cout << "[~] Terceiro numero em posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Terceiro numero incorreto" << endl;
						cout << "\033[0m";
					}
					if (res4 == num4) {
						cout << "\033[32m";
						cout << "[✓] Quarto numero correto" << endl;
						cout << "\033[0m";
					} else if (
					    res4 == num1 ||
					    res4 == num2 ||
					    res4 == num3
					) {
						cout << "\033[33m";
						cout << "[~] Quarto numero em posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Quarto numero incorreto" << endl;
						cout << "\033[0m";
					}
					if (
					    res1 == num1 &&
					    res2 == num2 &&
					    res3 == num3 &&
					    res4 == num4
					) {
						cout << "\nParabens! Voce venceu!" << endl;

						resposta = true;

						;

						break;
					}

					tentativas++;

					;
				}

				if (resposta == false) {

					cout << "Você não conseguiu adivinhar. Que pena!" << endl;
					cout << "A senha era: " << num1 << num2 << num3 << num4 << endl;
					;
				}
			}

			else if (dificuldade == 3) {
				int num1, num2, num3,num4, num5, tentativas = 1, res1 = 0, res2 = 0, res3= 0, res4 = 0, res5 = 0;
				bool resposta = false;
				srand(time(0));

				do {
					num1  = rand()%10 + 1;
					num2  = rand()%10 + 1;
					num3  = rand()%10 + 1;
					num4  = rand()%10 + 1;
					num5  = rand()%10 + 1;
				} while (num1 == num2 or num1 == num3 or num1 == num4 or num1 == num5 or num2 == num3 or num2 == num4 or num2 == num5 or num3 == num4 or num3 == num5 or num4 == num5);
				//cout << num1 << num2 << num3<<num4<<num5;
				while (tentativas <= 12 && resposta == false) {
					cout << "============DIFICULDADE MÁXIMA===================" << endl;
					cout << "Tentativa " << tentativas << " de 12" << endl;
					cout << "Seu último chute foi: " << res1 << res2 << res3 << res4 << res5 << endl;
					cout << "Digite 5 numeros de 1 a 10 (Aperte enter após cada um deles): " << endl;
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
					cout << "Quarto numero:  " << endl;
					cin  >> res4;
					if(cin.fail()) {

						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Digite apenas numeros!\n";

						continue;
					}
					cout << "Quinto numero:  " << endl;
					cin  >> res5;
					if(cin.fail()) {

						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Digite apenas numeros!\n";

						continue;
					}

					while (
					    res1 < 1 || res1 > 6 ||
					    res2 < 1 || res2 > 6 ||
					    res3 < 1 || res3 > 6 ||
					    res4 < 1 || res4 > 6 ||
					    res5 < 1 || res5 > 6 ||
					    res1 == res2 || res1 == res3 ||
					    res1 == res4 || res1 == res5 ||
					    res2 == res3 || res2 == res4 ||
					    res2 == res5 || res3 == res4 ||
					    res3 == res5 || res4 == res5
					) {

						cout << "Numeros invalidos!" << endl;
						if (res1 == res2 || res1 == res3 ||
						        res1 == res4 || res1 == res5 ||
						        res2 == res3 || res2 == res4 ||
						        res2 == res5 || res3 == res4 ||
						        res3 == res5 || res4 == res5) {
							cout<<"Os números não podem se repetir!"<<endl;
						}
						cout << "Digite 5 numeros de 1 a 6: " << endl;
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
						cout << "Quarto numero:  " << endl;
						cin  >> res4;
						if(cin.fail()) {

							cin.clear();
							cin.ignore(1000, '\n');

							cout << "Digite apenas numeros!\n";

							continue;
						}
						cout << "Quinto numero:  " << endl;
						cin  >> res5;
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
					} else if (res1 == num2 || res1 == num3 || res1 == num4 || res1 == num5) {
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
					} else if (res2 == num1 || res2 == num3 || res2 == num4 || res2 == num5) {
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
					} else if (res3 == num1 || res3 == num2 || res3 == num4 || res3 == num5) {
						cout << "\033[33m";
						cout << "[~] Terceiro numero existe mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Terceiro numero incorreto" << endl;
						cout << "\033[0m";
					}

					if (res4 == num4) {
						cout << "\033[32m";
						cout << "[✓] Quarto numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res4 == num1 || res4 == num2 || res4 == num3 || res4 == num5) {
						cout << "\033[33m";
						cout << "[~] Quarto numero correto mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Quarto numero incorreto" << endl;
						cout << "\033[0m";
					}

					if (res5 == num5) {
						cout << "\033[32m";
						cout << "[✓] Quinto numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res5 == num1 || res5 == num2 || res5 == num3 || res5 == num4) {
						cout << "\033[33m";
						cout << "[~] Quinto numero correto mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Quinto numero incorreto" << endl;
						cout << "\033[0m";
					}

					tentativas++;

					if (res1 == num1 && res2 == num2 && res3 == num3 && res4 == num4 && res5 == num5) {
						system("color 0A");
						cout << "Parabéns você conseguiu!!" << endl;
						resposta =  true;
						;
						break;
					}


				}
				if (tentativas == 12 and resposta ==  false) {
					system("color 0C");
					cout << "Você não conseguiu adivinhar. Que pena!" << endl;
					cout << "A senha era: " << num1 << num2 << num3 << num4 << num5 << endl;
					;
					break;
				}
			}
		}
		break;

		case 2: {
			system("clear");

			int num1, num2, num3;
			int num4, num5, num6;

			int res1 = 0, res2 = 0, res3 = 0;

			int tentativas = 1;

			bool chave1Resolvida = false;
			bool chave2Resolvida = false;

			srand(time(0));

			// CHAVE 1
			do {

				num1 = rand()%6 + 1;
				num2 = rand()%6 + 1;
				num3 = rand()%6 + 1;

			} while (
			    num1 == num2 ||
			    num1 == num3 ||
			    num2 == num3
			);

			// CHAVE 2
			do {

				num4 = rand()%6 + 1;
				num5 = rand()%6 + 1;
				num6 = rand()%6 + 1;

			} while (
			    num4 == num5 ||
			    num4 == num6 ||
			    num5 == num6
			);

			// cout << num1 << num2 << num3 << endl;
			// cout << num4 << num5 << num6 << endl;

			while (
			    tentativas <= 15 &&
			    !(chave1Resolvida && chave2Resolvida)
			)
			{
				system("clear");
				cout << "=========== MODO DUETO ===========" << endl;
				cout << " Sua ultima tentativa foi :"<< res1  <<  res2  << res3 << endl;
				cout << "Tentativa " << tentativas << " de 15" << endl;
				cout << endl;
				if(chave1Resolvida)
					cout << "[CHAVE 1] RESOLVIDA" << endl;
				else
					cout << "[CHAVE 1] PENDENTE" << endl;

				if(chave2Resolvida)
					cout << "[CHAVE 2] RESOLVIDA" << endl;
				else
					cout << "[CHAVE 2] PENDENTE" << endl;
				cout << endl;
				cout << "Digite 3 numeros de 1 a 6" << endl;

				cin >> res1;
				cin >> res2;
				cin >> res3;

				if(cin.fail()) {

					cin.clear();
					cin.ignore(1000, '\n');

					cout << "Digite apenas numeros!" << endl;

					;
					continue;
				}

				while(
				    res1 < 1 || res1 > 6 ||
				    res2 < 1 || res2 > 6 ||
				    res3 < 1 || res3 > 6 ||
				    res1 == res2 ||
				    res1 == res3 ||
				    res2 == res3
				)
				{

					cout << "Entrada invalida!" << endl;

					cin >> res1;
					cin >> res2;
					cin >> res3;

					if(cin.fail()) {

						cin.clear();
						cin.ignore(1000, '\n');

						cout << "Digite apenas numeros!" << endl;

						;
						continue;
					}
				}

				// ========= CHAVE 1 =========

				if(!chave1Resolvida) {

					cout << endl;
					cout << "===== CHAVE 1 =====" << endl;

					if (res1 == num1)
						cout << "[✓] Primeiro correto" << endl;
					else if (res1 == num2 || res1 == num3)
						cout << "[~] Primeiro existe mas esta em outra posicao" << endl;
					else
						cout << "[X] Primeiro incorreto" << endl;

					if (res2 == num2)
						cout << "[✓] Segundo correto" << endl;
					else if (res2 == num1 || res2 == num3)
						cout << "[~] Segundo existe mas esta em outra posicao" << endl;
					else
						cout << "[X] Segundo incorreto" << endl;

					if (res3 == num3)
						cout << "[✓] Terceiro correto" << endl;
					else if (res3 == num1 || res3 == num2)
						cout << "[~] Terceiro existe mas esta em outra posicao" << endl;
					else
						cout << "[X] Terceiro incorreto" << endl;

					if(
					    res1 == num1 &&
					    res2 == num2 &&
					    res3 == num3
					) {

						chave1Resolvida = true;

						cout << endl;
						cout << "CHAVE 1 DESBLOQUEADA!" << endl;
					}
				}

				// ========= CHAVE 2 =========

				if(!chave2Resolvida) {

					cout << endl;
					cout << "===== CHAVE 2 =====" << endl;

					if (res1 == num4)
						cout << "[✓] Primeiro correto" << endl;
					else if (res1 == num5 || res1 == num6)
						cout << "[~] Primeiro existe mas esta em outra posicao" << endl;
					else
						cout << "[X] Primeiro incorreto" << endl;

					if (res2 == num5)
						cout << "[✓] Segundo correto" << endl;
					else if (res2 == num4 || res2 == num6)
						cout << "[~] Segundo existe mas esta em outra posicao" << endl;
					else
						cout << "[X] Segundo incorreto" << endl;

					if (res3 == num6)
						cout << "[✓] Terceiro correto" << endl;
					else if (res3 == num4 || res3 == num5)
						cout << "[~] Terceiro existe mas esta em outra posicao" << endl;
					else
						cout << "[X] Terceiro incorreto" << endl;

					if(
					    res1 == num4 &&
					    res2 == num5 &&
					    res3 == num6
					) {

						chave2Resolvida = true;

						cout << endl;
						cout << "CHAVE 2 DESBLOQUEADA!" << endl;
					}
				}

				if(
				    chave1Resolvida &&
				    chave2Resolvida
				) {

					system("color 0A");

					cout << endl;
					cout << "PARABENS!" << endl;
					cout << "VOCE DESBLOQUEOU AS DUAS CHAVES!" << endl;

					

					break;
				}

				tentativas++;

				
			}

			if(
			    (chave1Resolvida != true && chave2Resolvida != true)
			) {

				system("color 0C");

				cout << endl;
				cout << "VOCE PERDEU!" << endl;

				
			}

			break;
		}

		case 3:// O codigo também ta motrando qual a dificuldade atual do jogador
			system("clear");
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
				else if (dificuldade == 2) {

					int num1, num2, num3, num4;
					int res1, res2, res3, res4;
					int tentativas = 1;

					bool resposta = false;

					do {

						num1 = rand()%8 + 1;
						num2 = rand()%8 + 1;
						num3 = rand()%8 + 1;
						num4 = rand()%8 + 1;

					} while (
					    num1 == num2 ||
					    num1 == num3 ||
					    num1 == num4 ||
					    num2 == num3 ||
					    num2 == num4 ||
					    num3 == num4
					);

					while (tentativas <= 10 && resposta == false) {

						system("clear");

						cout << "========= DIFICULDADE MEDIA =========" << endl;
						cout << "Tentativa " << tentativas << " de 10" << endl;

						cout << "Digite 4 numeros de 1 a 8" << endl;

						cin >> res1 >> res2 >> res3 >> res4;

						if(cin.fail()) {

							cin.clear();
							cin.ignore(1000, '\n');

							cout << "Digite apenas numeros!" << endl;

							
							continue;
						}

						if (
						    res1 < 1 || res1 > 8 ||
						    res2 < 1 || res2 > 8 ||
						    res3 < 1 || res3 > 8 ||
						    res4 < 1 || res4 > 8
						) {

							cout << "Digite apenas numeros entre 1 e 8!" << endl;

							
							continue;
						}
						if (res1 == num1) {

							cout << "\033[32m";
							cout << "[✓] Primeiro numero correto" << endl;
							cout << "\033[0m";
						} else if (
						    res1 == num2 ||
						    res1 == num3 ||
						    res1 == num4
						) {
							cout << "\033[33m";
							cout << "[~] Primeiro numero em posicao errada" << endl;
							cout << "\033[0m";
						} else {
							cout << "\033[31m";
							cout << "[X] Primeiro numero incorreto" << endl;
							cout << "\033[0m";
						}
						if (res2 == num2) {
							cout << "\033[32m";
							cout << "[✓] Segundo numero correto" << endl;
							cout << "\033[0m";
						} else if (
						    res2 == num1 ||
						    res2 == num3 ||
						    res2 == num4
						) {
							cout << "\033[33m";
							cout << "[~] Segundo numero em posicao errada" << endl;
							cout << "\033[0m";
						} else {
							cout << "\033[31m";
							cout << "[X] Segundo numero incorreto" << endl;
							cout << "\033[0m";
						}
						if (res3 == num3) {
							cout << "\033[32m";
							cout << "[✓] Terceiro numero correto" << endl;
							cout << "\033[0m";
						} else if (
						    res3 == num1 ||
						    res3 == num2 ||
						    res3 == num4
						) {
							cout << "\033[33m";
							cout << "[~] Terceiro numero em posicao errada" << endl;
							cout << "\033[0m";
						} else {
							cout << "\033[31m";
							cout << "[X] Terceiro numero incorreto" << endl;
							cout << "\033[0m";
						}
						if (res4 == num4) {
							cout << "\033[32m";
							cout << "[✓] Quarto numero correto" << endl;
							cout << "\033[0m";
						} else if (
						    res4 == num1 ||
						    res4 == num2 ||
						    res4 == num3
						) {
							cout << "\033[33m";
							cout << "[~] Quarto numero em posicao errada" << endl;
							cout << "\033[0m";
						} else {
							cout << "\033[31m";
							cout << "[X] Quarto numero incorreto" << endl;
							cout << "\033[0m";
						}
						if (
						    res1 == num1 &&
						    res2 == num2 &&
						    res3 == num3 &&
						    res4 == num4
						) {
							cout << "\nParabens! Voce venceu!" << endl;

							resposta = true;

							

							break;
						}

						tentativas++;

						
					}

					if (resposta == false) {

						cout << "\nVoce perdeu!" << endl;

						
					}
				}
			}

			break;

		case 4: // Coloquem o nome completo de voces aqui
			system("clear");
			cout << "==============SOBRE================" << endl;
			cout << "Equipe de Desenvolvimento==========" << endl;
			cout << "- João Gabriel M. T. dos Santos" << endl;
			cout << "- Thiago Schmitt dos Passos" << endl;
			cout << "- Juliano de Souza Castro Vieira" << endl;
			cout << "- Yasmin Inturn" << endl;
			cout << "dia e data atuais :" << endl;

			//Tem que converter a data de ingles para protgues ele pega direto do sistema
			cout << "Data atual: " << ctime(&now);

			cout << "===Professor e Disciplina=========="<< endl;
			cout << "Professor: Alex Rese" << endl;
			cout << "Disciplina : Algoritmo e Programação" << endl;
			
			break;

		case 5: {
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
					cout << "O último chute gerado foi: " << res1 << res2 << res3 << endl;
					cout << "O computador vai digitar 3 números de 1 a 6: " << endl;
					cout << tentativas << " chute:  " << endl;
					do {
						if (res1 != num1) {
							res1 = rand()%6 + 1;
						}
						if (res2 != num2) {
							res2 = rand()%6 + 1;
						}
						if (res3 != num3) {
							res3 = rand()%6 + 1;
						}
					} while (res1 == res2 || res1 == res3 || res2 == res3 );
					cout << res1 << res2 << res3;

					cout << "\n=========== RESULTADO ===========" << endl;

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
						cout << "Parabéns computador!!" << endl;
						resposta =  true;
						
						break;
					}


				}
				if (tentativas == 8 and resposta ==  false) {
					system("color 0C");
					cout << "Você não conseguiu adivinhar. Que pena!" << endl;
					system("pause");
					break;
				}

				if (res1 == num2 || res1 == num3) {
					res2 = res1;
					res3 = res1;
				}
				if (res2 == num1 || res2 == num3) {
					res1 = res2;
					res3 = res2;
				}
				if (res3 == num1 || res3 == num2) {
					res1 = res3;
					res2 = res3;

				}
			}
			else if (dificuldade == 2){
                int num1, num2, num3, num4, tentativas = 1, res1 = 0, res2 = 0, res3 = 0, res4 = 0;
				int imp1, imp2, imp3, imp4; //Vai impedir que o computador chute o mesmo número de antes se estiver errado
				bool resposta = false;
				srand(time(0));

				do {
					num1  = rand()%8 + 1;
					num2  = rand()%8 + 1;
					num3  = rand()%8 + 1;
					num4  = rand()%8 + 1;
				} while (num1 == num2 or num1 == num3 or num1 == num4 or num2 == num3 or num2 == num4 or num3 == num4);
				//cout << num1 << num2 << num3;
				while (tentativas <= 10 && resposta == false) {
					cout <<"============ DIFICULDADE MÉDIA ===================" << endl;
					cout << "Tentativa " << tentativas << " de 10" << endl;
					cout << "O último chute gerado foi: " << res1 << res2 << res3 << res4 << endl;
					cout << "O computador vai digitar 3 números de 1 a 8: " << endl;
					cout << tentativas << " chute:  " << endl;
                    do {
                        if (res1 != num1 || res1 == imp1){
                            res1 = rand()%8 + 1;
                        }
		    			if (res2 != num2 || res2 == imp2){
                            res2 = rand()%8 + 1;
                        }
		    			if (res3 != num3 || res3 == imp3){
                            res3 = rand()%8 + 1;
                        }
						if (res4 != num4 || res4 == imp4){
							res4 = rand()%8 + 1;
						}
                    } while (res1 == res2 || res1 == res3 || res1 == res4 || res2 == res3 || res2 == res4 || res3 == res4);
                    cout << res1 << res2 << res3 << res4;
					
                    cout << "\n=========== RESULTADO ===========" << endl;

					if (res1 == num1) {
						cout << "\033[32m";
						cout << "[✓] Primeiro numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res1 == num2 || res1 == num3 || res1 == num4) {
						cout << "\033[33m";
						cout << "[~] Primeiro numero correto mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Primeiro numero incorreto" << endl;
						cout << "\033[0m";
						imp1 = res1;
					}

					if (res2 == num2) {
						cout << "\033[32m";
						cout << "[✓] Segundo numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res2 == num1 || res2 == num3 || res2 == num4) {
						cout << "\033[33m";
						cout << "[~] Segundo numero existe mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Segundo numero incorreto" << endl;
						cout << "\033[0m";
						imp2 = res2;
					}

					if (res3 == num3) {
						cout << "\033[32m";
						cout << "[✓] Terceiro numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res3 == num1 || res3 == num2 || res3 == num4) {
						cout << "\033[33m";
						cout << "[~] Terceiro numero existe mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Terceiro numero incorreto" << endl;
						cout << "\033[0m";
						imp3 = res3;
					}

					if (res4 == num4) {
						cout << "\033[32m";
						cout << "[✓] Quarto numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res4 == num1 || res4 == num2 || res4 == num3) {
						cout << "\033[33m";
						cout << "[~] Quarto numero existe mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Quarto numero incorreto" << endl;
						cout << "\033[0m";
						imp4 = res4;
					}

					tentativas++;

					if (res1 == num1 && res2 == num2 && res3 == num3 && res4 == num4) {
						system("color 0A");
						cout << "Parabéns computador!!" << endl;
						resposta =  true;
						
						break;
					}


				}
				if (tentativas == 10 and resposta ==  false) {
					system("color 0C");
					cout << "O computador não conseguiu adivinhar. Que pena!" << endl;
					
					break;
				}

                if (res1 == num2 || res1 == num3 || res1 == num4) {
					res2 = res1;
					res3 = res1;
					res4 = res1;
				}
				if (res2 == num1 || res2 == num3 || res2 == num4) {
					res1 = res2;
					res3 = res2;
					res4 = res2;
				}
				if (res3 == num1 || res3 == num2 || res3 == num4) {
				    res1 = res3;
				    res2 = res3;
					res4 = res3;
				    
				}
				if (res4 == num1 || res4 == num2 || res4 == num3) {
				    res3 = res4;
				    res3 = res4;
					res3 = res4;
				    
				}
			}	
			else if (dificuldade == 3) {
			int num1, num2, num3, num4, num5;
			int res1 = 0, res2 = 0, res3 = 0, res4 = 0, res5 = 0;
			int imp1 = 0, imp2 = 0, imp3 = 0, imp4 = 0, imp5 = 0;

			int tentativas = 1;
			bool resposta = false;

			srand(time(0));

			do {

				num1 = rand()%6 + 1;
				num2 = rand()%6 + 1;
				num3 = rand()%6 + 1;
				num4 = rand()%6 + 1;
				num5 = rand()%6 + 1;

			} while (
				num1 == num2 || num1 == num3 || num1 == num4 || num1 == num5 ||
				num2 == num3 || num2 == num4 || num2 == num5 ||
				num3 == num4 || num3 == num5 ||
				num4 == num5
			);

			// cout << num1 << num2 << num3 << num4 << num5;

			while (tentativas <= 12 && resposta == false)
			{
				cout << "============ DIFICULDADE DIFICIL ===================" << endl;
				cout << "Tentativa " << tentativas << " de 12" << endl;
				cout << "Ultimo chute: "  << res1 << res2 << res3 << res4 << res5 << endl;
				do {
							if (res1 != num1) res1 = rand()%6 + 1;
							if (res2 != num2) res2 = rand()%6 + 1;
							if (res3 != num3) res3 = rand()%6 + 1;
							if (res4 != num4) res4 = rand()%6 + 1;
							if (res5 != num5) res5 = rand()%6 + 1;

						} while (
							res1 == res2 || res1 == res3 || res1 == res4 || res1 == res5 ||
							res2 == res3 || res2 == res4 || res2 == res5 ||
							res3 == res4 || res3 == res5 ||
							res4 == res5
						);

				cout << "Chute gerado: "
					<< res1 << res2 << res3 << res4 << res5 << endl;

				cout << "\n=========== RESULTADO ===========" << endl;
				if (res1 == num1) {
					cout << "[✓] Primeiro correto" << endl;
				} else if (
					res1 == num2 ||
					res1 == num3 ||
					res1 == num4 ||
					res1 == num5
				) {
					cout << "[~] Primeiro existe em outra posicao" << endl;
				} else {
					cout << "[X] Primeiro incorreto" << endl;
					imp1 = res1;
				}
				if (res2 == num2) {
					cout << "[✓] Segundo correto" << endl;
				} else if (
					res2 == num1 ||
					res2 == num3 ||
					res2 == num4 ||
					res2 == num5
				) {
					cout << "[~] Segundo existe em outra posicao" << endl;
				} else {
					cout << "[X] Segundo incorreto" << endl;
					imp2 = res2;
				}
				if (res3 == num3) {
					cout << "[✓] Terceiro correto" << endl;
				} else if (
					res3 == num1 ||
					res3 == num2 ||
					res3 == num4 ||
					res3 == num5
				) {
					cout << "[~] Terceiro existe em outra posicao" << endl;
				} else {
					cout << "[X] Terceiro incorreto" << endl;
					imp3 = res3;
				}
				if (res4 == num4) {
					cout << "[✓] Quarto correto" << endl;
				} else if (
					res4 == num1 ||
					res4 == num2 ||
					res4 == num3 ||
					res4 == num5
				) {
					cout << "[~] Quarto existe em outra posicao" << endl;
				} else {
					cout << "[X] Quarto incorreto" << endl;
					imp4 = res4;
				}
				if (res5 == num5) {
					cout << "[✓] Quinto correto" << endl;
				} else if (
					res5 == num1 ||
					res5 == num2 ||
					res5 == num3 ||
					res5 == num4
				) {
					cout << "[~] Quinto existe em outra posicao" << endl;
				} else {
					cout << "[X] Quinto incorreto" << endl;
					imp5 = res5;
				}
				if (
					res1 == num1 &&
					res2 == num2 &&
					res3 == num3 &&
					res4 == num4 &&
					res5 == num5
				) {
					cout << "\nPARABENS COMPUTADOR!!" << endl;
					resposta = true;
					
					break;
				}
				tentativas++;
				
			}
			if (resposta == false)
			{
				system("color 0C");

				cout << "\nO computador nao conseguiu adivinhar." << endl;
				cout << "A senha era: "
					<< num1 << num2 << num3 << num4 << num5 << endl;

				
			}

			break;
		}
			else if (dificuldade == 2){
                int num1, num2, num3, num4, tentativas = 1, res1 = 0, res2 = 0, res3 = 0, res4 = 0;
				int imp1, imp2, imp3, imp4; //Vai impedir que o computador chute o mesmo número de antes se estiver errado
				bool resposta = false;
				srand(time(0));

				do {
					num1  = rand()%8 + 1;
					num2  = rand()%8 + 1;
					num3  = rand()%8 + 1;
					num4  = rand()%8 + 1;
				} while (num1 == num2 or num1 == num3 or num1 == num4 or num2 == num3 or num2 == num4 or num3 == num4);
				//cout << num1 << num2 << num3;
				while (tentativas <= 10 && resposta == false) {
					cout <<"============ DIFICULDADE MÉDIA ===================" << endl;
					cout << "Tentativa " << tentativas << " de 10" << endl;
					cout << "O último chute gerado foi: " << res1 << res2 << res3 << res4 << endl;
					cout << "O computador vai digitar 3 números de 1 a 8: " << endl;
					cout << tentativas << " chute:  " << endl;
                    do {
                        if (res1 != num1 || res1 == imp1){
                            res1 = rand()%8 + 1;
                        }
		    			if (res2 != num2 || res2 == imp2){
                            res2 = rand()%8 + 1;
                        }
		    			if (res3 != num3 || res3 == imp3){
                            res3 = rand()%8 + 1;
                        }
						if (res4 != num4 || res4 == imp4){
							res4 = rand()%8 + 1;
						}
                    } while (res1 == res2 || res1 == res3 || res1 == res4 || res2 == res3 || res2 == res4 || res3 == res4);
                    cout << res1 << res2 << res3 << res4;
					
                    cout << "\n=========== RESULTADO ===========" << endl;

					if (res1 == num1) {
						cout << "\033[32m";
						cout << "[✓] Primeiro numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res1 == num2 || res1 == num3 || res1 == num4) {
						cout << "\033[33m";
						cout << "[~] Primeiro numero correto mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Primeiro numero incorreto" << endl;
						cout << "\033[0m";
						imp1 = res1;
					}

					if (res2 == num2) {
						cout << "\033[32m";
						cout << "[✓] Segundo numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res2 == num1 || res2 == num3 || res2 == num4) {
						cout << "\033[33m";
						cout << "[~] Segundo numero existe mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Segundo numero incorreto" << endl;
						cout << "\033[0m";
						imp2 = res2;
					}

					if (res3 == num3) {
						cout << "\033[32m";
						cout << "[✓] Terceiro numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res3 == num1 || res3 == num2 || res3 == num4) {
						cout << "\033[33m";
						cout << "[~] Terceiro numero existe mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Terceiro numero incorreto" << endl;
						cout << "\033[0m";
						imp3 = res3;
					}

					if (res4 == num4) {
						cout << "\033[32m";
						cout << "[✓] Quarto numero correto na posicao correta" << endl;
						cout << "\033[0m";
					} else if (res4 == num1 || res4 == num2 || res4 == num3) {
						cout << "\033[33m";
						cout << "[~] Quarto numero existe mas esta na posicao errada" << endl;
						cout << "\033[0m";
					} else {
						cout << "\033[31m";
						cout << "[X] Quarto numero incorreto" << endl;
						cout << "\033[0m";
						imp4 = res4;
					}

					tentativas++;

					if (res1 == num1 && res2 == num2 && res3 == num3 && res4 == num4) {
						system("color 0A");
						cout << "Parabéns computador!!" << endl;
						resposta =  true;
						system("pause");
						break;
					}


				}
				if (tentativas == 10 and resposta ==  false) {
					system("color 0C");
					cout << "O computador não conseguiu adivinhar. Que pena!" << endl;
					system("pause");
					break;
				}

                if (res1 == num2 || res1 == num3 || res1 == num4) {
					res2 = res1;
					res3 = res1;
					res4 = res1;
				}
				if (res2 == num1 || res2 == num3 || res2 == num4) {
					res1 = res2;
					res3 = res2;
					res4 = res2;
				}
				if (res3 == num1 || res3 == num2 || res3 == num4) {
				    res1 = res3;
				    res2 = res3;
					res4 = res3;
				    
				}
				if (res4 == num1 || res4 == num2 || res4 == num3) {
				    res3 = res4;
				    res3 = res4;
					res3 = res4;
				    
				}
			}


		case 6: // Finaliza o código
			return 0;
		}
		default:
			cout << "Digite uma escolha válida" << endl;
			break;

		}
	}
	return 0;

}