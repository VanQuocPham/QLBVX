#include<string.h>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std ;
int n,m;
// XAY DUNG CLASS KHACH HANG (HOTEN, TUOI, DIACHI, SODIENTHOAI)
class KhachHang{
	protected:
	    string hoten;
	    string tuoi;
	    string dc;
	    string sdt;
	    string id;
	public:
		void nhap();		
};
// HAM NHAP 
void KhachHang::nhap(){
cin.ignore();
	cout<<"\n\t\t\t------------------Nhap thong tin khach hang---------------"<<endl;
	cout<<"\n\t Nhap ma khach hang: ";
	getline(cin, id);
 	cout<<"\n\t Nhap ho ten khach hang: ";
 	getline(cin, hoten);
 	cout<<"\n\t Nhap tuoi khach hang: ";
    getline(cin, tuoi);
 	cout<<"\n\t Nhap dia chi khach hang: ";
    fflush(stdin);
	getline(cin, dc);
 	cout<<"\n\t Nhap so dien thoai khach hang: ";
    getline(cin, sdt);
}
// XAY DUNG CLASS THONG TIN VE KE THUA TU CLASS KHACH HANG.
class Thong_Tin_Ve : public KhachHang{
private:
		string ngay_thang_di;
		string gio_di;
		string vi_tri_don;
	    int loaive;
		float gia_ve;	
		int tuyen_duong;
public :
	    void nhapv();
virtual	void xuatv();
		void tien_ve();
virtual	void ghi_file(ofstream &fileout);
virtual void doc_flie(ifstream &filein);
virtual   void dskh();
	    void them_khach_hang();
	    
};
void Thong_Tin_Ve::nhapv() {
	cout << "\n\n\tTuyen Duong: ";
	cout << "\n\t\t1. DA NANG - TPHCM.";      
	cout << "\n\t\t2. DA NANG - QUANGBINH.";
	cout << "\n\t\t3. DA NANG - QUANG TRI.";  
	cout << "\n\t\t4. DA NANG - HA TINH.";    
	cout << "\n\t\t5. DA NANG - NGHE AN.";    
	cout<<"\n\tNhap tuyen duong: "; 
    cin>>tuyen_duong;cin.ignore();
	nhap();
	
	cout<<"\n\tNhap ngay thang di: ";
	getline(cin,ngay_thang_di);
	cout<<"\n\tNhap gio xe chay: ";
	getline(cin,gio_di);
	cout<<"\n\tNhap vi tri don:";
 	getline(cin, vi_tri_don);
 	cout<<("\n\tLoai ve:\n1.Vip.\n2.Thuong. ")<<endl;
	cout<<"Chon 1 hoac 2: "<<endl;
 	cin>>loaive;
}
// HAM XUAT VE
void Thong_Tin_Ve::xuatv(){
    cout<<endl<<left<<"\n\tHo va ten: "<<setw(20)<<hoten<<"Tuoi: "<<setw(20)<<tuoi;
    cout<<endl<<left<<"\n\tDia chi: "<<setw(20)<<dc<<"So Dien Thoai: +84"<<setw(20)<<sdt;
    cout<<endl<<left<<"\n\tLoai ve: ";
    if(loaive =='1'){
    	cout<<setw(20)<<"Vip.";
	}
	else
	cout<<setw(20)<<"Thuong";
	cout<<endl<<left<<"\n\tNgay khoi hanh: "<<setw(20)<<ngay_thang_di<<"Den truoc: "<<setw(20)<<gio_di;
	cout<<endl<<left<<"\n\tDia diem don: "<<setw(20)<<vi_tri_don;
}
// HAM TINH TIEN VE	
void Thong_Tin_Ve:: tien_ve () {
		int km;
		float giave;
		float tong_tien_ve;
    cout<<"\n\t\t\t\t\tBEN XE TRUNG TAM TP DA NANG";
    cout<<"\n\t\t\t\tDia chi: Ton Duc Thang, Hoa Minh Lien Chieu, Da Nang";
	cout<<"\n\n\t\t\t=======================THONG TIN KHACH HANG===========================\n";
    cout<<endl<<left<<"\n\n\tSTT: "<<setw(20)<<id;
	switch (tuyen_duong){
	// DN - TPHCM
	  case 1:
	  	  km = 960;
	  	  cout<<endl<<left<<setw(20)<<"\tTuyen Duong: DA NANG - TPHCM.";
	  	  xuatv();
	  	  	giave= (long)(km*0.5);
		if (loaive==1){
			gia_ve= giave+giave*0.2;
			cout<<"\tGiave: "<<	gia_ve<<"000 VND";
		}
		else {
				gia_ve=giave;
			cout<<"\tGiave: "<<gia_ve<<"000 VND";
		} 
		break;
	// DM- QB
	  case 2:
	      km = 271;
		  cout<<endl<<left<<setw(20)<<"\tTuyen xe: DA NANG - QUANG BINH. ";
		  xuatv();
		  	giave= (long)(km*0.5);
		if (loaive==1){
			gia_ve= giave+giave*0.2;
			cout<<"\t\tGiave: "<<gia_ve<<"000 VND";
		}
		else {
				gia_ve=giave;
			cout<<"\t\tGiave: "<<	gia_ve <<"000 VND";
		}  
		break;
        //DN - QT
        case 3: 
            km = 179;
            cout<<"\tTuyen xe: DA NANG - QUANG TRI. ";
            xuatv();
            giave= (long)(km*0.5);
        if (loaive==1){
        	gia_ve= giave+giave*0.2;
			cout<<"\t\tGiave: "<< gia_ve <<"000 VND";
		}
		else {
			gia_ve=giave;
			cout<<"\t\tGiave: "<<	gia_ve <<"000 VND";
        }
        break;
        // DN - HT
        case 4: 
         km= 419;
         cout<<"\tTuyen xe: DA NANG - HA TINH. ";
         xuatv();
         	giave= (long)(km*0.5);
        if (loaive==1){
        	gia_ve= giave+giave*0.2;
			cout<<"\t\tGiave: "<<gia_ve<<"000 VND";
		}
		else {
			gia_ve=giave;
			cout<<"\t\tGiave: "<<gia_ve<<"000 VND";
        } 
        break;
        // DN - NA
        case 5:
        	km = 468;
        	cout<<"\tTuyen xe: DA NANG - NGHE AN. ";
        	xuatv();
        	giave= (long)(km*0.5);
        if (loaive==1){
        	gia_ve= giave+giave*0.2;
			cout<<"\t\tGiave: "<< gia_ve <<"000 VND";
		}
		else {
			gia_ve=giave;
			cout<<"\t\tGiave: "<<gia_ve<<"000 VND"<<endl;
        }
        break;
   }
}
void Thong_Tin_Ve::them_khach_hang(){
	Thong_Tin_Ve kh1;
	kh1.nhapv();
	kh1.tien_ve();
}
void Thong_Tin_Ve::ghi_file(ofstream &fileout){
	
	nhapv();
	tien_ve();
    fileout<<id<<","<<tuyen_duong;
	fileout<<","<<hoten<<","<<tuoi<<","<<dc<<","<<sdt<<","<<loaive;
	fileout<<","<<ngay_thang_di<<","<<gio_di<<","<<vi_tri_don<<","<<gia_ve<<endl;
}
void Thong_Tin_Ve::doc_flie(ifstream &filein){
	//1
	//A1,TuyenXe:1,Hovaten:Pham Van Quoc,Tuoi:20,DiaChi:Quang Nam,SDT:0886689815,LoaiVe:1,NgayKhoiHanh:17/06/2021,GioKhoiHanh:18h30,DiemDon:Ben Xe,GiaVe:576
	char p;
	getline(filein,id,',');
    filein>>tuyen_duong;
    filein>>p;
	getline(filein,hoten,',');
    getline(filein,tuoi,',');
	getline(filein,dc,',');
	getline(filein,sdt,',');
    filein>>loaive;
    filein >>p;
	getline(filein,ngay_thang_di,',');
	getline(filein,gio_di,',');
	getline(filein,vi_tri_don,',');
    filein>>gia_ve;
}
void Thong_Tin_Ve::dskh(){
	cout<<"\nSTT: "<<id;
	cout<<"\nTuyen xe:"<<tuyen_duong;
	cout<<"\nHo va ten: "<<hoten;
	cout<<"\nTuoi: "<<tuoi;
	cout<<"\nDia chi: "<<dc;
	cout<<"\nSDT: "<<sdt;
	cout<<"\nLoai Ve: "<<loaive;
	cout<<"\nNgay khoi hanh: "<<ngay_thang_di;
	cout<<"\nGio khoi hanh: "<<gio_di;
	cout<<"\nDIem don: "<<vi_tri_don;
	cout<<"\nGia ve: "<<gia_ve;
}
void menu(Thong_Tin_Ve *kh[], int n){
	ifstream filein;
	ofstream fileout;
	while(true)
	{
		system("cls");
	cout<<"\n\t*********************************************************";
    cout<<"\n\t*                                                       *";
    cout<<"\n\t*                                                       *";
    cout<<"\n\t*             QUAN LY KHACH HANG                        *";
    cout<<"\n\t*                                                       *";
    cout<<"\n\t*  1. Nhap va xuat thong tin ve cua khach hang          *";
    cout<<"\n\t*  2. Them khach hang.                                  *";
    cout<<"\n\t*  3. Sua hoac xoa thong tin khach hang.                *";
    cout<<"\n\t*  4. Nhap thong tin khach hang vao file Khachhang.txt  *"; 
    cout<<"\n\t*  5. Doc thong tin khach hang tu file   Khachhang.txt  *";
    cout<<"\n\t*  6. Xuat danh sach khach hang                         *";
    cout<<"\n\t*  7. Exit                                              *";                                         
    cout<<"\n\t*                                                       *";
    cout<<"\n\t*********************************************************";
	
	int luachon;
    cout<<"\n\nLua chon cong viec tuong ung: ";  cin>>luachon;
	switch (luachon){
		Thong_Tin_Ve *x;
		case 1:
			{
				   
		        int temp;
	            cout<<"Loai ve mua: "<<"\n1. Mua le."<<"\n2. Mua Tap The.";
	            cout<<"\nNhap: ";
	            cin>>temp;
	            if (temp == 1){
		        for (int i=0; i<1; i++){
		          x= new Thong_Tin_Ve();
			      x -> nhapv();
			      x -> tien_ve();

	}
	}
	            if (temp == 2){
		        int n;
		        cout<<"Nhap so ve can mua: "; cin>>n;
		        for (int i=0; i<n; i++){
		        x= new Thong_Tin_Ve();
			    x -> nhapv();
			    x -> tien_ve();
		} 
	}	system("pause");
	cout<<"\n-------------------------------------------------------------------------------------------\n";
		
		}break ;
			
		case 2: 
		    {
		    	cout<<"\n\tBan muon them bao nhieu khach hang: ";cin>>n;
	           for (int i=0; i<n; i++){
	  	       kh[i] -> them_khach_hang();
				 }  
			} system("pause");
			break;
		//case 3: 
		case 4: 
		{ 
		  fileout.open("Khachhang.txt",ios_base::out);
		  cout<<"\n Nhap so luong khach hang can ghi vao File: ";
		  cin>>n; fileout <<n<<"\n";
		  for(int i =0; i< n; i++){
			cout<<"\n Nhap thong tin khach hang thu "<<i+1;
			x = new Thong_Tin_Ve();
			x -> ghi_file(fileout);
			}
			fileout.close();
			system("pause");
		}break;
		case 5: 
		{
			filein.open("Khachhang.txt",ios_base::in);
			filein>>n; char p; 
			for (int i =0; i< n; i++)
			{
				x = new Thong_Tin_Ve();
				x -> doc_flie(filein);
				kh[i]=x;
		}filein.close();
		cout<<"\nDa doc thanh cong\n";
		
		system("pause");
	  }break;
	    case 6: 
	    {
	    	cout<<"\n\t\t===============Thong tin khach hang=====================\t";
	    	for(int i=0; i<n; i++){
	    	cout<<"\n\tKhach hang thu "<<i+1;
	    	   kh[i] -> dskh();
			}
			cout<<endl;
			system("pause");
		}break;
		case 7: {
			exit(1);
			
		}break;
	}		
 }
}

int main () {
	Thong_Tin_Ve *kh[50];
	int n;
	menu(kh,n);
	return 0;
}
