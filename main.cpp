#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

int main() {
    DSBN dsbn = NULL;
    DSDV dsdv = NULL;
    DSThuoc S = NULL;
    DSBS dsbs = NULL;
    Bac_si A = {"Hoang Anh","Bac si",10000};
    Bac_si B = {"Tuan","Bac si",10000};
    Bac_si C = {"An" ,"Bac si",10000};
    Bac_si D = {"Can","Bac si",10000};
    InsertBSS(dsbs,A);
    InsertBSS(dsbs,B);
    InsertBSS(dsbs,C);
    InsertBSS(dsbs,D);
    InitBN(dsbn);
    Dapung(dsbn,S,dsdv,dsbs);
    return 0;
}