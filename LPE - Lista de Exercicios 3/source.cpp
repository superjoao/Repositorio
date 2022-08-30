#include "menu.h"

using namespace std; 

void a01 (){
    fstream fileA01;
    char caracter;
    
    int total=0, totalLetras=0;

    cout << "Digite a frase: \n";
    fileA01.open ("a01.txt", ios:: out);
    if (fileA01.is_open()){
        while ((caracter = getchar()) != '\n'){
            fileA01 << caracter;
            if (caracter >= 'A' && caracter <= 'Z' || caracter >= 'a' && caracter <= 'z')
            {
                totalLetras++;
            }
            total++; 
        }
        fileA01.close();
    }
    
    cout << "O total de caracter é de: " << total << endl << "O total de letras é de: " << totalLetras << endl;
}

void a02 (){

    fstream a02;
    string line;
    char tmp1 [30];
    int tmp = 0;

    a02.open("a02.txt", ios::in);

    if (a02.is_open()){
        
        while (getline(a02, line, ' ')){
            cout << line << endl;
            int size1 = line.length();
            if (size1 > tmp){
                tmp = size1;
                line.copy(tmp1,line.length());
            }
        }
        a02.close();
    }
    cout << "O comprimento da palavra de maior tamanho é: " << tmp << endl << "que é: ";
    for (int i = 0; i < strlen(tmp1); i++){
        cout << tmp1[i];
    }   
}

void codificar (char s[], int n){

    for (int i = 0; i < strlen(s); i++){
        if (s[i] != ' '){
            cout << char(s[i]+n);
        }else{
            cout << s[i];
        }
    }
}

void a04(){
    fstream a04a, a04b, a04c;
    string line;
    a04a.open("a04a.txt", ios::in);
    if (a04a.is_open()){
        while (getline(a04a, line)){
            cout << line;
        }
        a04a.close();
    }
    if (a04b.is_open()){
        while (getline(a04b, line)){
            cout << line;
        }
        a04b.close();
    }
    if (a04c.is_open()){
        while (getline(a04c, line)){
            cout << line;
        }
        a04a.close();
    }
}

void gate (user *u,int const n){
    char a[15] ={'\0'}, b [15] ={'\0'};
    do
    {
        cout << "\nDigite o login: ";
        cin >> b;
        cout << "\nDigite a senha: ";
        cin >> a;
        for (int i = 0; i < strlen(a); i++){
            if (a[i] != ' '){
                a[i]= char(a[i]+n);
            }else{
                a [i]= a[i];
            }
        }
        
    } while (strcmp(a, u[0].password)!= 0 ||  strcmp(b, u[0].login) != 0);
    


    cout << "logon.";
}

void codificar1 (user *u, int const n){
    
    cout << "\n senha é : " << endl;
    for (int i = 0; i < strlen(u[0].password); i++){
        if (u[0].password[i] != ' '){
            u[0].password[i] = char(u[0].password[i]+n);
            cout << char(u[0].password[i]);
        }else{
            u[0].password[i] = u[0].password[i];
            cout << u[0].password[i]; 
        }
    }
    gate (u, n);  
}

void a06 (){
    fstream a06;
    string line, word;
    int count=0, num=0;
    a06.open("a06.txt", ios::in);
    if (a06.is_open()){
        cout << "Digite a palavra que procura: ";
        getline (cin, word);
        while (getline(a06, line, ' ')){
            if (line == word){
                cout << "A palavra \"" << word << "\" esta contida no texto.";
                count ++;
            }         
        }
        if (count < 1){
            cout << "\nNão foi encontrada a palavra";
        }
        a06.close();
    }
}

void a07(){
    fstream a07, a07b;
    string line, word, coma = {',',' '};
    int j, k;
    a07.open("a07.txt",ios::in);
    if (a07.is_open()){
        a07b.open("a07b.txt", ios::out);
        if (a07b.is_open())
        {
            while(getline(a07, line)){

                /*Botar o sobrenome maiusculo primeiro.
                usando o char null ('\0) para parar no final da frase*/
                for (int i = 0; i<line.length()+1; i++){
                    j = i;
                    if (line[i] == '\0'){
                        //Rebobinar a var j até chegar no ultimo espaço.
                        while (line[j]!= ' '){
                            j--;   
                        }
                        // guarda o valor j (a posição onde encontra o sobrenome) em k.
                        k=j;

                        //escreve o sobrenome em mausculo.
                        if (line[j] == ' '){
                            for (j+=1; j < line.length(); j++){ 
                                a07b << char(toupper(line[j]));
                            }
                        }
                    }  
                }
                //separar por virgula.
                a07b << coma;

                // colocar o nome depois, utilizando var k como ponto final.
                for (int i = 0; i<k; i++){
                    a07b << line[i];
                }
                a07b << '\n';
            }
            a07b.close();
        }
        a07.close();
    }
}

//Algoritmos especiais.

void b01 (const int arr[], const int size){
    int num, count = 0, *numF = NULL;
    cout << "procurar no vetor pelo numero: ";
    cin >> num;
    for (int i=0; i<size; i++){
        if (arr[i] == num)
        {
            count++;
            numF = &num;
        }  
    }
    if (numF != NULL){
        cout << "O numero "<< num << " foi enocontrado " << count << endl;
    }else{
        cout << "O numero não foi encontrado no vetor";
    }
}

void b02(int arr[], int const size){
    
    int tmp;
    for (int i = 1; i <size; i++){
        
        for (int j = 0; j <size; j++){
            
            if(arr[j]> arr[i]){
                tmp = arr[j];
                arr[j]= arr[i];
                arr[i] = tmp;
            }
        }
    }
    for (int i = 0; i <size; i++){
        cout << arr[i] << " ";
    }
}

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Cria ponteiros de vetores temporarios.
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
 
    // copia os elementos para os respectivos vetores temporarios.
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    
    // indice dos subvetores 1, 2 e merged 
    auto l = 0, r = 0; 
    int m = left; 
 
    // fundi os vetores temporarios ao vetor.
    while (l < subArrayOne && r < subArrayTwo) {
        if (leftArray[l] <= rightArray[r]) {
            array[m] = leftArray[l];
            l++;
        }
        else {
            array[m] = rightArray[r];
            r++;
        }
        m++;
    }
    // Copia os elementos que sobram da esquerda.
    while (l < subArrayOne) {
        array[m] = leftArray[l];
        l++;
        m++;
    }
    // copia os elementos que sobraram da direita.
    while (r < subArrayTwo) {
        array[m] = rightArray[r];
        r++;
        m++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int arr[], int const begin, int const end){
    if (begin >= end){return;}

    auto mid = begin + (end - begin)/2;
    mergeSort (arr, begin, mid);
    mergeSort (arr, mid +1, end);
    merge (arr, begin, mid, end);
    
}

int binarySearch(int const a[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid]){
            cout << "\nO numero "<< item;
            return mid;
            
        }else if (item > a[mid]){
            return binarySearch(a, item, low, mid-1);
        }else{
            return binarySearch(a, item, mid+1, high);
        }
        
    }
    cout << "não encontrado";
    return 0;
}

void printArray(int const a[], int const size){
    for(int i = 0; i <size; i++){
        cout << a[i] << " ";
    }
}
void b03()
{
    int ar[] = {12, 11, 13, 5, 6, 7}, item;
    int size = sizeof(ar)/ sizeof(*ar);

    cout << "O vetor é:\n";
    printArray(ar, size);

    mergeSort(ar, 0, size -1);

    cout << "\nO vetor ordenado fica: \n";
    printArray(ar, size);

    cout << "\nQual numero voce pretende buscar? \n";
    cin >> item;
    binarySearch(ar, item, 0, size-1);

}

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

/*Função que encontra o valor minino da distancia, do conjunto
dos vertices que ainda não foram inclusos no menor caminho*/
int minDistance(int dist[], bool sptSet[])
{

	// inicializando valor minino.
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[])
{
	cout <<"Vertice \t Distancia da fonte" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // O vetor de saida. dist[i] vai conter o valor da menor distancia da fonte até i.
	

	bool sptSet[V]; /* sptSet[i] vai ser true se o vertice i for concluido no menor caminho
	ou na menor distancia da fonte ate i ser finalizado */ 

	// Inicializa todas as distancias sendo infinito e stpSet[] como false.
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distancia do vertice fonte dele mesmo que é igual a 0.
	dist[src] = 0;

	// encontra o menor caminho para todos os vertices.
	for (int count = 0; count < V - 1; count++) {
		/* Escolhe a minima distacia do vertice do grupo dos vertices ainda não processados.
		u é sempre igual a fonte na primeira interação.*/
		int u = minDistance(dist, sptSet);

		// Marca o vertice escolhido como processado.
		sptSet[u] = true;

		// Atualiza o valor de dist do vertice adjacente ao vertice escolhido.
		for (int v = 0; v < V; v++)

			/* Atualiza dist[v] somente se a condição !sptSet[v] for satisfeita,
            e o peso total do caminho, da fonte até v passndo por u,
            for menor que valor atual da dist[v]*/
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
            }
	}

	
	printSolution(dist);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
