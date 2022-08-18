#include <iostream>
using namespace std;

int num_moedas(int moedas[], int troco, int size)
{
	int qte_moedas = 0;
		
	for(int i = size - 1; i >= 0; i--)
	{
		int aux_moedas = troco / moedas[i];
		troco -= aux_moedas * moedas[i];
		qte_moedas += aux_moedas;
	}
	
	return qte_moedas;
}

int main(int argc, char *argv[])
{
	int moedas[] = {1, 2, 5 ,10, 20};
    int size = sizeof(moedas)/ sizeof (*moedas);
	int troco = 26;
	cout << "Numero de moedas: " << num_moedas(moedas, troco, size);

	return 0;
}