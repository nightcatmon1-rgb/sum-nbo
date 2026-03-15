#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
if(argc<2) {
printf("Input one or more files.");
return 1;
}

uint32_t sum=0;

for(int i=1; i<argc; i++) {
FILE *fp = fopen(argv[i], "rb");

if(fp==NULL) {
printf("Error: Can not open file %s", argv[i]);
return 1;
}

uint32_t n;
size_t read = fread(&n, 1, sizeof(uint32_t), fp);

if(read<sizeof(uint32_t)) {
printf("Error: File %s is less than 4 bytes.", argv[i]);
fclose(fp);
return 1;
}

if(fgetc(fp)!=EOF) {
printf("Error: File %s is larger than 4 bytes.", argv[i]);
fclose(fp);
return 1;
}

fclose(fp);

n=ntohl(n);
sum+=n;


}

printf("%u(0x%08x)", sum, sum);
return 0;

}
