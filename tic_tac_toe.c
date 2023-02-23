#include<stdio.h>
char a[3][3], n, m;
int i, j, x, xx, o, oo, x_x, o_o, l;
//creating the table
void table(void)
{
    printf("Create the Table(123456789) :\n");
    for (i = 0; i < 3; i++) {
	for (j = 0; j < 3; j++) {
	    scanf("%c", &a[i][j]);
	}
    }
    for (i = 0; i < 3; i++) {
	  printf("  -----------\n ");
	for (j = 0; j < 3; j++) {
	    printf("| %c ", a[i][j]);
	}
	printf("|\n");
    }
    printf("  -----------\n ");
}
//win or lose
void result(void)
{
	for (l = 1; l < 6; l++) {
	   printf("chance %d :\n", l);
	printf("User 1 :\nEnter the number 1 to 9 :\n");
restart:
	scanf("\n%c", &n);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (a[i][j] == n) {
				a[i][j] = 'x';
				goto run;
			}
		}
	}
       for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (a[i][j] != n) {
			printf("Invalid number:\nPlease Enter Another Number:\n");
			goto restart;
			}
		}
       }
run:
	for (i = 0; i < 3; i++) {
		printf("  -----------\n ");
		for (j = 0; j < 3; j++) {
			printf("| %c ", a[i][j]);
		}
		printf("|\n");
	}
	printf("  -----------\n ");
    if (l >= 3) {
	for (i = 0; i < 3; i++) {
		x = 0, xx = 0, x_x = 0;
		for (j = 0; j < 3; j++) {
			if (a[i][j] == 'x') {
				x += 1;
			}
			if (a[j][i] == 'x') {
				xx += 1;
			}
			if (a[j][j] == 'x') {
				x_x += 1;
			}
		}
		if (x == 3 || xx == 3 || x_x == 3 || (a[0][2] == 'x' && a[1][1] == 'x' && a[2][0] == 'x')) {
		printf("User 1 Win\n");
		goto end;
		}
      }
    }
    if (l >= 1 && l < 5) {
	printf("User 2 :\nEnter the number 1 to 9 :\n");
re_start:
	scanf("\n%c", &m);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (a[i][j] == m) {
				a[i][j] = 'o';
				goto r_u_n;
			}
		}
	}
       for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (a[i][j] != m) {
				printf("Invalid number:\nPlease Enter Another Number:\n");
				goto re_start;
			}
		}
       }
r_u_n:
	for (i = 0; i < 3; i++) {
		printf("  -----------\n ");
		for (j = 0; j < 3; j++) {
			printf("| %c ", a[i][j]);
		}
		printf("|\n");
	}
	printf("  -----------\n ");
     if (l >= 3) {
	for (i = 0; i < 3; i++) {
		o = 0, oo = 0, o_o = 0;
		for (j = 0; j < 3; j++) {
			if (a[i][j] == 'o') {
				o += 1;
			}
			if (a[j][i] == 'o') {
				oo += 1;
			}
			if (a[j][j] == 'o') {
				o_o += 1;
			}
		}
		if (oo == 3 || o_o == 3 || o == 3 || (a[0][2] == 'o' && a[1][1] == 'o' && a[2][0] == 'o')) {
			printf("User 2 Win\n");
			goto end;
		}
		}
	}
    }
  }
    printf("Draw The Match\n");
end:
    printf("\n");
}
//main function
int main(void)
{
table();
result();
return 0;
}

