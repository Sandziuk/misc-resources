#include <iostream>
#include <conio.h>
#include <ctime>
#include <cmath>
#define Radom <random>
#include Radom

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;

typedef long double T;

struct element {
	T dane;
	element * pNext;
};

void dodaj(T wartosc, element* &pGlowa) {
	element* pNowy = new element;
	(*pNowy).dane = wartosc;
	pNowy->pNext = pGlowa;
	pGlowa = pNowy;
}

void wypisz_I(element * pGlowa) {
	while (pGlowa) {
		cout << pGlowa->dane << endl;
		pGlowa = pGlowa->pNext;
	}
}

void wypisz_Rp(element * pGlowa) {
	if (pGlowa) {
		cout << pGlowa->dane << endl;
		wypisz_Rp(pGlowa->pNext);
	}
}

void wypisz_Rk(element * pGlowa) {
	if (pGlowa) {
		wypisz_Rk(pGlowa->pNext);
		cout << pGlowa->dane << endl;
	}
}

void dodajSortI(element *& pHead, T w) {
	if (!pHead) {								//Lista pusta
		pHead = new element{ w, 0 };
		return;
	}

	if (w < pHead->dane) {
		pHead = new element{ w, pHead };
		return;
	}

	auto p = pHead;								//Lista niepusta
	while (p->pNext && p->pNext->dane < w)	p = p->pNext;

	p->pNext = new element{ w, p->pNext };
	return;
}

void dodajSortR(element *& pHead, T w) {
	if (!pHead) {								//Lista pusta
		pHead = new element{ w, 0 };
		return;
	}

	if (w < pHead->dane) {
		pHead = new element{ w, pHead };
		return;
	}
	else {
		dodajSortR(pHead->pNext, w);
	}
}

void usun(element *& pHead, T w) {
	if (!pHead)	return;
	if (pHead->dane == w) {
		auto p = pHead;
		pHead = pHead->pNext;
		delete p;
	}
	auto p = pHead;
	while (p->pNext && p->pNext->dane != w)
		p = p->pNext;
	if (p->pNext) {			//Jezeli element istnieje!
		auto d = p->pNext;
		p->pNext = d->pNext;
		delete d;
	}
}

void usunI(element *& pHead) {
	while (pHead) {
		auto p = pHead;
		pHead = pHead->pNext;
		delete p;
	}
}

void usunR(element *& pHead) {
	if (pHead) {
		usunR(pHead->pNext);
		delete pHead;
		pHead = 0;
	}
}

//Napisac funkcje ktora usuwa element rekurencyjnie

int main()
{
	element* pHead = NULL;
	
	dodajSortI(pHead, 10);
	dodajSortI(pHead, 15);

	/*default_random_engine endzajn;
	endzajn.seed(time(NULL));
	uniform_real_distribution<T> distro(0, acos(-1));

	for (int i = 0; i < 1000; ++i){
		dodajSortR(pHead, distro(endzajn));
	}*/
	
	wypisz_Rp(pHead);

	usun(pHead, 10);

	std::cout << std::endl;

	wypisz_I(pHead);

	//usunI(pHead);
	usunR(pHead);

	//std::cout << pHead << std::endl;

	//srand(time(NULL));

	/*default_random_engine silnik;
	silnik.seed(time(NULL));
	uniform_real_distribution<T> podzialka(0, acos(-1));*/

	//for (int i = 0; i < 10000; i++)
	//{
	//	
	//	//dodaj(podzialka(silnik), pHead);

	//	dodaj(i,pHead);
	//	
	//	//dodaj(rand(),pHead);
	//}

	//wypisz_Rk(pHead);

	_CrtDumpMemoryLeaks();

	getch();

    return 0;
}

