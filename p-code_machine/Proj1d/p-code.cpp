#include <stdio.h>

#define levmax 3
#define amax 2047

enum fct {LIT, OPR, LOD, STO, CAL, INT, JMP, JPC};

struct instruction {
     fct    f;
     int    l; 
     int    a; 
};

typedef struct instruction instruction;

instruction code[2048];

#define stacksize 500

 int p, // program-register
     b, // base-register
     t; // topstack-register
 

int s[stacksize]; 
instruction i;    //: instruction; {instruction register}

int base(int l){ 
    int b1; 
    
    b1 = b; 
    
    while (l > 0) {
        b1 = s[b1];
        l  = l - 1;
    }
    return b1;
}



int main(){
    int index = 0;

    //Fatorial(4):
    
    // // main()
    // code[0].f = INT; code[0].l = 0; code[0].a = 5;        // Ram[5] Pilha[5]
    // code[1].f = LIT; code[1].l = 0; code[1].a = 4;        //Fatorial à se calcular 
    // code[2].f = STO; code[2].l = 0; code[2].a = 8;        //Salva como parâmetro
    // code[3].f = CAL; code[3].l = 0; code[3].a = 6;        //Chamando a função fat()
    // code[4].f = LOD; code[4].l = 0; code[4].a = 9;        //Return fat()
    // code[5].f = OPR; code[5].l = 0; code[5].a = 0;        // Return 0
    
    // //fat()
    // code[6].f = INT; code[6].l = 0; code[6].a = 5;         // Ram[5] Pilha[5]
    // code[7].f = LOD; code[7].l = 0; code[7].a = 3;         // Load parâmentro
    // code[8].f = LIT; code[8].l = 0; code[8].a = 1;         // Sobe 1 para comparação
    // code[9].f = OPR; code[9].l = 0; code[9].a = 12;        // Parâmetro <= 1 ??
    // code[10].f = JPC; code[10].l = 0; code[10].a = 13;    
    
    // //if(n <= 1)
    // code[11].f = STO; code[11].l = 0; code[11].a = 4;      // Return = resultado
    // code[12].f = OPR; code[12].l = 0; code[12].a = 0;      // OPR 0 0
    
    // //else
    // code[13].f = LOD; code[13].l = 0; code[13].a = 3;       // Load parâmetro
    // code[14].f = LIT; code[14].l = 0; code[14].a = 1;       // Sobe 1 para subtração
    // code[15].f = OPR; code[15].l = 0; code[15].a = 3;       // Parâmetro - 1
    // code[16].f = STO; code[16].l = 0; code[16].a = 8;       // Salva como parâmetro
    // code[17].f = CAL; code[17].l = 0; code[17].a = 6;       // Chama a função fat()

    // //mult
    // code[18].f = LOD; code[18].l = 0; code[18].a = 3;       // Load parâmetro
    // code[19].f = LOD; code[19].l = 0; code[19].a = 9;       // Load Return
    // code[20].f = OPR; code[20].l = 0; code[20].a = 4;       // mult top retorno
    // code[21].f = STO; code[21].l = 0; code[21].a = 4;       // Salva no return
    // code[22].f = OPR; code[22].l = 0; code[22].a = 0;       // OPR 0 0


    // //Fibonacci(5):

    // // main()
    // code[0].f = INT; code[0].l = 0; code[0].a = 3;        // Ram[3] Pilha[3]
    // code[1].f = LIT; code[1].l = 0; code[1].a = 5;        //Fibonacci à se calcular 
    // code[2].f = STO; code[2].l = 0; code[2].a = 6;        //Salva como parâmetro
    // code[3].f = CAL; code[3].l = 0; code[3].a = 6;        //Chamando a função fib()
    // code[4].f = LOD; code[4].l = 0; code[4].a = 6;        //Return fib
    // code[5].f = OPR; code[5].l = 0; code[5].a = 0;        // Return 0
    
    // //fib()
    // code[6].f = INT; code[6].l = 0; code[6].a = 5;         // Ram[5] Pilha[5]
    // code[7].f = LOD; code[7].l = 0; code[7].a = 3;         // Load parâmentro
    // code[8].f = LIT; code[8].l = 0; code[8].a = 1;         // Sobe 1 para comparação
    // code[9].f = OPR; code[9].l = 0; code[9].a = 12;        // Parâmetro <= 1 ??
    // code[10].f = JPC; code[10].l = 0; code[10].a = 13;    
    
    // //if(n <= 1)
    // code[11].f = STO; code[11].l = 0; code[11].a = 4;      //Return = resultado
    // code[12].f = OPR; code[12].l = 0; code[12].a = 0;      // OPR 0 0
    
    // //else
    // code[13].f = LOD; code[13].l = 0; code[13].a = 3;       // Load parâmetro
    // code[14].f = LIT; code[14].l = 0; code[14].a = 1;       // Sobe 1 para subtração
    // code[15].f = OPR; code[15].l = 0; code[15].a = 3;       // Parâmetro - 1
    // code[16].f = STO; code[16].l = 0; code[16].a = 8;       // Salva como parâmetro
    // code[17].f = CAL; code[17].l = 0; code[17].a = 6;       // Chama a função fib()

    // //sum
    // code[18].f = LOD; code[18].l = 0; code[18].a = 8;       // Load parâmetro
    // code[19].f = LOD; code[19].l = 0; code[19].a = 13;       // Load parâmetro 2
    // code[20].f = OPR; code[20].l = 0; code[20].a = 2;       // sum top retorno
    // code[21].f = STO; code[21].l = 0; code[21].a = 3;       // Salva no return
    // code[22].f = OPR; code[22].l = 0; code[22].a = 0;       // OPR 0 0

    

    printf("\n start pl/0");
    printf("\n\n t   b   p     f   l   a");
    printf("\n === === ===   === === === ");
    
    t = 0; // topstack-register
    b = 1; // base-register
    p = 0; // program-register
    
    s[1] = 0; 
    s[2] = 0; 
    s[3] = 0;
 
    do {
        i = code[p]; 
      
            printf("\n %3d %3d %3d   ", t, b, p);
            p = p + 1;
            
            switch  (i.f) { // with i do case f of
            case LIT : { 
                    t = t + 1; 
                    s[t] = i.a; 
                    printf("LIT %3d %3d", i.l, i.a); 
                } 
                break;
                
            case OPR :
               printf("OPR %3d %3d", i.l, i.a);
               switch(i.a){
                    case 0: 
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        break;
                   
                    case 1:
                        s[t] = -s[t];
                        break;
                   
                    case 2: 
                        t = t - 1;
                        s[t] = s[t] + s[t + 1];
                        break;
                   
                    case 3:
                        t = t - 1;
                        s[t] = s[t] - s[t + 1];
                        break;
                   
                    case 4: 
                        t = t - 1;
                        s[t] = s[t] * s[t + 1];
                        break;
                   
                    case 5:
                        t = t - 1;
                        s[t] = s[t] / s[t + 1]; 
                        break;
                   
                    case 6:
                        s[t] = (s[t]) % 2; 
                        break;
                   
                    case 7:
                        t = t - 1;
                        s[t] = (s[t] == s[t + 1]);
                        break;
                   
                    case 8:
                        t = t - 1;
                        s[t] = (s[t] != s[t + 1]);
                        break;
                   
                    case 9:
                        t = t - 1;
                        s[t] = (s[t] < s[t + 1]);
                        break;
                   
                    case 10:
                        t = t - 1;
                        s[t] = (s[t] >= s[t + 1]);
                        break;
                   
                    case 11: 
                        t = t - 1;
                        s[t] = (s[t] > s[t + 1]);
                        break;
                   
                    case 12: 
                        t = t - 1;
                        s[t] = (s[t] <= s[t + 1]);
                        break;
                   
                } 
            break;
                
            case LOD : 
                printf("LOD %3d %3d", i.l, i.a);
                t = t + 1; 
                s[t] = s[base(i.l) + i.a];
                break;
            
            case STO : 
                printf("STO %3d %3d", i.l, i.a);
                s[base(i.l)+i.a] = s[t]; 
                t = t - 1;
                break;
            
            case CAL :
                printf("CAL %3d %3d", i.l, i.a);
                s[t + 1] = base(i.l); 
                s[t + 2] = b; 
                s[t + 3] = p;
                b = t + 1; 
                p = i.a;
                break;
            
            case INT : 
               t = t + i.a;
               printf("INT %3d %3d", i.l, i.a); 
               break;
              
            case JMP : 
               p = i.a;    
               printf("JMP %3d %3d", i.l, i.a); 
               break;
              
            case JPC : 
               if (s[t] == 0) { 
                    p = i.a; 
                    t = t - 1; 
                   }  
               printf("JPC %3d %3d", i.l, i.a); 
               break;
              
            } 
     
        printf("      s[] : ");
         
        for (int h=0; h<=t; h++) 
            printf(" %3d", s[h]); 
          
    } while ( p != 0 );

    printf("\n === === ===   === === ==="); 
    printf("\n t   b   p     f   l   a");
    printf("\n\n end pl/0");


	return 0;
}
