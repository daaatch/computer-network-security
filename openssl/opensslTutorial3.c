#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  char command[128];
  
  /* Generating key pairs using OpenSSL */
  
  /* generating RSA keys in binary format */
  strcpy(command, "openssl rsa -in private.key -out private.bin -outform DER");
  system(command);
  
  /* examinating key in binary format */
  strcpy(command, "openssl rsa -in private.bin -inform DER -noout -text");
  system(command);
  
  /* generating encrypted private RSA key */
  strcpy(command, "openssl genrsa -aes-256-cbc -out private.rsa.enc 4096");
  system(command);
  
  /* generating DSA keypairs */
  strcpy(command, "openssl dsaparam -out parameter.dsa 2048");
  system(command);
  
  /* generating DSA private key */
  strcpy(command, "openssl gendsa -out private.dsa parameter.dsa");
  system(command);
  
  /* examinating DSA private key */
  strcpy(command, "openssl dsa -in private.dsa -noout -text");
  system(command);
  
  /* generating DSA public key from the private one */
  strcpy(command, "openssl dsa -in private.dsa -pubout -out public.dsa");
  system(command);
  
  /* examinating DSA public key */
  strcpy(command, "openssl dsa -in public.dsa -pubin -noout -text");
  system(command);
  
  /* generating encrypted private DSA key */
  strcpy(command, "openssl gendsa -des-ede3-cbc -out private.dsa.enc parameter.dsa");
  system(command);

  return 0;
}
