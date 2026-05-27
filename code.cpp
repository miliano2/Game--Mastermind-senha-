#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <ctime>
using namespace std;

int main() {
	time_t now = time(nullptr);

	setlocale(LC_ALL, "Portuguese");
	setlocale(LC_TIME, "pt_BR.UTF-8");

	int escolha = 0,  dificuldade  = 2;

	// Letras ainda tão quebrando o codigo todo
	while (escolha != 5) { // serve pra que todas as escolhas voltem pro menu

		system("cls");// pra deixar o jogo mais clean
		system("color 07");
		cout << "===================SENHA==================="  << endl;
		cout << "escolha uma opção :" << endl;
		cout << "1 - Jogar" << endl;
		cout << "2 - Dificuldade" << endl;
		cout << "3 - Sobre" << endl;
		cout << "4 - Automático" << endl;
		cout << "5 - FIM" << endl;
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
					    res3 < 1 || res3 > 6 ||
						res1 == res2 || 
						res1 == res3 ||
						res2 == res3
					) {

						cout << "Numeros invalidos!" << endl;
						if (
						res1 == res2 || 
						res1 == res3 ||
						res2 == res3){
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

						system("cls");

						cout << "========= DIFICULDADE MEDIA =========" << endl;
						cout << "Tentativa " << tentativas << " de 10" << endl;

						cout << "Digite 4 numeros de 1 a 8" << endl;

						cin >> res1 >> res2 >> res3 >> res4;

						if(cin.fail()) {

							cin.clear();
							cin.ignore(1000, '\n');

							cout << "Digite apenas numeros!" << endl;

							system("pause");
							continue;
						}

						if (
						    res1 < 1 || res1 > 8 ||
						    res2 < 1 || res2 > 8 ||
						    res3 < 1 || res3 > 8 ||
						    res4 < 1 || res4 > 8
						) {

							cout << "Digite apenas numeros entre 1 e 8!" << endl;

							system("pause");
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

							system("pause");

							break;
						}

						tentativas++;

						system("pause");
					}

					if (resposta == false) {

						cout << "\nVoce perdeu!" << endl;

						system("pause");
					}
				}
			
			else if (dificuldade == 3) {
				int num1, num2, num3,num4, num5, tentativas = 12, res1 = 0, res2 = 0, res3= 0, res4 = 0, res5 = 0;
				int certos = 0;
				int errados = 0;
				bool resposta = false;
				srand(time(0));

				do {
					num1  = rand()%6 + 1;
					num2  = rand()%6 + 1;
					num3  = rand()%6 + 1;
                    num4  = rand()%6 + 1;
					num5  = rand()%6 + 1;
				} while (num1 == num2 or num1 == num3 or num1 == num4 or num1 == num5 or num2 == num3 or num2 == num4 or num2 == num5 or num3 == num4 or num3 == num5 or num4 == num5);
				//cout << num1 << num2 << num3<<num4<<num5;
				while (tentativas > 0 && resposta == false) {
					cout <<"============TENTATIVAS RESTANTES: "<< tentativas << " ===================" << endl;
                    cout << "Seu último chute foi: " << res1 << res2 << res3 << res4 << res5 << endl;
					cout << "Digite 5 numeros de 1 a 6 (Aperte enter após cada um deles): " << endl;
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
                        res3 == res5 || res4 == res5){
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
					
					tentativas--;
					
					if (res1 == num1 && res2 == num2 && res3 == num3 && res4 == num4 && res5 == num5) {
                        system("color 0A");
						cout << "Parabéns você conseguiu!!" << endl;
						resposta =  true;
						system("pause");
						break;
					}


				}
				if (tentativas == 0 and resposta ==  false) {
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

						system("cls");

						cout << "========= DIFICULDADE MEDIA =========" << endl;
						cout << "Tentativa " << tentativas << " de 10" << endl;

						cout << "Digite 4 numeros de 1 a 8" << endl;

						cin >> res1 >> res2 >> res3 >> res4;

						if(cin.fail()) {

							cin.clear();
							cin.ignore(1000, '\n');

							cout << "Digite apenas numeros!" << endl;

							system("pause");
							continue;
						}

						if (
						    res1 < 1 || res1 > 8 ||
						    res2 < 1 || res2 > 8 ||
						    res3 < 1 || res3 > 8 ||
						    res4 < 1 || res4 > 8
						) {

							cout << "Digite apenas numeros entre 1 e 8!" << endl;

							system("pause");
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

							system("pause");

							break;
						}

						tentativas++;

						system("pause");
					}

					if (resposta == false) {

						cout << "\nVoce perdeu!" << endl;

						system("pause");
					}
				}
			}

			break;

		case 3: // Coloquem o nome completo de voces aqui
			system("cls");
			cout << "==============SOBRE================" << endl;
			cout << "Equipe de Desenvolvimento==========" << endl;
			cout << "- João Gabriel M. T. dos Santos" << endl;
			cout << "- Thiago Schmitt dos Passos" << endl;
			cout << "- Juliano" << endl;
			cout << "- Yasmin Inturn" << endl;
			cout << "dia e data atuais :" << endl;

			//Tem que converter a data de ingles para protgues ele pega direto do sistema
			cout << "Data atual: " << ctime(&now);

			cout << "===Professor e Disciplina=========="<< endl;
			cout << "Professor: Alex Rese" << endl;
			cout << "Disciplina : Algoritmo e Programação" << endl;
			system("pause");
			break;

		case 4:	
			if (dificuldade == 1){
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
                        if (res1 != num1){
                            res1 = rand()%6 + 1;
                        }
		    			if (res2 != num2){
                            res2 = rand()%6 + 1;
                        }
		    			if (res3 != num3){
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
						system("pause");
						break;
					}


				}
				if (tentativas == 8 and resposta ==  false) {
					system("color 0C");
					cout << "O computador não conseguiu adivinhar. Que pena!" << endl;
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


		case 5: // Finaliza o código
			return 0;

		default:
			cout << "Digite uma escolha válida" << endl;
			break;

		}
	}
	return 0;

}