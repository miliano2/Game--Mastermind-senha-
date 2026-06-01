#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <ctime>
using namespace std;

int main() {
	time_t now = time(nullptr);
	setlocale(LC_ALL, "Portuguese");

	int escolha = 0, dificuldade = 2;

	while (escolha != 6) {

		cout << "======================================" << endl;
		cout << "         MASTERMIND SENHA            " << endl;
		cout << "======================================" << endl;
		cout << "escolha uma opção :" << endl;
		cout << "1 - Jogar (modo single)" << endl;
		cout << "2 - Jogar (modo duplo)" << endl;
		cout << "3 - Dificuldade" << endl;
		cout << "4 - Sobre" << endl;
		cout << "5 - Automatico" << endl;
		cout << "6 - FIM" << endl;
		cin >> escolha;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Digite apenas numeros! ( de 1 a 6 ).\n";
			continue;
		}

		switch (escolha)
		{
		case 1: {
			system("clear"); // Limpa ao entrar no jogo
			if (dificuldade == 1) {
				int num1, num2, num3, tentativas = 1, res1 = 0, res2 = 0, res3 = 0;
				bool resposta = false;
				srand(time(0));

				do {
					num1 = rand()%6 + 1;
					num2 = rand()%6 + 1;
					num3 = rand()%6 + 1;
				} while (num1==num2 || num1==num3 || num2==num3);

				while (tentativas <= 8 && resposta == false) {
					cout << "============ DIFICULDADE FACIL ===================" << endl;
					cout << "Tentativa " << tentativas << " de 8" << endl;
					cout << "Seu ultimo chute foi: " << res1 << " " << res2 << " " << res3 << endl;
					cout << "--------------------------------------------------" << endl;
					cout << "Digite 3 numeros de 1 a 6:" << endl;
					cout << "Primeiro numero: ";
					cin >> res1;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}
					cout << "Segundo numero:  ";
					cin >> res2;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}
					cout << "Terceiro numero: ";
					cin >> res3;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}

					while (res1<1||res1>6||res2<1||res2>6||res3<1||res3>6||res1==res2||res1==res3||res2==res3) {
						cout << "Numeros invalidos! Nao podem se repetir e devem ser de 1 a 6." << endl;
						cout << "Primeiro numero: ";
						cin >> res1;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
						cout << "Segundo numero:  ";
						cin >> res2;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
						cout << "Terceiro numero: ";
						cin >> res3;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
					}

					cout << "\n=========== RESULTADO ===========" << endl;
					if (res1==num1)                    {
						cout<<"\033[32m[✓] Primeiro correto na posicao correta\033[0m"<<endl;
					}
					else if (res1==num2||res1==num3)   {
						cout<<"\033[33m[~] Primeiro correto mas posicao errada\033[0m"<<endl;
					}
					else                               {
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
					}

					if (res2==num2)                    {
						cout<<"\033[32m[✓] Segundo correto na posicao correta\033[0m"<<endl;
					}
					else if (res2==num1||res2==num3)   {
						cout<<"\033[33m[~] Segundo correto mas posicao errada\033[0m"<<endl;
					}
					else                               {
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
					}

					if (res3==num3)                    {
						cout<<"\033[32m[✓] Terceiro correto na posicao correta\033[0m"<<endl;
					}
					else if (res3==num1||res3==num2)   {
						cout<<"\033[33m[~] Terceiro correto mas posicao errada\033[0m"<<endl;
					}
					else                               {
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
					}

					tentativas++;

					if (res1==num1 && res2==num2 && res3==num3) {
						cout << "\nParabens voce conseguiu!!" << endl;
						resposta = true;
						break;
					}
				}
				if (tentativas > 8 && resposta == false) {
					cout << "\nVoce nao conseguiu adivinhar. Que pena!" << endl;
					cout << "A senha era: " << num1 << num2 << num3 << endl;
				}
			}
			else if (dificuldade == 2) {
				int num1, num2, num3, num4;
				int res1=0, res2=0, res3=0, res4=0;
				int tentativas = 1;
				bool resposta = false;

				do {
					num1=rand()%8+1;
					num2=rand()%8+1;
					num3=rand()%8+1;
					num4=rand()%8+1;
				} while (num1==num2||num1==num3||num1==num4||num2==num3||num2==num4||num3==num4);

				while (tentativas <= 10 && resposta == false) {
					cout << "========= DIFICULDADE MEDIA =========" << endl;
					cout << "Tentativa " << tentativas << " de 10" << endl;
					cout << "Seu ultimo chute foi: " << res1 << " " << res2 << " " << res3 << " " << res4 << endl;
					cout << "-------------------------------------" << endl;
					cout << "Digite 4 numeros de 1 a 8: ";
					cin >> res1 >> res2 >> res3 >> res4;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!"<<endl;
						continue;
					}
					if (res1<1||res1>8||res2<1||res2>8||res3<1||res3>8||res4<1||res4>8) {
						cout << "Digite apenas numeros entre 1 e 8!" << endl;
						continue;
					}

					cout << "\n=========== RESULTADO ===========" << endl;
					if (res1==num1)                              {
						cout<<"\033[32m[✓] Primeiro correto\033[0m"<<endl;
					}
					else if (res1==num2||res1==num3||res1==num4) {
						cout<<"\033[33m[~] Primeiro em posicao errada\033[0m"<<endl;
					}
					else                                         {
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
					}

					if (res2==num2)                              {
						cout<<"\033[32m[✓] Segundo correto\033[0m"<<endl;
					}
					else if (res2==num1||res2==num3||res2==num4) {
						cout<<"\033[33m[~] Segundo em posicao errada\033[0m"<<endl;
					}
					else                                         {
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
					}

					if (res3==num3)                              {
						cout<<"\033[32m[✓] Terceiro correto\033[0m"<<endl;
					}
					else if (res3==num1||res3==num2||res3==num4) {
						cout<<"\033[33m[~] Terceiro em posicao errada\033[0m"<<endl;
					}
					else                                         {
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
					}

					if (res4==num4)                              {
						cout<<"\033[32m[✓] Quarto correto\033[0m"<<endl;
					}
					else if (res4==num1||res4==num2||res4==num3) {
						cout<<"\033[33m[~] Quarto em posicao errada\033[0m"<<endl;
					}
					else                                         {
						cout<<"\033[31m[X] Quarto incorreto\033[0m"<<endl;
					}

					if (res1==num1&&res2==num2&&res3==num3&&res4==num4) {
						cout << "\nParabens! Voce venceu!" << endl;
						resposta = true;
						break;
					}
					tentativas++;
				}
				if (resposta == false) {
					cout << "\nVoce nao conseguiu adivinhar. Que pena!" << endl;
					cout << "A senha era: " << num1 << num2 << num3 << num4 << endl;
				}
			}
			else if (dificuldade == 3) {
				int num1,num2,num3,num4,num5;
				int res1=0,res2=0,res3=0,res4=0,res5=0;
				int tentativas = 12;
				bool resposta = false;
				srand(time(0));

				do {
					num1=rand()%6+1;
					num2=rand()%6+1;
					num3=rand()%6+1;
					num4=rand()%6+1;
					num5=rand()%6+1;
				} while (num1==num2||num1==num3||num1==num4||num1==num5||num2==num3||num2==num4||num2==num5||num3==num4||num3==num5||num4==num5);

				while (tentativas > 0 && resposta == false) {
					cout << "============ DIFICULDADE DIFICIL ===================" << endl;
					cout << "Tentativas restantes: " << tentativas << endl;
					cout << "Seu ultimo chute foi: " << res1<<" "<<res2<<" "<<res3<<" "<<res4<<" "<<res5 << endl;
					cout << "---------------------------------------------------" << endl;
					cout << "Digite 5 numeros de 1 a 6:" << endl;
					cout << "Primeiro numero: ";
					cin >> res1;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}
					cout << "Segundo numero:  ";
					cin >> res2;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}
					cout << "Terceiro numero: ";
					cin >> res3;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}
					cout << "Quarto numero:   ";
					cin >> res4;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}
					cout << "Quinto numero:   ";
					cin >> res5;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Digite apenas numeros!\n";
						continue;
					}

					while (res1<1||res1>6||res2<1||res2>6||res3<1||res3>6||res4<1||res4>6||res5<1||res5>6||
					        res1==res2||res1==res3||res1==res4||res1==res5||res2==res3||res2==res4||
					        res2==res5||res3==res4||res3==res5||res4==res5) {
						cout << "Numeros invalidos! Nao podem se repetir e devem ser de 1 a 6." << endl;
						cout << "Primeiro numero: ";
						cin >> res1;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
						cout << "Segundo numero:  ";
						cin >> res2;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
						cout << "Terceiro numero: ";
						cin >> res3;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
						cout << "Quarto numero:   ";
						cin >> res4;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
						cout << "Quinto numero:   ";
						cin >> res5;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000,'\n');
							continue;
						}
					}

					cout << "\n=========== RESULTADO ===========" << endl;
					if (res1==num1)                                         {
						cout<<"\033[32m[✓] Primeiro correto na posicao correta\033[0m"<<endl;
					}
					else if (res1==num2||res1==num3||res1==num4||res1==num5) {
						cout<<"\033[33m[~] Primeiro correto mas posicao errada\033[0m"<<endl;
					}
					else                                                     {
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
					}

					if (res2==num2)                                         {
						cout<<"\033[32m[✓] Segundo correto na posicao correta\033[0m"<<endl;
					}
					else if (res2==num1||res2==num3||res2==num4||res2==num5) {
						cout<<"\033[33m[~] Segundo correto mas posicao errada\033[0m"<<endl;
					}
					else                                                     {
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
					}

					if (res3==num3)                                         {
						cout<<"\033[32m[✓] Terceiro correto na posicao correta\033[0m"<<endl;
					}
					else if (res3==num1||res3==num2||res3==num4||res3==num5) {
						cout<<"\033[33m[~] Terceiro correto mas posicao errada\033[0m"<<endl;
					}
					else                                                     {
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
					}

					if (res4==num4)                                         {
						cout<<"\033[32m[✓] Quarto correto na posicao correta\033[0m"<<endl;
					}
					else if (res4==num1||res4==num2||res4==num3||res4==num5) {
						cout<<"\033[33m[~] Quarto correto mas posicao errada\033[0m"<<endl;
					}
					else                                                     {
						cout<<"\033[31m[X] Quarto incorreto\033[0m"<<endl;
					}

					if (res5==num5)                                         {
						cout<<"\033[32m[✓] Quinto correto na posicao correta\033[0m"<<endl;
					}
					else if (res5==num1||res5==num2||res5==num3||res5==num4) {
						cout<<"\033[33m[~] Quinto correto mas posicao errada\033[0m"<<endl;
					}
					else                                                     {
						cout<<"\033[31m[X] Quinto incorreto\033[0m"<<endl;
					}

					tentativas--;

					if (res1==num1&&res2==num2&&res3==num3&&res4==num4&&res5==num5) {
						cout << "\nParabens voce conseguiu!!" << endl;
						resposta = true;
						break;
					}
				}
				if (tentativas == 0 && resposta == false) {
					cout << "\nVoce nao conseguiu adivinhar. Que pena!" << endl;
					cout << "A senha era: " << num1 << num2 << num3 << num4 << num5 << endl;
				}
			}
			break;
		}

		case 2: {
			system("clear"); // Limpa
			int num1,num2,num3,num4,num5,num6;
			int res1=0,res2=0,res3=0;
			int tentativas = 1;
			bool chave1Resolvida=false, chave2Resolvida=false;
			srand(time(0));

			do {
				num1=rand()%6+1;
				num2=rand()%6+1;
				num3=rand()%6+1;
			} while (num1==num2||num1==num3||num2==num3);
			do {
				num4=rand()%6+1;
				num5=rand()%6+1;
				num6=rand()%6+1;
			} while (num4==num5||num4==num6||num5==num6);

			while (tentativas <= 10 && (chave1Resolvida == false && chave2Resolvida == false)) {
				cout << "=========== MODO DUETO ===========" << endl;
				cout << "Tentativa " << tentativas << " de 15" << endl;
				cout << "Seu ultimo chute foi: " << res1 << " " << res2 << " " << res3 << endl;
				cout << "----------------------------------" << endl;
				cout << (chave1Resolvida ? "\033[32m[CHAVE 1] RESOLVIDA\033[0m" : "\033[31m[CHAVE 1] PENDENTE\033[0m") << endl;
				cout << (chave2Resolvida ? "\033[32m[CHAVE 2] RESOLVIDA\033[0m" : "\033[31m[CHAVE 2] PENDENTE\033[0m") << endl;
				cout << "----------------------------------" << endl;
				cout << "Digite 3 numeros de 1 a 6: "<< endl;
				cout << "primeiro numero:" << endl;
				cin >> res1;
				cout << "Segundo numero:" << endl;
				cin >> res2;
				cout << "Terceiro numero:" << endl;
				cin >> res3;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<"Digite apenas numeros!"<<endl;
					continue;
				}
				while (res1<1||res1>6||res2<1||res2>6||res3<1||res3>6||res1==res2||res1==res3||res2==res3) {
					cout << "Entrada invalida! Nao repetir, de 1 a 6." << endl;
					cin >> res1 >> res2 >> res3;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						continue;
					}
				}

				if (chave1Resolvida == false) {
					cout << endl << "===== CHAVE 1 =====" << endl;
					if (res1==num1) {
						cout<<"\033[32m[✓] Primeiro correto\033[0m"<<endl;
					}
					else if (res1==num2||res1==num3) {
						cout<<"\033[33m[~] Primeiro em outra posicao\033[0m"<<endl;
					}
					else {
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
					}
					if (res2==num2) {
						cout<<"\033[32m[✓] Segundo correto\033[0m"<<endl;
					}
					else if (res2==num1||res2==num3) {
						cout<<"\033[33m[~] Segundo em outra posicao\033[0m"<<endl;
					}
					else {
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
					}
					if (res3==num3) {
						cout<<"\033[32m[✓] Terceiro correto\033[0m"<<endl;
					}
					else if (res3==num1||res3==num2) {
						cout<<"\033[33m[~] Terceiro em outra posicao\033[0m"<<endl;
					}
					else {
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
					}
					if (res1==num1&&res2==num2&&res3==num3) {
						chave1Resolvida=true;
						cout<<"\n\033[32mCHAVE 1 DESBLOQUEADA!\033[0m"<<endl;
					}
				}
				if (chave2Resolvida == false) {
					cout << endl << "===== CHAVE 2 =====" << endl;
					if (res1==num4) {
						cout<<"\033[32m[✓] Primeiro correto\033[0m"<<endl;
					}
					else if (res1==num5||res1==num6) {
						cout<<"\033[33m[~] Primeiro em outra posicao\033[0m"<<endl;
					}
					else {
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
					}
					if (res2==num5) {
						cout<<"\033[32m[✓] Segundo correto\033[0m"<<endl;
					}
					else if (res2==num4||res2==num6) {
						cout<<"\033[33m[~] Segundo em outra posicao\033[0m"<<endl;
					}
					else {
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
					}
					if (res3==num6) {
						cout<<"\033[32m[✓] Terceiro correto\033[0m"<<endl;
					}
					else if (res3==num4||res3==num5) {
						cout<<"\033[33m[~] Terceiro em outra posicao\033[0m"<<endl;
					}
					else {
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
					}
					if (res1==num4&&res2==num5&&res3==num6) {
						chave2Resolvida=true;
						cout<<"\n\033[32mCHAVE 2 FOI DESBLOQUEADA!\033[0m"<<endl;
					}
				}
				if (chave1Resolvida == true && chave2Resolvida == true) {
					cout << "\nPARABENS! VOCE CONSEGUIU DESBLOQUEAR AS DUAS CHAVES!" << endl;
					break;
				}
				tentativas++;
			}
			if (chave1Resolvida == false || !chave2Resolvida == false) {
				cout << "\nVOCE PERDEU!" << endl;
			}
			break;
		}

		case 3:
			system("clear");
			cout << "=============DIFICULDADE===========" << endl;
			cout << "Por favor escolha a dificuldade:" << endl;
			if (dificuldade==1) {
				cout << "  Dificuldade atual: Facil" << endl;
			} else if (dificuldade==2) {
				cout << "  Dificuldade atual: Medio" << endl;
			} else {
				cout << "  Dificuldade atual: Dificil" << endl;
			}
			cout << "1 - Facil" << endl;
			cout << "2 - Medio" << endl;
			cout << "3 - Dificil" << endl;
			cin >> dificuldade;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Digite apenas numeros!\n";
				break;
			}
			while (dificuldade<1||dificuldade>3) {
				cout << "Escolha apenas entre 1 e 3: ";
				cin >> dificuldade;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<"Digite apenas numeros!\n";
					break;
				}
			}
			if (dificuldade==1)      cout << "\nDificuldade definida para: Facil" << endl;
			else if (dificuldade==2) cout << "\nDificuldade definida para: Medio" << endl;
			else                     cout << "\nDificuldade definida para: Dificil" << endl;
			break;

		case 4:
			system("clear");
			cout << "==============SOBRE================" << endl;
			cout << "Equipe de Desenvolvimento==========" << endl;
			cout << "- Joao Gabriel Miliano Tomazelli dos Santos" << endl;
			cout << "- Thiago Schmitt dos Passos" << endl;
			cout << "- Juliano de Souza Castro Vieira" << endl;
			cout << "- Yasmin Inturn" << endl;
			cout << "Data atual: 1 de junho de 2026"<< endl;
			cout << "===Professor e Disciplina==========" << endl;
			cout << "Professor: Alex Rese" << endl;
			cout << "Disciplina: Algoritmo e Programacao" << endl;
			break;

		case 5: {
			system("clear"); // Limpa
			if (dificuldade == 1) {
				int num1,num2,num3,tentativas=1,res1=0,res2=0,res3=0;
				bool resposta=false;
				srand(time(0));
				do {
					num1=rand()%6+1;
					num2=rand()%6+1;
					num3=rand()%6+1;
				} while (num1==num2||num1==num3||num2==num3);

				while (tentativas <= 8 && resposta == false) {
					cout<<"============ AUTO - DIFICULDADE FACIL ==================="<<endl;
					cout<<"Tentativa "<<tentativas<<" de 8"<<endl;
					cout<<"Ultimo chute: "<<res1<<" "<<res2<<" "<<res3<<endl;
					cout<<"---------------------------------------------------------"<<endl;
					do {
						if (res1!=num1) {
							res1=rand()%6+1;
						}
						if (res2!=num2) {
							res2=rand()%6+1;
						}
						if (res3!=num3) {
							res3=rand()%6+1;
						}
					} while (res1==res2||res1==res3||res2==res3);
					cout<<"Chute gerado: "<<res1<<" "<<res2<<" "<<res3<<endl;
					cout<<"\n=========== RESULTADO ==========="<<endl;
					if (res1==num1)                  {
						cout<<"\033[32m[✓] Primeiro correto na posicao correta\033[0m"<<endl;
					}
					else if (res1==num2||res1==num3)  {
						cout<<"\033[33m[~] Primeiro correto mas posicao errada\033[0m"<<endl;
					}
					else                              {
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
					}
					if (res2==num2)                  {
						cout<<"\033[32m[✓] Segundo correto na posicao correta\033[0m"<<endl;
					}
					else if (res2==num1||res2==num3)  {
						cout<<"\033[33m[~] Segundo correto mas posicao errada\033[0m"<<endl;
					}
					else                              {
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
					}
					if (res3==num3)                  {
						cout<<"\033[32m[✓] Terceiro correto na posicao correta\033[0m"<<endl;
					}
					else if (res3==num1||res3==num2)  {
						cout<<"\033[33m[~] Terceiro correto mas posicao errada\033[0m"<<endl;
					}
					else                              {
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
					}
					tentativas++;
					if (res1==num1&&res2==num2&&res3==num3) {
						cout<<"\nParabens computador!!"<<endl;
						resposta=true;
						break;
					}
				}
				if (tentativas > 8 && resposta == false) {
					cout<<"\nO computador nao conseguiu adivinhar."<<endl;
				}
			}
			else if (dificuldade == 2) {
				int num1,num2,num3,num4,tentativas=1,res1=0,res2=0,res3=0,res4=0;
				int imp1=0,imp2=0,imp3=0,imp4=0;
				bool resposta=false;
				srand(time(0));
				do {
					num1=rand()%8+1;
					num2=rand()%8+1;
					num3=rand()%8+1;
					num4=rand()%8+1;
				} while (num1==num2||num1==num3||num1==num4||num2==num3||num2==num4||num3==num4);

				while (tentativas <= 10 && resposta == false) {
					cout<<"============ AUTO - DIFICULDADE MEDIA ==================="<<endl;
					cout<<"Tentativa "<<tentativas<<" de 10"<<endl;
					cout<<"Ultimo chute: "<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<endl;
					cout<<"---------------------------------------------------------"<<endl;
					do {
						if (res1!=num1||res1==imp1) {
							res1=rand()%8+1;
						}
						if (res2!=num2||res2==imp2) {
							res2=rand()%8+1;
						}
						if (res3!=num3||res3==imp3) {
							res3=rand()%8+1;
						}
						if (res4!=num4||res4==imp4) res4=rand()%8+1;
					} while (res1==res2||res1==res3||res1==res4||res2==res3||res2==res4||res3==res4);
					cout<<"Chute gerado: "<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<endl;
					cout<<"\n=========== RESULTADO ==========="<<endl;
					if (res1==num1)                              {
						cout<<"\033[32m[✓] Primeiro correto\033[0m"<<endl;
					}
					else if (res1==num2||res1==num3||res1==num4) {
						cout<<"\033[33m[~] Primeiro posicao errada\033[0m"<<endl;
					}
					else                                         {
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
						imp1=res1;
					}
					if (res2==num2)                              {
						cout<<"\033[32m[✓] Segundo correto\033[0m"<<endl;
					}
					else if (res2==num1||res2==num3||res2==num4) {
						cout<<"\033[33m[~] Segundo posicao errada\033[0m"<<endl;
					}
					else {
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
						imp2=res2;
					}
					if (res3==num3) {
						cout<<"\033[32m[✓] Terceiro correto\033[0m"<<endl;
					} else if (res3==num1||res3==num2||res3==num4) {
						cout<<"\033[33m[~] Terceiro posicao errada\033[0m"<<endl;
					} else {
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
						imp3=res3;
					}
					if (res4==num4)                              {
						cout<<"\033[32m[✓] Quarto correto\033[0m"<<endl;
					}
					else if (res4==num1||res4==num2||res4==num3) {
						cout<<"\033[33m[~] Quarto posicao errada\033[0m"<<endl;
					}
					else                                         {
						cout<<"\033[31m[X] Quarto incorreto\033[0m"<<endl;
						imp4=res4;
					}
					tentativas++;
					if (res1==num1&&res2==num2&&res3==num3&&res4==num4) {
						cout<<"\nParabens computador!!"<<endl;
						resposta=true;
						break;
					}
				}
				if (resposta==false) {
					cout<<"\nO computador nao conseguiu adivinhar."<<endl;
				}
			}
			else if (dificuldade == 3) {
				int num1,num2,num3,num4,num5;
				int res1=0,res2=0,res3=0,res4=0,res5=0;
				int tentativas=1;
				bool resposta=false;
				srand(time(0));
				do {
					num1=rand()%6+1;
					num2=rand()%6+1;
					num3=rand()%6+1;
					num4=rand()%6+1;
					num5=rand()%6+1;
				} while (num1==num2||num1==num3||num1==num4||num1==num5||num2==num3||num2==num4||num2==num5||num3==num4||num3==num5||num4==num5);

				while (tentativas <= 12 && resposta == false) {
					cout<<"============ AUTO - DIFICULDADE DIFICIL ==================="<<endl;
					cout<<"Tentativa "<<tentativas<<" de 12"<<endl;
					cout<<"Ultimo chute: "<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<" "<<res5<<endl;
					cout<<"-----------------------------------------------------------"<<endl;
					do {
						if (res1!=num1) {
							res1=rand()%6+1;
						}
						if (res2!=num2) {
							res2=rand()%6+1;
						}
						if (res3!=num3) {
							res3=rand()%6+1;
						}
						if (res4!=num4) {
							res4=rand()%6+1;
						}
						if (res5!=num5) {
							res5=rand()%6+1;
						}
					} while (res1==res2||res1==res3||res1==res4||res1==res5||res2==res3||res2==res4||res2==res5||res3==res4||res3==res5||res4==res5);
					cout<<"Chute gerado: "<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<" "<<res5<<endl;
					cout<<"\n=========== RESULTADO ==========="<<endl;
					if (res1==num1)                                          {
						cout<<"\033[32m[✓] Primeiro correto\033[0m"<<endl;
					}
					else if (res1==num2||res1==num3||res1==num4||res1==num5)
					{
						cout<<"\033[33m[~] Primeiro em outra posicao\033[0m"<<endl;
					}
					else
					{
						cout<<"\033[31m[X] Primeiro incorreto\033[0m"<<endl;
					}
					if (res2==num2)
					{
						cout<<"\033[32m[✓] Segundo correto\033[0m"<<endl;
					}
					else if (res2==num1||res2==num3||res2==num4||res2==num5)
					{
						cout<<"\033[33m[~] Segundo em outra posicao\033[0m"<<endl;
					}
					else
					{
						cout<<"\033[31m[X] Segundo incorreto\033[0m"<<endl;
					}
					if (res3==num3)
					{
						cout<<"\033[32m[✓] Terceiro correto\033[0m"<<endl;
					}
					else if (res3==num1||res3==num2||res3==num4||res3==num5)
					{
						cout<<"\033[33m[~] Terceiro em outra posicao\033[0m"<<endl;
					}
					else
					{
						cout<<"\033[31m[X] Terceiro incorreto\033[0m"<<endl;
					}
					if (res4==num4)
					{
						cout<<"\033[32m[✓] Quarto correto\033[0m"<<endl;
					}
					else if (res4==num1||res4==num2||res4==num3||res4==num5)
					{
						cout<<"\033[33m[~] Quarto em outra posicao\033[0m"<<endl;
					}
					else
					{
						cout<<"\033[31m[X] Quarto incorreto\033[0m"<<endl;
					}
					if (res5==num5)
					{
						cout<<"\033[32m[✓] Quinto correto\033[0m"<<endl;
					}
					else if (res5==num1||res5==num2||res5==num3||res5==num4)
					{
						cout<<"\033[33m[~] Quinto em outra posicao\033[0m"<<endl;
					}
					else
					{
						cout<<"\033[31m[X] Quinto incorreto\033[0m"<<endl;
					}
					tentativas++;
					if (res1==num1&&res2==num2&&res3==num3&&res4==num4&&res5==num5) {
						cout<<"\nPARABENS COMPUTADOR!!"<<endl;
						resposta=true;
						break;
					}
				}
				if (resposta==false) {
					cout<<"\nO computador nao conseguiu adivinhar."<<endl;
					cout<<"A senha era: "<<num1<<num2<<num3<<num4<<num5<<endl;
				}
			}
			break;
		}

		case 6:
			return 0;

		default:
			cout << "Digite uma escolha valida" << endl;
			break;
		}
	}
	return 0;
}
