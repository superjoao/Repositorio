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
