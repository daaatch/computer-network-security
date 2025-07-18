#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

int main(){
  const char *password1 = "password";
  const char *password2 = "strongPassword";
  const char *password3 = "verySecretPassword";
  const unsigned char salt[] = "aPinchOfSalt";
  int salt_length = strlen((char *)salt);
  int key_length = 32; //256 bits key
  unsigned char key[32];
  
  /*** PASSWORD #1 ***/
  PKCS5_PBKDF2_HMAC(password1, strlen(password1), salt, salt_length, 100, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password1);
  printf("Number of iterations: 100\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  PKCS5_PBKDF2_HMAC(password1, strlen(password1), salt, salt_length, 1000, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password1);
  printf("Number of iterations: 1000\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  PKCS5_PBKDF2_HMAC(password1, strlen(password1), salt, salt_length, 10000, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password1);
  printf("Number of iterations: 10000\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  /*** PASSWORD #2 ***/
  PKCS5_PBKDF2_HMAC(password2, strlen(password2), salt, salt_length, 100, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password2);
  printf("Number of iterations: 100\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  PKCS5_PBKDF2_HMAC(password2, strlen(password2), salt, salt_length, 1000, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password2);
  printf("Number of iterations: 1000\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  PKCS5_PBKDF2_HMAC(password2, strlen(password2), salt, salt_length, 10000, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password2);
  printf("Number of iterations: 10000\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  /*** PASSWORD #3 ***/
  PKCS5_PBKDF2_HMAC(password3, strlen(password3), salt, salt_length, 100, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password3);
  printf("Number of iterations: 100\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  PKCS5_PBKDF2_HMAC(password3, strlen(password3), salt, salt_length, 1000, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password3);
  printf("Number of iterations: 1000\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  PKCS5_PBKDF2_HMAC(password3, strlen(password3), salt, salt_length, 10000, EVP_sha256(), key_length, key);
  printf("Clear password: %s\n", password3);
  printf("Number of iterations: 10000\n");
  printf("Derived key: ");
  for(int i=0; i<key_length; i++){
    printf("%02x", key[i]);
  }
  printf("\n\n");
  
  return 0;
}
