#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char command[128];
	
	/* Encryption using OpenSSL */
	
	/* generating random data (with size) */
	strcpy(command, "openssl rand -hex 16");
	system(command);	
	
	/* generating random data in a file */
	strcpy(command, "openssl rand -hex -out randomData.txt 32");
	system(command);
	
	/* generating asymmetric keys (with size) */
	strcpy(command, "openssl genrsa 2048");
	system(command);	
	
	/* generating asymmetric keys in a file */
	strcpy(command, "openssl genrsa 2048 > private.key");
	system(command);	
	system("cat private.key");	
	
	/* output a generated key in a file */
	strcpy(command, "openssl genrsa -out private.key 2048");
	system(command);	
	system("cat private.key");
	
	/* examinating a previously generated key */
	strcpy(command, "openssl rsa -in private.key -noout -text");
	system(command);	
	
	/* generating a public key given a private one*/
	strcpy(command, "openssl rsa -in private.key -pubout -out public.key");
	system(command);	
	system("cat public.key");
	
	/* listing available algorithms */
	strcpy(command, "openssl list -cipher-algorithms");
	system(command);	
	
	/* obtaining informations on some algorithm */
	strcpy(command, "openssl list -options aes-256-cbc");
	system(command);	
	
	/* encrypting a text file */
	strcpy(command, "openssl aes-256-cbc -in palindrome.txt -out palindrome.enc -e -kfile private.key");
	system(command);	
	
	/* decrypting an encrypted file */
	strcpy(command, "openssl aes-256-cbc -in palindrome.enc -out palindrome.dec -d -kfile private.key");
	system(command);
	
	/* encrypting using a password */
	//strcpy(command, "openssl des-ede3-cbc -in palindrome.txt -out plaindromeDesEde3.enc -e -a");
	//system(command);
	
	/* decrypting using the same password*/
	//strcpy(command, "openssl des-ede3-cbc -in palindrome.enc -out palindromeDesEde3.dec -d -a");
	//system(command);
	
	/* using password key based derivation format*/
	/* -a to use base64 format */
	/* -iter to specify number of iterations (same for encryption and decryption) */
	strcpy(command, "openssl aes-256-cbc -in palindrome.txt -out palindrome.enc -e -a -kfile private.key -pbkdf2 -iter 10000");
	system(command);
	system("cat palindrome.enc");
	strcpy(command, "openssl aes-256-cbc -in palindrome.enc -out palindrome.dec -d -a -kfile private.key -pbkdf2 -iter 10000");
	system(command);
	system("cat palindrome.dec");
	
	/* yet another way to encrypt and decrypt */
	strcpy(command, "openssl enc -aes-256-ctr -in palindrome.txt -out palindrome.enc -e -a -kfile private.key -pbkdf2 -iter 2000");
	system(command);
	system("cat palindrome.enc");
	strcpy(command, "openssl enc -aes-256-ctr -in palindrome.enc -out palindrome.dec -d -a -kfile private.key -pbkdf2 -iter 2000");
	system(command);
	system("cat palindrome.dec");
	
	/* encrypt and decrypt using RSA keys*/
	strcpy(command, "openssl rsautl -encrypt -inkey public.key -pubin -in palindrome.txt -out plaindrome.enc");
	system(command);
	system("cat palindrome.enc");
	strcpy(command, "openssl rsautl -decrypt -inkey private.key -in plaindrome.enc -out plaindrome.dec");
	system(command);
	system("cat palindrome.dec");
	
	return 0;

}
