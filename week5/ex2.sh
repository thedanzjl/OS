
#!/usr/bin/bash
filename="ex2text.txt"
while read number
do
    new_number="$number"
done < "$filename"

number=$((number + 1))

echo "" >> ex2text.txt
echo -n "$number" >> ex2text.txt