# Read from the file words.txt and output the word frequency list to stdout.
tr -s ' ' '\n' < words.txt | tr " " "\n" |sort -bnr| uniq -c | sort -r | awk '{print $2" " $1 }'
