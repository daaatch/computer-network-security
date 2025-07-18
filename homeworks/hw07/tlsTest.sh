#!/bin/bash

# Hosts to test
HOSTS=("google.com:443" "amazon.com:443" "youtube.com:443" "facebook.com:443" "instagram.com:443" "uniroma1.it:443" "studenti.uniroma1.it:443" "openssl.org:443" "stackoverflow.com:443" "diag.uniroma1.it:443")

# TLS version
TLS_VERSION=("tls1_3")

# Cipher to use
CIPHER=("AES256-SHA")

# Output timings
TIMING="timings.txt"

# Timing initialization
echo "Host, TLS Version, Cipher, Time (s)" > $TIMING

# Loop over hosts
for HOST in "${HOSTS[@]}"; do
	# Loop over tls version
	for TLS in "${TLS_VERSION[@]}"; do
		# Loop over cipher
		for CIPHER in "${CIPHER[@]}"; do
			echo "Testing host $HOST with version $TLS using cipher $CIPHER"
			# Measuring time taken to execute
			START_TIME=$(date +%s.%N)
			openssl s_client -connect $HOST -$TLS -cipher $CIPHER < /dev/null > results_${HOST//:/_}_${TLS}_${CIPHER//-/_}.txt 2>&1
			END_TIME=$(date +%s.%N)
			# Measuring elapsed time
			ELAPSED_TIME=$(echo "$END_TIME - $START_TIME" | bc)
			# Save results
			echo "$HOST, $TLS, $CIPHER, $ELAPSED_TIME" >> $TIMING
			echo "Results saved to results_${HOST//:/_}_${TLS}_${CIPHER//-/_}.txt time taken: $ELAPSED_TIME seconds"
			done
		done
	done
echo "Timing results saved to $TIMING"
