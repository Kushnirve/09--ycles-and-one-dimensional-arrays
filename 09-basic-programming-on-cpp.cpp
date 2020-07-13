#include <iostream>
#include <random>
#include <string>
#include "windows.h"

using namespace std;

//1.1
void LineType(int line_type, char symbol, int speed) {
	for (int i = 0; i < 20; i++) {
		Sleep(speed);
		cout << symbol;
		if (line_type == 1) cout << endl;
	}
}

int main() {
	setlocale(0, "rus");

	//1.1
	char symbol;
	int line_type, speed;
	cout << "Введите символ -> ";
	cin >> symbol;
	cout << "Выберите тип линии (1-вертикальная, 2-горизонтальная) -> ";
	cin >> line_type;
	cout << "Выберите скорость отрисовки линии (1-быстрая, 2-средняя, 3-медленная) ->";
	cin >> speed;
	switch (speed) {
	case 1:
		speed = 100;
		LineType(line_type, symbol, speed);
		break;
	case 2:
		speed = 300;
		LineType(line_type, symbol, speed);
		break;
	case 3:
		speed = 500;
		LineType(line_type, symbol, speed);
		break;
	default:
		cout << "Ошибка";
		break;
	}

	////1.2
	random_device rd;// Генератор случайных чисел
	mt19937 sequence(rd());// Генератор последовательности случайных чисел
	uniform_int_distribution <> turn(0, 5);// Диапазон генерации чисел от 0 до 5
	//Интро
	string logo[8] = {
	"           /\x1b[46m$$$$$$\x1b[40m   /\x1b[36m$$\x1b[37m                               ",
	"          | \x1b[46m$$\x1b[40m__  \x1b[46m$$\x1b[40m|__/                              ",
	"          | \x1b[46m$$\x1b[40m  \\ \x1b[46m$$\x1b[40m /\x1b[36m$$\x1b[37m  /\x1b[36m$$$$$$\x1b[37m   /\x1b[36m$$$$$$\x1b[37m           ",
	"          | \x1b[46m$$\x1b[40m  | \x1b[46m$$\x1b[40m| \x1b[36m$$\x1b[37m /\x1b[36m$$\x1b[37m____/\x1b[36m \x1b[37m /\x1b[36m$$\x1b[37m__  \x1b[36m$$\x1b[37m          ",
	"          | \x1b[46m$$\x1b[40m  | \x1b[46m$$\x1b[40m| \x1b[36m$$\x1b[37m| \x1b[36m$$\x1b[37m    \x1b[36m  \x1b[37m| \x1b[36m$$$$$$$$\x1b[37m          ",
	"          | \x1b[46m$$\x1b[40m  | \x1b[46m$$\x1b[40m| \x1b[36m$$\x1b[37m| \x1b[36m$$\x1b[37m    \x1b[36m  \x1b[37m| \x1b[36m$$\x1b[37m_____/          ",
	"          | \x1b[46m$$$$$$$\x1b[40m/| \x1b[36m$$\x1b[37m|  \x1b[36m$$$$$$\x1b[37m/|  \x1b[36m$$$$$$$\x1b[37m          ",
	"          |_______/ |__/ \\______/  \\_______/          "
	};
	//Кости
	string face[6]{
		"\x1b[47m\x1b[30m           \x1b[40m\n\x1b[47m           \x1b[40m\n\x1b[47m     \x1b[31mo\x1b[30m     \x1b[40m\n\x1b[47m           \x1b[40m\n\x1b[47m\x1b[30m           \x1b[40m\n",
		"\x1b[47m\x1b[30m           \x1b[40m\n\x1b[47m     o     \x1b[40m\n\x1b[47m           \x1b[40m\n\x1b[47m     o     \x1b[40m\n\x1b[47m\x1b[30m           \x1b[40m\n",
		"\x1b[47m\x1b[30m           \x1b[40m\n\x1b[47m  o        \x1b[40m\n\x1b[47m     o     \x1b[40m\n\x1b[47m        o  \x1b[40m\n\x1b[47m\x1b[30m           \x1b[40m\n",
		"\x1b[47m\x1b[30m           \x1b[40m\n\x1b[47m  o     o  \x1b[40m\n\x1b[47m           \x1b[40m\n\x1b[47m  o     o  \x1b[40m\n\x1b[47m\x1b[30m           \x1b[40m\n",
		"\x1b[47m\x1b[30m           \x1b[40m\n\x1b[47m  o     o  \x1b[40m\n\x1b[47m     \x1b[31mo\x1b[30m     \x1b[40m\n\x1b[47m  o     o  \x1b[40m\n\x1b[47m\x1b[30m           \x1b[40m\n",
		"\x1b[47m\x1b[30m           \x1b[40m\n\x1b[47m  o     o  \x1b[40m\n\x1b[47m  o     o  \x1b[40m\n\x1b[47m  o     o  \x1b[40m\n\x1b[47m\x1b[30m           \x1b[40m\n"
	};
	bool game = true;
	while (game) {
		for (int i = 0; i < 8; i++) {
			cout << "\x1b[37m" << logo[i] << endl;
		}
		int dice1, dice2, playerscore = 0, pcscore = 0, round = 3;
		for (int i = 0; i < round; i++) {
			dice1 = turn(sequence);
			dice2 = turn(sequence);
			cout << "\x1b[33m<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\nХод игрока:\n<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\nБросайте кости\n\x1b[30m";
			system("pause");
			cout << face[dice1] << "\n" << face[dice2] << "\n\x1b[33m<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n";
			playerscore += dice1 + dice2 + 2;
			dice1 = turn(sequence);
			dice2 = turn(sequence);
			cout << "\x1b[35m<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\nХод компьютера:\n<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n";
			Sleep(2000);
			cout << face[dice1] << "\n" << face[dice2] << "\n\x1b[35m<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n";
			pcscore += dice1 + dice2 + 2;
			cout << "\x1b[36mОчки: Игрок " << playerscore << " : " << pcscore << " Компьютер\x1b[40m" << endl;
		}
		//Выводим результат
		if (playerscore < pcscore) cout << "\x1b[31mВы проиграли!" << endl;
		else if (playerscore > pcscore) cout << "\x1b[32mВы выиграли!" << endl;
		else cout << "\x1b[35mНичья." << endl;
		cout << "Хотите сыграть еще раз?(1 - да, 0 - нет)\n";
		cin >> game;
		cout << "\x1B[2J\x1B[H";
	}

	//2.1
	random_device rd;
	mt19937 sequence(rd());
	uniform_int_distribution <> cell(-10, 10);
	int const amount = 20;
	int masiv[amount];
	int min = 0, max = 0;
	cout << "Одномерный массив, заполненный случайными числами:" << endl;
	for (int i = 0; i < amount; i++) {
		masiv[i] = cell(sequence);
		cout << masiv[i] << " ";
	}
	for (int i = 0; i < amount; i++) {
		if (min > masiv[i]) min = masiv[i];
		if (max < masiv[i]) max = masiv[i];
	}
	cout << endl << "Минимальный элемент массива: " << min << " Максимальный элемент массива: " << max;

	//2.2
	int yearprofit[12], first_month, last_month, x = 0, y = 0;
	cout << "Введите прибыль за 12 месяцев ->" << endl;
	for (int i = 0; i < 12; i++) {
		cin >> yearprofit[i]; //Вводим прибыль за 12 месяцев
	}
	cout << "Введите диапазон" << endl;
	cin >> first_month >> last_month; //Вводим диапазон
	int min = yearprofit[first_month]; // инициализация наименьшей прибыльи в диапазоне
	x = first_month;
	int max = yearprofit[first_month]; // инициалиазция наибольшей прибыльи в диапазоне
	y = first_month;
	for (; first_month < last_month; first_month++) {
		if (min > yearprofit[first_month]) {
			min = yearprofit[first_month];
			x = first_month + 1; // номер ячейки наименьшей прибыли
		}
		if (max < yearprofit[first_month]) {
			max = yearprofit[first_month];
			y = first_month + 1;// номер ячейки наибольшей прибыли
		}
	}
	cout << "Наименьшая прибыль в " << x << " месяце, наибольшая прибыль в " << y << " месяце";

	//2.3
	random_device rd;
	mt19937 multiplication(rd());
	uniform_int_distribution <> distr(-5, 5); // Диапазон генерации чисел от -5 до 5
	int const amount = 6; // размер массива
	float my_array[amount]; // мой массив
	for (int i = 0; i < amount; i++) {
		cout << i + 1 << " "; // номер ячейки масива
	}
	cout << endl;
	for (int i = 0; i < amount; i++) {
		my_array[i] = distr(multiplication); // заполняем массив случайными числами из заданного диапазона
		cout << my_array[i] << " "; // печатаем массив
	}
	cout << endl;
	// искомые 
	float sum_of_negative = 0, float min_to_max_mult = 1, even_mult = 1, fst_to_lst_negative_sum = 0;
	// вспомогательные переменные
	float min = 0, max = 0;
	int min_idx = 0, max_idx = 0, fst_neg_idx = 0, lst_neg_idx = 0;
	bool flag = false, flag2 = false;
	// делаем первый проход по массиву
	for (int i = 0; i < amount; i++) {
		if (my_array[i] < 0) sum_of_negative += my_array[i]; //sum_of_negative
		if (i % 2 != 0) even_mult *= my_array[i]; //even_mult
	// находим мин и мах значения и их индексы
		if (min > my_array[i]) {
			min = my_array[i];
			min_idx = i;
		}
		if (max < my_array[i]) {
			max = my_array[i];
			max_idx = i;
		}
		// индекс первого вхождения отрицательного числа
		if ((my_array[i] < 0) and (flag == false)) { fst_neg_idx = i; flag = true; }
	}
	//cout << "Первый отрицательный элемент: " << fst_neg_idx << endl;
	// делаем проход по массиву с другой стороны и находим 
	// индекс последнего вхождения отрицательного числа
	for (int i = amount - 1; i >= 0; i--) {
		if ((my_array[i] < 0) and (flag2 == false)) {
			lst_neg_idx = i;
			flag2 = true;
		}
	}
	//cout << "Последний отрицательный элемент: " << lst_neg_idx << endl;
	// считаем fst_to_lst_negative_sum
	for (int i = fst_neg_idx; i <= lst_neg_idx; i++) {
		fst_to_lst_negative_sum += my_array[i];
	}
	// если значения min_idx и max_idx перепутаны меняем их местами чтобы цикл всегда исполнялся в одну сторону
	//cout << "Min элемент: " << min_idx << " Max элемент: " << max_idx << endl;
	if (max_idx < min_idx) {
		int temp = max_idx;
		max_idx = min_idx;
		min_idx = temp;
	}
	//cout << "Min элемент: " << min_idx << " Max элемент: " << max_idx << endl;
	// считаем min_to_max_mult
	for (int i = max_idx; i >= min_idx; i--) {
		min_to_max_mult *= my_array[i];
	}
	// ответы
	cout << "Сума отрицательных чисел: " << sum_of_negative << endl;
	cout << "Произведение элементов с четными номерами : " << even_mult << endl;
	cout << "Произведение элементов, находящихся между min и max элементами: " << min_to_max_mult << endl;
	cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами: " << fst_to_lst_negative_sum << endl;

}