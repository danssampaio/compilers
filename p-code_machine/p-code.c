#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define stacksize 500
#define levmax 3

char *instructions[] = {"LIT", "OPR", "LOD", "STO", "CAL", "INT", "JMP", "JPC"};
enum fct{LIT, OPR, LOD, STO, CAL, INT, JMP, JPC};
typedef enum fct fct;


struct instruction{
	fct f;
	int l;
	int a;
};
typedef struct instruction instruction; 


instruction i; // instruction register
instruction code[stacksize];

int s[stacksize] = {-1}; // datastore

int p, //p: program register
    b, //b: base register
    t, //t: topstack register
    instcount;

int base(int);
void interpret();

int main(){
	char inst[4];
    int aux = 1, var = 0, aux2 = 0;

	instcount = 0;

    printf("Enter instructions (OPR 0 0 to end): \n\n");

    while(aux){
        scanf("%s", inst);
        scanf("%d %d", &code[instcount].l, &code[instcount].a);
        if(strcmp(inst, "OPR") != 0 || code[instcount].l != 0 || code[instcount].a != 0){
        	for (int x = 0; x < 8; x++){
        		if(strcmp(inst, instructions[x]) == 0){
        			var = x;
                    aux2 += 1;
                }
        	}

            if(aux2 != 0){
                code[instcount].f = var;
                instcount += 1;
                aux2 = 0;
            }else{
              code[instcount].f = -1;
                instcount += 1;
            }
            
            
        }else
            aux = 0;
    }

	interpret();

	return 0;
}

int base(int l){
	int b1 = b;
	while(l > 0){
		b1 = s[b1];
		l = l - 1;
	}

	return b1;
}

void interpret(){	
    int aux, number_inst = -1;
    char *instruc = (char*)calloc(4,sizeof(char));
    
	s[1] = s[2] = s[3] = 0;
    t = p = 0;
	b = 1;

    printf("\n\nN    Instruction  Level    Argument    StackPtr     ProgCounter     \tStack\n\n");
	
	while(p < instcount){
		i = code[p];
		p += 1;

		switch(i.f){
			case LIT:{
				t += 1;
				s[t] = i.a;
                number_inst += 1;
				break;
			}
			case OPR:{
				switch(i.a){
					case 0:{ 
						t = b - 1;
						p = s[t + 3];
						b = s[t + 2];
                        number_inst += 1;
						break;
					} 
					case 1:{
						s[t] = ~s[t];
                        number_inst += 1;
						break;
					}
					case 2:{
						t -= 1;
						s[t] = s[t] + s[t+1];
                        number_inst += 1;
						break;
					}
					case 3:{
						t -= 1;
						s[t] = s[t] - s[t+1];
                        number_inst += 1;
						break;
					}
					case 4:{
						t -= 1;
						s[t] = s[t] * s[t+1];
                        number_inst += 1;
						break;
					}
					case 5:{
						t -= 1;
						s[t] = s[t] / s[t+1];
                        number_inst += 1;
						break;
					}
					case 6:{
						s[t] = ((s[t]%2) == 1);
                        number_inst += 1;
						break;
					}
					case 7:{
						t -= 1;
						s[t] = (s[t] == s[t+1]);
                        number_inst += 1;
						break;
					}
					case 8:{
						t -= 1;
						s[t] = (s[t] != s[t+1]);
                        number_inst += 1;
						break;
					}
					case 9:{
						t -= 1;
						s[t] = (s[t] < s[t+1]);
                        number_inst += 1;
						break;
					}
					case 10:{
						t -= 1;
						s[t] = (s[t] >= s[t+1]);
                        number_inst += 1;
						break;
					}
					case 11:{
						t -= 1;
						s[t] = (s[t] > s[t+1]);
                        number_inst += 1;
						break;
					}
					case 12:{
						t -= 1;
						s[t] = (s[t] <= s[t+1]);
                        number_inst += 1;
						break;
					}
				}
				break;
			}
			case LOD:{
				t += 1;
				s[t] = s[base(i.l) + i.a];
                number_inst += 1;
				break;
			}
			case STO:{
				s[base(i.l) + i.a] = s[t];
                number_inst += 1;
				t -= 1;
				break;
			}
			case CAL:{
				s[t+1] = base(i.l);
				s[t+2] = b;
				s[t+3] = p;
				b = t + 1;
				p = i.a;
                number_inst += 1;
				break;
			}
			case INT:{
				t += i.a;
                number_inst += 1;
				break;
			}
			case JMP:{
				p = i.a;
                number_inst += 1;
				break;
			}
			case JPC:{
				if(s[t] == 0)
					p = i.a;
                number_inst += 1;
				t -= 1;
				break;
			}
			default:{
				printf("\nERROR!! One of the instructions entered does not exist. Program finished in the last valid instruction.\n");
				exit(0);
				break;
			}
            
		}

        if(i.f < 8)
            strcpy(instruc, instructions[i.f]);
        else
	        strcpy(instruc, "---");


		printf("%d %9s %9d %10d %10d %13d \t   ", number_inst, instruc, i.l, i.a, s[t], p);
        printf("     ");
        
		for(aux = b; aux < t+1; aux++){
            printf("[%1d]", s[aux]);
            if(aux == 4)
                printf(" | ");
        }

		printf("\n");
	}
    
	printf("\nOUTPUT: %d\n\n", s[t]);
}