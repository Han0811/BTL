#ifndef BOSUNG_H
#define BOSUNG_H

#include <string>
#include <iostream>
#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
using namespace std;
// Cấu trúc dữ liệu về viện phí
struct Vienphi {
    Benh_nhan BN;
    int DK, MK, YK;
    DSDV DV;
    DSThuoc T;
    long Tong_VP;
};
struct NODEVP{
    Vienphi VP;
    NODEVP* nextVP;
};
typedef NODEVP* DSVP;
typedef NODEVP* VPNODE;

//Them
long SumBN(DSBN dsbn);
long SumDV(DSDV dsdv);
long tonggiaT(THUOC S);
long sumT(DSThuoc S);
void printfDV(DSDV dsdv);
void printfT(DSThuoc S);
//void printfBN(DSBN S);
void SuaxoaBN(DSBN &S);
void Hienthi();//Các dánh sách quan lý
void Hienthi1();//Các thao tác đối với danh sách
void Hienthi2();
void Hienthi3();
void Dapung(DSBN& dsbn, DSThuoc S, DSDV dsdv, DSBS dsbs);
#endif
