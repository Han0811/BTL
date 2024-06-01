#include <iostream>
#include <string>
#include "DICHVU.h"

using namespace std;
void InitDV(DSDV& dsdv){
    dsdv = NULL;
}
void DeleteDV(DSDV& dsdv, string serviceName) {
    DVNODE prevNode = 0;
    DVNODE currentNode = dsdv;
    while (currentNode != 0) {
        if (currentNode->DV.Ten_DV == serviceName) {
            if (prevNode == 0) {
                dsdv = currentNode->nextDV;
            } else {
                prevNode->nextDV = currentNode->nextDV;
            }
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->nextDV;
    }
    cout << "Khong tim tahy dich vu." << endl;
}

// tim kiem dich vu
Dich_vu FindDV(DSDV dsdv, string serviceName) {
    DVNODE currentNode = dsdv;
    while (currentNode != 0) {
        if (currentNode->DV.Ten_DV == serviceName) {
            return currentNode->DV;
        }
        currentNode = currentNode->nextDV;
    }
    
    Dich_vu defaultService;
    defaultService.Ten_DV = "Khong tim thay dich vu";
    return defaultService;
}

// sap xep dich vu theo gia tang dan
void ArrangeDV(DSDV& dsdv) {
    DVNODE currentNode = dsdv;
    while (currentNode != 0) {
        DVNODE nextNode = currentNode->nextDV;
        while (nextNode !=0) {
            if (currentNode->DV.Gia_DV > nextNode->DV.Gia_DV) {
                swap(currentNode->DV, nextNode->DV);
            }
            nextNode = nextNode->nextDV;
        }
        currentNode = currentNode->nextDV;
    }
}
// Th?m dich vu moi
void InsertDV(DSDV& dsdv, Dich_vu newService) {
    DVNODE newNode = new NODEDV;
    newNode->DV = newService;
    newNode->nextDV = dsdv;
    dsdv = newNode;
}
// Sua thong tin dich vu
void FixDV(DSDV& dsdv, string serviceName, long newPrice) {
    DVNODE currentNode = dsdv;
    while (currentNode != 0) {
        if (currentNode->DV.Ten_DV == serviceName) {
            currentNode->DV.Gia_DV = newPrice;
            return;
        }
        currentNode = currentNode->nextDV;
    }
    cout << "khong tim thay dich vu." << endl;
}

// Nhap thong tin dich vu
void NhapDichVu(DSDV& dsdv) {
    int x = 1;
    while(x==1){
        cin.ignore();
	    Dich_vu newService;
        cout << "Nhap ten dich vu: ";
        getline(cin,newService.Ten_DV);
        cout << "Nhap gia dich vu: ";
        cin >> newService.Gia_DV;
        InsertDV(dsdv, newService);
        cout << "0.khong , 1.nhap tiep: " ; cin >> x;
        while(x != 1 && x !=0){
    	    cout << "Nhap lai: " ; cin >> x;
	    }
    }
}