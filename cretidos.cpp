#include <iostream>
#include <cstdlib>
#include <windows.h>


using namespace std;

ostream& boldOn(ostream& os)
{
	return os << "\e[1m";
}

ostream& boldOff(ostream& os)
{
	return os << "\e[0m";
}
void imprimirArcoIris(string x){
	cout << "|";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  
	int k = 10;
	for(int i = 0; i < x.length(); i++){
		SetConsoleTextAttribute(hConsole, k);
		if (k >14)
		{
			k=10;
		}
		
		((i+1) %2 != 0)? cout << char(toupper(x[i])) : cout << x[i];
		k++;
		
	}
	SetConsoleTextAttribute(hConsole, 0);
	
}

void creditos()
{
	
	//28
	string guilherme = "guilherme a. silva.", edenilson = "edenilson do n. silva.", joao = "joao luis m. de lima.", 
	antonio = "antonio rodrigues da silva",	gabriel = "gabriel f. da s. fernandes", paulo = "paulo sergio m. m. de Oliveira."; 
    
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "|" << boldOn << "Creditos:" << boldOff << "|" << endl;
	SetConsoleTextAttribute(hConsole, 0);

	cout << "------------------------" << endl;
	cout << "|" << boldOn << "Author" << "                " <<  boldOff << "|" << endl;
	imprimirArcoIris(guilherme); 
	cout << "   |" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "                       " << "|" << boldOn << "Desenvolvedor de Conteudo" << boldOff << " |" << endl; 
	cout << "                       "; 
	imprimirArcoIris(antonio);
	cout << "|" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|" << boldOn << "Cordenador de Producao" << boldOff << "|" << "                          " << "|" << boldOn << "Estagiario         " << boldOff << "  |" << endl;
	imprimirArcoIris(edenilson);
	cout << "|";
	cout << "                          ";
	imprimirArcoIris(joao);
	cout << "|";
	cout << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "                       " << "|" << boldOn << "Cordenador de Projetos" << boldOff << "    |" << endl; 
	cout << "                       "; 
	imprimirArcoIris(gabriel);
	cout << "|" << endl;
	cout << "                       ------------------------------------------------------------" << endl;
	cout << "                       " << " " << "                          " << "|" << boldOn << "Revisor de Conteudo" << boldOff << "            |" << endl; 
	cout << "                       " << " " << "                          ";
	imprimirArcoIris(paulo);
	cout << "|" << endl;
	cout << "                                                  ---------------------------------" << endl;     
}

int main(int argc, char const *argv[])
{
    creditos();
    return 0;
}