#include <iostream>
#include <bitset>
#include <string>
using namespace std;
// Função para converter um número decimal para binário
string decimalParaBinario(int decimal)
{
	string binario = "";
	while (decimal > 0)
	{
		int bit = decimal % 2;
		binario = to_string(bit) + binario;
		decimal /= 2;
	}
	return binario;
}

// Função para converter um número binário para decimal
int binarioParaDecimal(string binario)
{
	int decimal = 0;
	int tamanho = binario.length();
	for (int i = 0; i < tamanho; i++)
		if (binario[i] == '1')
			decimal += 1 << (tamanho - 1 - i);
	return decimal;
}

// Função para realizar a soma de dois números binários usando operadores lógicos
string somaBinaria(string binario1, string binario2)
{
	string resultado = "";
	int carry = 0;
	int tamanho1 = binario1.length();
	int tamanho2 = binario2.length();
	int tamanhoMax = max(tamanho1, tamanho2);
	for (int i = 0; i < tamanhoMax; i++)
	{
		int bit1 = (i < tamanho1) ? (binario1[tamanho1 - 1 - i] - '0') : 0;
		int bit2 = (i < tamanho2) ? (binario2[tamanho2 - 1 - i] - '0') : 0;
		int soma = (bit1 ^ bit2) ^ carry; // Soma usando operadores XOR
		carry = (bit1 & bit2) | (carry & (bit1 ^ bit2)); // Cálculo do carry
		resultado = to_string(soma) + resultado;
	}
	if (carry)
		resultado = "1" + resultado;
	return resultado;
}

int main() {
	int numero1, numero2;
	cout << "Digite o primeiro número decimal: ";
	cin >> numero1;

	cout << "Digite o segundo número decimal: ";
	cin >> numero2;

	// Converter os números decimais para binário
	string binario1 = decimalParaBinario(numero1);
	string binario2 = decimalParaBinario(numero2);

	// Realizar a soma dos números binários usando apenas operadores lógicos
	string resultadoBinario = somaBinaria(binario1, binario2);

	// Converter o resultado de volta para decimal
	int resultadoDecimal = binarioParaDecimal(resultadoBinario);

	// Exibir os resultados
	cout << "Soma em binário: " << resultadoBinario << endl;
	cout << "Soma em decimal: " << resultadoDecimal << endl;

	return 0;
}
