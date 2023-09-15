#include <iostream>
using namespace std;
int transformaBinario(int num) {
	int bin = 0, rem = 0, place = 1;
	while (num) {
		rem = num % 2;
		num = num / 2;
		bin = bin + (rem * place);
		place = place * 10;
	}
	return bin;
}
int somaBinaria(int bin1, int bin2) {
	int carry = 0, result = 0, bit1, bit2; // carry = "vai um"
	int place = 1; // controlar a posição do dígito atual no número binário resultante -- sempre multiplicada por 10 a cada interação do looping

	while (bin1 || bin2) {
		bit1 = bin1 % 10;
		bit2 = bin2 % 10;
		int sum = bit1 ^ bit2 ^ carry; //a soma dos bits usando XOR, sum é o numero atual da soma
		result = result + (sum * place);
		carry = (bit1 & bit2) | (carry & (bit1 ^ bit2)); // quando usado o &, determina se há "vai um" entre as somas
		bin1 = bin1 / 10; //deslocando eles a direita
		bin2 = bin2 / 10;
		place = place * 10;
	}
	result = result + (carry * place); // Adiciona o carry final, se houver, ou seja, verifica se tem o vai um e coloca no lugar certo
	return result;
}

int main() {
	int num1, num2;
	cout << "Informe o primeiro numero decimal: ";
	cin >> num1;
	cout << "Informe o segundo numero decimal: ";
	cin >> num2;
	int bin1 = transformaBinario(num1);
	cout << "Decimal 1 em binario: " << bin1 << endl;
	int bin2 = transformaBinario(num2);
	cout << "Decimal 2 em binario: " << bin2 << endl;
	int resultado = somaBinaria(bin1, bin2);
	cout << "O resultado da soma binaria e: " << resultado << endl;
	cout << "O resultado da soma decimal e: " << num1 + num2 << endl;
	return 0;
}