#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char command[50];
	
	/* Verifying integrity using OpenSSL */
	
	/* sha1 checksum */
	strcpy(command, "cat openssl-1.1.1w.tar.gz.sha1");
	system(command);	
	strcpy(command, "sha1sum openssl-1.1.1w.tar.gz");
	system(command);
	
	/* sha256 checksum */
	strcpy(command, "cat openssl-1.1.1w.tar.gz.sha256");
	system(command);
	strcpy(command, "sha256sum openssl-1.1.1w.tar.gz");
	system(command);
	
	return 0;

}
