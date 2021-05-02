#ifdef _WIN32
  #include<windows.h>
#endif 

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Declaracion de variables de forma  global
int pPendientes=0, contador=0, GolMiEquipo=0;
int PG=0, PP=0, PE=0, puntosMiEquipo=0;
int golContrario=0, rangoGoles=5;
string equipo = "FC Barcelona";
//declaracion del metodo Jugadas() y LimpiarPantalla()
void Jugadas();
void LimpiarPantalla();

int main(){
	
	srand(time(NULL));
	int Continuar=0;
	
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"Prediccion de resultados de la UEFA CHAMPIONS LIGUE"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<endl;
	//Ciclo Do While para realizar nuevas predicciones "n" numero de veces
	do{
		Jugadas();	
		cout<<"Desea realizar otra prediccion ?   Si = 0        No = 1 : ";
		cin>>Continuar;
		cout<<endl;
		
			if(Continuar==0){
				LimpiarPantalla();	
			}
	
	}while(Continuar==0);
		
	return 0;			
}

//Metodo para la logica de las predicciones de los partidos
void Jugadas(){
	
	cout<<"Ingrese los partidos pendientes por jugar: ";
		cin>>pPendientes;
		//Ciclo for para evaluar cada partido pendiente jugado
		for(int i = 1; i<=pPendientes; i++){
			cout<<"\nPartido #: "<<i<<endl;
			//ciclo for para evaluar la cantidad de goles que meta cada equipo
			for(int j =1; j<=rangoGoles; j++){
				contador= rand() % 2;
				if(contador == 0){
					cout<<"Goooool del "<<equipo<<"! \n";
					GolMiEquipo++;	
						
				}else{
					cout<<"Goooool del Contrario! \n";
					golContrario++;
				}
				
			}
			
			cout<<"\n-------------------------------"<<endl;
			cout<<"Tabla de resultados del partido"<<endl;
			cout<<"-------------------------------"<<endl;
			cout<<equipo<<"("<<GolMiEquipo<<")"<<" - "<<"Equipo Contrario"<<"("<<golContrario<<")"<<endl;
			
			//Condicion if para validar si un equipo gana, pierde o empata	
			if(GolMiEquipo > golContrario){
				cout<<"\n** Gana el "<<equipo<<" - Visca Barca !! **"<<endl;
					puntosMiEquipo += 3;
						PG +=1;	
							GolMiEquipo = 0;
								golContrario = 0;
				
				}else if(GolMiEquipo < golContrario){
						cout<<"\n** Gana el Equipo Contrario!! **"<<endl;
							puntosMiEquipo += 0; 
								PP +=1;
									GolMiEquipo = 0;
										golContrario = 0;
					
					}else{
						cout<<"\n** El partido termina en Empate!! **"<<endl;
							puntosMiEquipo += 1;
								PE +=1;
									GolMiEquipo = 0;
										golContrario = 0;
			}
			cout<<"________________________________"<<endl;	
		}
		
		cout<<endl;
		cout<<"**********************************************"<<endl;
		cout<<"              TABLA DE PUNTOS                 "<<endl;
		cout<<"|____________________________________________|"<<endl;
		cout<<"|   Equipo       PJ   PG   PP   PE   Puntos  |"<<endl;
		cout<<"|____________________________________________|"<<endl;
		cout<<"|"<<equipo<<"    "<<pPendientes<<"    "<<PG<<"     "<<PP<<"    "<<PE<<"      "<<puntosMiEquipo<<"    |"<<endl;
		cout<<"|--------------------------------------------|"<<endl;
		cout<<endl;
		//finalizamos las varibles en 0 por si se desea realizar una nueva prediccion
		PG=0;
		PP=0;
		PE=0;
		puntosMiEquipo=0;
}

//metodo para limpiar pantalla en consola
void LimpiarPantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
