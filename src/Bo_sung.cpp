#include <string>
#include "BOSUNG.h"

using namespace std;
long SumBN(DSBN S){
	return S->BN.DV->TongtienDV + S->BN.T->TongtienT;
}

long SumDV(DSDV S){
	long a = 0;
	DSDV p = S;
	while(p != NULL){
		a += p->DV.Gia_DV;
		p = p->nextDV;
	}
	return a;
}

long tonggiaT(THUOC S) {
    return S.Gia_thuoc * S.so_luong;
}

long sumT(DSThuoc S) {
    long total = 0;
    NodeT p = S;
    while (p != NULL) {
        total += p->T.Gia_thuoc * p->T.so_luong;
        p = p->nextT;
    }
    return total;
}

void printfDV(DSDV S) {
     if(S == NULL){
        cout<<"Danh sach dich vu rong"<<endl;
        return;
    }
    S->TongtienDV = SumDV(S);
    int n = 0;
    DSDV P = S;
    while (P != NULL) {
        P = P->nextDV;
        n++;
    }

    DSDV R = S;
    string arr[100][3];

    // Assigning headers to the array
    arr[0][0] = "STT";
    arr[0][1] = "Ten";
    arr[0][2] = "Thanh tien";

    // Assigning values to the array
    for (int i = 1; i <= n; i++) {
        arr[i][0] = to_string(i);
        arr[i][1] = R->DV.Ten_DV;
        arr[i][2] = to_string(R->DV.Gia_DV);
        R = R->nextDV;
    }

    // Printing the array
    for (int j = 0; j <= n; j++) {
        for (int k = 0; k < 3; k++) {
            cout << arr[j][k] << "\t";
        }
        cout << endl;
    }
    cout << "Tong tien: " << S->TongtienDV << endl;
}

void printfT(DSThuoc S) {
    if(S == NULL){
        cout<<"DS Thuoc rong"<<endl;
        return;
    }
    S->TongtienT = sumT(S);
    int n = 0;
    NodeT P = S;
    while (P != NULL) {
        P = P->nextT;
        n++;
    }

    NodeT R = S;
    string arr[100][6];

    // Gán tiêu d? cho m?ng
    arr[0][0] = "STT";
    arr[0][1] = "Ma";
    arr[0][2] = "Ten";
    arr[0][3] = "Gia";
    arr[0][4] = "So luong";
    arr[0][5] = "Thanh tien";

    // Gán giá tr? cho m?ng
    for (int i = 1; i <= n; i++) {
        arr[i][0] = to_string(i);
        arr[i][1] = to_string(R->T.Ma_thuoc);
        arr[i][2] = R->T.Ten_thuoc;
        arr[i][3] = to_string(R->T.Gia_thuoc);
        arr[i][4] = to_string(R->T.so_luong);
        arr[i][5] = to_string(tonggiaT(R->T));
        R = R->nextT;
    }
    cout << "\tDanh Sach Thuoc" << endl;
    for (int j = 0; j <= n; j++) {
        for (int k = 0; k < 6; k++) {
            cout << arr[j][k] << "\t";
        }
        cout << endl;
    }
    cout << "Tong tien: " << S->TongtienT << endl;
}

// void printfBN(DSBN S) {
//     cout << "\n\tThong tin benh nhan:" << endl;
//     if (S == NULL) {
//         cout << "Danh sach benh nhan rong." << endl;
//         return;
//     }
    
//     DSBN R = S;
//     const int numRows = 3;
//     const int numCols = 2;

//     while (R != NULL) {
//         string arr[numRows][numCols];
//         arr[0][0] = "Ho ten: " + R->BN.Ho_tenBN;
//         arr[0][1] = "Gioi tinh: " + R->BN.Gioi_tinh;
//         arr[1][0] = "Tuoi: " + to_string(R->BN.Tuoi);
//         arr[1][1] = "CCCD: " + R->BN.CCCD;
//         arr[2][0] = "SDT: " + R->BN.SDT;
//         arr[2][1] = "Que: " + R->BN.Que;

//         for (int j = 0; j < numRows; j++) {
//             for (int k = 0; k < numCols; k++) {
//                 cout << arr[j][k] << "\t";
//             }
//             cout << endl;
//         }
//         cout << "Bao hiem: " << R->BN.Bao_hiem << endl;
//         cout << "\tDanh Sach Dich Vu\n";
//         printfDV(R->BN.DV);
//         printfT(R->BN.T);
//         cout << "Tong vien phi: " << SumBN(S) << endl;
//         if(R->BN.Bao_hiem == 1){
//         	cout << "Phai tra: " << (SumBN(S)*20)/100;
// 		}else{
// 			cout << "Phai tra: " << SumBN(S);
// 		}
//         R = R->nextBN;
//     }
// }

//sua xoa
void SuaxoaBN(DSBN &S){
    int check ;
    do{
	    string a;
	    cout << "Nhap cccd cua BN muon duoc sua: " ; cin >> a;
	    BNNODE p = NULL;
	    while(p == NULL){
		    cout << "Nhap lai cccd: " ; cin >> a;
		    p = FindBN(S,a);
	    }
	
	    int x;
	    cout << "0.Xoa\n1.Thong tin\n2.Dich vu\n3.Thuoc\n";
	    cin >> x; 
	    while(x < 0 || x > 3){
		    cout << "Nhap lai: "; cin >> x;
	    }
	    switch(x){
		    case 0: {
			    DeleteBN(S,a);
			    break;
		    }
		    case 1:{
			    FixBN(S,a);
			    break;
		    }
		    case 2:{
//			cout << "0."
			    break;
		    }
		    case 3:{
			    int x;
			    while(x == 1){
			    int i;
			    cout << "Nhap ma thuoc: "; cin >> i;
			    NodeT r = NULL;
			    while(r == NULL){
				    cout << "Nhap lai ma: " ; cin >> i;
				    r = FindT(p->BN.T,i);
			    }
			    int y;
			    cout << "0.Xoa\n1.Sua\n"; cin >> y;
			    while(y != 0 && y != 1){
				    cout << "Nhap lai: "; cin >>y;
		    	}
			    switch(y){
			    	case 0:{
				    	DeleteT(p->BN.T,i);
				    	break;
			    	}
				    case 1:{
					    FixT(p->BN.T,i);
				    	break;
				    }
			    }
			    cout << "0.khong\n1.\nSua tiep\n"; cin >> x;
			    while(x != 0 && x != 1){
				    cout << "Nhap lai: "; cin >> x;
			    }
			    }
			    break;
		    }
        }
        cout << "\n\tThong tin benh nhan sau khi sua:" << endl;
        printfBN(S);
        cout << "Co tiep tuc sua nua khong:(1. Co , 2. Khong)"<<endl;
        cin >> check;
	} while (check);	
}
void Hienthi(){
    cout<<"\n\tChon cac chuc nang"<<endl;
    cout<<"1. Benh nhan"<<endl;
    cout<<"2. DSDV"<<endl;
    cout<<"3. DSBS"<<endl;
    cout<<"4. DS Thuoc"<<endl;
    
    return; 
}
void Hienthi1(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Nhap thong tin benh nhan"<<endl;
    cout<<"2. Sua thong tin benh nhan"<<endl;
    cout<<"3. Nhap thuoc cho benh nhan"<<endl;
    cout<<"4. In ra thong tin BN"<<endl;
    
}
void Hienthi2(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem DS dich vu"<<endl;
    cout<<"2. Nhap them dich vu "<<endl;
    return;
}
void Hienthi3(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem DS bac si"<<endl;
    cout<<"2. Nhap them bac si(Private)"<<endl;
    return;
}
void Dapung(DSBN& dsbn,DSThuoc S,DSDV dsdv,DSBS dsbs){
    int x;
    do{
        Hienthi();
        cin>>x;
        switch(x){
            case 1:{
                int y;
                Hienthi1();
                cin>> y ; 
                switch(y){
                    case 1: InsertBN(dsbn , S , dsdv);break;
                    case 2: SuaxoaBN(dsbn);break;
                    case 3:{
                        string cccd;
                        cout<<"Nhap ma cccd Benh nhan: ";
                        cin>>cccd;
                        NhapThuoc(dsbn,S,dsdv,FindBN(dsbn,cccd));
                        break;
                    }
                    case 4: printfBN(dsbn);break;
                }
                break;
            }
            case 2:{
                int y;
                Hienthi2();
                cin>> y;
                switch(y){
                    case 1:printfDV(dsdv);break;
                    case 2:NhapDichVu(dsdv);break;
                }
                break;
            }
            case 3:{
                int y;
                Hienthi3();
                cin>>y;
                switch(y){
                    case 1:PrintBS(dsbs);break;
                    case 2:InsertBS(dsbs);break;
                }
            }
            case 4:printfT(S);break;
        }
    } while(1);
}