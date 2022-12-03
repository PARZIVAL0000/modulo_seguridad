#include <iostream>
#include <unistd.h>
#include <cmath>
#include <stdlib.h> //ejecutamos funciones para salir del programa.....

using namespace std;

bool verificarNumeros(bool numero1, bool numero2){

    if(numero1 > 0 && numero2 > 0){
        return true;
    }else{
        return false;
    }
}


int main()
{
    //modulo de seguridad

    //estos son como los datos guardados en la base de datos.
    string nombres[] = {"Dennis", "Juan"};
    string passwords[] = {"Dennis1234", "Juan1234"};

    string usuario;
    string upass;





    //credenciales ingresados por el usuario.


    //que el usuario solamente tenga tres intentos para poder ingresar sus credenciales.
    int intentos = 3;

    int i = 0;

    do{
        /*
            ==================================================================
            [*]            VAMOS A PROCESAR LAS CREDENCIALES
            ==================================================================
        */

            //PEDIR CREDENCIALES....
            cout << "\n[>] Introduce tu nombre: "; cin >> usuario;
            cout << "\n[>] Introduce tu password: "; cin >> upass;


            string *nombre_;
            string *password_;
            int flag = 0;

            //Vamos usar una variable llamada --flag--... si es dos es porque las credenciales son correctas.
            //Si es 1 entonces las credenciales no son correctas....
            //usaremos esto para poder ingresar al sistema...
            for(int i = 0; i < sizeof(nombres) / sizeof(nombres[0]); i++){
                    nombre_ = &nombres[i];

                    if(usuario == *nombre_){
                        flag += 1; //si esta correcto el nombre aumentamos uno
                    }

            }

            for(int j = 0; j < sizeof(passwords) / sizeof(passwords[0]); j++){
                password_ = &passwords[j];

                if(upass == *password_){
                    flag += 1;
                }
            }


        /*
            =================================================================
            [*]             VAMOS A PROCESAR LAS CREDENCIALES
            =================================================================
        */


        //si bandera es igual a 2 .... credenciales correctas

        /* ==================================
           [*]  ACCEDEMOS AL SISTEMA
           ==================================
        */
        if(flag == 2){

            intentos = 0; //para salir del bucle

            system("clear");

            cout << "*********************************************" << endl;
            cout << "       [1] HACER FORMULA                     " << endl;
            cout << "       [2] CALCULADORA BASICA                " << endl;
            cout << "       [3] SALIR                             " << endl;
            cout << "*********************************************" << endl;


            //Definiremos unas variables para escuchar por otras entradas del usuario.
            char entrada, operador;
            char salir = 'N';
            bool preguntar = true;
            bool p = true;
            double numero1, numero2 = 0.0;

            //variables para calcular nuestra formula.
            int x = 0;
            int y = 0;
            int divisibles, resultado;
            int exponente = 0;

            while(preguntar){

                cout << "\n\n[>] Introduce tu opcion: "; cin >> entrada;


                switch(entrada){
                    case '1':
                        preguntar = false;

                        system("clear");
                        //Calcularemos una formula que nosotros queramos...
                        cout << "\n\t*******************************************" << endl;
                        cout << "\t* BIENVENIDO A NUESTRO JUEGO DE FORMULA   *" << endl;
                        cout << "\t*******************************************" << endl;

                        cout << "\n[>] Introduce un valor para X: "; cin >> x;
                        cout << "\n[>] Introduce un valor para Y: "; cin >> y;

                        //Al principio nuestras dos incognitas van a estar con raiz de sexta....

                        //nuestras dos incognitas son divisibles
                        divisibles = x % y;
                        if(divisibles == 0){
                            resultado = x / y;

                            while(resultado > 1){
                                resultado /= 2;
                                exponente += 1;
                            }

                            //debe ser divisible para nuestra raiz de sexta.....
                            if((6%exponente) == 0){
                                resultado = 6 / exponente;
                                cout << "\nTU RESULTADO ES: " << pow(2, resultado) << endl;
                            }
                        }else{
                            //cuandos los dos numeros no son divisibles entre si....
                            int divisible = 2;


                            while(divisible <= 9){
                                int resultado_x = x%divisible;
                                int resultado_y = y%divisible;

                                if(resultado_x == 0 && resultado_y == 0){

                                    cout << x/divisible << "/" << y/divisible << " Elevandos al a raiz sexta...." << endl;
                                    break;
                                }else{
                                    divisible += 1;
                                }

                            }//while();

                        }


                        break;

                    case '2':
                        //aplaste F -> para poder salir del programa.
                        preguntar = false;


                        system("clear");

                        cout << "\n\t\t***********************************" << endl;
                        cout << "\t\t* CALCULADORA BASICA              *" << endl;
                        cout << "\t\t***********************************" << endl;

                        sleep(3);

                        system("clear");


                        while(p){
                                system("clear");
                                cout << "\n\t*****************************************" << endl;
                                cout << "\t*   [#] Introduce un numero: "; cin >> numero1;
                                cout << "\n\t*   [#] Introduce otro numero: "; cin >> numero2;
                                cout << "\n\t*   [#] Inserta el operador: "; cin >> operador;
                                cout << "\t*****************************************" << endl;

                                //primeros verificamos que los numeros no sean menores a 0
                                if(operador == '+'){

                                       bool respuesta = verificarNumeros(numero1, numero2);

                                       //verificamos que sean mayores de 0 para poder hacer cualquier tipo de proceso....
                                       if(respuesta){
                                            //si los numeros son mayores de 0... ejecutamos....
                                           double resultado = numero1 + numero2;
                                           cout << "\n[>>] La respuesta es: " << resultado;

                                        }else{
                                            cout << "\n[!] Introduciste un valor igual a 0";
                                        }

                                        //pregunat si desea salir del programa...
                                        cout << "\n\n[?] Deseas salir del programa [Y/N]: "; cin >> salir;


                                        if(salir == 'Y' || salir == 'y' || salir == 'N' || salir == 'n'){
                                              if(salir == 'Y' || salir == 'y'){
                                                //salimos del programa...
                                                p = false;
                                            }else{
                                                p = true;
                                            }

                                        }else{
                                            p = false;
                                        }
                                }


                                if(operador == '-'){

                                        bool respuesta = verificarNumeros(numero1, numero2);
                                        if(respuesta){
                                            //si los numeros son mayores de 0... ejecutamos....
                                            double resultado = numero1 - numero2;
                                            cout << "\n[>>] La respuesta es: " << resultado;
                                        }else{
                                            cout << "\n[!] Introduciste un valor igual a 0";
                                        }

                                        //pregunat si desea salir del programa...
                                        cout << "\n\n[?] Deseas salir del programa [Y/N]: "; cin >> salir;


                                        if(salir == 'Y' || salir == 'y' || salir == 'N' || salir == 'n'){
                                              if(salir == 'Y' || salir == 'y'){
                                                //salimos del programa...
                                                p = false;
                                            }else{
                                                p = true;
                                            }

                                        }else{
                                            p = false;
                                        }
                                    }

                                if(operador == '*'){

                                        bool respuesta = verificarNumeros(numero1, numero2);
                                        if(respuesta){
                                            double resultado = numero1 * numero2;
                                            cout << "\n[>>] La respuesta es: " << resultado;
                                        }else{
                                            cout << "\n[!] Introduciste un valor igual a 0";
                                        }

                                        //pregunat si desea salir del programa...
                                        cout << "\n\n[?] Deseas salir del programa [Y/N]: "; cin >> salir;


                                        if(salir == 'Y' || salir == 'y' || salir == 'N' || salir == 'n'){
                                              if(salir == 'Y' || salir == 'y'){
                                                //salimos del programa...
                                                p = false;
                                            }else{
                                                p = true;
                                            }

                                        }else{
                                            p = false;
                                        }
                                    }


                                if(operador == '/'){

                                        //el divisor tiene que ser distinto de cero....
                                        bool respuesta = verificarNumeros(numero1, numero2);
                                        if(respuesta){
                                            double resultado = numero1 / numero2;
                                            cout << "\n[>>] La respuesta es: " << resultado;
                                        }else{
                                            cout << "\n[!] Introduciste un valor igual a 0";
                                        }

                                        //pregunat si desea salir del programa...
                                        cout << "\n\n[?] Deseas salir del programa [Y/N]: "; cin >> salir;


                                        if(salir == 'Y' || salir == 'y' || salir == 'N' || salir == 'n'){
                                              if(salir == 'Y' || salir == 'y'){
                                                //salimos del programa...
                                                p = false;
                                            }else{
                                                p = true;
                                            }

                                        }else{
                                            p = false;
                                        }
                                    }

                                if(operador == '%'){

                                        bool respuesta = verificarNumeros(numero1, numero2);
                                        if(respuesta){
                                            int n = numero1;
                                            int n2 = numero2;
                                            int resultado = 0;

                                            resultado = n % n2;

                                            cout << "\n[>>] Tu resultado es: " << resultado;


                                        }else{
                                            cout << "\n[!] Introduciste un valor igual a 0";
                                        }

                                        //pregunat si desea salir del programa...
                                        cout << "\n\n[?] Deseas salir del programa [Y/N]: "; cin >> salir;


                                        if(salir == 'Y' || salir == 'y' || salir == 'N' || salir == 'n'){
                                              if(salir == 'Y' || salir == 'y'){
                                                //salimos del programa...
                                                p = false;
                                            }else{
                                                p = true;
                                            }

                                        }else{
                                            p = false;
                                        }
                                 }

                        }


                        break;

                    case '3':
                        preguntar = false;
                        break;

                    default:
                        cout << "\n[!] Haz introducido una opcion incorrecta. ";
                }

            }

        }else{ //CUANDO NUESTRAS CREDENCIALES NO SON CORRECTAS....
            //sus credenciales son incorrectas....
            intentos -= 1;
            cout << "\n\t\t\t\t\t[>] Numero de intentos: " << intentos <<  endl;
        }



    }while(intentos >= 1);


    return 0;
}
