/**
* @file main.cpp
* @description programın main dosyası satır satır okuyarak bir stack içerisine koyuluyor.
* @course 1.Öğretim A Grubu
* @assignment 2.ödev
* @date 1.Aug.2023
* @author Mustafa Yakın mustafa.yakin@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "stack.h"
#include "bst.h"
#include <unistd.h>

int main() {

    Stack* stackArr;
    int stackArrIndex = 0;

    BinarySearchTree* binarySearchTreeArr;

    string satir;
    ifstream dosya("Sayilar.txt");

    if(!dosya.is_open()){
        cout << "Dosya acilamadi, Yanlis konum veya yanlis dosya adi...";
        return -1;
    }


    while(getline (dosya, satir)) {



        stackArr = new Stack[20];


        stackArrIndex = 0;
        /** Bir satırı stack'lere doldurmak */
        string sayi;
        stringstream satirAyirici(satir);
        while (getline(satirAyirici, sayi, ' ')) {
            int intsayi = stoi(sayi);

            if(stackArr[stackArrIndex].isEmpty()){
                stackArr[stackArrIndex].push(intsayi);
                continue;
            }

            if(intsayi % 2 == 0 && stackArr[stackArrIndex].top() < intsayi){
                stackArrIndex++;
            }

            stackArr[stackArrIndex].push(intsayi);

        }


        /** Tüm stackleri BST'lere dağıtmak */
        binarySearchTreeArr = new BinarySearchTree[stackArrIndex + 1];

        int lastIndex = stackArrIndex;
        while (stackArrIndex >= 0){

            binarySearchTreeArr[lastIndex - stackArrIndex] = BinarySearchTree();

            while(!stackArr[stackArrIndex].isEmpty()){
                binarySearchTreeArr[lastIndex - stackArrIndex].insert
                (
                        stackArr[stackArrIndex].pop()
                        );
            }
            stackArrIndex--;
        }

        /** BST'ler içinden en fazla height'a sahip olan BST'yi çekmek.
         * Eğer heightlar eşit ise, eleman toplamı en yüksek olan BST'yi çekmek.
         */
        int enBuyukIndex = 0;

        for (int i = 1; i < lastIndex + 1; i++)
        {
            if (binarySearchTreeArr[i].calculateHeight() > binarySearchTreeArr[enBuyukIndex].calculateHeight())
                enBuyukIndex = i;
            else if(binarySearchTreeArr[i].calculateHeight() == binarySearchTreeArr[enBuyukIndex].calculateHeight()){

                if(binarySearchTreeArr[i].totalOfElements > binarySearchTreeArr[enBuyukIndex].totalOfElements){
                    enBuyukIndex = i;
                }
            }

        }

        // En fazla height'a sahip olan BST'yi postorder şekilde yazdırma
        binarySearchTreeArr[enBuyukIndex].postorderYazdirma();

        cout << "\n";
        sleep(0.001);

    }

    dosya.close();


    return 0;
}
