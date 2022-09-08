int primo(int n) {
 if (n == 2) {
 return 1;
 } else if (n<2 || (n%2)== 0) {
 return 0;
 } else {
 int lim = (int) sqrt(n);
 for (int i=3; i<= lim; i+=2) {
 if (n% i == 0) {
 return 0;
 }
 }
 return 1;
 }
}