# Read from the file file.txt and output the tenth line to stdout.
# awk 'NR == 10 {print; exit}' file.txt
sed -n "10p" file.txt

