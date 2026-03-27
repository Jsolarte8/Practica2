#include <iostream>
using namespace std;

// -------- PROBLEMA 1 --------
void problema1(){
    int dinero;
    int b[]={50000,20000,10000,5000,2000,1000,500,200,100,50};

    cout<<"Dinero: ";
    cin>>dinero;

    for(int i=0;i<10;i++){
        int c = dinero / b[i];
        cout<<b[i]<<" : "<<c<<endl;
        dinero %= b[i];
    }
    cout<<"Faltante: "<<dinero<<endl;
}

// -------- PROBLEMA 3 --------
bool comparar(char *a,char *b){
    int i=0;
    while(a[i] && b[i]){
        if(a[i]!=b[i]) return false;
        i++;
    }
    return (a[i]==b[i]);
}

void problema3(){
    char a[100],b[100];
    cout<<"Cadena 1: ";
    cin>>a;
    cout<<"Cadena 2: ";
    cin>>b;

    if(comparar(a,b)) cout<<"Iguales\n";
    else cout<<"Diferentes\n";
}

// -------- PROBLEMA 5 --------
void convertir(int n,char *cad){
    int i=0;
    while(n>0){
        cad[i]=(n%10)+'0';
        n/=10;
        i++;
    }
    cad[i]='\0';

    for(int j=0,k=i-1;j<k;j++,k--){
        char t=cad[j]; cad[j]=cad[k]; cad[k]=t;
    }
}

void problema5(){
    int n; char cad[20];
    cout<<"Numero: ";
    cin>>n;
    convertir(n,cad);
    cout<<"Cadena: "<<cad<<endl;
}

// -------- PROBLEMA 7 --------
void eliminar(char *c,char *r){
    int k=0;
    for(int i=0;c[i];i++){
        bool rep=false;
        for(int j=0;j<k;j++)
            if(c[i]==r[j]) rep=true;

        if(!rep) r[k++]=c[i];
    }
    r[k]='\0';
}

void problema7(){
    char c[100],r[100];
    cout<<"Cadena: ";
    cin>>c;
    eliminar(c,r);
    cout<<"Sin repetidos: "<<r<<endl;
}

// -------- PROBLEMA 9 --------
int suma(char *c,int n){
    int total=0;
    for(int i=0;c[i];i+=n){
        int num=0;
        for(int j=0;j<n && c[i+j];j++)
            num = num*10 + (c[i+j]-'0');
        total+=num;
    }
    return total;
}

void problema9(){
    char c[100]; int n;
    cout<<"Cadena: ";
    cin>>c;
    cout<<"n: ";
    cin>>n;
    cout<<"Suma: "<<suma(c,n)<<endl;
}

// -------- PROBLEMA 11 --------
void mostrar(int *m){
    for(int i=0;i<15;i++){
        for(int j=0;j<20;j++){
            if(*(m+i*20+j)==0) cout<<"- ";
            else cout<<"+ ";
        }
        cout<<endl;
    }
}

void problema11(){
    int sala[15][20]={0};
    mostrar(&sala[0][0]);
}

// -------- PROBLEMA 13 --------
int estrellas(int *m,int f,int c){
    int cont=0;

    for(int i=1;i<f-1;i++){
        for(int j=1;j<c-1;j++){
            int s = *(m+i*c+j)
            + *(m+i*c+j-1)
                + *(m+i*c+j+1)
                + *(m+(i-1)*c+j)
                + *(m+(i+1)*c+j);

            if(s/5 > 6) cont++;
        }
    }
    return cont;
}

void problema13(){
    int m[6][8]={
        {0,3,4,0,0,0,6,8},
        {5,13,6,0,0,0,2,3},
        {2,6,2,7,3,0,10,0},
        {0,0,4,15,4,1,6,0},
        {0,0,7,12,6,9,10,4},
        {5,0,6,10,6,4,8,0}
    };

    cout<<"Estrellas: "<<estrellas(&m[0][0],6,8)<<endl;
}

// -------- PROBLEMA 15 --------
int max(int a,int b){ return (a>b)?a:b; }
int min(int a,int b){ return (a<b)?a:b; }

void inter(int *A,int *B,int *C){
    int x1=max(A[0],B[0]);
    int y1=max(A[1],B[1]);
    int x2=min(A[0]+A[2],B[0]+B[2]);
    int y2=min(A[1]+A[3],B[1]+B[3]);

    if(x2>x1 && y2>y1){
        C[0]=x1;
        C[1]=y1;
        C[2]=x2-x1;
        C[3]=y2-y1;
    }
}

void problema15(){
    int A[4]={0,0,8,4};
    int B[4]={5,2,6,7};
    int C[4];

    inter(A,B,C);

    cout<<"Interseccion: ";
    for(int i=0;i<4;i++) cout<<C[i]<<" ";
    cout<<endl;
}

// -------- PROBLEMA 17 --------
int sumaDiv(int n){
    int s=0;
    for(int i=1;i<n;i++)
        if(n%i==0) s+=i;
    return s;
}

void problema17(){
    int n;
    cout<<"Numero: ";
    cin>>n;

    int total=0;

    for(int i=1;i<n;i++){
        int a=sumaDiv(i);
        if(a!=i && sumaDiv(a)==i)
            total+=i;
    }

    cout<<"Suma: "<<total<<endl;
}